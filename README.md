![alt text](https://github.com/ThomasThelen/AntiDebugging/raw/master/anti-debug.png)
[![Project Status: Active – The project has reached a stable, usable state and is being actively developed.](http://www.repostatus.org/badges/latest/active.svg)](http://www.repostatus.org/#active)  [![license](https://img.shields.io/github/license/mashape/apistatus.svg)]()
[![HitCount](http://hits.dwyl.com/thomasthelen/zipline-bokeh.svg)](http://hits.dwyl.com/thomasthelen/zipline-bokeh)


When developing software, it's sometimes necessary to thwart attempts to reverse engineer your program. While reverse engineering software, it's common to run across code that attempts you from reversing.

This repository hosts code that shows some fairly basic ways that developers can check for attached debuggers. If you're a reverse engineer, these are thing things that you'll need to bypass.

At this point, there are fairly standard techniques for trying to prevent reverse engineering. There are books on it, many pdfs, research articles, and even entire websites that go in-depth into each method. This is in no way an exhaustive list, but may be worth a star if you are learning about this area and want additional code to reference.

Also note that I don't describe how the methods actually work. As mentioned, this has been done a bazillion times by a bazillion people. At the end of this page I have links to other resources that describe them in detail.


### Checking Your Own Process
[IsDebuggerPresent](./IsDebuggerPresent/ReadMe.md) - Most basic check

[OutputDebugString](./OutputDebugString/ReadMe.md) - Attempt to communicate with an attached debugger

[FindWindow](./FindWindow/ReadMe.md) - Search for debugger windows

[ReadTEB](./ReadTEB/ReadMe.md) - Internals of IsDebuggerPresent

[NtCreateThreadEx](./NtCreateThreadEx/Readme.md) - Run your code in another thread with debugging disables

### Checking Other Processes
[CheckRemoteDebuggerPresent](./IsDebuggerPresent/ReadMe.md) - IsDebuggerPresent for external processes

### References and Other Repositories

[Great guide to how these work and how to bypass them](https://www.apriorit.com/dev-blog/367-anti-reverse-engineering-protection-techniques-to-use-before-releasing-software)

[Scholarly paper on additional techniques](https://www.blackhat.com/presentations/bh-usa-07/Yason/Whitepaper/bh-usa-07-yason-WP.pdf)

