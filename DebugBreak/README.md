## Checking for a Debugger with DebugBreak


### Background

This is kind of a weird one. If a debugger _isn't__ attached, an exception is thrown which is why the the call in in a try/catch block. If it _doesn't_ throw, then
a debugger is attached to the process.


#### Relevant Links
[MSDN Page](https://docs.microsoft.com/en-us/windows/win32/api/debugapi/nf-debugapi-debugbreak?redirectedfrom=MSDN)