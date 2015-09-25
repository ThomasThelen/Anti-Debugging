#include <iostream>
#include <windows.h>
#include <winbase.h>
#include <String>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	std::string aaa="Chance";
	if (IsDebuggerPresent() == TRUE)
	{
		MessageBoxA(NULL, aaa.c_str(), "Error: Debugger", MB_OK);
		return 0;
	}
	else
	MessageBoxA(NULL,"No Debugger Found", "Okay!", MB_OK);
	return 0;
}
