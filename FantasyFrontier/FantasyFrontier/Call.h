#pragma once

HWND GetWindowHandle();
void CallEncryption(DWORD 秘钥, DWORD 加密长度, DWORD 加密地址, DWORD 加密地址2);
void SendPacket(DWORD 包长, DWORD 包地址);


void  Call_吃药封包(char* 药品名称);
void  Call_攻击技能封包(WORD 技能ID, DWORD 怪物ID);
void  Call_疾速空翻技能封包(WORD 技能ID);
void  Call_寻路(DWORD x, DWORD y);
void  Call_寻到(DWORD x, DWORD y);
void  Call_主线寻到(DWORD x, DWORD y);

DWORD Call_是否有该技能(char* 技能名);
DWORD Call_该技能是否冷却(char* 技能名);
void  Call_智能使用技能(DWORD 怪物ID);
DWORD Call_目的地是否可达(DWORD x, DWORD y);
DWORD Call_寻路是否成功();

void  Call_交接任务封包(char* 任务名称, DWORD 操作类型);
void  Call_打开NPC封包(char* NPC名称);
DWORD Call_返回任务状态(char* 任务名称);
void  Call_任务中间对话封包();



void  Call_保护线程();
void  Call_关闭保护线程();
void  Call_自动杀怪(char* 怪物名称);
void  Call_打怪线程(char*  str);
void  打怪线程(char* str);
void  Call_关闭打怪线程();

void  Call_主线线程();
void  Call_关闭主线线程();