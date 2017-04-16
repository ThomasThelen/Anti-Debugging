// FindWindow.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<Windows.h>

int main()
{
	LPCWSTR window = L"x64dbg"; //! Window name of the debugger you are checking for
	if (FindWindow(NULL, window))
	{
		MessageBoxA(NULL, "Debugger Found", "Notification", MB_OK);
	}
	return 0;
}