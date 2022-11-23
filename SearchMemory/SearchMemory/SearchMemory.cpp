// SearchMemory.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include <Windows.h>
#include <vector>
#include <Time.h>
#include <iostream>

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


int main()
{
	HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, 6952);
	WORD FeatureCode[4] = { 0x63,0x84,0x7F,0x53 };
	std::vector<DWORD64>ResultArray;
	float Start = clock();
	SearchMemory(hProcess, FeatureCode, 4, 0x41000, 0x7FFFFFFFF, ResultArray);
	float End = clock();
	for (int i = 0; i < ResultArray.size(); i++)
	{

		printf("%X\n", ResultArray[i]);

	}
	printf("搜索到%d个内存地址,用时%f毫秒", ResultArray.size(), End - Start);
}

