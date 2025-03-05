#include <windows.h>
#include <commdlg.h> // GetOpenFileNameA
#include <iostream>

int main()
{
	OPENFILENAMEA f = { sizeof(OPENFILENAMEA) };

	f.lpstrFilter = "png files\0*.png\0jpg files\0*.jpg\0"; // 필터 설정
	f.lpstrTitle = "다이얼로그 창"; // 타이틀 설정

	// 파일 읽기 위한 버퍼설정
	char buff[MAX_PATH] = {};
	f.nMaxFile = sizeof(buff);
	f.lpstrFile = buff;

	// 다이얼로그 열기
	GetOpenFileNameA(&f);
}