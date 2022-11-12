// RoleDialog.cpp: 实现文件
//

#include "pch.h"
#include "Torchlight2.h"
#include "RoleDialog.h"
#include "afxdialogex.h"


// RoleDialog 对话框

IMPLEMENT_DYNAMIC(RoleDialog, CDialogEx)

RoleDialog::RoleDialog(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_Zero, pParent)
	, HP(0)
	, MP(0)
	, Strength(0)
	, Dexterity(0)
	, Focus(0)
	, Vitality(0)
	, Level(0)
	, Fame(0)
	, Name(_T(""))
	, StatPoints(0)
	, SkillPoints(0)
	, EXP(0)
	, Gold(0)
{

}

RoleDialog::~RoleDialog()
{
}

void RoleDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, HP);
	DDX_Text(pDX, IDC_EDIT2, MP);
	DDX_Text(pDX, IDC_EDIT3, Strength);
	DDX_Text(pDX, IDC_EDIT4, Dexterity);
	DDX_Text(pDX, IDC_EDIT5, Focus);
	DDX_Text(pDX, IDC_EDIT6, Vitality);
	DDX_Text(pDX, IDC_EDIT7, Level);
	DDX_Text(pDX, IDC_EDIT8, Fame);
	DDX_Text(pDX, IDC_EDIT9, Name);
	DDX_Text(pDX, IDC_EDIT10, StatPoints);
	DDX_Text(pDX, IDC_EDIT11, SkillPoints);
	DDX_Text(pDX, IDC_EDIT12, EXP);
	DDX_Text(pDX, IDC_EDIT13, Gold);
}


BEGIN_MESSAGE_MAP(RoleDialog, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &RoleDialog::OnBnClickedButton1)
END_MESSAGE_MAP()


// RoleDialog 消息处理程序


void RoleDialog::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	ULONG_PTR _Stat = (ULONG_PTR)GetModuleHandleA("Torchlight2.exe");
	_Stat = *(ULONG_PTR*)(_Stat + 0x24E95F4);
	_Stat = *(ULONG_PTR*)(_Stat + 0x2C);

	HP = *(float*)(_Stat + 0x560);

	MP = *(float*)(_Stat + 0x584);

	Strength = *(ULONG_PTR*)(_Stat + 0x578);

	Dexterity = *(ULONG_PTR*)(_Stat + 0x574);

	Focus = *(ULONG_PTR*)(_Stat + 0x580);

	Vitality = *(ULONG_PTR*)(_Stat + 0x57C);

	Level = *(ULONG_PTR*)(_Stat + 0x110);

	Fame = *(ULONG_PTR*)(_Stat + 0x598);

	EXP = *(ULONG_PTR*)(_Stat + 0x594);

	Gold = *(ULONG_PTR*)(_Stat + 0x590);

	StatPoints = *(ULONG_PTR*)(_Stat + 0x5A8);

	SkillPoints = *(ULONG_PTR*)(_Stat + 0x5AC);

	Name = (const wchar_t*)(_Stat + 0x5F0);

	//ULONG_PTR Stat_ = (ULONG_PTR)GetModuleHandleA("TORCHLIGHT2.EXE");
	//Stat_ = *(ULONG_PTR*)(Stat_ + 0x33883F8);
	//Stat_ = *(ULONG_PTR*)(Stat_ + 0x9C);
	//Stat_ = *(ULONG_PTR*)(Stat_ + 0x10);
	//Stat_ = *(ULONG_PTR*)(Stat_ + 0xC);
	//Stat_ = *(ULONG_PTR*)(Stat_ + 0x8);
	//Stat_ = *(ULONG_PTR*)(Stat_ + 0x0);
	//Stat_ = *(ULONG_PTR*)(Stat_ + 0x400);
	//Name = (const wchar_t*)(Stat_ + 0x0);

	UpdateData(FALSE);
}
