// ELEMENTDLL.h : ELEMENTDLL DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CELEMENTDLLApp
// �йش���ʵ�ֵ���Ϣ������� ELEMENTDLL.cpp
//

class CELEMENTDLLApp : public CWinApp
{
public:
	CELEMENTDLLApp();

// ��д
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
