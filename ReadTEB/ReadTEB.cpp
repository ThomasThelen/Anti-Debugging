#include<iostream>
#include <Windows.h>

int CheckTEB()
{
	int isBeingDebugged=0;
	__asm
	{
		; Grab the PEB at offset 30 of the fs register
		mov eax, fs:[30h]
		; push it to the stack 
		push ecx
		; Grab the IsBeingDebugged flag out of the PED
		mov ecx, [eax+2]
		mov isBeingDebugged, ecx
		pop ecx
	}
	return isBeingDebugged;
}

int main()
{
	if (CheckTEB())
	{
		MessageBoxA(NULL, "Debugger Detected", "", MB_OK);
	}
	return 0;
}

