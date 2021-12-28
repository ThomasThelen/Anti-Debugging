#include <windows.h>

int main(int argc, char** argv)
{
	//! IsDebuggerPresent will return 0 if one wasn't found
	if (IsDebuggerPresent()) {
		MessageBoxA(NULL, "There is currently a debugger attached to the process.", "Error: Debugger", MB_OK);
	}
	else {
		MessageBoxA(NULL, "No debugger detected.", "Debugger", MB_OK);
	}
	return 0;
}
