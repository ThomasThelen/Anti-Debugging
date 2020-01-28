
## Background


This method is supposed to be used when checking another process for the presence of a debugger. There's a bit of leg work to go from the name of the process to the actual process ID. I abstracted all of that crap into a Process class.

#### Relevant Links

https://docs.microsoft.com/en-us/windows/win32/api/tlhelp32/nf-tlhelp32-createtoolhelp32snapshot