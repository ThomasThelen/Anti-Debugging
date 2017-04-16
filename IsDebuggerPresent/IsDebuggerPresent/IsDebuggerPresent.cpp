// IsDebuggerPresent.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include <windows.h>

int main(int argc, char** argv)
{
	if (IsDebuggerPresent())
	{
		MessageBoxA(NULL, "There is currently a debugger attached to the process.", "Error: Debugger", MB_OK);
	}
	return 0;
}
