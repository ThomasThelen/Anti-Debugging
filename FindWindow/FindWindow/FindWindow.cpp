/*

This method checks for a particular debuger. In this case it checks for x64dbg (http://x64dbg.com/).
Once detected, the programmer can choose how she wants to deal with its presence. This may include
termination of the program or a message sent to the user.
*/

#include "stdafx.h"
#include<Windows.h>
#include <string>

int main()
{
	LPCWSTR window = L"x64dbg";
	if (FindWindow(NULL, window) != NULL)
	{
		MessageBoxA(NULL, "Debugger Found", "Debugger Detected", MB_OK);
		return 1;
	}
	return 0;
}

