#include <iostream>
#include <Windows.h>

int main()
{
    std::cout << "Checking presence of a debugger!\n";
    __try {
        DebugBreak();
    }
    __except (GetExceptionCode() == EXCEPTION_BREAKPOINT ?
        EXCEPTION_EXECUTE_HANDLER : EXCEPTION_CONTINUE_SEARCH) {
        std::cout << "No debugger attached...\n";
    }
}
