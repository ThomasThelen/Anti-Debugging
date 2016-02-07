// ReadTEB.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include <Windows.h>
using namespace std;

int CheckTEB();


int _tmain(int argc, _TCHAR* argv[])
{
	if (CheckTEB())
		MessageBoxA(NULL, "Debugger Detected", "", MB_OK);
	system("pause");
	return 0;
}

int CheckTEB()
{
	int debugger_flag = 0;
	int a;
	__asm
	{
		mov eax, fs:[30h]
		push ecx
		mov ecx, [eax+2]
		mov a, ecx
		pop ecx

	}
	return a;
}