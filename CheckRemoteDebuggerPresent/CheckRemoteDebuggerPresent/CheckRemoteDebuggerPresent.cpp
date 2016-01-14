#include "stdafx.h"
#include <iostream>
#include <Windows.h>
#include "Tlhelp32.h"
#include <wchar.h>

class Process
{
public:
	wchar_t name[256];
	BOOL is_detected;
	void IsDbgPresent();

private:
	int pid;
	HANDLE hSnapshot;
	PROCESSENTRY32 pEntry;
	void FindProcessID();
	void SetPrivileges();
};
/*
Because a handle is needed to the process-to-be-checked and the PID
is not known, it must be found from the process name. This is 
achieved by taking a snapshot of the current processes and
iterating through the list until the user specified process
is found. Once found, the PID can be extracted.
*/
void Process::FindProcessID()
{
	hSnapshot=CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);	// Take a snapshot of current processes
	pEntry.dwSize = sizeof(PROCESSENTRY32);	// Must set the size before calling Process32First (From MSDN)
	Process32First(hSnapshot, &pEntry);	// Take the first entry and fill the PROCESSENTRY32 structure with its information
	while (wcscmp(pEntry.szExeFile, name) != 0)	// Iterate through the list until the user specified process is obtained
	{
		Process32Next(hSnapshot, &pEntry);
	}
	pid = pEntry.th32ProcessID;	// When it is obtained, save the PID
	CloseHandle(hSnapshot);	// Clean the handle to the snapshot
}
/*
Set the current process's privileges to debug
*/
void Process::SetPrivileges()
{
	HANDLE hToken, hProcess;
	TOKEN_PRIVILEGES tokenPriv;
	hProcess = OpenProcess(PROCESS_ALL_ACCESS, NULL, GetCurrentProcessId());
	tokenPriv.PrivilegeCount = 1;
	LookupPrivilegeValue(NULL, _T("SeDebugPrivilege"), &tokenPriv.Privileges[0].Luid);
	tokenPriv.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;
	OpenProcessToken(hProcess, TOKEN_ADJUST_PRIVILEGES, &hToken);
	AdjustTokenPrivileges(hToken, FALSE, &tokenPriv, NULL, NULL, NULL);
	CloseHandle(hToken);
	CloseHandle(hProcess);
}
void Process::IsDbgPresent()
{

	Process::FindProcessID();
	Process::SetPrivileges();
	HANDLE processHandle = OpenProcess(PROCESS_ALL_ACCESS, NULL, pid);
	CheckRemoteDebuggerPresent(processHandle, &is_detected);
}

int main()
{
	Process process;
	std::cout << "Enter Process Name: " << std::endl;
	std::wcin >> process.name;
	process.IsDbgPresent();
	if (process.is_detected == TRUE)
	{
		std::cout << "Debugger is attached"<< std::endl;
	}
	else
	{
		std::cout << "Debugger not detected" << std::endl;
	}
	system("pause");
	return 0;
}

