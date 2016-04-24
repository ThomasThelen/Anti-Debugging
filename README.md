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

IsDebuggerPresent

[MSDN Documentation](https://msdn.microsoft.com/en-us/library/windows/desktop/ms680345(v=vs.85).aspx)

    BOOL WINAPI IsDebuggerPresent(void);
    
ReadTEB


OutputDebugString



