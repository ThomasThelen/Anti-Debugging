# AntiDebugging
This is a collection of short snippets that are/can be used to detect if a debugger is attached to a process.  

CheckRemoteDebuggerPresent

Any process including your own can be checked for attached debuggers by using CheckRemoteDebuggerPresent.

[MSDN Documentation](https://msdn.microsoft.com/en-us/library/windows/desktop/ms679280%28v=vs.85%29.aspx)

    BOOL WINAPI CheckRemoteDebuggerPresent(
    _In_    HANDLE hProcess,
    _Inout_ PBOOL  pbDebuggerPresent
    );

FindWindow

The FindWindow check works by searching the current window's properties for the name of a specified debugger/reversing tool. 

[MSDN Documentation](https://msdn.microsoft.com/en-us/library/windows/desktop/ms633499%28v=vs.85%29.aspx)

    HWND WINAPI FindWindow(
    _In_opt_ LPCTSTR lpClassName,
    _In_opt_ LPCTSTR lpWindowName
    );

You can, for example, search for the title of a debugger and determine its presence based on the return value. 

IsDebuggerPresent

[MSDN Documentation](https://msdn.microsoft.com/en-us/library/windows/desktop/ms680345(v=vs.85).aspx)

    BOOL WINAPI IsDebuggerPresent(void);

ReadTeb

Reads the BeingDebugged field in the Process Environment Block(PEB). One way to determine the address of the PEB is by reading offset 0x30 from the Thread Information Block(TIB), which is obtained from the fs segment register. 

OutputDebugString
[MSDN Documentation](https://msdn.microsoft.com/en-us/library/windows/desktop/aa363362(v=vs.85).aspx)

void WINAPI OutputDebugString(
	_In_opt_ LPCTSTR lpOutputString
	);
	
	

