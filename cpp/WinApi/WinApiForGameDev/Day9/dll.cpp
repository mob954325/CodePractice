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
	case DLL_PROCESS_ATTACH: // 1. hello 출력 후 동작확인하기
		// Initialize once for each new process.
		// Return FALSE to fail DLL load.
		std::cout << "hello!\n";
		break;

	case DLL_THREAD_ATTACH: // 2. 여기에 hello 스레드 메세지를 추가하고 dll을 로드한 후 메인 프로그램에서 스레드를 시작하여 화면에 나타나는지 확인하기
		// Do thread-specific initialization. (called when the process creates a new thread)
		//	and made in the context of the new thread.
		std::cout << "hello from thread!\n";
		break;

	case DLL_THREAD_DETACH:
		// Do thread-specific cleanup.
		std::cout << "bye from thread!\n";
		break;

	case DLL_PROCESS_DETACH: // 여기서 프로그램을 다시 열면 닫을 수 없는 프로그램을 만들 수 있다.(프로그램을 닫으면 스레드가 분리되기 때문에)

		if (lpvReserved != nullptr)
		{
			break; // do not do cleanup if process termination scenario
		}


		// Perform any necessary cleanup.
		break;
	}
	return TRUE;  // Successful DLL_PROCESS_ATTACH.
}