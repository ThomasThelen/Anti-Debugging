#include <Windows.h>

int main()
{
	// Make sure there isn't an error state
	SetLastError(0);
	// Send a string to the debugger
	OutputDebugStringA("Hello, debugger");
	if (GetLastError() != 0)
	{
		MessageBoxA(NULL, "Debugger Detected", "", MB_OK);
	}
	return 0;
}
