// ReadTEB.cpp : Defines the entry point for the console application.
//
#include"stdafx.h"
#include<iostream>
#include <C:\Program Files (x86)\Windows Kits\10\Include\10.0.15063.0\um\windows.h>


int main(int argc, char* argv[])
{
	auto checkTEB = []() {
		int debugger_flag = 0;
		__asm
		{
			mov eax, fs:[30h] //! The address to the PEB is located at position 0x30 in the TEB.
			push ecx //! Before using ecx, preserve it by pushing it on the stack
			mov ecx, [eax + 2] //! The BeingDebugged flag is located at the second byte in the PEB
			mov debugger_flag, ecx
			pop ecx //! Restore ecx to its original value
		}
		return debugger_flag;
	};

	if (checkTEB())
	{
		MessageBoxA(NULL, "Debugger Detected", "", MB_OK);
	}
	return 0;
}