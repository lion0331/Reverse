#pragma once


void HookPlaintextPacket();
void RestorePlaintextPacket();
void HookPlaintextPacketReceiving();
void RestorePlaintextPacketReceiving();


DWORD Call_Hook���߳�();
DWORD Call_ж��Hook���߳�();
#define ID_���ͷ�� 0x0
#define ID_Ѱ· 0x1
#define ID_Ŀ�ĵ��Ƿ�ɴ� 0x2

struct T�������
{
	DWORD nd����;
	DWORD p����ַ;
};
struct TѰ·����
{
	DWORD X;
	DWORD Y;
};

struct TĿ�ĵ��Ƿ�ɴ�
{
	DWORD X;
	DWORD Y;
};

void Msg_SendPacket(DWORD ����, DWORD ����ַ);
void Msg_Ѱ·(DWORD X, DWORD Y);
DWORD Msg_Ŀ�ĵ��Ƿ�ɴ�(DWORD x, DWORD y);