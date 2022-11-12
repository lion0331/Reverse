// FunctionDialog.cpp: 实现文件
//

#include "pch.h"
#include "Torchlight2.h"
#include "FunctionDialog.h"
#include "afxdialogex.h"


// FunctionDialog 对话框

IMPLEMENT_DYNAMIC(FunctionDialog, CDialogEx)

FunctionDialog::FunctionDialog(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_One, pParent)
{

}

FunctionDialog::~FunctionDialog()
{
}

void FunctionDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(FunctionDialog, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &FunctionDialog::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_CHECK1, &FunctionDialog::OnBnClickedCheck1)
END_MESSAGE_MAP()


// FunctionDialog 消息处理程序

void KillEnemies()
{
	__asm
	{
		cmp [esi + 0x31C], 0x01
		jne EnemyHealth
		jmp return

	EnemyHealth:
		fldz
		fstp dword ptr [esi + 0x00000560]
	// __declspec(naked) 
	return:
		cmp [esi + 0x31C], 0x07
	}
}

void FunctionDialog::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	ULONG_PTR _Stat = (ULONG_PTR)GetModuleHandleA("Torchlight2.exe");
	_Stat = *(ULONG_PTR*)(_Stat + 0x24E95F4);
	_Stat = *(ULONG_PTR*)(_Stat + 0x2C);

	*(float*)(_Stat + 0x70) = 0.05;
	*(float*)(_Stat + 0x74) = -0.21;
	*(float*)(_Stat + 0x78) = 250;

	*(float*)(_Stat + 0x670) = 0.05;
	*(float*)(_Stat + 0x674) = -0.21;
	*(float*)(_Stat + 0x678) = 250;

}


void FunctionDialog::OnBnClickedCheck1()
{
	// TODO: 在此添加控件通知处理程序代码   "Torchlight2.exe"+11EA65

	ULONG_PTR _Stat = (ULONG_PTR)GetModuleHandleA("Torchlight2.exe");
	_Stat = (ULONG_PTR)(_Stat + 0x0011EA65);

	if (BST_CHECKED == IsDlgButtonChecked(IDC_CHECK1))
	{

		DWORD Hook地址 = _Stat;
		DWORD Hook子程序指针 = (DWORD)KillEnemies;
		DWORD 跳转值 = Hook子程序指针 - Hook地址 - 5;

		DWORD old = 0;
		VirtualProtect((PVOID)_Stat, 100, PAGE_EXECUTE_READWRITE, &old);

		*(BYTE*)_Stat = 0xE8;
		*(DWORD*)(_Stat + 1) = 跳转值;
		*(BYTE*)(_Stat + 5) = 0x90;
		*(BYTE*)(_Stat + 6) = 0x90;

		VirtualProtect((PVOID)_Stat, 100, old, &old);

	}

	else
	{

		DWORD old = 0;
		VirtualProtect((PVOID)_Stat, 100, PAGE_EXECUTE_READWRITE, &old);

		*(BYTE*)_Stat = 0x83;
		*(BYTE*)(_Stat + 1) = 0xBE;
		*(BYTE*)(_Stat + 2) = 0x1C;
		*(BYTE*)(_Stat + 3) = 0x03;
		*(BYTE*)(_Stat + 4) = 0x00;
		*(BYTE*)(_Stat + 5) = 0x00;
		*(BYTE*)(_Stat + 6) = 0x07;

		VirtualProtect((PVOID)_Stat, 100, old, &old);
	}
}
