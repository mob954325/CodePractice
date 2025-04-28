#include <Windows.h>
#include <iostream>
#include <common.h>
#include <iostream>

extern "C" __declspec(dllexport) void foo()
{
	std::cout << "hello from the dll!\n";
}


#include <Windows.h>
//https://learn.microsoft.com/en-us/windows/win32/dlls/dllmain
BOOL WINAPI DllMain(
	HINSTANCE hinstDLL,  // handle to DLL module
	DWORD fdwReason,     // reason for calling function
	LPVOID lpvReserved)  // reserved
{
	// Perform actions based on the reason for calling.
	switch (fdwReason)
	{
	case DLL_PROCESS_ATTACH: // 1. hello ��� �� ����Ȯ���ϱ�
		// Initialize once for each new process.
		// Return FALSE to fail DLL load.
		std::cout << "hello!\n";
		break;

	case DLL_THREAD_ATTACH: // 2. ���⿡ hello ������ �޼����� �߰��ϰ� dll�� �ε��� �� ���� ���α׷����� �����带 �����Ͽ� ȭ�鿡 ��Ÿ������ Ȯ���ϱ�
		// Do thread-specific initialization. (called when the process creates a new thread)
		//	and made in the context of the new thread.
		std::cout << "hello from thread!\n";
		break;

	case DLL_THREAD_DETACH:
		// Do thread-specific cleanup.
		std::cout << "bye from thread!\n";
		break;

	case DLL_PROCESS_DETACH: // ���⼭ ���α׷��� �ٽ� ���� ���� �� ���� ���α׷��� ���� �� �ִ�.(���α׷��� ������ �����尡 �и��Ǳ� ������)

		if (lpvReserved != nullptr)
		{
			break; // do not do cleanup if process termination scenario
		}


		// Perform any necessary cleanup.
		break;
	}
	return TRUE;  // Successful DLL_PROCESS_ATTACH.
}