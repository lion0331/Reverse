// ELEMENTDLL.cpp : 定义 DLL 的初始化例程。
//

#include "stdafx.h"
#include "ELEMENTDLL.h"
#include "ELEMENTDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//
//TODO: 如果此 DLL 相对于 MFC DLL 是动态链接的，
//		则从此 DLL 导出的任何调入
//		MFC 的函数必须将 AFX_MANAGE_STATE 宏添加到
//		该函数的最前面。
//
//		例如:
//
//		extern "C" BOOL PASCAL EXPORT ExportedFunction()
//		{
//			AFX_MANAGE_STATE(AfxGetStaticModuleState());
//			// 此处为普通函数体
//		}
//
//		此宏先于任何 MFC 调用
//		出现在每个函数中十分重要。这意味着
//		它必须作为函数中的第一个语句
//		出现，甚至先于所有对象变量声明，
//		这是因为它们的构造函数可能生成 MFC
//		DLL 调用。
//
//		有关其他详细信息，
//		请参阅 MFC 技术说明 33 和 58。
//

// CELEMENTDLLApp

BEGIN_MESSAGE_MAP(CELEMENTDLLApp, CWinApp)
END_MESSAGE_MAP()


// CELEMENTDLLApp 构造

CELEMENTDLLApp::CELEMENTDLLApp()
{
	// TODO: 在此处添加构造代码，
	// 将所有重要的初始化放置在 InitInstance 中
}


// 唯一的一个 CELEMENTDLLApp 对象

CELEMENTDLLApp theApp;

ELEMENTDialog* PMainDialog;//窗口类
DWORD WINAPI ShowDialog(LPARAM lpData)
{
	PMainDialog = new ELEMENTDialog;//给指针分配空间 
	PMainDialog->DoModal();//阻塞的方式 模态窗口
	delete PMainDialog;//释放空间
	FreeLibraryAndExitThread(theApp.m_hInstance, 1);//释放DLL退出线程
	return TRUE;
}
// CELEMENTDLLApp 初始化

BOOL CELEMENTDLLApp::InitInstance()
{
	CWinApp::InitInstance();
	::CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)ShowDialog, NULL, NULL, NULL);//创建线程
	return TRUE;
}
