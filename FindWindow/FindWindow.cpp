#include<Windows.h>

int main()
{
	//! Windows types suck. You could make a std::wchar and convert it with .c_str()
	LPCSTR windowName ="x64dbg"; //! Window name of the debugger you are checking for
	//! LPCWSTR windowName = L"OllyDbg, IDA Pro, etc";

	//! Recall that FindWindow will return NULL if it wasn't found
	if (FindWindow(NULL, windowName))
	{
		MessageBoxA(NULL, "Debugger Found", "Notification", MB_OK);
	}
	return 0;
}