#include <iostream>

#include <Windows.h>
#include "Tlhelp32.h"
#include <wchar.h>

namespace
{
	/*
	A class that represents the process being checked.

	*/
	class Process
	{
	public:
		//! Returns true when a debugger is detected, false otherwise
		bool IsDbgPresent();
		//! The name of the process that we're checking
		wchar_t m_processName[256];

	private:
		//! PID of this process
		int m_pid;
		//! Handle to the snapshot
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
	    //! Get a list of all the running processes
		m_hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);
		//! Must set the size before calling Process32First (From MSDN)
		m_processEntry.dwSize = sizeof(PROCESSENTRY32);
		//! Take the first entry and fill the PROCESSENTRY32 structure with its information
		Process32First(m_hSnapshot, &m_processEntry);
		//! Convert char* to wchar_t*
		auto process_name = std::make_shared<wchar_t*>();
		mbstowcs(*process_name, m_processEntry.szExeFile, strlen(m_processEntry.szExeFile) + 1);
		//! Iterate through the list until the user specified process is obtained
		while (wcscmp(*process_name, m_processName) != 0)
		{
			Process32Next(m_hSnapshot, &m_processEntry);
		}
		//! When it is obtained, save the PID
		m_pid = m_processEntry.th32ProcessID;
		//! Clean the handle to the snapshot
		CloseHandle(m_hSnapshot);
	}

	bool Process::IsDbgPresent()
	{
		Process::FindProcessID();
		HANDLE processHandle = OpenProcess(PROCESS_ALL_ACCESS, NULL, m_pid);
		PBOOL isDetected = false;
		CheckRemoteDebuggerPresent(processHandle, isDetected);
		return isDetected;
	}
}

	/*
	Set the current process's privileges to debug. Note that this is being set on the process running THIS code.
	It's not setting it on the process being tested.
	*/
	void SetPrivileges()
	{
		HANDLE hToken;
		TOKEN_PRIVILEGES tokenPriv;

		//! Open the current process
		auto hProcess = OpenProcess(PROCESS_ALL_ACCESS, NULL, GetCurrentProcessId());
		tokenPriv.PrivilegeCount = 1;
		LookupPrivilegeValue(NULL, ("SeDebugPrivilege"), &tokenPriv.Privileges[0].Luid);
		tokenPriv.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;
		OpenProcessToken(hProcess, TOKEN_ADJUST_PRIVILEGES, &hToken);
		AdjustTokenPrivileges(hToken, FALSE, &tokenPriv, NULL, NULL, NULL);
		
		//! Make sure to clean up the hanldes
		CloseHandle(hToken);
		CloseHandle(hProcess);
	}

int main()
{
	SetPrivileges();
	Process process;
	std::cout << "Enter Process Name: " << std::endl;
	std::wcin >> process.m_processName;
	
	if (process.IsDbgPresent())
	{
		std::cout << "Debugger is attached" << std::endl;
	}
	return 0;
}