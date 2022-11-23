﻿// SkillDialog.cpp: 实现文件
//

#include "pch.h"
#include "Torchlight2.h"
#include "SkillDialog.h"
#include "afxdialogex.h"
#include "afxdialogex.h"
#include <Windows.h>
#include <vector>
#include <Time.h>


// SkillDialog 对话框

IMPLEMENT_DYNAMIC(SkillDialog, CDialogEx)

SkillDialog::SkillDialog(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_Two, pParent)
{

}

SkillDialog::~SkillDialog()
{
}

void SkillDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(SkillDialog, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &SkillDialog::OnBnClickedButton1)
END_MESSAGE_MAP()


// SkillDialog 消息处理程序
int SearchMemory(HANDLE hProcess, WORD FeatureCode[], BYTE FeatureCodeSize, DWORD64 StartAddress, DWORD64 EndAddress, std::vector<DWORD64>& ResultArray)
{
	MEMORY_BASIC_INFORMATION MemoryInformation;
	FeatureCodeSize -= 1;
	while (VirtualQueryEx(hProcess, (LPCVOID)StartAddress, &MemoryInformation, sizeof(MemoryInformation)))
	{
		if (MemoryInformation.State == MEM_COMMIT && MemoryInformation.Protect == PAGE_EXECUTE_READWRITE || MemoryInformation.Protect == PAGE_READWRITE)
		{
			BYTE* MemoryData = new BYTE[MemoryInformation.RegionSize];

			if (!ReadProcessMemory(hProcess, MemoryInformation.BaseAddress, MemoryData, MemoryInformation.RegionSize, nullptr))
			{
				return 0;
			}
			MemoryInformation.RegionSize -= FeatureCodeSize;
			for (int v = 0; v < MemoryInformation.RegionSize; v++)
			{
				for (int i = 0; i <= FeatureCodeSize; i++)
				{
					if (MemoryData[v + i] != FeatureCode[i] && FeatureCode[i] <= 255)
					{
						break;
					}
					if (i == FeatureCodeSize)
					{
						ResultArray.push_back((DWORD64)MemoryInformation.BaseAddress + v);
						i += FeatureCodeSize + 1;
					}

				}
			}
			delete[] MemoryData;
		}
		StartAddress = (DWORD64)MemoryInformation.BaseAddress + MemoryInformation.RegionSize + FeatureCodeSize;
		if (StartAddress >= EndAddress)
		{
			return ResultArray.size();
		}
	}
	return 0;
}


void SkillDialog::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	//ULONG_PTR _Stat = (ULONG_PTR)GetModuleHandleA("Torchlight2.exe");
	//_Stat = (ULONG_PTR)(_Stat + 0x00184170);

	//ULONG_PTR _ECX = (ULONG_PTR)GetModuleHandleA("Torchlight2.exe");
	//_ECX = *(ULONG_PTR*)(_ECX + 0x024E95F4);
	//_ECX = *(ULONG_PTR*)(_ECX + 0x2C);

	//ULONG_PTR ECX_ = (ULONG_PTR)GetModuleHandleA("Torchlight2.exe");
	//ECX_ = *(ULONG_PTR*)(ECX_ + 0x0337EFC8);
	//ECX_ = *(ULONG_PTR*)(ECX_ + 0x9C);
	//ECX_ = *(ULONG_PTR*)(ECX_ + 0x40);
	//ECX_ = (ULONG_PTR)(ECX_ + 0xD8C);

	//__asm {
	//	push _ECX
	//	mov ecx, ECX_
	//	mov eax, _Stat
	//	call eax
	//}
	WORD FeatureCode[4] = { 0x63,0x84,0x7F,0x53 };
	std::vector<DWORD64>ResultArray;
	float Start = clock();
	SearchMemory(this, FeatureCode, 4, 0x41000, 0x7FFFFFFFF, ResultArray);
	float End = clock();
	CString str[1024];
	for (int i = 0; i < ResultArray.size(); i++)
	{

		printf("%X\n", ResultArray[i]);

	}
	printf("搜索到%d个内存地址,用时%f毫秒", ResultArray.size(), End - Start);
}
