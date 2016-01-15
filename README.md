# AntiDebugging
These projects demonstrate ways of cheicking if a debugger is running. The project names correspond to the main windows API function call used.

CheckRemoteDebuggerPresent
[MSDN Documentation](https://msdn.microsoft.com/en-us/library/windows/desktop/ms679280%28v=vs.85%29.aspx)

    BOOL WINAPI CheckRemoteDebuggerPresent(
    _In_    HANDLE hProcess,
    _Inout_ PBOOL  pbDebuggerPresent
    );

FindWindow
[MSDN Documentation](https://msdn.microsoft.com/en-us/library/windows/desktop/ms633499%28v=vs.85%29.aspx)

    HWND WINAPI FindWindow(
    _In_opt_ LPCTSTR lpClassName,
    _In_opt_ LPCTSTR lpWindowName
    );

IsDebuggerPresent
[MSDN Documentation](https://msdn.microsoft.com/en-us/library/windows/desktop/ms680345(v=vs.85).aspx)
    BOOL WINAPI IsDebuggerPresent(void);
    
