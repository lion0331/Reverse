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
DWORD g_包长 = 0;
DWORD g_包地址 = 0;

DWORD g_old = 0;
__declspec(naked) void HookPlaintextPacketCall()
{
	__asm
	{
		pushad
		mov ecx, [esi + 4]
		mov eax, [esi + 8]
		mov g_包地址, ecx
		sub eax, ecx
		mov g_包长, eax
	}

	UpgradePermissions(TRUE);//提升EXE权限
	GetWindowThreadProcessId(GetWindowHandle(), &pid);//获得进程ID
	hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);//打开进程

	p = new byte[g_包长];
	ReadProcessMemory(hProcess, (LPCVOID)g_包地址, p, g_包长, 0);// p 封包字节集
	*(WORD*)p = g_包长 - 2;
	for (int i = 0; i < (int)g_包长; i++)
	{
		sprintf_s(s, "%02X", p[i]);
		strcat_s(a, s);
	}
	OutputDebuggingInformation("幻想神域     包长:%x   包内容:%s\r\n", g_包长, a);
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

	DWORD Hook地址 = 0x00B92C82;
	DWORD Hook子程序指针 = (DWORD)HookPlaintextPacketCall;
	DWORD 跳转值 = Hook子程序指针 - Hook地址 - 5;

	DWORD old = 0;
	VirtualProtect((PVOID)0x00B92C82, 100, PAGE_EXECUTE_READWRITE, &old);

	*(BYTE*)0x00B92C82 = 0xE8;
	*(DWORD*)(0x00B92C82 + 1) = 跳转值;

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
	UpgradePermissions(TRUE);//提升EXE权限
	GetWindowThreadProcessId(GetWindowHandle(), &pid);//获得进程ID
	hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);//打开进程
	p = new byte[g_包长];
	ReadProcessMemory(hProcess, (LPCVOID)g_包地址, p, g_包长, 0);// p 封包字节集
	for (int i = 0; i < (int)g_包长; i++)
	{
		sprintf_s(s, "%02X", p[i]);
		strcat_s(a, s);
	}
	OutputDebuggingInformation("幻想神域    收包   包长:%x   包内容:%s\r\n", g_包长, a);
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
		mov g_包地址, ecx
		mov eax, [edi + 8]
		sub eax, ecx
		mov g_包长, eax
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
                                      
	DWORD Hook地址 = 0x00B92931;
	DWORD Hook子程序指针 = (DWORD)HookPlaintextPacketReceivingCall;
	DWORD 跳转值 = Hook子程序指针 - Hook地址 - 5;

	DWORD old = 0;
	VirtualProtect((PVOID)0x00B92931, 100, PAGE_EXECUTE_READWRITE, &old);

	*(BYTE*)0x00B92931 = 0xE8;
	*(DWORD*)(0x00B92931 + 1) = 跳转值;
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



DWORD g_目的地是否可达;
HHOOK g_Hook返回;
const DWORD g_My消息ID = RegisterWindowMessageA("MyMsyCode");
//主线程回调函数
LRESULT CALLBACK Call_主线程回调函数(int nCode, WPARAM wParam, LPARAM lparam)
{
	CWPSTRUCT* lpArg = (CWPSTRUCT*)lparam;//结构  hwnd message wParam lParam
	if (nCode == HC_ACTION)//自己进程的消息
	{
		if (lpArg->hwnd == GetWindowHandle() && lpArg->message == g_My消息ID)//我们自己的消息  
		{
			switch (lpArg->wParam)
			{
				T封包参数* 封包;
				T寻路参数* 寻路;
				T目的地是否可达* 目的地;
			case ID_发送封包:
				封包 = (T封包参数*)lpArg->lParam;
				SendPacket(封包->nd包长, 封包->p包地址);
				return 1;
				break;
			case ID_寻路:
				寻路 = (T寻路参数*)lpArg->lParam;
				Call_寻路(寻路->X, 寻路->Y);
				return 1;
				break;
			case ID_目的地是否可达:
				目的地 = (T目的地是否可达*)lpArg->lParam;
				g_目的地是否可达 = Call_目的地是否可达(目的地->X, 目的地->Y);
				return 1;
				break;
			}
		}
	}
	return CallNextHookEx(g_Hook返回, nCode, wParam, lparam);
}

DWORD Call_Hook主线程()
{
	HWND hGame = GetWindowHandle();
	DWORD ndThreadId = GetWindowThreadProcessId(hGame, NULL);
	if (ndThreadId != 0)
	{
		g_Hook返回 = SetWindowsHookEx(WH_CALLWNDPROC, Call_主线程回调函数, NULL, ndThreadId);
	}
	return 1;
}
//卸载主线程
DWORD Call_卸载Hook主线程()
{
	UnhookWindowsHookEx(g_Hook返回);
	return 1;
}



void Msg_SendPacket(DWORD 包长, DWORD 包地址)
{
	T封包参数 封包;
	封包.nd包长 = 包长;
	封包.p包地址 = 包地址;
	::SendMessageA(GetWindowHandle(), g_My消息ID, ID_发送封包, (LPARAM)&封包);
}

void Msg_寻路(DWORD X, DWORD Y)
{
	T寻路参数 寻路;
	寻路.X = X;
	寻路.Y = Y;
	::SendMessageA(GetWindowHandle(), g_My消息ID, ID_寻路, (LPARAM)&寻路);
}


DWORD Msg_目的地是否可达(DWORD x, DWORD y)
{
	g_目的地是否可达 = 9999;
	T目的地是否可达 目的地;
	目的地.X = x;
	目的地.Y = y;
	::SendMessageA(GetWindowHandle(), g_My消息ID, ID_目的地是否可达, (LPARAM)&目的地);
	while (g_目的地是否可达 == 9999)
	{
		Sleep(10);
	}
	return g_目的地是否可达;
}