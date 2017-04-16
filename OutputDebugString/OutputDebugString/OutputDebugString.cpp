// OutputDebugString.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <Windows.h>

int main()
{
	SetLastError(0);
	OutputDebugStringA("Is there a debugger?");
	if (GetLastError() != 0)
	{
		MessageBoxA(NULL, "Debugger Detected", "", MB_OK);
	}
	return 0;
}
