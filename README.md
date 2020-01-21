![alt text](https://github.com/ThomasThelen/AntiDebugging/raw/master/anti-debug.png)
[![Project Status: Active – The project has reached a stable, usable state and is being actively developed.](http://www.repostatus.org/badges/latest/active.svg)](http://www.repostatus.org/#active)  [![license](https://img.shields.io/github/license/mashape/apistatus.svg)]()  


When developing software, it's sometimes necessary to thwart attempts to reverse engineer your program. While reverse engineering software, it's common to run across code that attempts you from reversing.

This repository hosts code that shows some fairly basic ways that developers can check for attached debuggers. If you're a reverse engineer, these are thing things that you'll need to bypass.

This is in no way an exhaustive list, but may be a handy reference.


### Checking Your Own Process
[IsDebuggerPresent](./IsDebuggerPresent/ReadMe.md) - Most basic check

[OutputDebugString](./OutputDebugString/ReadMe.md) - Attempt to communicate with an attached debugger

[FindWindow](./FindWindow/ReadMe.md) - Search for debugger windows

[ReadTEB](./ReadTEB/ReadMe.md) - Internals of IsDebuggerPresent

### Checking Other Processes
[CheckRemoteDebuggerPresent](./IsDebuggerPresent/ReadMe.md) - IsDebuggerPresent for external processes

### References and Other Repositories

[Tool whose source code can be checked out](https://github.com/secrary/makin)

