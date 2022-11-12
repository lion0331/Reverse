// Torchlight2Dialog.cpp: 实现文件
//

#include "pch.h"
#include "Torchlight2.h"
#include "Torchlight2Dialog.h"
#include "afxdialogex.h"


// Torchlight2Dialog 对话框

IMPLEMENT_DYNAMIC(Torchlight2Dialog, CDialogEx)

Torchlight2Dialog::Torchlight2Dialog(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_Main, pParent)
{

}

Torchlight2Dialog::~Torchlight2Dialog()
{
}

void Torchlight2Dialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB1, mTab);
}


BEGIN_MESSAGE_MAP(Torchlight2Dialog, CDialogEx)
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB1, &Torchlight2Dialog::OnTcnSelchangeTab1)
END_MESSAGE_MAP()

BOOL Torchlight2Dialog::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。


	InstallPage(&PageZero, IDD_Zero, L"角色数据", true);
	InstallPage(&PageOne, IDD_One, L"功能");
	InstallPage(&PageTwo, IDD_Two, L"技能");


	//
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}
// Torchlight2Dialog 消息处理程序


bool Torchlight2Dialog::InstallPage(CDialogEx* wnd, int IDD_WND, CString&& _Name, BOOL IsShow)
{

	if (CurPage >= MAX_PAGE_MAIN) return false;
	Pages[CurPage] = wnd;
	Pages[CurPage]->Create(IDD_WND,this);
	Pages[CurPage]->ShowWindow(IsShow);

	CRect rect;
	mTab.GetClientRect(&rect);
	rect.top += 40;
	Pages[CurPage]->MoveWindow(&rect);
	mTab.InsertItem(CurPage, _Name);

	CurPage++;
	return false;
}




void Torchlight2Dialog::OnTcnSelchangeTab1(NMHDR* pNMHDR, LRESULT* pResult)
{
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
	int n = mTab.GetCurSel();
	for (int i = 0; i < CurPage; i++)
	{
		Pages[i]->ShowWindow(i == n);
	}
}
