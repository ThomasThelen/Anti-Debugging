[![Project Status: Active – The project has reached a stable, usable state and is being actively developed.](http://www.repostatus.org/badges/latest/active.svg)](http://www.repostatus.org/#active)  [![license](https://img.shields.io/github/license/mashape/apistatus.svg)]()  

Each directory represents a different that can be used to reinforce anti-debugging/anti-cracking. Each technique, can of course, be bypassed.

### IsDebuggerPresent
The most trivial way to check if a debugger is present is by calling `IsDebuggerPresent`. Internally, IsDebuggerPresent checks a flag in the Process Environment Block (PEB). The address of the PEB can be found in the Thread Information Block, which can be found in the FS register. Most software do not soley rely on this method as it can easily be bypassed by jumping over the `cmp` instruction.

[MSDN Documentation](https://msdn.microsoft.com/en-us/library/windows/desktop/ms680345(v=vs.85).aspx)

    BOOL WINAPI IsDebuggerPresent(void);
    
### CheckRemoteDebuggerPresent
When access to the program is limited, it cna be checked remotely with CheckRemoteDebuggerPresent. The function acts as a wrapper to `NtQueryInformationProcess`, which provides infomration about a specified process. One piece of infomration that can be extracted are the available debug ports. When the number is non-zero, a debugger is attached to the process. This again is easily bypassed and software rarely relies on it to stop reverse engineers.

[MSDN Documentation](https://msdn.microsoft.com/en-us/library/windows/desktop/ms679280%28v=vs.85%29.aspx)

    BOOL WINAPI CheckRemoteDebuggerPresent(
    _In_    HANDLE hProcess,
    _Inout_ PBOOL  pbDebuggerPresent
    );

### ReadTeb
Reads the `BeingDebugged` field in the Process Environment Block(PEB). One way to determine the address of the PEB is by reading offset 0x30 from the Thread Information Block(TIB), which is obtained from the FS segment register. This is how `IsDebuggerPresent`  works internally. Instead of calling `IsDebuggerPresent`, some software will manually perform this check. It can be bypassed the same way a call to `IsDebuggerPresent` is.

### OutputDebugString
The Windows API allows for printing debug statements out to a debugger, and will set an error if a debugger is not found. This is used by attempting to send a message to an attached debugger and checking for errors to determine if one is attached.
[MSDN Documentation](https://msdn.microsoft.com/en-us/library/windows/desktop/aa363362(v=vs.85).aspx)

void WINAPI OutputDebugString(
	_In_opt_ LPCTSTR lpOutputString
	);

### FindWindow
Instead of using debug specific APIs, if the window name of the debugger is known it can be searched for via FindWindow. Software/malware can search for window titles such as `OllyDbg`, `x64dbg`, `Soft Ice`, etc.
[MSDN Documentation](https://msdn.microsoft.com/en-us/library/windows/desktop/ms633499%28v=vs.85%29.aspx)

    HWND WINAPI FindWindow(
    _In_opt_ LPCTSTR lpClassName,
    _In_opt_ LPCTSTR lpWindowName
    );



	
	

