#pragma once


void HookPlaintextPacket();
void RestorePlaintextPacket();
void HookPlaintextPacketReceiving();
void RestorePlaintextPacketReceiving();


DWORD Call_Hook主线程();
DWORD Call_卸载Hook主线程();
#define ID_发送封包 0x0
#define ID_寻路 0x1
#define ID_目的地是否可达 0x2

struct T封包参数
{
	DWORD nd包长;
	DWORD p包地址;
};
struct T寻路参数
{
	DWORD X;
	DWORD Y;
};

struct T目的地是否可达
{
	DWORD X;
	DWORD Y;
};

void Msg_SendPacket(DWORD 包长, DWORD 包地址);
void Msg_寻路(DWORD X, DWORD Y);
DWORD Msg_目的地是否可达(DWORD x, DWORD y);