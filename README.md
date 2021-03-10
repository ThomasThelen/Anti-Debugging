![alt text](https://github.com/ThomasThelen/AntiDebugging/raw/master/anti-debug.png)
[![Project Status: Active – The project has reached a stable, usable state and is being actively developed.](http://www.repostatus.org/badges/latest/active.svg)](http://www.repostatus.org/#active)  [![license](https://img.shields.io/github/license/mashape/apistatus.svg)]()
[![Maintenance](https://img.shields.io/badge/Maintained%3F-yes-green.svg)](https://GitHub.com/Naereen/StrapDown.js/graphs/commit-activity)
[![HitCount](http://hits.dwyl.com/thomasthelen/zipline-bokeh.svg)](http://hits.dwyl.com/thomasthelen/zipline-bokeh)

When developing software, it's sometimes necessary to check, at runtime
if the application is running under the presence of a debugger.
_Sometimes_, the goal is to stop the application from running under a
debugger to slow reversing attempts. Conversely, a reverse engineer may
run across the checks that the developer placed.

This repository hosts code that shows some of the trivial ways that are
commonly encountered in the wild. Note that bypassing this class of
check has been almost entirely automated by modern disassemblers.


### Checking Your Own Process
[IsDebuggerPresent](./IsDebuggerPresent/ReadMe.md) - Basic Win32 API
call to check for the presence of a debugger

[OutputDebugString](./OutputDebugString/ReadMe.md) - Use the Win32 API
to tryto communicate with a potentially attached debugger

[FindWindow](./FindWindow/ReadMe.md) - Use the Win32 API to search for
debugger windows

[ReadTEB](./ReadTEB/ReadMe.md) - A brief look at the internals of
IsDebuggerPresent

[DebugBreak](./DebugBreak/ReadMe.md) - A win32 call that will throw when a debugger isn't attached (sounds weird I know).

### Checking Other Processes
[CheckRemoteDebuggerPresent](./IsDebuggerPresent/ReadMe.md) - IsDebuggerPresent for external processes

### References and Other Repositories

[Anti Reverse Engineering Protection Techniques to Use Before Releasing
Software](https://www.apriorit.com/dev-blog/367-anti-reverse-engineering-protection-techniques-to-use-before-releasing-software)

