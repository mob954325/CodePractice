#include <stdio.h>
#include <windows.h>

int main()
{
	// MAX_PATH
	// 윈도우 운영체제의 경로 길이는 260자를 넘을 일이 없다.
	// 260을 기억하기 힘든데 헤더파일에는 이러한 길이를 매크로로 선언해놔서 이걸 사용하면된다.

	// GetCurrentDirectory
	char* dirPath = (char*)malloc(MAX_PATH * sizeof(char));
	GetCurrentDirectoryA(MAX_PATH, dirPath);

	// GetMoudleFileName
	char* modulePath = (char*)malloc(MAX_PATH * sizeof(char));
	GetModuleFileNameA(NULL, modulePath, MAX_PATH);

	printf("%s\n", dirPath); // D:\CodePractice\c\Practice\GetPath1
	printf("%s", modulePath); // D:\CodePractice\c\Practice\GetPath1\x64\Debug\GetPath1.exe
}