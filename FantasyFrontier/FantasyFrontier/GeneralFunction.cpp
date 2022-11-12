#include "pch.h"
#include "GeneralFunction.h"
#include "FantasyDialog.h"
#include "FantasyFrontier.h"
#include "framework.h"
#include "Call.h"
#include "HOOK.h"
#include "Structure.h"

using namespace std;

BYTE CharToByte(char ch1, char ch2)
{
	int S{};
	if ((ch1 >= 48) && (ch1 <= 57))
	{
		S = ch1 - 48;
	}
	else if ((ch1 >= 65) && (ch1 <= 70))
	{
		S = ch1 - 65 + 10;
	}

	if ((ch2 >= 48) && (ch2 <= 57))
	{
		return S * 16 + ch2 - 48;
	}
	else if ((ch2 >= 65) && (ch2 <= 70))
	{
		return S * 16 + ch2 - 65 + 10;
	}
	else
	{
		return -1;
	}
}


BOOL UpgradePermissions(BOOL bEnable) //OpenProcess失败的情况调用
{
	BOOL fOK = FALSE;
	HANDLE hToken;
	if (OpenProcessToken(GetCurrentProcess(), TOKEN_ADJUST_PRIVILEGES, &hToken)) //打开进程访问令牌
	{
		TOKEN_PRIVILEGES tp{};
		tp.PrivilegeCount = 1;
		LookupPrivilegeValue(NULL, SE_DEBUG_NAME, &tp.Privileges[0].Luid);
		tp.Privileges[0].Attributes = bEnable ? SE_PRIVILEGE_ENABLED : 0;
		AdjustTokenPrivileges(hToken, FALSE, &tp, sizeof(tp), NULL, NULL);
		fOK = (GetLastError() == ERROR_SUCCESS);
		CloseHandle(hToken);
	}
	return fOK;
}

void OutputDebuggingInformation(char* pszFormat, ...)
{
#ifdef _DEBUG

	char szbufFormat[0x1000];
	char szbufFormat_Game[0x1100] = "";
	va_list argList;
	va_start(argList, pszFormat);//参数列表初始化
	vsprintf_s(szbufFormat, pszFormat, argList);
	strcat_s(szbufFormat_Game, szbufFormat);
	OutputDebugStringA(szbufFormat_Game);
	va_end(argList);

#endif

}

void BIGTOGBK(char* szBuf)
{
	if (!strcmp(szBuf, ""))
		return;
	int nStrLen = strlen(szBuf);
	wchar_t* pws = new wchar_t[nStrLen + 1];
	__try
	{   //CP_UTF8
		//CP_UTF8;
		//计算字符串长度
		int nReturn = MultiByteToWideChar(950, 0, szBuf, nStrLen, pws, nStrLen + 1);
		BOOL bValue = false;
		nReturn = WideCharToMultiByte(936, 0, pws, nReturn, szBuf, nStrLen + 1, "?", &bValue);
		szBuf[nReturn] = 0;
	}
	__except (1)
	{
		delete[] pws;
	}
}

//void GBTOGBK(char* szBuf)
//{
//	if (!strcmp(szBuf, ""))
//		return;
//	int nStrLen = strlen(szBuf);
//	WORD wLCID = MAKELCID(MAKELANGID(LANG_CHINESE, SUBLANG_CHINESE_SIMPLIFIED), SORT_CHINESE_PRC);
//	int nReturn = LCMapString(wLCID, LCMAP_TRADITIONAL_CHINESE, (LPCWSTR)szBuf, nStrLen, NULL, 0);
//	if (!nReturn)
//		return;
//	char* pcBuf = new char[nReturn + 1];
//	__try
//	{
//		wLCID = MAKELCID(MAKELANGID(LANG_CHINESE, SUBLANG_CHINESE_SIMPLIFIED), SORT_CHINESE_PRC);
//		LCMapString(wLCID, LCMAP_TRADITIONAL_CHINESE, (LPCWSTR)szBuf, nReturn, (LPWSTR)pcBuf, nReturn + 1);
//		strncpy(szBuf, pcBuf, nReturn);
//	}
//	__except (1)
//	{
//		delete[] pcBuf;
//	}
//}
//
//void GBKTOBIG5(char* szBuf)
//{
//	if (!strcmp(szBuf, ""))
//		return;
//	int nStrLen = strlen(szBuf);
//	wchar_t* pws = new wchar_t[nStrLen + 1];
//	__try
//	{
//		MultiByteToWideChar(936, 0, szBuf, nStrLen, pws, nStrLen + 1);
//		BOOL bValue = false;
//		WideCharToMultiByte(950, 0, pws, nStrLen, szBuf, nStrLen + 1, "?", &bValue);
//		szBuf[nStrLen] = 0;
//	}
//	__except (1)
//	{
//		delete[] pws;
//	}
//}