#pragma once

BYTE CharToByte(char ch1, char ch2);
BOOL UpgradePermissions(BOOL bEnable);//OpenProcessʧ�ܵ��������
void OutputDebuggingInformation(char* pszFormat, ...);
void BIGTOGBK(char* szBuf);
//void GBTOGBK(char* szBuf);
//void GBKTOBIG5(char* szBuf);