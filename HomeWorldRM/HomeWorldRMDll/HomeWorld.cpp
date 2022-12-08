#include "pch.h"
#include "HomeWorld.h"

__declspec(naked) int HGodMode(ULONG_PTR Stat_)
{

	__asm {

		// Player check
		mov eax, [esi + 0x00095C]
		cmp dword ptr ds : [Stat_] , eax
		jne short lblShipHealthUpdaterSkip
		mov eax, dword ptr ds : [esi + 0x154]
		test eax, eax
		jz short lblShipHealthUpdaterSkip
		movss xmm0, dword ptr ds : [eax + 0x18]
		xorps xmm3, xmm3
		lblShipHealthUpdaterSkip :
		subss xmm0, xmm3
		movss dword ptr ds : [esi + 0x000164] , xmm0
	}

}
EXPORT extern "C" __declspec(dllexport)  void GodMode()
{
	ULONG_PTR _Stat = (ULONG_PTR)GetModuleHandleA("HomeworldRM.exe");
	_Stat = (ULONG_PTR)(_Stat + 0x0022AEEA);

	ULONG_PTR Stat_ = (ULONG_PTR)GetModuleHandleA("HomeworldRM.exe");
	Stat_ = (ULONG_PTR)(Stat_ + 0x005E4C8C);
	Stat_ = *(ULONG_PTR*)(Stat_ + 0x2C);

	DWORD Hook地址 = _Stat;
	DWORD Hook子程序指针 = (DWORD)HGodMode(Stat_);
	DWORD 跳转值 = Hook子程序指针 - Hook地址 - 5;

	DWORD old = 0;
	VirtualProtect((PVOID)_Stat, 100, PAGE_EXECUTE_READWRITE, &old);

	*(BYTE*)_Stat = 0xE8;
	*(DWORD*)(_Stat + 1) = 跳转值;
	*(BYTE*)(_Stat + 5) = 0x90;
	*(BYTE*)(_Stat + 6) = 0x90;
	*(BYTE*)(_Stat + 7) = 0x90;
	*(BYTE*)(_Stat + 8) = 0x90;
	*(BYTE*)(_Stat + 9) = 0x90;
	*(BYTE*)(_Stat + 0x0A) = 0x90;
	*(BYTE*)(_Stat + 0x0B) = 0x90;

	VirtualProtect((PVOID)_Stat, 100, old, &old);



}

EXPORT extern "C" __declspec(dllexport) void NormalMode() {

	ULONG_PTR _Stat = (ULONG_PTR)GetModuleHandleA("HomeworldRM.exe");
	_Stat = (ULONG_PTR)(_Stat + 0x0022AEEA);

	DWORD old = 0;
	VirtualProtect((PVOID)_Stat, 100, PAGE_EXECUTE_READWRITE, &old);

	*(BYTE*)_Stat = 0xF3;
	*(BYTE*)(_Stat + 1) = 0x0F;
	*(BYTE*)(_Stat + 2) = 0x5C;
	*(BYTE*)(_Stat + 3) = 0xC3;
	*(BYTE*)(_Stat + 4) = 0xF3;
	*(BYTE*)(_Stat + 5) = 0x0F;
	*(BYTE*)(_Stat + 6) = 0x11;
	*(BYTE*)(_Stat + 7) = 0x86;
	*(BYTE*)(_Stat + 8) = 0x64;
	*(BYTE*)(_Stat + 9) = 0x01;
	*(BYTE*)(_Stat + 0x0A) = 0x00;
	*(BYTE*)(_Stat + 0x0B) = 0x00;

	VirtualProtect((PVOID)_Stat, 100, old, &old);

}