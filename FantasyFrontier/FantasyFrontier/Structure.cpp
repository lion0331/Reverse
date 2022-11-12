#include "pch.h"
#include "Structure.h"
#include "FantasyFrontier.h"
#include "FantasyDialog.h"
#include "framework.h"
#include "Call.h"
#include "GeneralFunction.h"
#include "Hook.h"
using namespace std;

//对象+8 ID
//[对象+C]+8 血量
//[对象+C]+10 当前等级
//[对象+C]+18 移动速度
//[对象+C]+24 最大血量
//[对象+C]+30 暴击伤害
//[对象+C]+34 命中率
//[对象+C]+38 治疗比例
//[对象+C]+68 经验
//[对象+C]+27C 剩余攻击点数
//[对象+C]+280 剩余防御点数
//[对象+10]+154 X
//[对象+10]+158 Y
//[对象+10]+15C Z

//人物ID [[0F84B74]+40C] 经过加密 获得数组下标EBX
//ebx = （([[0F84B74]+40C]*41 + [[0F84B74]+40C]/4 +9E3779B9) and [[0F84B74]+410+20]）*2
//然后到数组中取得对象 [[[[[0F84B74]+410+14]+ebx*8+4]+C]+C]+8
//[0F84B74]+410+14开始的指针
//[0F84B74]+410+18结束的指针

//mov     ecx, dword ptr [F84B74]
//mov     eax, dword ptr [ecx+40C]
//push eax
//add ecx,410
//call 00665870
//mov eax,[eax+0C]
//mov eax,[eax+8]
//mov ecx,12345678
//mov [ecx],eax
void T人物属性::c初始化()
{
	__try
	{
		DWORD 人物对象 = 0;
		__asm
		{
			mov     ecx, 0x0F84B74
			mov     ecx, [ecx]
			mov     eax, dword ptr[ecx + 0x40C]
			push eax
			add ecx, 0x410
			mov eax, 0x00665870
			call eax
			mov 人物对象, eax
		}
		d对象 = 人物对象;
		dID = *(DWORD*)(人物对象 + 0x8);// 用 [[0x0F84B74]+40C]也可以
		DWORD Temp = *(DWORD*)(人物对象 + 0xC);
		d血量 = *(DWORD*)(Temp + 0x8);
		d最大血量 = *(DWORD*)(Temp + 0x24);
		Temp = *(DWORD*)(人物对象 + 0x10);
		fX = *(FLOAT*)(Temp + 0x154);
		fY = *(FLOAT*)(Temp + 0x158);
		fZ = *(FLOAT*)(Temp + 0x15C);
		f距离 = 0;

	}
	__except (1)
	{
		OutputDebuggingInformation("幻想神域   读取人物信息异常\r\n");
	}
}



//然后到数组中取得对象 [[[[[0F84B74]+410+14]+ebx*8+4]+C]+C]+8
//[0F84B74]+410+14开始的指针
//[0F84B74]+410+18结束的指针


void T取人物对象数组::c初始化()
{

	__try
	{
		DWORD a = 0;
		DWORD Temp = *(DWORD*)0x0F84B74;
		DWORD 数组开始地址 = *(DWORD*)(Temp + 0x410 + 0x14);
		DWORD 数组结束地址 = *(DWORD*)(Temp + 0x410 + 0x18);
		d数量 = (数组结束地址 - 数组开始地址) / 8;
		for (int i = 0; i < (int)d数量; i++)
		{
			Temp = *(DWORD*)(数组开始地址 + i * 8 + 4);
			Temp = *(DWORD*)(Temp + 0xc);
			if (Temp != 0)
			{
				Temp = *(DWORD*)(Temp + 0xc);
				列表[a].d血量 = *(DWORD*)(Temp + 0x8);
				a++;
			}
		}
		d数量 = a;



	}
	__except (1)
	{
		OutputDebuggingInformation("幻想神域   读取人物对象数组信息异常\r\n");
	}

}




//[[[[[00F84B74]+410+8]]+c]+c]+8
//[[[00F84B74]+410+8]]链表头
//+0 链表 
//新对象 == [[00F84B74]+410+8]跳出循环

void T周围遍历::c初始化()
{

	__try
	{
		DWORD a = *(DWORD*)0x00F84B74;
		DWORD 跳出标志 = *(DWORD*)(a + 0x410 + 0x8);
		DWORD 链表头 = *(DWORD*)跳出标志;
		DWORD 链表对象 = 链表头;
		DWORD Temp;
		DWORD i = 0;
		DWORD Temp2;
		T人物属性 人物;
		人物.c初始化();

		while (链表对象 != 跳出标志)
		{

			Temp = *(DWORD*)(链表对象 + 0xC);
			列表[i].d对象 = Temp;
			列表[i].dID = *(DWORD*)(Temp + 0x8);
			Temp = *(DWORD*)(Temp + 0xC);
			if (Temp != 0)
			{
				列表[i].d血量 = *(DWORD*)(Temp + 0x8);
				列表[i].d最大血量 = *(DWORD*)(Temp + 0x24);
			}
			else
			{
				列表[i].d血量 = 0;
				列表[i].d最大血量 = 0;
			}
			Temp2 = *(DWORD*)(链表对象 + 0xC);
			Temp2 = *(DWORD*)(Temp2 + 0x10);
			列表[i].fX = *(FLOAT*)(Temp2 + 0x154);
			列表[i].fY = *(FLOAT*)(Temp2 + 0x158);
			列表[i].fZ = *(FLOAT*)(Temp2 + 0x15C);


			列表[i].f距离 = sqrt((人物.fX - 列表[i].fX) * (人物.fX - 列表[i].fX) + (人物.fY - 列表[i].fY) * (人物.fY - 列表[i].fY));


			if (Temp != 0)
			{
				DWORD 名称长度 = *(DWORD*)(Temp + 0x114);
				if (名称长度 >= 0x10)
				{
					Temp = *(DWORD*)(Temp + 0x100);
					列表[i].p名称 = (char*)Temp;
				}
				else
				{
					列表[i].p名称 = (char*)(Temp + 0x100);
				}
				strcpy_s(列表[i].pgbk名称, 列表[i].p名称);
				BIGTOGBK(列表[i].pgbk名称);

			}
			else
			{
				列表[i].p名称 = "";
				strcpy_s(列表[i].pgbk名称, 列表[i].p名称);
				BIGTOGBK(列表[i].pgbk名称);

			}

			i++;
			链表对象 = *(DWORD*)链表对象;

		}

		d数量 = i;

	}
	__except (1)
	{
		OutputDebuggingInformation("幻想神域   读取周围遍历信息异常\r\n");
	}

}






T人物属性 T周围遍历::c返回最近怪物()
{
	this->c初始化();
	T人物属性 人物;
	人物.c初始化();
	T人物属性 a;
	__try
	{
		for (int i = 0; i < (int)this->d数量 - 1; i++)
		{

			for (int i = 0; i < (int)this->d数量 - 1; i++)
			{
				if (this->列表[i].f距离 < this->列表[i + 1].f距离)
				{
					a = this->列表[i + 1];
					this->列表[i + 1] = this->列表[i];
					this->列表[i] = a;
				}
			}

		}
		if (d数量 >= 2)
		{
			return this->列表[d数量 - 2];
		}
		else
		{
			return 人物;
		}
	}
	__except (1)
	{
		return 人物;
		OutputDebuggingInformation("幻想神域   返回最近怪物信息异常\r\n");
	}

}






DWORD g_背包物品数量 = 0;
void T背包物品遍历::c初始化()
{

	__try
	{
		g_背包物品数量 = 0;
		T人物属性 人物;
		人物.c初始化();
		DWORD Temp = *(DWORD*)(人物.d对象 + 0xC);
		Temp = *(DWORD*)(Temp + 0x3C0);
		Temp = *(DWORD*)(Temp + 0x4);
		DWORD 根节点 = *(DWORD*)(Temp + 0x4);
		c递归遍历(根节点);
		d数量 = g_背包物品数量;

	}
	__except (1)
	{
		OutputDebuggingInformation("幻想神域   读取背包物品遍历信息异常\r\n");
	}

}


void T背包物品遍历::c递归遍历(DWORD 节点)
{
	__try
	{
		DWORD 左子树 = *(DWORD*)(节点 + 0x0);
		DWORD 右子树 = *(DWORD*)(节点 + 0x8);
		BYTE 标志位 = *(BYTE*)(节点 + 0x15);
		if (标志位 == 0)
		{
			DWORD 对象 = *(DWORD*)(节点 + 0x10);
			WORD 背包序号 = *(WORD*)(节点 + 0xC);
			OutputDebuggingInformation("幻想神域   背包序号：%d   背包对象：%X\r\n", 背包序号, 对象);


			DWORD 数组开始地址 = *(DWORD*)(对象 + 0x8);
			DWORD 数组结束地址 = *(DWORD*)(对象 + 0xC);
			DWORD 数量 = (数组结束地址 - 数组开始地址) / 4;
			for (int i = 0; i < (int)数量; i++)
			{
				DWORD 物品对象 = *(DWORD*)(数组开始地址 + i * 4);
				DWORD ID = *(DWORD*)(物品对象 + 0);
				if (ID != 0)
				{
					列表[g_背包物品数量].d对象 = 物品对象;
					列表[g_背包物品数量].dID = ID;
					列表[g_背包物品数量].d位置 = i;
					列表[g_背包物品数量].w数量 = *(WORD*)(物品对象 + 0x28);
					列表[g_背包物品数量].w最大数量 = *(WORD*)(物品对象 + 0x2A);
					列表[g_背包物品数量].d所在背包 = 背包序号;



					列表[g_背包物品数量].p名称 = "";
					DWORD 名称对象;
					DWORD Temp;
					__asm
					{
						mov ecx, 0x1789168
						mov ecx, [ecx]
						mov eax, [ecx]
						push  ID
						mov edx, [eax + 0x0A8]
						call edx
						mov 名称对象, eax
					}
					DWORD 名称长度 = *(DWORD*)(名称对象 + 0xF8 + 0x18);
					if (名称长度 >= 0x10)
					{
						Temp = *(DWORD*)(名称对象 + 0xFC);
						列表[g_背包物品数量].p名称 = (char*)Temp;
					}
					else
					{
						列表[g_背包物品数量].p名称 = (char*)(名称对象 + 0xFC);
					}
					strcpy_s(列表[g_背包物品数量].pgbk名称, 列表[g_背包物品数量].p名称);
					BIGTOGBK(列表[g_背包物品数量].pgbk名称);



					g_背包物品数量++;
				}
			}

			c递归遍历(左子树);
			c递归遍历(右子树);
		}

	}
	__except (1)
	{
		OutputDebuggingInformation("幻想神域   读取背包物品遍历信息异常2\r\n");
	}

}



DWORD g_技能冷却数量 = 0;
void T技能冷却遍历::c初始化()
{

	__try
	{

		g_技能冷却数量 = 0;
		DWORD Temp = *(DWORD*)0x17EA2B0;
		Temp = *(DWORD*)(Temp + 0x30);
		Temp = *(DWORD*)(Temp + 0x8);
		DWORD 根节点 = *(DWORD*)(Temp + 0x4);
		c递归遍历(根节点);
		d数量 = g_技能冷却数量;
		OutputDebuggingInformation("幻想神域   技能冷却数量:%d\r\n", d数量);

	}
	__except (1)
	{
		OutputDebuggingInformation("幻想神域   读取技能冷却遍历信息异常\r\n");
	}

}



void T技能冷却遍历::c递归遍历(DWORD 节点)
{
	__try
	{
		DWORD 左子树 = *(DWORD*)(节点 + 0x0);
		DWORD 右子树 = *(DWORD*)(节点 + 0x8);
		BYTE 标志位 = *(BYTE*)(节点 + 0x15);
		if (标志位 == 0)
		{
			列表[g_技能冷却数量].dID = *(DWORD*)(节点 + 0xC);



			DWORD ID = 列表[g_技能冷却数量].dID;
			列表[g_技能冷却数量].p名称 = "";
			DWORD 名称对象;
			DWORD Temp;
			__asm
			{
				mov ecx, 0x1789168
				mov ecx, [ecx]
				mov edx, [ecx]
				push  ID
				mov edx, [edx + 0x0C4]
				call edx
				mov 名称对象, eax
			}
			DWORD 名称长度 = *(DWORD*)(名称对象 + 0x100 + 0x18);
			if (名称长度 >= 0x10)
			{
				Temp = *(DWORD*)(名称对象 + 0x104);
				列表[g_技能冷却数量].p名称 = (char*)Temp;
			}
			else
			{
				列表[g_技能冷却数量].p名称 = (char*)(名称对象 + 0x104);
			}
			strcpy_s(列表[g_技能冷却数量].pgbk名称, 列表[g_技能冷却数量].p名称);
			BIGTOGBK(列表[g_技能冷却数量].pgbk名称);



			g_技能冷却数量++;

			c递归遍历(左子树);
			c递归遍历(右子树);
		}

	}
	__except (1)
	{
		OutputDebuggingInformation("幻想神域   读取技能冷却遍历信息异常2\r\n");
	}

}







DWORD g_已学技能数量 = 0;
void T已学技能遍历::c初始化()
{

	__try
	{

		g_已学技能数量 = 0;
		T人物属性 人物;
		人物.c初始化();
		DWORD Temp = *(DWORD*)(人物.d对象 + 0xC);
		Temp = *(DWORD*)(Temp + 0x444 + 0x4);
		DWORD 根节点 = *(DWORD*)(Temp + 0x4);
		c递归遍历(根节点);
		d数量 = g_已学技能数量;
		OutputDebuggingInformation("幻想神域   技能已学数量:%d\r\n", d数量);

	}
	__except (1)
	{
		OutputDebuggingInformation("幻想神域   读取已学技能遍历信息异常\r\n");
	}

}



void T已学技能遍历::c递归遍历(DWORD 节点)
{
	__try
	{
		DWORD 左子树 = *(DWORD*)(节点 + 0x0);
		DWORD 右子树 = *(DWORD*)(节点 + 0x8);
		BYTE 标志位 = *(BYTE*)(节点 + 0x21);
		if (标志位 == 0)
		{
			列表[g_已学技能数量].dID = *(WORD*)(节点 + 0xC);
			DWORD ID = 列表[g_已学技能数量].dID;
			列表[g_已学技能数量].p名称 = "";
			DWORD 名称对象;
			DWORD Temp;
			__asm
			{
				mov ecx, 0x1789168
				mov ecx, [ecx]
				mov edx, [ecx]
				push  ID
				mov edx, [edx + 0x0C4]
				call edx
				mov 名称对象, eax
			}

			DWORD 名称长度 = *(DWORD*)(名称对象 + 0x100 + 0x18);
			if (名称长度 >= 0x10)
			{
				Temp = *(DWORD*)(名称对象 + 0x104);
				列表[g_已学技能数量].p名称 = (char*)Temp;
			}
			else
			{
				列表[g_已学技能数量].p名称 = (char*)(名称对象 + 0x104);
			}
			strcpy_s(列表[g_已学技能数量].pgbk名称, 列表[g_已学技能数量].p名称);
			BIGTOGBK(列表[g_已学技能数量].pgbk名称);





			g_已学技能数量++;

			c递归遍历(左子树);
			c递归遍历(右子树);

		}

	}
	__except (1)
	{
		OutputDebuggingInformation("幻想神域   读取已学技能遍历信息异常2\r\n");
	}

}


DWORD g_任务数量 = 0;
void T任务遍历::c初始化()
{

	__try
	{

		g_任务数量 = 0;
		T人物属性 a;
		a.c初始化();
		DWORD Temp = *(DWORD*)(a.d对象 + 0xC);
		Temp = *(DWORD*)(Temp + 0x3C4);
		Temp = *(DWORD*)(Temp + 0xC + 4);
		DWORD 根节点 = *(DWORD*)(Temp + 0x4);
		c递归遍历(根节点);
		d数量 = g_任务数量;
		OutputDebuggingInformation("幻想神域   任务数量:%d\r\n", d数量);

	}
	__except (1)
	{
		OutputDebuggingInformation("幻想神域   读取任务遍历信息异常\r\n");
	}

}



void T任务遍历::c递归遍历(DWORD 节点)
{
	__try
	{

		DWORD 左子树 = *(DWORD*)(节点 + 0x0);
		DWORD 右子树 = *(DWORD*)(节点 + 0x8);
		BYTE 标志位 = *(BYTE*)(节点 + 0x11);
		if (标志位 == 0)
		{
			列表[g_任务数量].wID = *(WORD*)(节点 + 0xC);
			列表[g_任务数量].w完成度 = *(WORD*)(节点 + 0xE);
			列表[g_任务数量].d对象 = 节点;


			g_任务数量++;

			c递归遍历(左子树);
			c递归遍历(右子树);
		}

	}
	__except (1)
	{
		OutputDebuggingInformation("幻想神域   读取任务遍历信息异常2\r\n");
	}

}






DWORD g_任务库数量 = 0;
void T任务库遍历::c初始化()
{

	__try
	{
		g_任务库数量 = 0;
		DWORD Temp = *(DWORD*)(0x17E928C + 4);
		DWORD 根节点 = *(DWORD*)(Temp + 0x4);
		c递归遍历(根节点);
		d数量 = g_任务库数量;
		OutputDebuggingInformation("幻想神域   任务库数量:%d\r\n", d数量);

	}
	__except (1)
	{
		OutputDebuggingInformation("幻想神域   读取任务库遍历信息异常\r\n");
	}

}



void T任务库遍历::c递归遍历(DWORD 节点)
{
	__try
	{
		DWORD 左子树 = *(DWORD*)(节点 + 0x0);
		DWORD 右子树 = *(DWORD*)(节点 + 0x8);
		BYTE 标志位 = *(BYTE*)(节点 + 0x15);
		DWORD Temp;
		if (标志位 == 0)
		{

			列表[g_任务库数量].d对象 = *(DWORD*)(节点 + 0x10);
			列表[g_任务库数量].wID = *(WORD*)(列表[g_任务库数量].d对象 + 0x18);


			DWORD 名称长度 = *(DWORD*)(列表[g_任务库数量].d对象 + 0x1C + 0x18);
			if (名称长度 >= 0x10)
			{
				Temp = *(DWORD*)(列表[g_任务库数量].d对象 + 0x1C + 4);
				列表[g_任务库数量].p名称 = (char*)Temp;
			}
			else
			{
				列表[g_任务库数量].p名称 = (char*)(列表[g_任务库数量].d对象 + 0x1C + 4);
			}
			strcpy_s(列表[g_任务库数量].pgbk名称, 列表[g_任务库数量].p名称);
			BIGTOGBK(列表[g_任务库数量].pgbk名称);


			g_任务库数量++;

			c递归遍历(左子树);
			c递归遍历(右子树);
		}

	}
	__except (1)
	{
		OutputDebuggingInformation("幻想神域   读取任务库遍历信息异常2\r\n");
	}

}