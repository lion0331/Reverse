
// HomeWorldRMDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "HomeWorldRM.h"
#include "HomeWorldRMDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
//#include "F:\\WorkFiles\\Source\\Reverse\\HomeWorldRM\\HomeWorldRMDll\\HomeWorld.h"



// CHomeWorldRMDlg 对话框



CHomeWorldRMDlg::CHomeWorldRMDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_HOMEWORLDRM_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CHomeWorldRMDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CHomeWorldRMDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_CHECK1, &CHomeWorldRMDlg::OnBnClickedCheck1)
END_MESSAGE_MAP()


// CHomeWorldRMDlg 消息处理程序

BOOL CHomeWorldRMDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CHomeWorldRMDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CHomeWorldRMDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CHomeWorldRMDlg::MonitoringThreadProc()
{
	// TODO: 在此添加控件通知处理程序代码
	//CDialogEx::OnOK();
	TCHAR     szName[MAX_PATH] = { 0 };
	CString m_StrDLLPath = _T("");
	GetCurrentDirectory(MAX_PATH, szName); //获取当前进程已加载模块的文件的完整路径，该模块必须由当前进程加载
	m_StrDLLPath = szName;
	m_StrDLLPath = m_StrDLLPath + _T("\\HomeWorldRMDll.dll");
	//为DLL文件的绝对路径
	if (m_StrDLLPath.IsEmpty()) {
		MessageBox(_T("请选择DLL模块"));
		return;
	}
	// :: 代表全局查找，后面的内容可以通过SPY++获取
	// 【参数1】类
	// 【参数2】标题
	HWND hwnd = ::FindWindowA("hwRM", "Homeworld Remastered");
	if (hwnd == NULL) {
		MessageBox(L"没有找到");
		return;
	}
	// 获取窗口所在的PID
	DWORD dwPID = 0;
	GetWindowThreadProcessId(hwnd, &dwPID);
	if (dwPID == 0) {
		MessageBox(L"获取PID失败");
		return;
	}
	// 通过PID获取进程的句柄
	// 获取句柄后，可以完全控制进程
	HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, dwPID);
	if (hProcess == NULL) {
		MessageBox(L"进程的句柄获取失败");
		return;
	}
	// TerminateProcess(hProcess, 0);//关闭句柄对象
	// 实现注入
	// 1.首先要提升权限，打开进程的访问令牌
	// 【参数1】当前程序
	// 【参数2】权限，可添加的权限|可查询的权限
	HANDLE hToken;
	if (FALSE == OpenProcessToken(GetCurrentProcess(), TOKEN_ADJUST_PRIVILEGES | TOKEN_QUERY, &hToken)) {
		// 权限修改失败
		MessageBox(L"权限修改失败");
		return;
	}
	//2.查看与进程相关的特权信息
	LUID luid;
	if (FALSE == LookupPrivilegeValue(NULL, SE_DEBUG_NAME, &luid)) {
		// 特权信息查询失败
		MessageBox(L"特权信息查询失败");
		return;
	};
	//3.调节进程的访问令牌的特权属性
	// 这几行代码固定不变
	TOKEN_PRIVILEGES tkp;
	tkp.PrivilegeCount = 1;
	tkp.Privileges[0].Luid = luid;
	tkp.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED; // 打开特权
	// 【参数1】访问令牌
	// 【参数2】是否禁用特权
	// 【参数3】新特权所占的字节数
	// 【参数4】原来的特权是否需要保存
	// 【参数5】原特权的长度
	if (FALSE == AdjustTokenPrivileges(hToken, FALSE, &tkp, sizeof(tkp), NULL, NULL)) {
		// 提升特权失败
		MessageBox(L"提升特权失败");
		return;
	};

	//在远程进程中申请内存空间
	// 【参数1】程序的句柄对象
	// 【参数2】申请的内存地址，由系统分配，所以为NULL
	// 【参数3】申请的内存长度
	// 【参数4】调用物理存储器
	// 【参数5】这块内存可读可写，可执行
	// 【返回】申请到的地址
	LPVOID lpAddr = VirtualAllocEx(hProcess, NULL, m_StrDLLPath.GetLength() * 2 + 2, MEM_COMMIT, PAGE_EXECUTE_READWRITE);
	if (lpAddr == NULL) {
		// 在远程进程中申请内存失败
		MessageBox(L"在远程进程中申请内存失败");
		return;
	}
	// 把DLL路径写入到远程进程中
	// 强行修改程序的内存
	// 【参数1】程序的句柄
	// 【参数2】申请到的内存首地址
	// 【参数3】写入的内容
	// 【参数4】要写入的字节数
	// 【参数5】
	if (FALSE == WriteProcessMemory(hProcess, lpAddr, m_StrDLLPath, m_StrDLLPath.GetLength() * 2, NULL)) {
		// 在远程进程中写入数据失败
		MessageBox(L"在远程进程中写入数据失败");
		return;
	};

	////加载HomeWorldRMDll.dll
	//HMODULE HomeWorldRMDll = LoadLibraryW(L"HomeWorldRMDll.dll");
	//if (HomeWorldRMDll == NULL)
	//{
	//	MessageBox(L"加载HomeWorldRMDll失败");
	//	return;
	//}

	// 调用Kernel32.dll中的LoadLibraryW方法用以加载DLL文件
	PTHREAD_START_ROUTINE pfnStartAssr = (PTHREAD_START_ROUTINE)GetProcAddress(GetModuleHandle(L"Kernel32.dll"), "LoadLibraryW");

	// 在远程进程中开辟线程
	// 【参数1】远程线程的句柄
	// 【参数2】线程属性。NULL表示使用默认属性
	// 【参数3】堆栈大小。0代表默认
	// 【参数4】加载DLL文件的对象
	// 【参数5】加载文件的路径
	// 【参数6】延迟时间。0代表立即启动
	// 【参数7】线程ID。为NULL就行了


	HANDLE hThread = CreateRemoteThread(hProcess, NULL, 0, pfnStartAssr, lpAddr, 0, NULL);
	if (hThread == NULL) {
	// 创建远程线程失败
	MessageBox(L"创建远程线程失败");
	return;
	}
	MessageBox(L"注入成功");
	//关闭句柄
	CloseHandle(hProcess);
	//FreeLibrary(HomeWorldRMDll);
	return;



}



void CHomeWorldRMDlg::OnBnClickedCheck1()
{
	// TODO: 在此添加控件通知处理程序代码
	MonitoringThreadProc();
	//HINSTANCE m_hDll = LoadLibrary(L"HomeWorldRMDll.dll");

	//if (NULL == m_hDll)
	//{
	//	MessageBox(L"Load dll failed!");
	//	return;

	//}
	//else
	//{

	//	if (BST_CHECKED == IsDlgButtonChecked(IDC_CHECK1)) {
	//		typedef void(WINAPI* mGodMode)();
	//		mGodMode m_GodMode;
	//		m_GodMode = (mGodMode)GetProcAddress(m_hDll, "GodMode");
	//		if (m_GodMode == NULL)
	//		{
	//			MessageBox(L"加载GodMode函数地址失败");
	//			return;
	//		}
	//		MessageBox(TEXT("m_GodMode"));
	//		m_GodMode();
	//		MessageBox(L"GodMode");
	//	}
	//	else
	//	{
	//		typedef void(WINAPI* mNormalMode)();
	//		mNormalMode m_NormalMode;
	//		m_NormalMode = (mNormalMode)GetProcAddress(m_hDll, "NormalMode");
	//		if (m_NormalMode == NULL)
	//		{
	//			MessageBox(L"加载NormalMode函数地址失败");
	//			return;
	//		}
	//		m_NormalMode();
	//		MessageBox(L"NormalMode");
	//	}

	//}
}
