#include <iostream>
#include <windows.h>

SYSTEM_INFO systemInfo;

int main()
{
	GetSystemInfo(&systemInfo); // �ý��� ���� ���

	std::cout << "page size : " << systemInfo.dwPageSize << "\n";
	std::cout << "min Adress : " << systemInfo.lpMinimumApplicationAddress << "\n";
	std::cout << "max Adree : " << systemInfo.lpMaximumApplicationAddress << "\n";

	size_t size = systemInfo.dwPageSize;

	void* memory = VirtualAlloc(0, size,
		MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);

	std::cout << "Alloc memory address : " << memory << "\n";

	((unsigned char*)memory)[123] = 5;
	std::cout << (int)((unsigned char*)memory)[123] << "\n"; // memnory 123 ��ġ�� �� ���

	VirtualFree(memory, 0, MEM_RELEASE); // ����

	std::cout << "Alloc memory free : " << memory << "\n";
	std::cout << (int)((unsigned char*)memory)[123] << "\n"; // VirtualFree�� ���� ������ �Ұ���
	//std::cout << GetLastError() << "\n";
}