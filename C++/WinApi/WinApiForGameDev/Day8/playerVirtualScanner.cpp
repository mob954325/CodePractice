#include <Windows.h>
#include <TlHelp32.h>
#include <iostream>
#include <vector>

DWORD findPidByName(const char* name)
{
	HANDLE h;
	PROCESSENTRY32 singleProcess;	// ������ ����?�Ǿ����� �ý��� �ּ� ������ �ִ� ���μ��� ����� �׸��� ����?�Ѵ�
	h = CreateToolhelp32Snapshot(	// Ư�� ���μ����� ������ ��������(����)
		TH32CS_SNAPPROCESS,			// ��� ���μ��� ��������
		0); // ���� 

	singleProcess.dwSize = sizeof(PROCESSENTRY32);

	do
	{
		if (strcmp(singleProcess.szExeFile, name) == 0) // ���ڿ� �������� ��Ƽ����Ʈ ���� ����ϱ�
		{
			DWORD pid = singleProcess.th32ProcessID; // pid ��������
			CloseHandle(h);
			return pid;
		}
	} while (Process32Next(h, &singleProcess)); // �ý��� �������� ��ϵ� �ٸ� ���μ��� ������ �˻� (������ false)
	// ������ ���ۿ� ����ǰ� true
	CloseHandle(h);

	return 0;
}

void* findIntValueAtPage(HANDLE handleToProcess, int findValue, int newData)
{
	// page ������ ��������
	SYSTEM_INFO sSysInfo = {};  // ���� ��ǻ�� �ý��� ���� ����ü
	GetSystemInfo(&sSysInfo);	// �ý��� ���� ��������

	// ���μ��� ���� �ּҿ� ���� ����
	MEMORY_BASIC_INFORMATION memInfo;

	void* currentScanAddress = 0; // �ּ�
	void* curAddress = 0; // ��ȯ�� �ּ�
	while (true)
	{
		// ���μ����� ���� �ּ� ���� �� ������ ������ ���� ���� ã��
		SIZE_T readBytes =
			VirtualQueryEx(handleToProcess, currentScanAddress, &memInfo, sizeof(MEMORY_BASIC_INFORMATION));

		if (!readBytes) return NULL; // ������ ����

		currentScanAddress = (char*)memInfo.BaseAddress + memInfo.RegionSize;


		// commited �޸� ã��
		if (memInfo.State == MEM_COMMIT)
		{
			if (memInfo.Protect == PAGE_READWRITE)
			{
				//std::cout << "base : " << memInfo.BaseAddress << "\n";
				int pageCount = memInfo.RegionSize / sSysInfo.dwPageSize;
				//std::cout << "pages count : " << memInfo.RegionSize / sSysInfo.dwPageSize << "\n";

				int typeIntCount = (memInfo.RegionSize / sizeof(INT)); // ���̽� �ּҸ� �������� �������� ���� intŸ�� ũ�⸸ŭ �ɰ���

				// ���� ���Ե� ��� �ּҰ�ã��
				for (int i = 1; i <= typeIntCount; i++)
				{
					int data = 0;
					SIZE_T readBytes;
					curAddress = (char*)memInfo.BaseAddress + sizeof(INT) * i;

					// ã��
					if (&curAddress)
					{
						ReadProcessMemory(handleToProcess, curAddress, &data, sizeof(data), &readBytes); // �޸� �ϱ�

						if (readBytes == sizeof(INT) && data == findValue) // �ش� ��ġ�� Ÿ���� int�̰� �����Ͱ��� ã�� ���̶��
						{
							//std::cout << i << " : " << curAddress << "\n";
							//std::cout << "data : " << data << "\n";

							// �� ����
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