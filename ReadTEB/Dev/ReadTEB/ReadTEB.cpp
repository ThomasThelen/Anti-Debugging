// ReadTEB.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include <Windows.h>


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
	__asm
	{
		mov eax, fs:[30h]
		push ecx // Because we are going to store the value in ecx, presere it on the stack
		mov ecx, [eax+2]
		mov debugger_flag, ecx
		pop ecx // Take ecx back off the stack

	}
	return debugger_flag;
}