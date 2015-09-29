// CheckRemoteDebuggerPresent.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <Windows.h>
#include "Tlhelp32.h"
#include <wchar.h>
using namespace std;

class process
{
public:
	void FindProcessID(wchar_t[256]);
	void SetPrivileges();
	wchar_t name[256];
	int pid;
	bool debuggeractive;
	HANDLE hSnapshot;
	PROCESSENTRY32 pEntry;
} proc;
/*
Because a handle is needed to the process-to-be-checked nad the PID
is not known, it must be found from the process name. This is 
achieved by taking a snapshot of the current processes and
iterating through the list until the user specified process
is found. Once found, the PID can be found.
*/
void process::FindProcessID(wchar_t processname[256])
{
	// Take a snapshot of current processes
	hSnapshot=CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);
	// Must set the size before calling Process32First (From MSDN)
	pEntry.dwSize = sizeof(PROCESSENTRY32);
	// Take the first entry and fill the PROCESSENTRY32 structure with its information
	Process32First(hSnapshot, &proc.pEntry);
	// Iterate through the list until the user specified process is obtained
	while (wcscmp(proc.pEntry.szExeFile, proc.name) != 0)
	{
	//	system("pause");
		Process32Next(proc.hSnapshot, &proc.pEntry);
	}
	// When it is obtained, save the PID
	proc.pid = proc.pEntry.th32ProcessID;
	// Clean up any handles
	CloseHandle(proc.hSnapshot);
}

void process::SetPrivileges()
{
	HANDLE hToken, hProcess;
	TOKEN_PRIVILEGES tokenPriv;
	hProcess=OpenProcess(PROCESS_ALL_ACCESS, NULL, GetCurrentProcessId());
	tokenPriv.PrivilegeCount = 1;
	LookupPrivilegeValue(NULL, _T("SeDebugPrivilege"), &tokenPriv.Privileges[0].Luid);
	tokenPriv.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;
	OpenProcessToken(hProcess, TOKEN_ADJUST_PRIVILEGES, &hToken);
	AdjustTokenPrivileges(hToken, FALSE, &tokenPriv, NULL, NULL, NULL);
	CloseHandle(hToken);
	CloseHandle(hProcess);
}

int _tmain(int argc, _TCHAR* argv[])
{
	BOOL isenabled;
	cout << "Enter Process Name: " << endl;
	char *ass;
	wcin >> proc.name;
	proc.FindProcessID(proc.name);

	HANDLE processHandle=OpenProcess(PROCESS_ALL_ACCESS, NULL, proc.pid);
	CheckRemoteDebuggerPresent(processHandle, &isenabled);
	if (isenabled == TRUE)
	{
		cout << "Debugger is attached");
	}
	else
	{
		cout << "Debugger not detected" << endl;
	}
	return 0;
}

