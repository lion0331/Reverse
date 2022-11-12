// Torchlight2.h: Torchlight2 DLL 的主标头文件
//

#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含 'pch.h' 以生成 PCH"
#endif

#include "resource.h"		// 主符号
#include "Torchlight2Dialog.h"

// CTorchlight2App
// 有关此类实现的信息，请参阅 Torchlight2.cpp
//

class CTorchlight2App : public CWinApp
{
public:
	CTorchlight2App();

// 重写
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
