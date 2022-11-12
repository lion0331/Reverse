// FantasyDialog.cpp: 实现文件
//

#include "pch.h"
#include "FantasyFrontier.h"
#include "afxdialogex.h"
#include "FantasyDialog.h"
#include <windows.h>
#include <iostream>
#include "Call.h"
#include "GeneralFunction.h"
#include "HOOK.h"
#include "Structure.h"
using namespace std;

// FantasyDialog 对话框

IMPLEMENT_DYNAMIC(FantasyDialog, CDialogEx)

FantasyDialog::FantasyDialog(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, m_Edit3(_T(""))
	, m_Edit4(_T(""))
	, m_Edit5(_T(""))
{

}

FantasyDialog::~FantasyDialog()
{
}

void FantasyDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_Edit1);
	DDX_Text(pDX, IDC_EDIT2, m_Edit2);
	DDX_Text(pDX, IDC_EDIT3, m_Edit3);
	DDX_Text(pDX, IDC_EDIT4, m_Edit4);
	DDX_Text(pDX, IDC_EDIT5, m_Edit5);
}


BEGIN_MESSAGE_MAP(FantasyDialog, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &FantasyDialog::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &FantasyDialog::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &FantasyDialog::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &FantasyDialog::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &FantasyDialog::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &FantasyDialog::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &FantasyDialog::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &FantasyDialog::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON9, &FantasyDialog::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON10, &FantasyDialog::OnBnClickedButton10)
	ON_BN_CLICKED(IDC_BUTTON11, &FantasyDialog::OnBnClickedButton11)
	ON_BN_CLICKED(IDC_BUTTON12, &FantasyDialog::OnBnClickedButton12)
	ON_BN_CLICKED(IDC_BUTTON13, &FantasyDialog::OnBnClickedButton13)
	ON_BN_CLICKED(IDC_BUTTON14, &FantasyDialog::OnBnClickedButton14)
	ON_BN_CLICKED(IDC_BUTTON15, &FantasyDialog::OnBnClickedButton15)
	ON_BN_CLICKED(IDC_BUTTON16, &FantasyDialog::OnBnClickedButton16)
	ON_BN_CLICKED(IDC_BUTTON17, &FantasyDialog::OnBnClickedButton17)
	ON_BN_CLICKED(IDC_BUTTON18, &FantasyDialog::OnBnClickedButton18)
	ON_BN_CLICKED(IDC_BUTTON19, &FantasyDialog::OnBnClickedButton19)
	ON_BN_CLICKED(IDC_BUTTON20, &FantasyDialog::OnBnClickedButton20)
	ON_BN_CLICKED(IDC_BUTTON21, &FantasyDialog::OnBnClickedButton21)
	ON_BN_CLICKED(IDC_BUTTON22, &FantasyDialog::OnBnClickedButton22)
	ON_BN_CLICKED(IDC_BUTTON23, &FantasyDialog::OnBnClickedButton23)
	ON_BN_CLICKED(IDC_BUTTON24, &FantasyDialog::OnBnClickedButton24)
END_MESSAGE_MAP()


// FantasyDialog 消息处理程序


void FantasyDialog::OnBnClickedButton1()
{
	HookPlaintextPacket();

	// TODO: 在此添加控件通知处理程序代码
}


void FantasyDialog::OnBnClickedButton2()
{

	RestorePlaintextPacket();

	// TODO: 在此添加控件通知处理程序代码
}



void FantasyDialog::OnBnClickedButton3()
{

	HookPlaintextPacketReceiving();
	// TODO: 在此添加控件通知处理程序代码
}


void FantasyDialog::OnBnClickedButton4()
{
	RestorePlaintextPacketReceiving();
	// TODO: 在此添加控件通知处理程序代码
}


void FantasyDialog::OnBnClickedButton5()
{
	UpdateData(TRUE);
	CString str1 = m_Edit1;
	CString str2 = m_Edit2;
	int 包长 = strtol((const char*)CW2A(str1.GetBuffer(0)), NULL, 16);
	string str = CW2A(str2.GetString());
	byte p[0x200];
	int len = str.size() / 2;
	for (int i = 0; i < len; i++)
	{
		p[i] = CharToByte(str[2 * i], str[2 * i + 1]);//2char 转btye
	}

	SendPacket(包长, (DWORD)p);
	// TODO: 在此添加控件通知处理程序代码
}




void FantasyDialog::OnBnClickedButton6()
{
	Call_Hook主线程();
	
	// TODO: 在此添加控件通知处理程序代码
}


void FantasyDialog::OnBnClickedButton7()
{
	Call_卸载Hook主线程();
	

	// TODO: 在此添加控件通知处理程序代码
}


void FantasyDialog::OnBnClickedButton8()
{
	T人物属性 a;
	a.c初始化();
	OutputDebuggingInformation("幻想神域       人物信息：   人物血量%d\\%d   人物坐标%f  %f  %f", a.d血量, a.d最大血量, a.fX, a.fY, a.fZ);
	
	// TODO: 在此添加控件通知处理程序代码
}


void FantasyDialog::OnBnClickedButton9()
{
	T取人物对象数组 List;
	List.c初始化();


	for (int i = 0; i < (int)List.d数量; i++)
	{
		OutputDebuggingInformation("幻想神域      %d", List.列表[i].d血量);
	}
	
	// TODO: 在此添加控件通知处理程序代码
}


void FantasyDialog::OnBnClickedButton10()
{
	T周围遍历 List;
	List.c初始化();


	for (int i = 0; i < (int)List.d数量; i++)
	{
		OutputDebuggingInformation("幻想神域    对象:%X  血量：%d/%d   坐标:%f  %f  %f  距离:%f    名称:%s", List.列表[i].d对象, List.列表[i].d血量, List.列表[i].d最大血量, \
			List.列表[i].fX, List.列表[i].fY, List.列表[i].fZ, List.列表[i].f距离, List.列表[i].pgbk名称);
	}
	
	// TODO: 在此添加控件通知处理程序代码
}


void FantasyDialog::OnBnClickedButton11()
{
	T周围遍历 List;
	T人物属性 A = List.c返回最近怪物();
	OutputDebuggingInformation("幻想神域     最近怪物:%s", A.pgbk名称);

	for (int i = 0; i < (int)List.d数量; i++)
	{
		OutputDebuggingInformation("幻想神域    对象:%X  血量：%d/%d   坐标:%f  %f  %f  距离:%f    名称:%s", List.列表[i].d对象, List.列表[i].d血量, List.列表[i].d最大血量, \
			List.列表[i].fX, List.列表[i].fY, List.列表[i].fZ, List.列表[i].f距离, List.列表[i].pgbk名称);
	}
	
	// TODO: 在此添加控件通知处理程序代码
}


void FantasyDialog::OnBnClickedButton12()
{
	T背包物品遍历 List;
	List.c初始化();
	for (int i = 0; i < (int)List.d数量; i++)
	{
		OutputDebuggingInformation("幻想神域    数量：%d/%d   物品ID：%X   在第几个背包：%d    背包中的位置：%d     %s", List.列表[i].w数量, List.列表[i].w最大数量, List.列表[i].dID\
			, List.列表[i].d所在背包, List.列表[i].d位置, List.列表[i].pgbk名称);
	}
	// TODO: 在此添加控件通知处理程序代码
}


void FantasyDialog::OnBnClickedButton13()
{
	Call_吃药封包("輕型HP藥水");
	
	// TODO: 在此添加控件通知处理程序代码
}


void FantasyDialog::OnBnClickedButton14()
{
	T技能冷却遍历 List;
	List.c初始化();
	for (int i = 0; i < (int)List.d数量; i++)
	{
		OutputDebuggingInformation("幻想神域    冷却技能ID：%X     %s", List.列表[i].dID, List.列表[i].pgbk名称);
	}
	// TODO: 在此添加控件通知处理程序代码
}


void FantasyDialog::OnBnClickedButton15()
{
	T已学技能遍历 List;
	List.c初始化();
	for (int i = 0; i < (int)List.d数量; i++)
	{
		OutputDebuggingInformation("幻想神域    冷却技能ID：%X    %s ", List.列表[i].dID, List.列表[i].pgbk名称);
	}
	// TODO: 在此添加控件通知处理程序代码
}


void FantasyDialog::OnBnClickedButton16()
{
	UpdateData(TRUE);
	CString str3 = m_Edit3;
	CString str4 = m_Edit4;
	DWORD X = strtol((const char*)(CW2A)str3.GetBuffer(0), NULL, 10);
	DWORD Y = strtol((const char*)(CW2A)str4.GetBuffer(0), NULL, 10);
	Msg_寻路(X, Y);
	
	// TODO: 在此添加控件通知处理程序代码
}


void FantasyDialog::OnBnClickedButton17()
{
	Call_保护线程();
	// TODO: 在此添加控件通知处理程序代码
}


void FantasyDialog::OnBnClickedButton18()
{
	Call_关闭保护线程();
	// TODO: 在此添加控件通知处理程序代码
}


void FantasyDialog::OnBnClickedButton19()
{
	UpdateData(TRUE);
	CString str5 = m_Edit5;
	CStringA str6(str5);
	char* str = str6.GetBuffer(0);
	OutputDebuggingInformation("幻想神域    怪物名称:%s\r\n", str);
	//GBTOGBK(str);
	//OutputDebuggingInformation("幻想神域    怪物名称:%s\r\n", str);
	//GBKTOBIG5(str);
	//OutputDebuggingInformation("幻想神域    怪物名称:%s\r\n", str);
	Call_打怪线程(str);
	
	// TODO: 在此添加控件通知处理程序代码
}


void FantasyDialog::OnBnClickedButton20()
{
	
	Call_关闭打怪线程();
	// TODO: 在此添加控件通知处理程序代码
}


void FantasyDialog::OnBnClickedButton21()
{
	T任务遍历 List;
	List.c初始化();
	T任务库遍历 List2;
	List2.c初始化();
	for (int i = 0; i < (int)List.d数量; i++)
	{
		for (int j = 0; j < (int)List2.d数量; j++)
		{

			if (List.列表[i].wID == List2.列表[j].wID)
			{
				List.列表[i].p名称 = List2.列表[j].p名称;
				strcpy_s(List.列表[i].pgbk名称, List.列表[i].p名称);
				BIGTOGBK(List.列表[i].pgbk名称);
				OutputDebuggingInformation("幻想神域    任务ID：%X    完成度：%d    %s", List.列表[i].wID, List.列表[i].w完成度, List.列表[i].pgbk名称);
				break;
			}
		}


	}
	// TODO: 在此添加控件通知处理程序代码
}


void FantasyDialog::OnBnClickedButton22()
{
	T任务库遍历 List;
	List.c初始化();
	for (int i = 0; i < (int)List.d数量; i++)
	{
		OutputDebuggingInformation("幻想神域    任务ID：%X    %s ", List.列表[i].wID, List.列表[i].pgbk名称);
	}
	// TODO: 在此添加控件通知处理程序代码
}


void FantasyDialog::OnBnClickedButton23()
{
	Call_主线线程();
	// TODO: 在此添加控件通知处理程序代码
}


void FantasyDialog::OnBnClickedButton24()
{
	Call_关闭主线线程();
	// TODO: 在此添加控件通知处理程序代码
}
