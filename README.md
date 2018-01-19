[![Project Status: Active – The project has reached a stable, usable state and is being actively developed.](http://www.repostatus.org/badges/latest/active.svg)](http://www.repostatus.org/#active)  [![license](https://img.shields.io/github/license/mashape/apistatus.svg)]()  [![GitHub last commit](https://img.shields.io/github/last-commit/google/skia.svg)]() [![GitHub code size in bytes](https://img.shields.io/github/languages/code-size/badges/shields.svg)]()


This is a collection of short snippets that are/can be used to detect if a debugger is attached to a process.  

### IsDebuggerPresent
Perhaps the most trivial way of checking if a process is being run under a debugger is by calling IsDebuggerPresent. Internally, IsDebuggerPresent checks a flag in the Process Environment Block (PEB). The address of the PEB can be found in the Thread Information Block, which can be found in the FS register. 

[MSDN Documentation](https://msdn.microsoft.com/en-us/library/windows/desktop/ms680345(v=vs.85).aspx)

    BOOL WINAPI IsDebuggerPresent(void);
    
### CheckRemoteDebuggerPresent
When access to the program is limited, it cna be checked remotely with CheckRemoteDebuggerPresent. The function acts as a wrapper to NtQueryInformationProcess, which provides infomration about a specified process. One piece of infomration that can be extracted are available debug ports. When the number iis non-zero, a debugger is attached to the process.

[MSDN Documentation](https://msdn.microsoft.com/en-us/library/windows/desktop/ms679280%28v=vs.85%29.aspx)

    BOOL WINAPI CheckRemoteDebuggerPresent(
    _In_    HANDLE hProcess,
    _Inout_ PBOOL  pbDebuggerPresent
    );

### ReadTeb
Reads the BeingDebugged field in the Process Environment Block(PEB). One way to determine the address of the PEB is by reading offset 0x30 from the Thread Information Block(TIB), which is obtained from the FS segment register. This is how IsDebuggerPresent  internally works.

### OutputDebugString
The Windows API allows for printing debug statements out to a debugger, and will set an error if a debugger is not found. This is used by attempting to send a message to an attached debugger and checking for errors to determine if one is attached.
[MSDN Documentation](https://msdn.microsoft.com/en-us/library/windows/desktop/aa363362(v=vs.85).aspx)

void WINAPI OutputDebugString(
	_In_opt_ LPCTSTR lpOutputString
	);

### FindWindow
Instead of using debug specific APIs, if the window name of the debugger is known it can be searched for via FindWindow.
[MSDN Documentation](https://msdn.microsoft.com/en-us/library/windows/desktop/ms633499%28v=vs.85%29.aspx)

    HWND WINAPI FindWindow(
    _In_opt_ LPCTSTR lpClassName,
    _In_opt_ LPCTSTR lpWindowName
    );



	
	

