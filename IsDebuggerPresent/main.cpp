#include <iostream>
#include <windows.h>
#include <winbase.h>
#include <String>

/*
Uses the return value of IsDebuggerPresent to make the check. 
*/

int main(int argc, char** argv)
{
	
	if (IsDebuggerPresent() == TRUE)
	{
		MessageBoxA(NULL, "There is currently a debugger attached to the process.", "Error: Debugger", MB_OK);
		return 0;
	}
	else
	MessageBoxA(NULL,"No Debugger Found", "Okay!", MB_OK);
	return 0;
}
