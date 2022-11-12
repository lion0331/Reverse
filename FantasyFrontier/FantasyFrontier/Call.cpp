#include "pch.h"
#include "Call.h"
#include "GeneralFunction.h"
#include "FantasyDialog.h"
#include "FantasyFrontier.h"
#include "framework.h"
#include "HOOK.h"
#include "Structure.h"

using namespace std;

HWND GetWindowHandle()
{
	HWND hGame;
	hGame = *(HWND*)0x00F7BFB0;
	return hGame;
}

__declspec(naked) void CallEncryption(DWORD 秘钥, DWORD 加密长度, DWORD 加密地址, DWORD 加密地址2)
{


	__asm
	{
		push    ebp
		push    ebx
		push    esi
		push    edi
		mov     edi, dword ptr[esp + 0x14]
		mov     edx, dword ptr[esp + 0x18]
		mov     esi, dword ptr[esp + 0x1C]
		mov     ebp, dword ptr[esp + 0x20]
		xor eax, eax
		xor ebx, ebx
		cmp     edx, 0
		je      Label1
		mov     al, byte ptr[edi]
		mov     bl, byte ptr[edi + 4]
		add     edi, 8
		lea     ecx, dword ptr[esi + edx]
		sub     ebp, esi
		mov     dword ptr[esp + 0x18], ecx
		inc     al
		cmp     dword ptr[edi + 0x100], -1
		je      Label2
		mov     ecx, dword ptr[edi + eax * 4]
		and edx, 0xFFFFFFFC
		je      Label3
		lea     edx, dword ptr[esi + edx - 4]
		mov     dword ptr[esp + 0x1C], edx
		mov     dword ptr[esp + 0x20], ebp
		Label4 :
		add     bl, cl
			mov     edx, dword ptr[edi + ebx * 4]
			mov     dword ptr[edi + ebx * 4], ecx
			mov     dword ptr[edi + eax * 4], edx
			add     edx, ecx
			inc     al
			and edx, 0x0FF
			mov     ecx, dword ptr[edi + eax * 4]
			mov     ebp, dword ptr[edi + edx * 4]
			add     bl, cl
			mov     edx, dword ptr[edi + ebx * 4]
			mov     dword ptr[edi + ebx * 4], ecx
			mov     dword ptr[edi + eax * 4], edx
			add     edx, ecx
			inc     al
			and edx, 0x0FF
			ror     ebp, 8
			mov     ecx, dword ptr[edi + eax * 4]
			or ebp, dword ptr[edi + edx * 4]
			add     bl, cl
			mov     edx, dword ptr[edi + ebx * 4]
			mov     dword ptr[edi + ebx * 4], ecx
			mov     dword ptr[edi + eax * 4], edx
			add     edx, ecx
			inc     al
			and edx, 0x0FF
			ror     ebp, 8
			mov     ecx, dword ptr[edi + eax * 4]
			or ebp, dword ptr[edi + edx * 4]
			add     bl, cl
			mov     edx, dword ptr[edi + ebx * 4]
			mov     dword ptr[edi + ebx * 4], ecx
			mov     dword ptr[edi + eax * 4], edx
			add     edx, ecx
			inc     al
			and edx, 0x0FF
			ror     ebp, 8
			mov     ecx, dword ptr[esp + 0x20]
			or ebp, dword ptr[edi + edx * 4]
			ror     ebp, 8
			xor ebp, dword ptr[esi]
			cmp     esi, dword ptr[esp + 0x1C]
			mov     dword ptr[ecx + esi], ebp
			lea     esi, dword ptr[esi + 4]
			mov     ecx, dword ptr[edi + eax * 4]
			jb      Label4
			cmp     esi, dword ptr[esp + 0x18]
			je      Label5
			mov     ebp, dword ptr[esp + 0x20]

			Label3:
		add     bl, cl
			mov     edx, dword ptr[edi + ebx * 4]
			mov     dword ptr[edi + ebx * 4], ecx
			mov     dword ptr[edi + eax * 4], edx
			add     edx, ecx
			inc     al
			and edx, 0x0FF
			mov     edx, dword ptr[edi + edx * 4]
			xor dl, byte ptr[esi]
			lea     esi, dword ptr[esi + 1]
			mov     ecx, dword ptr[edi + eax * 4]
			cmp     esi, dword ptr[esp + 0x18]
			mov     byte ptr[ebp + esi - 1], dl
			jb      Label3
			jmp     Label5

			Label2 :
		movzx   ecx, byte ptr[edi + eax]

			Label6 :
			add     bl, cl
			movzx   edx, byte ptr[edi + ebx]
			mov     byte ptr[edi + ebx], cl
			mov     byte ptr[edi + eax], dl
			add     dl, cl
			movzx   edx, byte ptr[edi + edx]
			add     al, 1
			xor dl, byte ptr[esi]
			lea     esi, dword ptr[esi + 1]
			movzx   ecx, byte ptr[edi + eax]
			cmp     esi, dword ptr[esp + 0x18]
			mov     byte ptr[ebp + esi - 1], dl
			jb      Label6
			Label5 :
		dec     al
			mov     byte ptr[edi - 4], bl
			mov     byte ptr[edi - 8], al

			Label1 :
		pop     edi
			pop     esi
			pop     ebx
			pop     ebp
			retn

	}

}

void  SendPacket(DWORD 包长, DWORD 包地址) 
{

	DWORD 加密地址 = 包地址 + 2;
	DWORD 加密长度 = 包长 - 2;
	DWORD 秘钥 = 0;
	__asm
	{
		mov ecx, 0x00f84ba4
		mov ecx, [ecx]
		mov ecx, [ecx]
		mov ecx, [ecx + 0x4]
		mov ecx, [ecx + 0x14]
		mov ecx, [ecx]
		lea ecx, [ecx + 0x54]
		mov 秘钥, ecx
	}

	CallEncryption(秘钥, 加密长度, 加密地址, 加密地址);


	HWND 窗口句柄 = FindWindowA("Lapis Network Class", 0);
	DWORD A = GetWindowLongW(窗口句柄, -21);
	DWORD S = *(DWORD*)(A + 0x38);

	send(S, (const char*)包地址, 包长, 0);
}


void  Call_吃药封包(char* 药品名称)
{

	//包长:16   包内容:1400  4F000000  0100 0400 000000000000000000000000    +6 的位置 WORD第几个包裹   +8的位置 WORD背包位置

	byte b[0x16] = { 0x14,00,0x4F,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00 };
	T背包物品遍历 List;
	List.c初始化();
	for (int i = 0; i < (int)List.d数量; i++)
	{
		if (strcmp(药品名称, List.列表[i].pgbk名称) == 0)
		{
			*(WORD*)(b + 6) = (WORD)List.列表[i].d所在背包;
			*(WORD*)(b + 8) = (WORD)List.列表[i].d位置;
			OutputDebuggingInformation("幻想神域   第几个包裹：%d   背包位置：%d\r\n", List.列表[i].d所在背包, List.列表[i].d位置);
			Msg_SendPacket(0x16, (DWORD)b);
			break;
		}
	}

}






void  Call_攻击技能封包(WORD 技能ID, DWORD 怪物ID)
{
	//包长:c   包内容:0A00  5500    5ACA      1FEEFEFF    0000      +4 WORD 技能ID       +6 DWORD 怪物ID

	byte b[0xC] = { 0x0A,00,0x55,00,00,00,00,00,00,00,00,00 };

	*(WORD*)(b + 4) = 技能ID;
	*(DWORD*)(b + 6) = 怪物ID;
	Msg_SendPacket(0xC, (DWORD)b);

	//包长:6   包内容:040043000000 
	byte bb[0x6] = { 0x04,00,0x43,00,00,00 };
	Msg_SendPacket(0x6, (DWORD)bb);
}


void  Call_疾速空翻技能封包(WORD 技能ID)
{
	//包长:10   包内容:0E00 4E00  61CA  5BA0A543  D3BCD643 0000 

	T人物属性 a;
	a.c初始化();
	byte b[0x10] = { 0x0E,00,0x4E,00 };

	*(WORD*)(b + 4) = 技能ID;
	*(FLOAT*)(b + 6) = a.fX;
	*(FLOAT*)(b + 0xA) = a.fY;
	Msg_SendPacket(0x10, (DWORD)b);

}


void  Call_寻路(DWORD x, DWORD y)
{

	byte b[0x10] = { 0 };
	*(FLOAT*)b = (FLOAT)x;
	*(FLOAT*)(b + 4) = (FLOAT)y;
	*(DWORD*)(b + 8) = x;
	*(DWORD*)(b + 0xC) = y;
	DWORD A = (DWORD)b;
	OutputDebuggingInformation("幻想神域   寻路到： %d   %d\r\n", x, y);
	__asm
	{
		pushad
		push 1
		push 0
		push 0
		push A
		mov ecx, 0x0F84B74
		mov ecx, [ecx]
		mov eax, 0x006D8340
		call eax
		mov ecx, eax
		mov edx, [eax + 0xC]
		mov edx, [edx + 0x3A4]
		push edx
		mov eax, 0x006F0D60
		call eax
		popad
	}

}


void  Call_寻到(DWORD x, DWORD y)// 用于寻往怪物
{
	int i = 0;
	T人物属性 人物;
	人物.c初始化();
	DWORD 人物对象 = 人物.d对象;
	FLOAT 距离;
	do
	{
		Msg_寻路(x, y);
		Sleep(300);
		DWORD Temp = *(DWORD*)(人物对象 + 0x10);
		FLOAT X = *(FLOAT*)(Temp + 0x154);
		FLOAT Y = *(FLOAT*)(Temp + 0x158);

		距离 = sqrt((X - x) * (X - x) + (Y - y) * (Y - y));
		i++;
		if (i > 15)
		{
			break;// 如果5秒没有达到地点跳出函数  防止卡点
		}
	} while (距离 > 5);

}

void  Call_主线寻到(DWORD x, DWORD y)
{

	T人物属性 人物;
	人物.c初始化();
	DWORD 人物对象 = 人物.d对象;
	FLOAT 距离;
	do
	{
		Msg_寻路(x, y);
		Sleep(2000);
		DWORD Temp = *(DWORD*)(人物对象 + 0x10);
		FLOAT X = *(FLOAT*)(Temp + 0x154);
		FLOAT Y = *(FLOAT*)(Temp + 0x158);

		距离 = sqrt((X - x) * (X - x) + (Y - y) * (Y - y));

	} while (距离 > 5);

}

DWORD Call_是否有该技能(char* 技能名)
{
	T已学技能遍历 List;
	List.c初始化();
	for (int i = 0; i < (int)List.d数量; i++)
	{

		if (strcmp(List.列表[i].pgbk名称, 技能名) == 0)
		{
			return 1;
		}
	}
	return 0;

}

DWORD Call_该技能是否冷却(char* 技能名)
{
	T技能冷却遍历 List;
	List.c初始化();
	for (int i = 0; i < (int)List.d数量; i++)
	{

		if (strcmp(List.列表[i].pgbk名称, 技能名) == 0)
		{
			return 0;
		}
	}
	return 1;

}

void  Call_智能使用技能(DWORD 怪物ID)///职业是双刀刺客技能
{

	//优先级   旋舞閃  後搖公共CD1秒  散華雪 0.7  十字斬 1.2   斬切 1.5  疾速空翻 0.5展示未用
	if (Call_是否有该技能("旋舞閃") && Call_该技能是否冷却("旋舞閃"))
	{
		Call_攻击技能封包(0xCA5D, 怪物ID);
		Sleep(1000);
	}
	else if (Call_是否有该技能("散華雪") && Call_该技能是否冷却("散華雪"))
	{
		Call_攻击技能封包(0xCA5B, 怪物ID);
		Sleep(700);
	}
	else if (Call_是否有该技能("十字斬") && Call_该技能是否冷却("十字斬"))
	{
		Call_攻击技能封包(0xCA5A, 怪物ID);
		Sleep(1200);
	}
	else if (Call_是否有该技能("斬切") && Call_该技能是否冷却("斬切"))
	{
		Call_攻击技能封包(0xCA59, 怪物ID);
		Sleep(1500);
	}

}

DWORD Call_目的地是否可达(DWORD x, DWORD y)
{
	__try
	{

		T人物属性 a;
		a.c初始化();
		DWORD 人物对象 = a.d对象;
		DWORD Temp = *(DWORD*)(人物对象 + 0x2c);
		Temp = Temp + 0x118;
		DWORD old = 0;
		VirtualProtect((PVOID)Temp, 1000, PAGE_EXECUTE_READWRITE, &old);
		*(FLOAT*)(Temp + 0x10) = (FLOAT)x;
		*(FLOAT*)(Temp + 0x14) = (FLOAT)y;
		VirtualProtect((PVOID)Temp, 1000, old, &old);
		OutputDebuggingInformation("幻想神域   目的地是否可达结构体地址:%X\r\n", Temp);
		__asm
		{
			mov ecx, Temp
			mov eax, 0x0077D8B0
			call eax
		}
		DWORD R = *(WORD*)(Temp + 0x64);
		OutputDebuggingInformation("幻想神域    判断目的地%d   %d  返回%d\r\n", x, y, R);
		return R;

	}
	__except (1)
	{
		OutputDebuggingInformation("幻想神域   判断目的地是否可达异常\r\n");
		return 0;
	}
}


DWORD Call_寻路是否成功()
{
	T人物属性 a;
	a.c初始化();
	DWORD Temp = *(DWORD*)(a.d对象 + 0x2c);
	DWORD A = *(DWORD*)(Temp + 0x118 + 0x1C);
	return A;

}


void  Call_交接任务封包(char* 任务名称, DWORD 操作类型)
{

	//0A00    1D00   0100    ED030000    FFFF 
	//长度      包头   操作方式    任务ID       暂时固定

	DWORD 任务ID = 0;
	byte b[0xC] = { 0x0A,00,0x1D,00,00,00,00,00,00,00,0xFF,0xFF };


	T任务库遍历 List;
	List.c初始化();
	for (int i = 0; i < (int)List.d数量; i++)
	{
		if (strcmp(任务名称, List.列表[i].pgbk名称) == 0)
		{
			任务ID = List.列表[i].wID;
			break;
		}
	}


	*(WORD*)(b + 4) = (WORD)操作类型;
	*(DWORD*)(b + 6) = 任务ID;
	Msg_SendPacket(0xC, (DWORD)b);

}



void  Call_打开NPC封包(char* NPC名称)
{

	//0600      5800     E1FEFFFF
	//                    NPCID
	//0600        0300     E1FEFFFF

	DWORD NPCID = 0;
	byte b[0x8] = { 0x06,00,0x58,00,00,00,00,00 };
	byte bb[0x8] = { 0x06,00,0x03,00,00,00,00,00 };

	T周围遍历 a;
	a.c初始化();
	for (int i = 0; i < (int)a.d数量; i++)
	{

		if (strcmp(NPC名称, a.列表[i].pgbk名称) == 0)
		{
			NPCID = a.列表[i].dID;
			break;
		}
	}



	*(DWORD*)(b + 4) = NPCID;
	*(DWORD*)(bb + 4) = NPCID;

	Msg_SendPacket(0x8, (DWORD)b);
	Msg_SendPacket(0x8, (DWORD)bb);

}


DWORD Call_返回任务状态(char* 任务名称)
{
	T任务遍历 List;
	List.c初始化();
	T任务库遍历 List2;
	List2.c初始化();
	for (int i = 0; i < (int)List.d数量; i++)
	{
		for (int j = 0; j < (int)List2.d数量; j++)
		{

			if (List.列表[i].wID == List2.列表[j].wID)
			{
				List.列表[i].p名称 = List2.列表[j].p名称;
				strcpy_s(List.列表[i].pgbk名称, List.列表[i].p名称);
				BIGTOGBK(List.列表[i].pgbk名称);
				break;
			}
		}
	}


	for (int i = 0; i < (int)List.d数量; i++)
	{
		if (strcmp(任务名称, List.列表[i].pgbk名称) == 0)
		{
			return List.列表[i].w完成度;
		}
	}

	return 99;


}

void  Call_任务中间对话封包()
{

	//包长:6   包内容:040057000100
	byte b[0x6] = { 0x04,00,0x57,00,01,00 };
	Msg_SendPacket(0x6, (DWORD)b);

}



DWORD g_保护线程 = 0;
void 保护线程()
{
	T人物属性 a;
	while (g_保护线程)
	{
		a.c初始化();
		if (a.d血量 < a.d最大血量 * 0.8)
		{
			Call_吃药封包("輕型HP藥水");
			Sleep(5700);
		}

		Sleep(300);
	}

}

void  Call_保护线程()
{
	g_保护线程 = 1;
	::CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)保护线程, NULL, NULL, NULL);
}

void  Call_关闭保护线程()
{
	g_保护线程 = 0;
}









void  Call_自动杀怪(char* 怪物名称)
{


	DWORD 怪物对象;
	T周围遍历 List;
	List.c初始化();//怪物初始化
	List.c返回最近怪物();// 让怪物重新排列
	for (int i = List.d数量 - 1; i > 0; i--)// 从距离最近的开始寻找
	{
		if (strcmp(怪物名称, List.列表[i].pgbk名称) == 0)// 符号条件的怪物
		{
			if (List.列表[i].d血量 == List.列表[i].d最大血量)// 活着且不是别人攻击过的怪物
			{
				OutputDebuggingInformation("幻想神域   找到怪物   i=%d\r\n", i);


				Msg_寻路((int)List.列表[i].fX, (int)List.列表[i].fY);
				Sleep(100);
				if (Call_寻路是否成功() != 0)
				{
					OutputDebuggingInformation("幻想神域   寻往怪物\r\n");
					Call_寻到((int)List.列表[i].fX, (int)List.列表[i].fY);//寻到怪物
				}
				else
				{
					OutputDebuggingInformation("幻想神域   继续下次找怪\r\n");
					continue;
				}


				怪物对象 = List.列表[i].d对象;
				while (List.列表[i].d血量 != 0)//循环攻击怪物
				{
					OutputDebuggingInformation("幻想神域   循环杀怪\r\n");
					DWORD Temp = *(DWORD*)(怪物对象 + 0x10);
					FLOAT X = *(FLOAT*)(Temp + 0x154);
					FLOAT Y = *(FLOAT*)(Temp + 0x158);

					Msg_寻路((int)X, (int)Y);
					Sleep(100);
					if (Call_寻路是否成功() != 0)//要防止进距离不可寻路
					{
						Call_寻到((int)X, (int)Y);//寻到怪物
					}
					else
					{
						OutputDebuggingInformation("幻想神域   正在攻击怪物不可寻路\r\n");
						break;
					}
					// 判断怪物血量
					Temp = *(DWORD*)(怪物对象 + 0xC);
					List.列表[i].d血量 = *(DWORD*)(Temp + 0x8);//继续判定怪物血量
					if (List.列表[i].d血量 != 0)
					{
						Call_智能使用技能(List.列表[i].dID);//智能选择攻击方式
					}
					Temp = *(DWORD*)(怪物对象 + 0xC);
					List.列表[i].d血量 = *(DWORD*)(Temp + 0x8);//继续判定怪物血量

				}
				break;
			}
		}
	}


}



DWORD g_打怪线程 = 0;
void  Call_打怪线程(char* str)
{
	g_打怪线程 = 1;	
	OutputDebuggingInformation("幻想神域    怪物名称:%s\r\n", str);
	Sleep(300);
	size_t len = strlen(str) + 1;
	char* copy = new char[len];
	strcpy_s(copy, len, str);
	::CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)打怪线程, copy, NULL, NULL);


}

void  打怪线程( char* str)
{

	OutputDebuggingInformation("幻想神域    怪物名称:%s\r\n", str);
	while (g_打怪线程)
	{

		Call_自动杀怪(str);
		Sleep(300);
	}
}


void  Call_关闭打怪线程()
{
	g_打怪线程 = 0;
}


DWORD g_主线线程 = 0;
void 主线线程()
{

	while (g_主线线程)
	{

		if (Call_返回任务状态("Lv1.噩夢的後遺症") == 1 && Call_返回任务状态("Lv1.送貨") != 1)//Lv1.送貨
		{
			do
			{
				Call_主线寻到(531, 339);
				Sleep(100);
				Call_打开NPC封包("村長夫人\n絲卡蒂");
				Sleep(100);
				Call_交接任务封包("Lv1.送貨", 1);
				Sleep(100);
			} while (Call_返回任务状态("Lv1.送貨") != 3);


			do
			{
				Call_主线寻到(493, 313);
				Sleep(100);
				Call_打开NPC封包("雜貨舖老闆\n安妮塔");
				Sleep(100);
				Call_任务中间对话封包();
				Sleep(100);
				Call_主线寻到(503, 280);
				Sleep(100);
				Call_打开NPC封包("防具屋老闆\n貝琪");
				Sleep(100);
				Call_任务中间对话封包();
				Sleep(100);
				Call_主线寻到(526, 277);
				Sleep(100);
				Call_打开NPC封包("武器店老闆\n柯倫");
				Sleep(100);
				Call_任务中间对话封包();
				Sleep(100);
			} while (Call_返回任务状态("Lv1.送貨") != 4);

			do
			{
				Call_主线寻到(531, 339);
				Sleep(100);
				Call_打开NPC封包("村長夫人\n絲卡蒂");
				Sleep(100);
				Call_交接任务封包("Lv1.送貨", 2);
				Sleep(100);

			} while (Call_返回任务状态("Lv1.送貨") != 1);
		}

		if (Call_返回任务状态("Lv1.送貨") == 1 && Call_返回任务状态("Lv2.愛心便當") != 1)//Lv2.愛心便當
		{
			do
			{
				Call_主线寻到(531, 339);
				Sleep(100);
				Call_打开NPC封包("村長夫人\n絲卡蒂");
				Sleep(100);
				Call_交接任务封包("Lv2.愛心便當", 1);
				Sleep(100);
			} while (Call_返回任务状态("Lv2.愛心便當") != 4);

			do
			{
				Call_主线寻到(553, 230);
				Sleep(100);
				Call_打开NPC封包("村長\n約克");
				Sleep(100);
				Call_交接任务封包("Lv2.愛心便當", 2);
				Sleep(100);

			} while (Call_返回任务状态("Lv2.愛心便當") != 1);

		}


		if (Call_返回任务状态("Lv2.愛心便當") == 1 && Call_返回任务状态("Lv2.正式工作") != 1)//Lv2.正式工作

		{
			do
			{
				Call_主线寻到(553, 230);
				Sleep(100);
				Call_打开NPC封包("村長\n約克");
				Sleep(100);
				Call_交接任务封包("Lv2.正式工作", 1);
				Sleep(100);
			} while (Call_返回任务状态("Lv2.正式工作") != 4);

			do
			{
				Call_主线寻到(291, 299);
				Sleep(100);
				Call_打开NPC封包("工頭\n肯恩");
				Sleep(100);
				Call_交接任务封包("Lv2.正式工作", 2);
				Sleep(100);

			} while (Call_返回任务状态("Lv2.正式工作") != 1);

		}


		if (Call_返回任务状态("Lv2.正式工作") == 1 && Call_返回任务状态("Lv3.良好的工作環境") != 1)//Lv3.良好的工作環境


		{
			do
			{
				Call_主线寻到(291, 299);
				Sleep(100);
				Call_打开NPC封包("工頭\n肯恩");
				Sleep(100);
				Call_交接任务封包("Lv3.良好的工作環境", 1);
				Sleep(100);
			} while (Call_返回任务状态("Lv3.良好的工作環境") != 3);


			do
			{
				Call_主线寻到(354, 317);
				Sleep(100);
				for (int i = 0; i < 4; i++)
				{
					Call_自动杀怪("跳跳兔");
				}
				Call_主线寻到(330, 254);
				Sleep(100);
				for (int i = 0; i < 3; i++)
				{
					Call_自动杀怪("搗蛋跳跳兔");
				}
				Sleep(100);
			} while (Call_返回任务状态("Lv3.良好的工作環境") != 4);


			do
			{
				Call_主线寻到(291, 299);
				Sleep(100);
				Call_打开NPC封包("工頭\n肯恩");
				Sleep(100);
				Call_交接任务封包("Lv3.良好的工作環境", 2);
				Sleep(100);

			} while (Call_返回任务状态("Lv3.良好的工作環境") != 1);

		}




		Sleep(300);
	}

}




void  Call_主线线程()
{
	g_主线线程 = 1;
	::CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)主线线程, NULL, NULL, NULL);
}

void  Call_关闭主线线程()
{
	g_主线线程 = 0;
}
