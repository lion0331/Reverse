// ELEMENTDLL.cpp : ���� DLL �ĳ�ʼ�����̡�
//

#include "stdafx.h"
#include "ELEMENTDLL.h"
#include "ELEMENTDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//
//TODO: ����� DLL ����� MFC DLL �Ƕ�̬���ӵģ�
//		��Ӵ� DLL �������κε���
//		MFC �ĺ������뽫 AFX_MANAGE_STATE ����ӵ�
//		�ú�������ǰ�档
//
//		����:
//
//		extern "C" BOOL PASCAL EXPORT ExportedFunction()
//		{
//			AFX_MANAGE_STATE(AfxGetStaticModuleState());
//			// �˴�Ϊ��ͨ������
//		}
//
//		�˺������κ� MFC ����
//		������ÿ��������ʮ����Ҫ������ζ��
//		��������Ϊ�����еĵ�һ�����
//		���֣������������ж������������
//		������Ϊ���ǵĹ��캯���������� MFC
//		DLL ���á�
//
//		�й�������ϸ��Ϣ��
//		����� MFC ����˵�� 33 �� 58��
//

// CELEMENTDLLApp

BEGIN_MESSAGE_MAP(CELEMENTDLLApp, CWinApp)
END_MESSAGE_MAP()


// CELEMENTDLLApp ����

CELEMENTDLLApp::CELEMENTDLLApp()
{
	// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}


// Ψһ��һ�� CELEMENTDLLApp ����

CELEMENTDLLApp theApp;

ELEMENTDialog* PMainDialog;//������
DWORD WINAPI ShowDialog(LPARAM lpData)
{
	PMainDialog = new ELEMENTDialog;//��ָ�����ռ� 
	PMainDialog->DoModal();//�����ķ�ʽ ģ̬����
	delete PMainDialog;//�ͷſռ�
	FreeLibraryAndExitThread(theApp.m_hInstance, 1);//�ͷ�DLL�˳��߳�
	return TRUE;
}
// CELEMENTDLLApp ��ʼ��

BOOL CELEMENTDLLApp::InitInstance()
{
	CWinApp::InitInstance();
	::CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)ShowDialog, NULL, NULL, NULL);//�����߳�
	return TRUE;
}
