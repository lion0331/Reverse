#include "pch.h"
#include "Structure.h"
#include "FantasyFrontier.h"
#include "FantasyDialog.h"
#include "framework.h"
#include "Call.h"
#include "GeneralFunction.h"
#include "Hook.h"
using namespace std;

//����+8 ID
//[����+C]+8 Ѫ��
//[����+C]+10 ��ǰ�ȼ�
//[����+C]+18 �ƶ��ٶ�
//[����+C]+24 ���Ѫ��
//[����+C]+30 �����˺�
//[����+C]+34 ������
//[����+C]+38 ���Ʊ���
//[����+C]+68 ����
//[����+C]+27C ʣ�๥������
//[����+C]+280 ʣ���������
//[����+10]+154 X
//[����+10]+158 Y
//[����+10]+15C Z

//����ID [[0F84B74]+40C] �������� ��������±�EBX
//ebx = ��([[0F84B74]+40C]*41 + [[0F84B74]+40C]/4 +9E3779B9) and [[0F84B74]+410+20]��*2
//Ȼ��������ȡ�ö��� [[[[[0F84B74]+410+14]+ebx*8+4]+C]+C]+8
//[0F84B74]+410+14��ʼ��ָ��
//[0F84B74]+410+18������ָ��

//mov     ecx, dword ptr [F84B74]
//mov     eax, dword ptr [ecx+40C]
//push eax
//add ecx,410
//call 00665870
//mov eax,[eax+0C]
//mov eax,[eax+8]
//mov ecx,12345678
//mov [ecx],eax
void T��������::c��ʼ��()
{
	__try
	{
		DWORD ������� = 0;
		__asm
		{
			mov     ecx, 0x0F84B74
			mov     ecx, [ecx]
			mov     eax, dword ptr[ecx + 0x40C]
			push eax
			add ecx, 0x410
			mov eax, 0x00665870
			call eax
			mov �������, eax
		}
		d���� = �������;
		dID = *(DWORD*)(������� + 0x8);// �� [[0x0F84B74]+40C]Ҳ����
		DWORD Temp = *(DWORD*)(������� + 0xC);
		dѪ�� = *(DWORD*)(Temp + 0x8);
		d���Ѫ�� = *(DWORD*)(Temp + 0x24);
		Temp = *(DWORD*)(������� + 0x10);
		fX = *(FLOAT*)(Temp + 0x154);
		fY = *(FLOAT*)(Temp + 0x158);
		fZ = *(FLOAT*)(Temp + 0x15C);
		f���� = 0;

	}
	__except (1)
	{
		OutputDebuggingInformation("��������   ��ȡ������Ϣ�쳣\r\n");
	}
}



//Ȼ��������ȡ�ö��� [[[[[0F84B74]+410+14]+ebx*8+4]+C]+C]+8
//[0F84B74]+410+14��ʼ��ָ��
//[0F84B74]+410+18������ָ��


void Tȡ�����������::c��ʼ��()
{

	__try
	{
		DWORD a = 0;
		DWORD Temp = *(DWORD*)0x0F84B74;
		DWORD ���鿪ʼ��ַ = *(DWORD*)(Temp + 0x410 + 0x14);
		DWORD ���������ַ = *(DWORD*)(Temp + 0x410 + 0x18);
		d���� = (���������ַ - ���鿪ʼ��ַ) / 8;
		for (int i = 0; i < (int)d����; i++)
		{
			Temp = *(DWORD*)(���鿪ʼ��ַ + i * 8 + 4);
			Temp = *(DWORD*)(Temp + 0xc);
			if (Temp != 0)
			{
				Temp = *(DWORD*)(Temp + 0xc);
				�б�[a].dѪ�� = *(DWORD*)(Temp + 0x8);
				a++;
			}
		}
		d���� = a;



	}
	__except (1)
	{
		OutputDebuggingInformation("��������   ��ȡ�������������Ϣ�쳣\r\n");
	}

}




//[[[[[00F84B74]+410+8]]+c]+c]+8
//[[[00F84B74]+410+8]]����ͷ
//+0 ���� 
//�¶��� == [[00F84B74]+410+8]����ѭ��

void T��Χ����::c��ʼ��()
{

	__try
	{
		DWORD a = *(DWORD*)0x00F84B74;
		DWORD ������־ = *(DWORD*)(a + 0x410 + 0x8);
		DWORD ����ͷ = *(DWORD*)������־;
		DWORD ������� = ����ͷ;
		DWORD Temp;
		DWORD i = 0;
		DWORD Temp2;
		T�������� ����;
		����.c��ʼ��();

		while (������� != ������־)
		{

			Temp = *(DWORD*)(������� + 0xC);
			�б�[i].d���� = Temp;
			�б�[i].dID = *(DWORD*)(Temp + 0x8);
			Temp = *(DWORD*)(Temp + 0xC);
			if (Temp != 0)
			{
				�б�[i].dѪ�� = *(DWORD*)(Temp + 0x8);
				�б�[i].d���Ѫ�� = *(DWORD*)(Temp + 0x24);
			}
			else
			{
				�б�[i].dѪ�� = 0;
				�б�[i].d���Ѫ�� = 0;
			}
			Temp2 = *(DWORD*)(������� + 0xC);
			Temp2 = *(DWORD*)(Temp2 + 0x10);
			�б�[i].fX = *(FLOAT*)(Temp2 + 0x154);
			�б�[i].fY = *(FLOAT*)(Temp2 + 0x158);
			�б�[i].fZ = *(FLOAT*)(Temp2 + 0x15C);


			�б�[i].f���� = sqrt((����.fX - �б�[i].fX) * (����.fX - �б�[i].fX) + (����.fY - �б�[i].fY) * (����.fY - �б�[i].fY));


			if (Temp != 0)
			{
				DWORD ���Ƴ��� = *(DWORD*)(Temp + 0x114);
				if (���Ƴ��� >= 0x10)
				{
					Temp = *(DWORD*)(Temp + 0x100);
					�б�[i].p���� = (char*)Temp;
				}
				else
				{
					�б�[i].p���� = (char*)(Temp + 0x100);
				}
				strcpy_s(�б�[i].pgbk����, �б�[i].p����);
				BIGTOGBK(�б�[i].pgbk����);

			}
			else
			{
				�б�[i].p���� = "";
				strcpy_s(�б�[i].pgbk����, �б�[i].p����);
				BIGTOGBK(�б�[i].pgbk����);

			}

			i++;
			������� = *(DWORD*)�������;

		}

		d���� = i;

	}
	__except (1)
	{
		OutputDebuggingInformation("��������   ��ȡ��Χ������Ϣ�쳣\r\n");
	}

}






T�������� T��Χ����::c�����������()
{
	this->c��ʼ��();
	T�������� ����;
	����.c��ʼ��();
	T�������� a;
	__try
	{
		for (int i = 0; i < (int)this->d���� - 1; i++)
		{

			for (int i = 0; i < (int)this->d���� - 1; i++)
			{
				if (this->�б�[i].f���� < this->�б�[i + 1].f����)
				{
					a = this->�б�[i + 1];
					this->�б�[i + 1] = this->�б�[i];
					this->�б�[i] = a;
				}
			}

		}
		if (d���� >= 2)
		{
			return this->�б�[d���� - 2];
		}
		else
		{
			return ����;
		}
	}
	__except (1)
	{
		return ����;
		OutputDebuggingInformation("��������   �������������Ϣ�쳣\r\n");
	}

}






DWORD g_������Ʒ���� = 0;
void T������Ʒ����::c��ʼ��()
{

	__try
	{
		g_������Ʒ���� = 0;
		T�������� ����;
		����.c��ʼ��();
		DWORD Temp = *(DWORD*)(����.d���� + 0xC);
		Temp = *(DWORD*)(Temp + 0x3C0);
		Temp = *(DWORD*)(Temp + 0x4);
		DWORD ���ڵ� = *(DWORD*)(Temp + 0x4);
		c�ݹ����(���ڵ�);
		d���� = g_������Ʒ����;

	}
	__except (1)
	{
		OutputDebuggingInformation("��������   ��ȡ������Ʒ������Ϣ�쳣\r\n");
	}

}


void T������Ʒ����::c�ݹ����(DWORD �ڵ�)
{
	__try
	{
		DWORD ������ = *(DWORD*)(�ڵ� + 0x0);
		DWORD ������ = *(DWORD*)(�ڵ� + 0x8);
		BYTE ��־λ = *(BYTE*)(�ڵ� + 0x15);
		if (��־λ == 0)
		{
			DWORD ���� = *(DWORD*)(�ڵ� + 0x10);
			WORD ������� = *(WORD*)(�ڵ� + 0xC);
			OutputDebuggingInformation("��������   ������ţ�%d   ��������%X\r\n", �������, ����);


			DWORD ���鿪ʼ��ַ = *(DWORD*)(���� + 0x8);
			DWORD ���������ַ = *(DWORD*)(���� + 0xC);
			DWORD ���� = (���������ַ - ���鿪ʼ��ַ) / 4;
			for (int i = 0; i < (int)����; i++)
			{
				DWORD ��Ʒ���� = *(DWORD*)(���鿪ʼ��ַ + i * 4);
				DWORD ID = *(DWORD*)(��Ʒ���� + 0);
				if (ID != 0)
				{
					�б�[g_������Ʒ����].d���� = ��Ʒ����;
					�б�[g_������Ʒ����].dID = ID;
					�б�[g_������Ʒ����].dλ�� = i;
					�б�[g_������Ʒ����].w���� = *(WORD*)(��Ʒ���� + 0x28);
					�б�[g_������Ʒ����].w������� = *(WORD*)(��Ʒ���� + 0x2A);
					�б�[g_������Ʒ����].d���ڱ��� = �������;



					�б�[g_������Ʒ����].p���� = "";
					DWORD ���ƶ���;
					DWORD Temp;
					__asm
					{
						mov ecx, 0x1789168
						mov ecx, [ecx]
						mov eax, [ecx]
						push  ID
						mov edx, [eax + 0x0A8]
						call edx
						mov ���ƶ���, eax
					}
					DWORD ���Ƴ��� = *(DWORD*)(���ƶ��� + 0xF8 + 0x18);
					if (���Ƴ��� >= 0x10)
					{
						Temp = *(DWORD*)(���ƶ��� + 0xFC);
						�б�[g_������Ʒ����].p���� = (char*)Temp;
					}
					else
					{
						�б�[g_������Ʒ����].p���� = (char*)(���ƶ��� + 0xFC);
					}
					strcpy_s(�б�[g_������Ʒ����].pgbk����, �б�[g_������Ʒ����].p����);
					BIGTOGBK(�б�[g_������Ʒ����].pgbk����);



					g_������Ʒ����++;
				}
			}

			c�ݹ����(������);
			c�ݹ����(������);
		}

	}
	__except (1)
	{
		OutputDebuggingInformation("��������   ��ȡ������Ʒ������Ϣ�쳣2\r\n");
	}

}



DWORD g_������ȴ���� = 0;
void T������ȴ����::c��ʼ��()
{

	__try
	{

		g_������ȴ���� = 0;
		DWORD Temp = *(DWORD*)0x17EA2B0;
		Temp = *(DWORD*)(Temp + 0x30);
		Temp = *(DWORD*)(Temp + 0x8);
		DWORD ���ڵ� = *(DWORD*)(Temp + 0x4);
		c�ݹ����(���ڵ�);
		d���� = g_������ȴ����;
		OutputDebuggingInformation("��������   ������ȴ����:%d\r\n", d����);

	}
	__except (1)
	{
		OutputDebuggingInformation("��������   ��ȡ������ȴ������Ϣ�쳣\r\n");
	}

}



void T������ȴ����::c�ݹ����(DWORD �ڵ�)
{
	__try
	{
		DWORD ������ = *(DWORD*)(�ڵ� + 0x0);
		DWORD ������ = *(DWORD*)(�ڵ� + 0x8);
		BYTE ��־λ = *(BYTE*)(�ڵ� + 0x15);
		if (��־λ == 0)
		{
			�б�[g_������ȴ����].dID = *(DWORD*)(�ڵ� + 0xC);



			DWORD ID = �б�[g_������ȴ����].dID;
			�б�[g_������ȴ����].p���� = "";
			DWORD ���ƶ���;
			DWORD Temp;
			__asm
			{
				mov ecx, 0x1789168
				mov ecx, [ecx]
				mov edx, [ecx]
				push  ID
				mov edx, [edx + 0x0C4]
				call edx
				mov ���ƶ���, eax
			}
			DWORD ���Ƴ��� = *(DWORD*)(���ƶ��� + 0x100 + 0x18);
			if (���Ƴ��� >= 0x10)
			{
				Temp = *(DWORD*)(���ƶ��� + 0x104);
				�б�[g_������ȴ����].p���� = (char*)Temp;
			}
			else
			{
				�б�[g_������ȴ����].p���� = (char*)(���ƶ��� + 0x104);
			}
			strcpy_s(�б�[g_������ȴ����].pgbk����, �б�[g_������ȴ����].p����);
			BIGTOGBK(�б�[g_������ȴ����].pgbk����);



			g_������ȴ����++;

			c�ݹ����(������);
			c�ݹ����(������);
		}

	}
	__except (1)
	{
		OutputDebuggingInformation("��������   ��ȡ������ȴ������Ϣ�쳣2\r\n");
	}

}







DWORD g_��ѧ�������� = 0;
void T��ѧ���ܱ���::c��ʼ��()
{

	__try
	{

		g_��ѧ�������� = 0;
		T�������� ����;
		����.c��ʼ��();
		DWORD Temp = *(DWORD*)(����.d���� + 0xC);
		Temp = *(DWORD*)(Temp + 0x444 + 0x4);
		DWORD ���ڵ� = *(DWORD*)(Temp + 0x4);
		c�ݹ����(���ڵ�);
		d���� = g_��ѧ��������;
		OutputDebuggingInformation("��������   ������ѧ����:%d\r\n", d����);

	}
	__except (1)
	{
		OutputDebuggingInformation("��������   ��ȡ��ѧ���ܱ�����Ϣ�쳣\r\n");
	}

}



void T��ѧ���ܱ���::c�ݹ����(DWORD �ڵ�)
{
	__try
	{
		DWORD ������ = *(DWORD*)(�ڵ� + 0x0);
		DWORD ������ = *(DWORD*)(�ڵ� + 0x8);
		BYTE ��־λ = *(BYTE*)(�ڵ� + 0x21);
		if (��־λ == 0)
		{
			�б�[g_��ѧ��������].dID = *(WORD*)(�ڵ� + 0xC);
			DWORD ID = �б�[g_��ѧ��������].dID;
			�б�[g_��ѧ��������].p���� = "";
			DWORD ���ƶ���;
			DWORD Temp;
			__asm
			{
				mov ecx, 0x1789168
				mov ecx, [ecx]
				mov edx, [ecx]
				push  ID
				mov edx, [edx + 0x0C4]
				call edx
				mov ���ƶ���, eax
			}

			DWORD ���Ƴ��� = *(DWORD*)(���ƶ��� + 0x100 + 0x18);
			if (���Ƴ��� >= 0x10)
			{
				Temp = *(DWORD*)(���ƶ��� + 0x104);
				�б�[g_��ѧ��������].p���� = (char*)Temp;
			}
			else
			{
				�б�[g_��ѧ��������].p���� = (char*)(���ƶ��� + 0x104);
			}
			strcpy_s(�б�[g_��ѧ��������].pgbk����, �б�[g_��ѧ��������].p����);
			BIGTOGBK(�б�[g_��ѧ��������].pgbk����);





			g_��ѧ��������++;

			c�ݹ����(������);
			c�ݹ����(������);

		}

	}
	__except (1)
	{
		OutputDebuggingInformation("��������   ��ȡ��ѧ���ܱ�����Ϣ�쳣2\r\n");
	}

}


DWORD g_�������� = 0;
void T�������::c��ʼ��()
{

	__try
	{

		g_�������� = 0;
		T�������� a;
		a.c��ʼ��();
		DWORD Temp = *(DWORD*)(a.d���� + 0xC);
		Temp = *(DWORD*)(Temp + 0x3C4);
		Temp = *(DWORD*)(Temp + 0xC + 4);
		DWORD ���ڵ� = *(DWORD*)(Temp + 0x4);
		c�ݹ����(���ڵ�);
		d���� = g_��������;
		OutputDebuggingInformation("��������   ��������:%d\r\n", d����);

	}
	__except (1)
	{
		OutputDebuggingInformation("��������   ��ȡ���������Ϣ�쳣\r\n");
	}

}



void T�������::c�ݹ����(DWORD �ڵ�)
{
	__try
	{

		DWORD ������ = *(DWORD*)(�ڵ� + 0x0);
		DWORD ������ = *(DWORD*)(�ڵ� + 0x8);
		BYTE ��־λ = *(BYTE*)(�ڵ� + 0x11);
		if (��־λ == 0)
		{
			�б�[g_��������].wID = *(WORD*)(�ڵ� + 0xC);
			�б�[g_��������].w��ɶ� = *(WORD*)(�ڵ� + 0xE);
			�б�[g_��������].d���� = �ڵ�;


			g_��������++;

			c�ݹ����(������);
			c�ݹ����(������);
		}

	}
	__except (1)
	{
		OutputDebuggingInformation("��������   ��ȡ���������Ϣ�쳣2\r\n");
	}

}






DWORD g_��������� = 0;
void T��������::c��ʼ��()
{

	__try
	{
		g_��������� = 0;
		DWORD Temp = *(DWORD*)(0x17E928C + 4);
		DWORD ���ڵ� = *(DWORD*)(Temp + 0x4);
		c�ݹ����(���ڵ�);
		d���� = g_���������;
		OutputDebuggingInformation("��������   ���������:%d\r\n", d����);

	}
	__except (1)
	{
		OutputDebuggingInformation("��������   ��ȡ����������Ϣ�쳣\r\n");
	}

}



void T��������::c�ݹ����(DWORD �ڵ�)
{
	__try
	{
		DWORD ������ = *(DWORD*)(�ڵ� + 0x0);
		DWORD ������ = *(DWORD*)(�ڵ� + 0x8);
		BYTE ��־λ = *(BYTE*)(�ڵ� + 0x15);
		DWORD Temp;
		if (��־λ == 0)
		{

			�б�[g_���������].d���� = *(DWORD*)(�ڵ� + 0x10);
			�б�[g_���������].wID = *(WORD*)(�б�[g_���������].d���� + 0x18);


			DWORD ���Ƴ��� = *(DWORD*)(�б�[g_���������].d���� + 0x1C + 0x18);
			if (���Ƴ��� >= 0x10)
			{
				Temp = *(DWORD*)(�б�[g_���������].d���� + 0x1C + 4);
				�б�[g_���������].p���� = (char*)Temp;
			}
			else
			{
				�б�[g_���������].p���� = (char*)(�б�[g_���������].d���� + 0x1C + 4);
			}
			strcpy_s(�б�[g_���������].pgbk����, �б�[g_���������].p����);
			BIGTOGBK(�б�[g_���������].pgbk����);


			g_���������++;

			c�ݹ����(������);
			c�ݹ����(������);
		}

	}
	__except (1)
	{
		OutputDebuggingInformation("��������   ��ȡ����������Ϣ�쳣2\r\n");
	}

}