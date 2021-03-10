## Checking for a Debugger with IsDebuggerPresent


### Background

IsDebuggerPresent is a method that's located inside the Windows.h header. Behind the scenes, it checks a particular struct (the PEB) for the [BeingDebugged flag](https://www.aldeid.com/wiki/PEB-Process-Environment-Block/BeingDebugged). If it's set, then IsDebuggerPresent returns something that's _not_ 0.

#### Relevant Links
[MSDN Page](https://docs.microsoft.com/en-us/windows/win32/api/debugapi/nf-debugapi-isdebuggerpresent)

[More Examples](https://github.com/search?q=IsDebuggerPresent)
