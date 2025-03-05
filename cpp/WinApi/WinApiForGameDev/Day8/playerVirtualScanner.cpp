#include <Windows.h>
#include <TlHelp32.h>
#include <iostream>
#include <vector>

DWORD findPidByName(const char* name)
{
	HANDLE h;
	PROCESSENTRY32 singleProcess;	// 스냅샷 수행?되었을때 시스템 주소 공간에 있는 프로세스 목록의 항목을 설명?한다
	h = CreateToolhelp32Snapshot(	// 특정 프로세스의 스냅샷 가져오기(보기)
		TH32CS_SNAPPROCESS,			// 모든 프로세스 가져오기
		0); // 무시 

	singleProcess.dwSize = sizeof(PROCESSENTRY32);

	do
	{
		if (strcmp(singleProcess.szExeFile, name) == 0) // 문자열 에러나면 멀티바이트 집합 사용하기
		{
			DWORD pid = singleProcess.th32ProcessID; // pid 가져오기
			CloseHandle(h);
			return pid;
		}
	} while (Process32Next(h, &singleProcess)); // 시스템 스냅샷에 기록된 다름 프로세스 정보를 검색 (없으면 false)
	// 있으면 버퍼에 복사되고 true
	CloseHandle(h);

	return 0;
}

void* findIntValueAtPage(HANDLE handleToProcess, int findValue, int newData)
{
	// page 사이즈 가져오기
	SYSTEM_INFO sSysInfo = {};  // 현재 컴퓨터 시스템 정보 구조체
	GetSystemInfo(&sSysInfo);	// 시스템 정보 가져오기

	// 프로세스 가상 주소에 대한 정보
	MEMORY_BASIC_INFORMATION memInfo;

	void* currentScanAddress = 0; // 주소
	void* curAddress = 0; // 반환될 주소
	while (true)
	{
		// 프로세스의 가상 주소 공간 내 페이지 범위에 대한 정보 찾기
		SIZE_T readBytes =
			VirtualQueryEx(handleToProcess, currentScanAddress, &memInfo, sizeof(MEMORY_BASIC_INFORMATION));

		if (!readBytes) return NULL; // 정보가 없음

		currentScanAddress = (char*)memInfo.BaseAddress + memInfo.RegionSize;


		// commited 메모리 찾기
		if (memInfo.State == MEM_COMMIT)
		{
			if (memInfo.Protect == PAGE_READWRITE)
			{
				//std::cout << "base : " << memInfo.BaseAddress << "\n";
				int pageCount = memInfo.RegionSize / sSysInfo.dwPageSize;
				//std::cout << "pages count : " << memInfo.RegionSize / sSysInfo.dwPageSize << "\n";

				int typeIntCount = (memInfo.RegionSize / sizeof(INT)); // 베이스 주소를 시작으로 페이지의 수를 int타입 크기만큼 쪼개기

				// 값이 포함된 모든 주소값찾기
				for (int i = 1; i <= typeIntCount; i++)
				{
					int data = 0;
					SIZE_T readBytes;
					curAddress = (char*)memInfo.BaseAddress + sizeof(INT) * i;

					// 찾음
					if (&curAddress)
					{
						ReadProcessMemory(handleToProcess, curAddress, &data, sizeof(data), &readBytes); // 메모리 일기

						if (readBytes == sizeof(INT) && data == findValue) // 해당 위치의 타입이 int이고 데이터값이 찾는 값이라면
						{
							//std::cout << i << " : " << curAddress << "\n";
							//std::cout << "data : " << data << "\n";

							// 값 변경
							if (WriteProcessMemory(handleToProcess, curAddress, &newData, sizeof(newData), nullptr));
							{
								std::cout << "Successfully written the data! :D\n";
							}
						}
					}
				}
			}
		}
	}// while

	return curAddress;
}

int main()
{
	auto pid = findPidByName("PlayerInfo.exe");
	//auto pid = findPidByName("Victim.exe");
	void* dataAddress = 0;
	if (pid)
	{
		std::cout << "Found the program ! \n";

		std::cout << "Find Value. \n";
		int findValue = 0;
		std::cin >> findValue;

		int newData = 0;
		std::cout << "Type write value. \n";
		std::cin >> newData;

		HANDLE handleToProcess = OpenProcess(PROCESS_ALL_ACCESS, 0, pid);

		if (handleToProcess)
		{
			dataAddress = findIntValueAtPage(handleToProcess, findValue, newData);
		}
		else
		{
			std::cout << "Failed to open process. \n";
		}
	}
	else
	{
		std::cout << "couldn't find program process :/\n";
	}

	std::cin.ignore();
	std::cin.get();
	return 0;
}