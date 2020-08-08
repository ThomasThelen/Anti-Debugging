## Checking for a Debugger with FindWindow


### Background

Checking for the presence of a debugger with `FindWindow` is probably
one of the most hacky ways to check if a debugger is watching your
program. The idea is that we know the names of many of the common
debuggers and the Windows API provides a method to check if a window
with a particular name exists. If there's a match, it means that there is most likely an
instance of that debugger running. It won't however, tell you if it's
attached to your process.


#### Relevant Links
[MSDN Page](https://docs.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-findwindowa)