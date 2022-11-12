// SkillDialog.cpp: 实现文件
//

#include "pch.h"
#include "Torchlight2.h"
#include "SkillDialog.h"
#include "afxdialogex.h"


// SkillDialog 对话框

IMPLEMENT_DYNAMIC(SkillDialog, CDialogEx)

SkillDialog::SkillDialog(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_Two, pParent)
{

}

SkillDialog::~SkillDialog()
{
}

void SkillDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(SkillDialog, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &SkillDialog::OnBnClickedButton1)
END_MESSAGE_MAP()


// SkillDialog 消息处理程序


void SkillDialog::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	ULONG_PTR _Stat = (ULONG_PTR)GetModuleHandleA("Torchlight2.exe");
	_Stat = (ULONG_PTR)(_Stat + 0x00184170);
	
	ULONG_PTR _ECX = (ULONG_PTR)GetModuleHandleA("Torchlight2.exe");
	_ECX = *(ULONG_PTR*)(_ECX + 0x024E95F4);
	_ECX = *(ULONG_PTR*)(_ECX + 0x2C);
	
	ULONG_PTR ECX_ = (ULONG_PTR)GetModuleHandleA("Torchlight2.exe");
	ECX_ = *(ULONG_PTR*)(ECX_ + 0x0337EFC8);
	ECX_ = *(ULONG_PTR*)(ECX_ + 0x9C);
	ECX_ = *(ULONG_PTR*)(ECX_ + 0x40);
	ECX_ = (ULONG_PTR)(ECX_ + 0xD8C);

	__asm{
		push _ECX
		mov ecx, ECX_
		mov eax, _Stat
		call eax
	}
}
