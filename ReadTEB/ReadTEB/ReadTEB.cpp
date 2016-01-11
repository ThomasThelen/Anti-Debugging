// ReadTEB.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include <Windows.h>
#include<dbghelp.h>
#include <Wdbgexts.h>
#include <Dbgeng.h>
using namespace std;




//NtQueryInformationProcess->ProcessBasicInfo struct -> ReadProcessMemory(ProcessBasicInfo.PEBAddr)

int _tmain(int argc, _TCHAR* argv[])
{
	HANDLE token_handle;
	LUID luid;
	TOKEN_PRIVILEGES token_privs;
	wchar_t* exe_name;
	exe_name = L"notepad.exe";

	if (!OpenProcessToken(GetCurrentProcess(), TOKEN_ADJUST_PRIVILEGES | TOKEN_QUERY, &token_handle))
	{
		cout << "Could not open process token" << endl;
		return FALSE;
	}

	if (!LookupPrivilegeValue(NULL, SE_DEBUG_NAME, &luid))
	{
		cout << "Could not look up priviliges" << endl;
		return FALSE;
	}

	token_privs.PrivilegeCount = 1;
	token_privs.Privileges[0].Luid = luid;
	token_privs.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;

	if (!AdjustTokenPrivileges(token_handle, false, &token_privs, sizeof(token_privs), NULL, NULL))
	{
		cout << "Could not adjust the security token" << endl;
		return FALSE;
	}

	if (!CloseHandle(token_handle))
	{
		cout << "Could not close the handle" << endl;
		return FALSE;
	}

	ULONGLONG PEB_Address;
	GetTebAddress(&PEB_Address);
	//cout << "Address at: " << PEB_Address << endl;

	system("pause");
	return 0;
}