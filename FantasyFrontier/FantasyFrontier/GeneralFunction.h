#pragma once

BYTE CharToByte(char ch1, char ch2);
BOOL UpgradePermissions(BOOL bEnable);//OpenProcess失败的情况调用
void OutputDebuggingInformation(char* pszFormat, ...);
void BIGTOGBK(char* szBuf);
//void GBTOGBK(char* szBuf);
//void GBKTOBIG5(char* szBuf);