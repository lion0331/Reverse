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

__declspec(naked) void CallEncryption(DWORD ��Կ, DWORD ���ܳ���, DWORD ���ܵ�ַ, DWORD ���ܵ�ַ2)
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

void  SendPacket(DWORD ����, DWORD ����ַ) 
{

	DWORD ���ܵ�ַ = ����ַ + 2;
	DWORD ���ܳ��� = ���� - 2;
	DWORD ��Կ = 0;
	__asm
	{
		mov ecx, 0x00f84ba4
		mov ecx, [ecx]
		mov ecx, [ecx]
		mov ecx, [ecx + 0x4]
		mov ecx, [ecx + 0x14]
		mov ecx, [ecx]
		lea ecx, [ecx + 0x54]
		mov ��Կ, ecx
	}

	CallEncryption(��Կ, ���ܳ���, ���ܵ�ַ, ���ܵ�ַ);


	HWND ���ھ�� = FindWindowA("Lapis Network Class", 0);
	DWORD A = GetWindowLongW(���ھ��, -21);
	DWORD S = *(DWORD*)(A + 0x38);

	send(S, (const char*)����ַ, ����, 0);
}


void  Call_��ҩ���(char* ҩƷ����)
{

	//����:16   ������:1400  4F000000  0100 0400 000000000000000000000000    +6 ��λ�� WORD�ڼ�������   +8��λ�� WORD����λ��

	byte b[0x16] = { 0x14,00,0x4F,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00 };
	T������Ʒ���� List;
	List.c��ʼ��();
	for (int i = 0; i < (int)List.d����; i++)
	{
		if (strcmp(ҩƷ����, List.�б�[i].pgbk����) == 0)
		{
			*(WORD*)(b + 6) = (WORD)List.�б�[i].d���ڱ���;
			*(WORD*)(b + 8) = (WORD)List.�б�[i].dλ��;
			OutputDebuggingInformation("��������   �ڼ���������%d   ����λ�ã�%d\r\n", List.�б�[i].d���ڱ���, List.�б�[i].dλ��);
			Msg_SendPacket(0x16, (DWORD)b);
			break;
		}
	}

}






void  Call_�������ܷ��(WORD ����ID, DWORD ����ID)
{
	//����:c   ������:0A00  5500    5ACA      1FEEFEFF    0000      +4 WORD ����ID       +6 DWORD ����ID

	byte b[0xC] = { 0x0A,00,0x55,00,00,00,00,00,00,00,00,00 };

	*(WORD*)(b + 4) = ����ID;
	*(DWORD*)(b + 6) = ����ID;
	Msg_SendPacket(0xC, (DWORD)b);

	//����:6   ������:040043000000 
	byte bb[0x6] = { 0x04,00,0x43,00,00,00 };
	Msg_SendPacket(0x6, (DWORD)bb);
}


void  Call_���ٿշ����ܷ��(WORD ����ID)
{
	//����:10   ������:0E00 4E00  61CA  5BA0A543  D3BCD643 0000 

	T�������� a;
	a.c��ʼ��();
	byte b[0x10] = { 0x0E,00,0x4E,00 };

	*(WORD*)(b + 4) = ����ID;
	*(FLOAT*)(b + 6) = a.fX;
	*(FLOAT*)(b + 0xA) = a.fY;
	Msg_SendPacket(0x10, (DWORD)b);

}


void  Call_Ѱ·(DWORD x, DWORD y)
{

	byte b[0x10] = { 0 };
	*(FLOAT*)b = (FLOAT)x;
	*(FLOAT*)(b + 4) = (FLOAT)y;
	*(DWORD*)(b + 8) = x;
	*(DWORD*)(b + 0xC) = y;
	DWORD A = (DWORD)b;
	OutputDebuggingInformation("��������   Ѱ·���� %d   %d\r\n", x, y);
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


void  Call_Ѱ��(DWORD x, DWORD y)// ����Ѱ������
{
	int i = 0;
	T�������� ����;
	����.c��ʼ��();
	DWORD ������� = ����.d����;
	FLOAT ����;
	do
	{
		Msg_Ѱ·(x, y);
		Sleep(300);
		DWORD Temp = *(DWORD*)(������� + 0x10);
		FLOAT X = *(FLOAT*)(Temp + 0x154);
		FLOAT Y = *(FLOAT*)(Temp + 0x158);

		���� = sqrt((X - x) * (X - x) + (Y - y) * (Y - y));
		i++;
		if (i > 15)
		{
			break;// ���5��û�дﵽ�ص���������  ��ֹ����
		}
	} while (���� > 5);

}

void  Call_����Ѱ��(DWORD x, DWORD y)
{

	T�������� ����;
	����.c��ʼ��();
	DWORD ������� = ����.d����;
	FLOAT ����;
	do
	{
		Msg_Ѱ·(x, y);
		Sleep(2000);
		DWORD Temp = *(DWORD*)(������� + 0x10);
		FLOAT X = *(FLOAT*)(Temp + 0x154);
		FLOAT Y = *(FLOAT*)(Temp + 0x158);

		���� = sqrt((X - x) * (X - x) + (Y - y) * (Y - y));

	} while (���� > 5);

}

DWORD Call_�Ƿ��иü���(char* ������)
{
	T��ѧ���ܱ��� List;
	List.c��ʼ��();
	for (int i = 0; i < (int)List.d����; i++)
	{

		if (strcmp(List.�б�[i].pgbk����, ������) == 0)
		{
			return 1;
		}
	}
	return 0;

}

DWORD Call_�ü����Ƿ���ȴ(char* ������)
{
	T������ȴ���� List;
	List.c��ʼ��();
	for (int i = 0; i < (int)List.d����; i++)
	{

		if (strcmp(List.�б�[i].pgbk����, ������) == 0)
		{
			return 0;
		}
	}
	return 1;

}

void  Call_����ʹ�ü���(DWORD ����ID)///ְҵ��˫���̿ͼ���
{

	//���ȼ�   �����W  ��u����CD1��  ɢ�Aѩ 0.7  ʮ�֔� 1.2   ���� 1.5  ���ٿշ� 0.5չʾδ��
	if (Call_�Ƿ��иü���("�����W") && Call_�ü����Ƿ���ȴ("�����W"))
	{
		Call_�������ܷ��(0xCA5D, ����ID);
		Sleep(1000);
	}
	else if (Call_�Ƿ��иü���("ɢ�Aѩ") && Call_�ü����Ƿ���ȴ("ɢ�Aѩ"))
	{
		Call_�������ܷ��(0xCA5B, ����ID);
		Sleep(700);
	}
	else if (Call_�Ƿ��иü���("ʮ�֔�") && Call_�ü����Ƿ���ȴ("ʮ�֔�"))
	{
		Call_�������ܷ��(0xCA5A, ����ID);
		Sleep(1200);
	}
	else if (Call_�Ƿ��иü���("����") && Call_�ü����Ƿ���ȴ("����"))
	{
		Call_�������ܷ��(0xCA59, ����ID);
		Sleep(1500);
	}

}

DWORD Call_Ŀ�ĵ��Ƿ�ɴ�(DWORD x, DWORD y)
{
	__try
	{

		T�������� a;
		a.c��ʼ��();
		DWORD ������� = a.d����;
		DWORD Temp = *(DWORD*)(������� + 0x2c);
		Temp = Temp + 0x118;
		DWORD old = 0;
		VirtualProtect((PVOID)Temp, 1000, PAGE_EXECUTE_READWRITE, &old);
		*(FLOAT*)(Temp + 0x10) = (FLOAT)x;
		*(FLOAT*)(Temp + 0x14) = (FLOAT)y;
		VirtualProtect((PVOID)Temp, 1000, old, &old);
		OutputDebuggingInformation("��������   Ŀ�ĵ��Ƿ�ɴ�ṹ���ַ:%X\r\n", Temp);
		__asm
		{
			mov ecx, Temp
			mov eax, 0x0077D8B0
			call eax
		}
		DWORD R = *(WORD*)(Temp + 0x64);
		OutputDebuggingInformation("��������    �ж�Ŀ�ĵ�%d   %d  ����%d\r\n", x, y, R);
		return R;

	}
	__except (1)
	{
		OutputDebuggingInformation("��������   �ж�Ŀ�ĵ��Ƿ�ɴ��쳣\r\n");
		return 0;
	}
}


DWORD Call_Ѱ·�Ƿ�ɹ�()
{
	T�������� a;
	a.c��ʼ��();
	DWORD Temp = *(DWORD*)(a.d���� + 0x2c);
	DWORD A = *(DWORD*)(Temp + 0x118 + 0x1C);
	return A;

}


void  Call_����������(char* ��������, DWORD ��������)
{

	//0A00    1D00   0100    ED030000    FFFF 
	//����      ��ͷ   ������ʽ    ����ID       ��ʱ�̶�

	DWORD ����ID = 0;
	byte b[0xC] = { 0x0A,00,0x1D,00,00,00,00,00,00,00,0xFF,0xFF };


	T�������� List;
	List.c��ʼ��();
	for (int i = 0; i < (int)List.d����; i++)
	{
		if (strcmp(��������, List.�б�[i].pgbk����) == 0)
		{
			����ID = List.�б�[i].wID;
			break;
		}
	}


	*(WORD*)(b + 4) = (WORD)��������;
	*(DWORD*)(b + 6) = ����ID;
	Msg_SendPacket(0xC, (DWORD)b);

}



void  Call_��NPC���(char* NPC����)
{

	//0600      5800     E1FEFFFF
	//                    NPCID
	//0600        0300     E1FEFFFF

	DWORD NPCID = 0;
	byte b[0x8] = { 0x06,00,0x58,00,00,00,00,00 };
	byte bb[0x8] = { 0x06,00,0x03,00,00,00,00,00 };

	T��Χ���� a;
	a.c��ʼ��();
	for (int i = 0; i < (int)a.d����; i++)
	{

		if (strcmp(NPC����, a.�б�[i].pgbk����) == 0)
		{
			NPCID = a.�б�[i].dID;
			break;
		}
	}



	*(DWORD*)(b + 4) = NPCID;
	*(DWORD*)(bb + 4) = NPCID;

	Msg_SendPacket(0x8, (DWORD)b);
	Msg_SendPacket(0x8, (DWORD)bb);

}


DWORD Call_��������״̬(char* ��������)
{
	T������� List;
	List.c��ʼ��();
	T�������� List2;
	List2.c��ʼ��();
	for (int i = 0; i < (int)List.d����; i++)
	{
		for (int j = 0; j < (int)List2.d����; j++)
		{

			if (List.�б�[i].wID == List2.�б�[j].wID)
			{
				List.�б�[i].p���� = List2.�б�[j].p����;
				strcpy_s(List.�б�[i].pgbk����, List.�б�[i].p����);
				BIGTOGBK(List.�б�[i].pgbk����);
				break;
			}
		}
	}


	for (int i = 0; i < (int)List.d����; i++)
	{
		if (strcmp(��������, List.�б�[i].pgbk����) == 0)
		{
			return List.�б�[i].w��ɶ�;
		}
	}

	return 99;


}

void  Call_�����м�Ի����()
{

	//����:6   ������:040057000100
	byte b[0x6] = { 0x04,00,0x57,00,01,00 };
	Msg_SendPacket(0x6, (DWORD)b);

}



DWORD g_�����߳� = 0;
void �����߳�()
{
	T�������� a;
	while (g_�����߳�)
	{
		a.c��ʼ��();
		if (a.dѪ�� < a.d���Ѫ�� * 0.8)
		{
			Call_��ҩ���("�p��HPˎˮ");
			Sleep(5700);
		}

		Sleep(300);
	}

}

void  Call_�����߳�()
{
	g_�����߳� = 1;
	::CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)�����߳�, NULL, NULL, NULL);
}

void  Call_�رձ����߳�()
{
	g_�����߳� = 0;
}









void  Call_�Զ�ɱ��(char* ��������)
{


	DWORD �������;
	T��Χ���� List;
	List.c��ʼ��();//�����ʼ��
	List.c�����������();// �ù�����������
	for (int i = List.d���� - 1; i > 0; i--)// �Ӿ�������Ŀ�ʼѰ��
	{
		if (strcmp(��������, List.�б�[i].pgbk����) == 0)// ���������Ĺ���
		{
			if (List.�б�[i].dѪ�� == List.�б�[i].d���Ѫ��)// �����Ҳ��Ǳ��˹������Ĺ���
			{
				OutputDebuggingInformation("��������   �ҵ�����   i=%d\r\n", i);


				Msg_Ѱ·((int)List.�б�[i].fX, (int)List.�б�[i].fY);
				Sleep(100);
				if (Call_Ѱ·�Ƿ�ɹ�() != 0)
				{
					OutputDebuggingInformation("��������   Ѱ������\r\n");
					Call_Ѱ��((int)List.�б�[i].fX, (int)List.�б�[i].fY);//Ѱ������
				}
				else
				{
					OutputDebuggingInformation("��������   �����´��ҹ�\r\n");
					continue;
				}


				������� = List.�б�[i].d����;
				while (List.�б�[i].dѪ�� != 0)//ѭ����������
				{
					OutputDebuggingInformation("��������   ѭ��ɱ��\r\n");
					DWORD Temp = *(DWORD*)(������� + 0x10);
					FLOAT X = *(FLOAT*)(Temp + 0x154);
					FLOAT Y = *(FLOAT*)(Temp + 0x158);

					Msg_Ѱ·((int)X, (int)Y);
					Sleep(100);
					if (Call_Ѱ·�Ƿ�ɹ�() != 0)//Ҫ��ֹ�����벻��Ѱ·
					{
						Call_Ѱ��((int)X, (int)Y);//Ѱ������
					}
					else
					{
						OutputDebuggingInformation("��������   ���ڹ������ﲻ��Ѱ·\r\n");
						break;
					}
					// �жϹ���Ѫ��
					Temp = *(DWORD*)(������� + 0xC);
					List.�б�[i].dѪ�� = *(DWORD*)(Temp + 0x8);//�����ж�����Ѫ��
					if (List.�б�[i].dѪ�� != 0)
					{
						Call_����ʹ�ü���(List.�б�[i].dID);//����ѡ�񹥻���ʽ
					}
					Temp = *(DWORD*)(������� + 0xC);
					List.�б�[i].dѪ�� = *(DWORD*)(Temp + 0x8);//�����ж�����Ѫ��

				}
				break;
			}
		}
	}


}



DWORD g_����߳� = 0;
void  Call_����߳�(char* str)
{
	g_����߳� = 1;	
	OutputDebuggingInformation("��������    ��������:%s\r\n", str);
	Sleep(300);
	size_t len = strlen(str) + 1;
	char* copy = new char[len];
	strcpy_s(copy, len, str);
	::CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)����߳�, copy, NULL, NULL);


}

void  ����߳�( char* str)
{

	OutputDebuggingInformation("��������    ��������:%s\r\n", str);
	while (g_����߳�)
	{

		Call_�Զ�ɱ��(str);
		Sleep(300);
	}
}


void  Call_�رմ���߳�()
{
	g_����߳� = 0;
}


DWORD g_�����߳� = 0;
void �����߳�()
{

	while (g_�����߳�)
	{

		if (Call_��������״̬("Lv1.ج�������z֢") == 1 && Call_��������״̬("Lv1.��؛") != 1)//Lv1.��؛
		{
			do
			{
				Call_����Ѱ��(531, 339);
				Sleep(100);
				Call_��NPC���("���L����\n�z����");
				Sleep(100);
				Call_����������("Lv1.��؛", 1);
				Sleep(100);
			} while (Call_��������״̬("Lv1.��؛") != 3);


			do
			{
				Call_����Ѱ��(493, 313);
				Sleep(100);
				Call_��NPC���("�s؛�m���\n������");
				Sleep(100);
				Call_�����м�Ի����();
				Sleep(100);
				Call_����Ѱ��(503, 280);
				Sleep(100);
				Call_��NPC���("���������\nؐ��");
				Sleep(100);
				Call_�����м�Ի����();
				Sleep(100);
				Call_����Ѱ��(526, 277);
				Sleep(100);
				Call_��NPC���("���������\n��");
				Sleep(100);
				Call_�����м�Ի����();
				Sleep(100);
			} while (Call_��������״̬("Lv1.��؛") != 4);

			do
			{
				Call_����Ѱ��(531, 339);
				Sleep(100);
				Call_��NPC���("���L����\n�z����");
				Sleep(100);
				Call_����������("Lv1.��؛", 2);
				Sleep(100);

			} while (Call_��������״̬("Lv1.��؛") != 1);
		}

		if (Call_��������״̬("Lv1.��؛") == 1 && Call_��������״̬("Lv2.���ı㮔") != 1)//Lv2.���ı㮔
		{
			do
			{
				Call_����Ѱ��(531, 339);
				Sleep(100);
				Call_��NPC���("���L����\n�z����");
				Sleep(100);
				Call_����������("Lv2.���ı㮔", 1);
				Sleep(100);
			} while (Call_��������״̬("Lv2.���ı㮔") != 4);

			do
			{
				Call_����Ѱ��(553, 230);
				Sleep(100);
				Call_��NPC���("���L\n�s��");
				Sleep(100);
				Call_����������("Lv2.���ı㮔", 2);
				Sleep(100);

			} while (Call_��������״̬("Lv2.���ı㮔") != 1);

		}


		if (Call_��������״̬("Lv2.���ı㮔") == 1 && Call_��������״̬("Lv2.��ʽ����") != 1)//Lv2.��ʽ����

		{
			do
			{
				Call_����Ѱ��(553, 230);
				Sleep(100);
				Call_��NPC���("���L\n�s��");
				Sleep(100);
				Call_����������("Lv2.��ʽ����", 1);
				Sleep(100);
			} while (Call_��������״̬("Lv2.��ʽ����") != 4);

			do
			{
				Call_����Ѱ��(291, 299);
				Sleep(100);
				Call_��NPC���("���^\n�϶�");
				Sleep(100);
				Call_����������("Lv2.��ʽ����", 2);
				Sleep(100);

			} while (Call_��������״̬("Lv2.��ʽ����") != 1);

		}


		if (Call_��������״̬("Lv2.��ʽ����") == 1 && Call_��������״̬("Lv3.���õĹ����h��") != 1)//Lv3.���õĹ����h��


		{
			do
			{
				Call_����Ѱ��(291, 299);
				Sleep(100);
				Call_��NPC���("���^\n�϶�");
				Sleep(100);
				Call_����������("Lv3.���õĹ����h��", 1);
				Sleep(100);
			} while (Call_��������״̬("Lv3.���õĹ����h��") != 3);


			do
			{
				Call_����Ѱ��(354, 317);
				Sleep(100);
				for (int i = 0; i < 4; i++)
				{
					Call_�Զ�ɱ��("������");
				}
				Call_����Ѱ��(330, 254);
				Sleep(100);
				for (int i = 0; i < 3; i++)
				{
					Call_�Զ�ɱ��("�v��������");
				}
				Sleep(100);
			} while (Call_��������״̬("Lv3.���õĹ����h��") != 4);


			do
			{
				Call_����Ѱ��(291, 299);
				Sleep(100);
				Call_��NPC���("���^\n�϶�");
				Sleep(100);
				Call_����������("Lv3.���õĹ����h��", 2);
				Sleep(100);

			} while (Call_��������״̬("Lv3.���õĹ����h��") != 1);

		}




		Sleep(300);
	}

}




void  Call_�����߳�()
{
	g_�����߳� = 1;
	::CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)�����߳�, NULL, NULL, NULL);
}

void  Call_�ر������߳�()
{
	g_�����߳� = 0;
}
