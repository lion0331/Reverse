#pragma once

#include <Windows.h>

struct T��������
{
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
	DWORD dѪ��;
	DWORD d���Ѫ��;
	FLOAT fX;
	FLOAT fY;
	FLOAT fZ;
	DWORD dID;
	DWORD d����;
	FLOAT f����;
	char* p����;
	char pgbk����[100];
	void c��ʼ��();

};


struct Tȡ�����������
{

	T�������� �б�[0x1000];
	DWORD d����;
	void c��ʼ��();

};


struct T��Χ����
{

	T�������� �б�[0x1000];
	DWORD d����;
	void c��ʼ��();
	T�������� c�����������();

};



struct T������Ʒ
{
	DWORD dID;
	WORD w����;
	WORD w�������;
	DWORD d����;
	DWORD dλ��;
	DWORD d���ڱ���;
	char* p����;
	char pgbk����[100];
};


struct T������Ʒ����
{
	T������Ʒ �б�[0x1000];
	DWORD d����;
	void c��ʼ��();
	void c�ݹ����(DWORD);

};

struct T������ȴ
{
	DWORD dID;
	FLOAT f��ȴʱ��;
	char* p����;
	char pgbk����[100];
};


struct T������ȴ����
{
	T������ȴ �б�[0x1000];
	DWORD d����;
	void c��ʼ��();
	void c�ݹ����(DWORD);
};


struct T��ѧ���ܱ���
{
	T������ȴ �б�[0x1000];
	DWORD d����;
	void c��ʼ��();
	void c�ݹ����(DWORD);
};


struct T����
{
	WORD wID;
	WORD w��ɶ�;
	DWORD d����;
	char* p����;
	char pgbk����[100];
};


struct T�������
{
	T���� �б�[0x1000];
	DWORD d����;
	void c��ʼ��();
	void c�ݹ����(DWORD);

};

struct T��������
{
	T���� �б�[0x1000];
	DWORD d����;
	void c��ʼ��();
	void c�ݹ����(DWORD);

};