// �� �ؽ�Ʈ ���α׷�(.txt)���� ��ȭ�ϴ� ���α׷� �����
// getstdhandle�� ������ ���� �����ֱ�
// console ----
// 1 file
// 2 other file

#define _CRT_SECURE_NO_WARNINGS

#include <Windows.h>
#include <iostream>

int main()
{
	// create file
	HANDLE file = CreateFileA(FILE_PATH "file.txt", GENERIC_READ | GENERIC_WRITE,
		FILE_SHARE_WRITE | FILE_SHARE_READ,
		NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);


	// otherfile
	HANDLE otherFile = CreateFileA(FILE_PATH "otherFile.txt", GENERIC_READ | GENERIC_WRITE,
		FILE_SHARE_WRITE | FILE_SHARE_READ,
		NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

	// stdHandle to write texts on console
	HANDLE stdHandle = GetStdHandle(STD_OUTPUT_HANDLE);

	// ��� ���� ��ȯ ��
	DWORD characters = 0;

	if (file != INVALID_HANDLE_VALUE && otherFile != INVALID_HANDLE_VALUE)
	{
		constexpr int size = 32;
		constexpr int otherSize = 32;

		HANDLE fileMapping = CreateFileMappingA(file, NULL, PAGE_READWRITE, 0, size, NULL);
		HANDLE otherFileMapping = CreateFileMappingA(otherFile, NULL, PAGE_READWRITE, 0, otherSize, NULL);

		if (fileMapping != NULL && otherFileMapping != NULL)
		{
			char* data = (char*)MapViewOfFile(fileMapping, FILE_MAP_ALL_ACCESS, 0, 0, size);
			char* otherData = (char*)MapViewOfFile(otherFileMapping, FILE_MAP_ALL_ACCESS, 0, 0, otherSize);

			if (data != nullptr)
			{
				// write data
				strcpy(data, "First");
				strcpy(otherData, "Second");

				while (!(GetAsyncKeyState(VK_F1) & 0b1))
				{
					std::string firstData = data;
					WriteConsoleOutputCharacter(stdHandle, firstData.c_str() , size, { 0, 0 }, &characters);

					std::string secondData = otherData;
					WriteConsoleOutputCharacter(stdHandle, secondData.c_str(), otherSize, {0, 1}, &characters);
				}

				const char* endMessage = "Chatting End";
				WriteConsoleOutputCharacter(stdHandle, endMessage, strlen(endMessage), { 1, 0 }, &characters);

				// ���� �ߴ�
				UnmapViewOfFile(data);
				UnmapViewOfFile(otherData);

				CloseHandle(otherFileMapping);
				CloseHandle(fileMapping);
				CloseHandle(otherFile);
				CloseHandle(file);
			}
			else
			{
				CloseHandle(otherFileMapping);
				CloseHandle(fileMapping);
				CloseHandle(otherFile);
				CloseHandle(file);
			}
		}
		else
		{
			CloseHandle(file);
			CloseHandle(otherFile);
		} // if : mapping
	} // if : handle
} // main