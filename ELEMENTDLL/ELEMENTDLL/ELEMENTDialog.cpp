// ELEMENTDialog.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ELEMENTDLL.h"
#include "ELEMENTDialog.h"
#include "afxdialogex.h"
#include <stdio.h>
#include <vector>

using namespace std;
// ELEMENTDialog �Ի���

IMPLEMENT_DYNAMIC(ELEMENTDialog, CDialogEx)

ELEMENTDialog::ELEMENTDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(ELEMENTDialog::IDD, pParent)
{

}

ELEMENTDialog::~ELEMENTDialog()
{
}

void ELEMENTDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(ELEMENTDialog, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &ELEMENTDialog::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &ELEMENTDialog::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &ELEMENTDialog::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &ELEMENTDialog::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &ELEMENTDialog::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &ELEMENTDialog::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &ELEMENTDialog::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &ELEMENTDialog::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON9, &ELEMENTDialog::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON10, &ELEMENTDialog::OnBnClickedButton10)
	ON_BN_CLICKED(IDC_BUTTON11, &ELEMENTDialog::OnBnClickedButton11)
	ON_BN_CLICKED(IDC_BUTTON12, &ELEMENTDialog::OnBnClickedButton12)
	ON_BN_CLICKED(IDC_BUTTON13, &ELEMENTDialog::OnBnClickedButton13)
	ON_BN_CLICKED(IDC_BUTTON14, &ELEMENTDialog::OnBnClickedButton14)
	ON_BN_CLICKED(IDC_BUTTON15, &ELEMENTDialog::OnBnClickedButton15)
END_MESSAGE_MAP()


// ELEMENTDialog ��Ϣ�������


void ELEMENTDialog::OnBnClickedButton1()
{
	DWORD B = (DWORD)GetModuleHandleA("ELEMENTCLIENT.EXE");
	DWORD a = *(DWORD*)(B + 0x00911A6C);// [00D11A6C]     0xD11A6C =  0x00400000 +00911A6C =    ELEMENTCLIENT.EXE +00911A6C
	a = *(DWORD*)(a + 0x28);// [[00D11A6C]+28]
	a = *(DWORD*)(a + 0x288);//[[[00D11A6C]+28]+288]
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void ELEMENTDialog::OnBnClickedButton2()
{
	DWORD B = (DWORD)GetModuleHandleA("ELEMENTCLIENT.EXE");
	DWORD a = *(DWORD*)(B + 0x00911A6C);// [00D11A6C]
	a = *(DWORD*)(a + 0x28);// [[00D11A6C]+28]
	*(DWORD*)(a + 0x288) = 2000;
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void ELEMENTDialog::OnBnClickedButton3()
{
	__asm {
		push   1
		mov eax, 0x00D0DF1C
		mov eax, [eax]
		mov ecx, [eax + 0x1C]
		mov ecx, [ecx + 0x28]
		mov eax, 0x0047E7E0
		call eax
	}
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void ELEMENTDialog::OnBnClickedButton4()
{
	__asm {
		push 0		//edxҩ��λ��
		push 0
		mov eax, 0x004FACD0
		call eax
		mov ecx, eax
		mov eax, 0x00491C50
		call eax
	}
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void ELEMENTDialog::OnBnClickedButton5()
{

	DWORD item = (DWORD)malloc(4);
	if (item == NULL)
	{
		MessageBoxA(NULL, "�����ڴ�ռ�ʧ��", NULL, NULL);
		free((DWORD*)item);
	}
	else {
		*(DWORD*)item = 0x020E0011;//02 �·� 0E�·�λ��


		__asm {

			mov edx, 0x00D0DF1C
			mov edx, [edx]
			push 4
			push item
			mov ecx, [edx + 0x20]
			mov eax, 0x0067D4E0
			call eax
		}
		free((DWORD*)item);
	}
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}



void ELEMENTDialog::OnBnClickedButton6()
{


	DWORD A = (DWORD)GetModuleHandleA("ELEMENTCLIENT.EXE");
	A = *(DWORD*)(A + 0x009207AC);
	A = *(DWORD*)(A + 0x10);
	A = *(DWORD*)(A + 0x27C);
	A = *(DWORD*)(A + 0x0);//�����ĵ�ַ(�ǵ�ַ��ĵ�ַ)
	DWORD key = (DWORD)malloc(4);

	if (key == NULL)
	{
		MessageBoxA(NULL, "�����ڴ�ռ�ʧ��", NULL, NULL);
		free((DWORD*)key);
	}
	else {
		*(DWORD*)key = A;


		__asm {
			push 0x300001
			push 0x42
			push 0x100
			mov ecx, key
			mov ecx, [ecx]
			mov eax, 0x006296F0
			call eax
		}

		Sleep(500);

		__asm {
			push 0x300001
			push 0x62
			push 0x102
			mov ecx, key
			mov ecx, [ecx]
			mov eax, 0x006296F0
			call eax
		}

		free((DWORD*)key);
	}
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}



int G_DrinkMedicine;


void DrinkMedicine()
{
	while (G_DrinkMedicine == 1)
	{
		DWORD B = (DWORD)GetModuleHandleA("ELEMENTCLIENT.EXE");
		DWORD a = *(DWORD*)(B + 0x00911A6C);
		a = *(DWORD*)(a + 0x28);
		a = *(DWORD*)(a + 0x288);
		if (a <= 950)
		{
			__asm {
				push 0   //ҩƿλ��
				push 0
				mov eax, 0x004FACD0
				call eax
				mov ecx, eax
				mov eax, 0x00491C50
				call eax
			}
			Sleep(3000);
		}
		Sleep(50);
	}
}


void ELEMENTDialog::OnBnClickedButton7()
{
	G_DrinkMedicine = 1;
	CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)DrinkMedicine, NULL, NULL, NULL);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void ELEMENTDialog::OnBnClickedButton8()
{
	G_DrinkMedicine = 0;
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


int g_������;

__declspec(naked) void �����call()
{

	__asm
	{
		pushad
	}
	g_������ = 1;
	__asm
	{
		popad
		mov edi, [esp + 0x14]
		cmp edi, 0x19
		retn
	}
}

__declspec(naked) void �ڲ���call()
{

	__asm
	{
		pushad
	}
	g_������ = g_������ - 1;
	if (g_������ != 0)
	{
		MessageBoxA(0, "��⵽���", 0, 0);
	}
	__asm
	{
		popad
		mov eax, [esp + 0x20]
		mov ecx, ebx
		retn
	}
}





void ELEMENTDialog::OnBnClickedButton9()
{

	DWORD Hook��ַ = 0x00566580;
	DWORD Hook�ӳ���ָ�� = (DWORD)�����call;
	DWORD ��תֵ = Hook�ӳ���ָ�� - Hook��ַ - 5;


	DWORD old = 0;//���ԭ��������
	VirtualProtect((PVOID)0x00566580, 114, PAGE_EXECUTE_READWRITE, &old);
	//�޸��ڴ�
	*(BYTE*)0x00566580 = 0xE8;
	*(DWORD*)(0x00566580 + 1) = ��תֵ;
	*(BYTE*)(0x00566580 + 5) = 0x90;
	*(BYTE*)(0x00566580 + 6) = 0x90;

	VirtualProtect((PVOID)0x00566580, 114, old, &old);//�ָ�ҳ������



	Hook��ַ = 0x00491C68;
	Hook�ӳ���ָ�� = (DWORD)�ڲ���call;
	��תֵ = Hook�ӳ���ָ�� - Hook��ַ - 5;


	old = 0;//���ԭ��������
	VirtualProtect((PVOID)0x00491C68, 114, PAGE_EXECUTE_READWRITE, &old);
	//�޸��ڴ�
	*(BYTE*)0x00491C68 = 0xE8;
	*(DWORD*)(0x00491C68 + 1) = ��תֵ;
	*(BYTE*)(0x00491C68 + 5) = 0x90;

	VirtualProtect((PVOID)0x00491C68, 114, old, &old);//�ָ�ҳ������
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


int g_��ջ������;

__declspec(naked) void ��ջ���call()
{

	__asm
	{
		pushad
		mov eax, [esp + 0x4C]//  28+ 4��call ��+20(pushad) 
		mov g_��ջ������, eax
	}
	if (g_��ջ������ != 0x566737)
	{
		MessageBoxA(0, "��ջ��⵽���", 0, 0);
	}
	__asm
	{
		popad
		add ecx, 0x0E0
		retn
	}
}


void ELEMENTDialog::OnBnClickedButton10()
{


	DWORD Hook��ַ = 0x00491FFA;
	DWORD Hook�ӳ���ָ�� = (DWORD)��ջ���call;
	DWORD ��תֵ = Hook�ӳ���ָ�� - Hook��ַ - 5;


	DWORD old = 0;//���ԭ��������
	VirtualProtect((PVOID)0x00491FFA, 114, PAGE_EXECUTE_READWRITE, &old);
	//�޸��ڴ�
	*(BYTE*)0x00491FFA = 0xE8;
	*(DWORD*)(0x00491FFA + 1) = ��תֵ;
	*(BYTE*)(0x00491FFA + 5) = 0x90;

	VirtualProtect((PVOID)0x00491FFA, 114, old, &old);//�ָ�ҳ������

	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


int g_���ص�ַ;
//int g_gg = 0x00492115;

__declspec(naked) void �Ķ�ջcall()
{

	__asm
	{
		pushad
		mov eax, [esp + 0x3c]
		mov g_���ص�ַ, eax
		mov dword ptr[esp + 0x3c], 0x00566737
	}

	__asm
	{

		popad
		je equal1
		retn
		equal1 :
		mov edx, 0x00492115
		jmp  edx
		retn
	}
}


__declspec(naked) void �Ļض�ջcall()
{

	__asm
	{
		pushad
		mov eax, g_���ص�ַ
		mov[esp + 0x2C], eax
	}

	__asm
	{
		popad
		mov al, 1
		pop ebx
		add esp, 8
		mov edx, 0x0049200E
		jmp  edx
	}
}


void ELEMENTDialog::OnBnClickedButton11()
{

	DWORD Hook��ַ = 0x00491C62;
	DWORD Hook�ӳ���ָ�� = (DWORD)�Ķ�ջcall;
	DWORD ��תֵ = Hook�ӳ���ָ�� - Hook��ַ - 5;


	DWORD old = 0;//���ԭ��������
	VirtualProtect((PVOID)0x00491C62, 114, PAGE_EXECUTE_READWRITE, &old);
	//�޸��ڴ�
	*(BYTE*)0x00491C62 = 0xE8;
	*(DWORD*)(0x00491C62 + 1) = ��תֵ;
	*(BYTE*)(0x00491C62 + 5) = 0x90;

	VirtualProtect((PVOID)0x00491C62, 114, old, &old);//�ָ�ҳ������




	Hook��ַ = 0x00492008;
	Hook�ӳ���ָ�� = (DWORD)�Ļض�ջcall;
	��תֵ = Hook�ӳ���ָ�� - Hook��ַ - 5;


	old = 0;//���ԭ��������
	VirtualProtect((PVOID)0x00492008, 114, PAGE_EXECUTE_READWRITE, &old);
	//�޸��ڴ�
	*(BYTE*)0x00492008 = 0xE9;
	*(DWORD*)(0x00492008 + 1) = ��תֵ;
	*(BYTE*)(0x00492008 + 5) = 0x90;

	VirtualProtect((PVOID)0x00492008, 114, old, &old);//�ָ�ҳ������



	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void ELEMENTDialog::OnBnClickedButton12()
{
	__asm
	{

		sub esp, 0x2C
		mov dword ptr[esp + 0x28], 0x008E1B8E

		push 5
		push 0
		mov eax, 0x004FACD0
		call eax
		mov ecx, eax
		mov eax, 0x00491C50
		call eax

		add  esp, 0x2C

	}
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}




int Validate(int a, int b)
{
	int n = 0;
	for (int i = 0; i < b - a + 1; i++)
	{
		n = n + *(BYTE*)(a + i);

	}
	if (n == 0x25977CC9)
	{
		return 0;
	}

	return 1;
}



int g_CRC = 0;

void CRC()
{
	while (g_CRC == 1)
	{
		int a = 0x00401000;
		int b = 0x00A00000;
		int c = Validate(a, b);
		if (c == 1)
		{
			MessageBoxA(0, "���������ж�", 0, 0);
		}

		Sleep(10000);

	}

}



void ELEMENTDialog::OnBnClickedButton13()
{

	g_CRC = 1;
	CreateThread(0, 0, (LPTHREAD_START_ROUTINE)CRC, 0, 0, 0);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}



int g_���ݼ����Ʊ���;
int g_���ݼ�����;
int g_���Ѫ��ԭʼֵ;

void CJJC()
{

	g_���ݼ����� = g_���Ѫ��ԭʼֵ;

	while (g_���ݼ����Ʊ��� == 1)
	{
		if (g_���ݼ����� != g_���Ѫ��ԭʼֵ)// ���������ֵ�Ƿ��иı�
		{
			MessageBoxA(0, "�����쳣", 0, 0);
		}


		Sleep(10000);
	}
}




void AAAA()// ���������� ���ݵķ����Ƿ��ж�     ���������Ҫ���غ�  ���Է��ʵĺ�������10����
{
	Sleep(120000);

	while (g_���ݼ����Ʊ��� == 1)
	{

		DWORD a = (DWORD)GetModuleHandleA("ELEMENTCLIENT.EXE");
		a = *(DWORD*)(a + 0x00911A6C);
		a = *(DWORD*)(a + 0x28);
		a = *(DWORD*)(a + 0x2DC);
		if (g_���ݼ����� != a)
		{
			MessageBoxA(0, "�����쳣", 0, 0);
		}

		Sleep(120000);
	}
}




void JJJC()//�������Ѫ����g_���ݼ�����
{
	Sleep(1000);

	DWORD a = (DWORD)GetModuleHandleA("ELEMENTCLIENT.EXE");
	a = *(DWORD*)(a + 0x00911A6C);
	DWORD Temp;

	while (g_���ݼ����Ʊ��� == 1)
	{


		Temp = *(DWORD*)(a + 0x28);
		Temp = *(DWORD*)(Temp + 0x2DC);
		g_���ݼ����� = Temp;


		Sleep(1000);
	}
}





void ELEMENTDialog::OnBnClickedButton14()
{

	DWORD a = (DWORD)GetModuleHandleA("ELEMENTCLIENT.EXE");
	a = *(DWORD*)(a + 0x00911A6C);
	a = *(DWORD*)(a + 0x28);
	a = *(DWORD*)(a + 0x2DC);
	g_���Ѫ��ԭʼֵ = a;


	g_���ݼ����Ʊ��� = 1;
	CreateThread(0, 0, (LPTHREAD_START_ROUTINE)JJJC, 0, 0, 0);
	CreateThread(0, 0, (LPTHREAD_START_ROUTINE)CJJC, 0, 0, 0);
	CreateThread(0, 0, (LPTHREAD_START_ROUTINE)AAAA, 0, 0, 0);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}




void ELEMENTDialog::OnBnClickedButton15()
{


	// TODO: �ڴ���ӿؼ�֪ͨ����������
}

