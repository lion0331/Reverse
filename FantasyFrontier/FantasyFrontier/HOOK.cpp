#include "pch.h"
#include "HOOK.h"
#include "GeneralFunction.h"
#include "FantasyDialog.h"
#include "FantasyFrontier.h"
#include "framework.h"
#include "Call.h"
#include "Structure.h"

using namespace std;

HANDLE hProcess = 0;
DWORD pid = NULL;
byte* p = 0;
char s[0x2000];
char a[0x2000] = "";
DWORD g_���� = 0;
DWORD g_����ַ = 0;

DWORD g_old = 0;
__declspec(naked) void HookPlaintextPacketCall()
{
	__asm
	{
		pushad
		mov ecx, [esi + 4]
		mov eax, [esi + 8]
		mov g_����ַ, ecx
		sub eax, ecx
		mov g_����, eax
	}

	UpgradePermissions(TRUE);//����EXEȨ��
	GetWindowThreadProcessId(GetWindowHandle(), &pid);//��ý���ID
	hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);//�򿪽���

	p = new byte[g_����];
	ReadProcessMemory(hProcess, (LPCVOID)g_����ַ, p, g_����, 0);// p ����ֽڼ�
	*(WORD*)p = g_���� - 2;
	for (int i = 0; i < (int)g_����; i++)
	{
		sprintf_s(s, "%02X", p[i]);
		strcat_s(a, s);
	}
	OutputDebuggingInformation("��������     ����:%x   ������:%s\r\n", g_����, a);
	sprintf_s(a, "%s", "");
	delete[] p;

	__asm
	{
		popad
		mov     eax, dword ptr[esi + 8]
		sub     eax, ecx
		retn
	}
}

void HookPlaintextPacket()
{

	DWORD Hook��ַ = 0x00B92C82;
	DWORD Hook�ӳ���ָ�� = (DWORD)HookPlaintextPacketCall;
	DWORD ��תֵ = Hook�ӳ���ָ�� - Hook��ַ - 5;

	DWORD old = 0;
	VirtualProtect((PVOID)0x00B92C82, 100, PAGE_EXECUTE_READWRITE, &old);

	*(BYTE*)0x00B92C82 = 0xE8;
	*(DWORD*)(0x00B92C82 + 1) = ��תֵ;

	VirtualProtect((PVOID)0x00B92C82, 100, old, &old);

}

void RestorePlaintextPacket()
{

	DWORD old = 0;
	VirtualProtect((PVOID)0x00B92C82, 100, PAGE_EXECUTE_READWRITE, &old);

	*(BYTE*)0x00B92C82 = 0x8B;
	*(DWORD*)(0x00B92C82 + 1) = 0xC12B0846;

	VirtualProtect((PVOID)0x00B92C82, 100, old, &old);
}

void HOOKCALL()
{
	UpgradePermissions(TRUE);//����EXEȨ��
	GetWindowThreadProcessId(GetWindowHandle(), &pid);//��ý���ID
	hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);//�򿪽���
	p = new byte[g_����];
	ReadProcessMemory(hProcess, (LPCVOID)g_����ַ, p, g_����, 0);// p ����ֽڼ�
	for (int i = 0; i < (int)g_����; i++)
	{
		sprintf_s(s, "%02X", p[i]);
		strcat_s(a, s);
	}
	OutputDebuggingInformation("��������    �հ�   ����:%x   ������:%s\r\n", g_����, a);
	sprintf_s(a, "%s", "");
	delete[] p;
}


__declspec(naked) void HookPlaintextPacketReceivingCall()
{
	__asm
	{
		pushad
		mov edi, [edi]
		mov ecx, [edi + 4]
		mov g_����ַ, ecx
		mov eax, [edi + 8]
		sub eax, ecx
		mov g_����, eax
	}

	HOOKCALL();

	__asm
	{
		popad
		mov     ebp, dword ptr[esi + 0x2874]
		retn
	}
}

void HookPlaintextPacketReceiving()
{
                                      
	DWORD Hook��ַ = 0x00B92931;
	DWORD Hook�ӳ���ָ�� = (DWORD)HookPlaintextPacketReceivingCall;
	DWORD ��תֵ = Hook�ӳ���ָ�� - Hook��ַ - 5;

	DWORD old = 0;
	VirtualProtect((PVOID)0x00B92931, 100, PAGE_EXECUTE_READWRITE, &old);

	*(BYTE*)0x00B92931 = 0xE8;
	*(DWORD*)(0x00B92931 + 1) = ��תֵ;
	*(BYTE*)(0x00B92931 + 5) = 0x90;

	VirtualProtect((PVOID)0x00B92931, 100, old, &old);
}


void RestorePlaintextPacketReceiving()
{
	                                      
	DWORD old = 0;
	VirtualProtect((PVOID)0x00B92931, 100, PAGE_EXECUTE_READWRITE, &old);

	*(BYTE*)0x00B92931 = 0x8B;
	*(DWORD*)(0x00B92931 + 1) = 0x002874AE;
	*(BYTE*)(0x00B92931 + 5) = 0x00;

	VirtualProtect((PVOID)0x00B92931, 100, old, &old);
}



DWORD g_Ŀ�ĵ��Ƿ�ɴ�;
HHOOK g_Hook����;
const DWORD g_My��ϢID = RegisterWindowMessageA("MyMsyCode");
//���̻߳ص�����
LRESULT CALLBACK Call_���̻߳ص�����(int nCode, WPARAM wParam, LPARAM lparam)
{
	CWPSTRUCT* lpArg = (CWPSTRUCT*)lparam;//�ṹ  hwnd message wParam lParam
	if (nCode == HC_ACTION)//�Լ����̵���Ϣ
	{
		if (lpArg->hwnd == GetWindowHandle() && lpArg->message == g_My��ϢID)//�����Լ�����Ϣ  
		{
			switch (lpArg->wParam)
			{
				T�������* ���;
				TѰ·����* Ѱ·;
				TĿ�ĵ��Ƿ�ɴ�* Ŀ�ĵ�;
			case ID_���ͷ��:
				��� = (T�������*)lpArg->lParam;
				SendPacket(���->nd����, ���->p����ַ);
				return 1;
				break;
			case ID_Ѱ·:
				Ѱ· = (TѰ·����*)lpArg->lParam;
				Call_Ѱ·(Ѱ·->X, Ѱ·->Y);
				return 1;
				break;
			case ID_Ŀ�ĵ��Ƿ�ɴ�:
				Ŀ�ĵ� = (TĿ�ĵ��Ƿ�ɴ�*)lpArg->lParam;
				g_Ŀ�ĵ��Ƿ�ɴ� = Call_Ŀ�ĵ��Ƿ�ɴ�(Ŀ�ĵ�->X, Ŀ�ĵ�->Y);
				return 1;
				break;
			}
		}
	}
	return CallNextHookEx(g_Hook����, nCode, wParam, lparam);
}

DWORD Call_Hook���߳�()
{
	HWND hGame = GetWindowHandle();
	DWORD ndThreadId = GetWindowThreadProcessId(hGame, NULL);
	if (ndThreadId != 0)
	{
		g_Hook���� = SetWindowsHookEx(WH_CALLWNDPROC, Call_���̻߳ص�����, NULL, ndThreadId);
	}
	return 1;
}
//ж�����߳�
DWORD Call_ж��Hook���߳�()
{
	UnhookWindowsHookEx(g_Hook����);
	return 1;
}



void Msg_SendPacket(DWORD ����, DWORD ����ַ)
{
	T������� ���;
	���.nd���� = ����;
	���.p����ַ = ����ַ;
	::SendMessageA(GetWindowHandle(), g_My��ϢID, ID_���ͷ��, (LPARAM)&���);
}

void Msg_Ѱ·(DWORD X, DWORD Y)
{
	TѰ·���� Ѱ·;
	Ѱ·.X = X;
	Ѱ·.Y = Y;
	::SendMessageA(GetWindowHandle(), g_My��ϢID, ID_Ѱ·, (LPARAM)&Ѱ·);
}


DWORD Msg_Ŀ�ĵ��Ƿ�ɴ�(DWORD x, DWORD y)
{
	g_Ŀ�ĵ��Ƿ�ɴ� = 9999;
	TĿ�ĵ��Ƿ�ɴ� Ŀ�ĵ�;
	Ŀ�ĵ�.X = x;
	Ŀ�ĵ�.Y = y;
	::SendMessageA(GetWindowHandle(), g_My��ϢID, ID_Ŀ�ĵ��Ƿ�ɴ�, (LPARAM)&Ŀ�ĵ�);
	while (g_Ŀ�ĵ��Ƿ�ɴ� == 9999)
	{
		Sleep(10);
	}
	return g_Ŀ�ĵ��Ƿ�ɴ�;
}