#include <stdio.h>
#include <Windows.h>

int main(int argc, char** argv)
{
	STARTUPINFO startupinfo;
	PROCESS_INFORMATION processinformation;

	ZeroMemory(&startupinfo, sizeof(startupinfo));

	startupinfo.cb = sizeof(startupinfo);

	ZeroMemory(&processinformation, sizeof(processinformation));

	if (argc != 2)
	{
		printf("Usage: %s [cmdline]\n", argv[0]);
		return;
	}

	if (!CreateProcess("C:\\Users\\brobu\\source\\repos\\Lab1_Win_Task1\\x64\\Debug\\Lab1_Win_Task1.exe", NULL, NULL, NULL, FALSE, 0, NULL, NULL, &startupinfo, &processinformation))
	{
		printf("CreateProcess failed (%d).\n", GetLastError());
	}

	WaitForSingleObject(processinformation.hProcess, INFINITE);

	CloseHandle(processinformation.hProcess);
	CloseHandle(processinformation.hThread);

	return 0;
}