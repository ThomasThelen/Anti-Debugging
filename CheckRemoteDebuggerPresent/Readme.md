## Checking for a Debugger with CheckRemoteDebuggerPresent

### Background

Checking for the presence of a debugger with `FindWindow` is probably one of the most hacky ways to check 
if a debugger is watching your program. The idea is that we know the names of many of the common debuggers. 
The Windows API provides a method to check if a window with a particular name exists. This can be used with 
a list of debugger window names. If there's a match, it means that there is most likely an instance of that debugger 
running. It won't however, tell you if it's attached to your process.

### Source Code

In order to call FindWindow we need to include Windows.h. Doing this will vary based on your tool chain or IDE. 

There isn't much to the actual code when it comes to calling this method. From the MSDN page (see link below), we see that the call takes a few arguments and returns a handle.

```
HWND FindWindowA(
  LPCSTR lpClassName,
  LPCSTR lpWindowName
);

If the function succeeds, the return value is a handle to the window that has the specified class name and window name.

If the function fails, the return value is NULL. To get extended error information, call GetLastError.
```

Note from MSDN that

`If lpClassName is NULL, it finds any window whose title matches the lpWindowName parameter.`

In our case we want to search over all windows, so we'll set `lpClassName` to NULL.

``LPCSTR`` is an ugly type, but it's just a pointer to a C character string. FindWindow has no reason to modify either argument, so it wants them as const.

In the example, I define the name of with window with

`LPCWSTR windowName = L"x64dbg";`

and call the method with

`FindWindow(NULL, windowName)`

We'll either get a HANDLE to the window, or we'll get NULL which makes for an easy if statement.

#### Relevant Links
[MSDN Page](https://docs.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-findwindowa)