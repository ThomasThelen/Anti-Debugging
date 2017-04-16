#include "stdafx.h"
#include <iostream>
#include <Windows.h>
#include "Tlhelp32.h"
#include <wchar.h>

namespace
{
	class Process
	{
	public:
		//! Returns true when a debugger is detected, false otherwise
		bool IsDbgPresent();
		//! The name of the process that we're checking
		wchar_t m_processName[256];

	private:
		int m_pid;
		HANDLE m_hSnapshot;
		PROCESSENTRY32 m_processEntry;
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
		m_hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);	// Take a snapshot of current processes
		m_processEntry.dwSize = sizeof(PROCESSENTRY32);	// Must set the size before calling Process32First (From MSDN)
		Process32First(m_hSnapshot, &m_processEntry);	// Take the first entry and fill the PROCESSENTRY32 structure with its information
		while (wcscmp(m_processEntry.szExeFile, m_processName) != 0)	// Iterate through the list until the user specified process is obtained
		{
			Process32Next(m_hSnapshot, &m_processEntry);
		}
		m_pid = m_processEntry.th32ProcessID;	// When it is obtained, save the PID
		CloseHandle(m_hSnapshot);	// Clean the handle to the snapshot
	}
	/*
	Set the current process's privileges to debug
	*/
	void Process::SetPrivileges()
	{
		HANDLE hToken;
		TOKEN_PRIVILEGES tokenPriv;
		auto hProcess = OpenProcess(PROCESS_ALL_ACCESS, NULL, GetCurrentProcessId());
		tokenPriv.PrivilegeCount = 1;
		LookupPrivilegeValue(NULL, _T("SeDebugPrivilege"), &tokenPriv.Privileges[0].Luid);
		tokenPriv.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;
		OpenProcessToken(hProcess, TOKEN_ADJUST_PRIVILEGES, &hToken);
		AdjustTokenPrivileges(hToken, FALSE, &tokenPriv, NULL, NULL, NULL);
		CloseHandle(hToken);
		CloseHandle(hProcess);
	}

	bool Process::IsDbgPresent()
	{
		Process::FindProcessID();
		Process::SetPrivileges();
		HANDLE processHandle = OpenProcess(PROCESS_ALL_ACCESS, NULL, m_pid);
		PBOOL isDetected = false;
		CheckRemoteDebuggerPresent(processHandle, isDetected);
		return isDetected;
	}
}

int main()
{
	Process process;
	std::cout << "Enter Process Name: " << std::endl;
	std::wcin >> process.m_processName;
	
	if (process.IsDbgPresent())
	{
		std::cout << "Debugger is attached" << std::endl;
	}
	return 0;
}