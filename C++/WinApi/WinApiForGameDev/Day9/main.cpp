#include <Windows.h>
#include <iostream>
#include <common.h>

#include <tchar.h>
#include <strsafe.h>

#define MAX_THREADS 1
#define BUF_SIZE 255

DWORD WINAPI myThreadFunction(LPVOID lpParam);

int main()
{
	HMODULE dll = LoadLibraryA("dllProject.dll");

	DWORD dwThreadId;

	if (dll)
	{
		//you can also do: decltype(foo) *fooPointer = ...;
		foo_t* fooPointer = (foo_t*)GetProcAddress(dll, "foo");

		// Thread
		HANDLE thread = CreateThread(
			NULL,                   // default security attributes
			0,                      // use default stack size  
			myThreadFunction,       // thread function name
			0,						// argument to thread function 
			0,                      // use default creation flags 
			&dwThreadId);			// returns the thread identifie
			std::cout << "Thread Crated\n";

		if (fooPointer)
		{
			fooPointer();

			if (thread != NULL)
			{
				WaitForSingleObject(thread, INFINITE); // Wait until thread have terminated
				std::cout << "Before Thread Close\n";
				CloseHandle(thread);
				std::cout << "Thread Close\n";
			}
			else
			{
				std::cout << "Thread is NULL\n";
				// https://learn.microsoft.com/ko-kr/windows/win32/api/processthreadsapi/nf-processthreadsapi-exitprocess
				ExitProcess(3); // DLL_PROCESS_DETACH 호출
			}
		}
		else
		{
			std::cout << "Error loading the function\n";
		}		

		FreeLibrary(dll); // unload the DLL.
	}
	else
	{
		std::cout << "Error loading DLL \n";
	}

	std::cin.get();
	return 0;
}

DWORD WINAPI myThreadFunction(LPVOID lpParam)
{
	return 0;
}