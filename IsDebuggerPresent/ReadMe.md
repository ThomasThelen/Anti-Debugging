## Checking for a Debugger with IsDebuggerPresent


### Background

The most basic check a software developer can do to check for the presence of a debugger is with Window's built in IsDebuggerPresent. The method is located in Kernel32.dll and interfaced with IsDebuggerPresent, which exists in Windows.h


### Source Code

In order to call IsDebuggerPresent we need to include Windows.h. Doing this will vary based on your tool chain or IDE. 

There isn't much to the actual code when it comes to calling this method. From the MSDN page (see link below), we see that the call takes no arguments and returns

```
If the current process is running in the context of a debugger, the return value is nonzero.

If the current process is not running in the context of a debugger, the return value is zero.

```


#### Relevant Links
[MSDN Page](https://docs.microsoft.com/en-us/windows/win32/api/debugapi/nf-debugapi-isdebuggerpresent)

[More Examples](https://github.com/search?q=IsDebuggerPresent)
