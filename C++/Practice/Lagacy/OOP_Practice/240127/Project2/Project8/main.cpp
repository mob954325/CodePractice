#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
int main() {
	char str[] = "monster";
	char str2[] = " is World!!";  
	char str3[40]; 
	char str4[] = "monster is World!!";
	//1. strlen 문자열의 문자갯수 세는 함수 
	int count = strlen(str); 
	printf("str: %s의 문자갯수는 : %d\n", str, count);
	// 2. strcpy 문자열을 복사하는 함수 
	strcpy(str3, str); 
	printf("str3: %s\n", str3);
	// 3. strcat 문자열 병합하는 함수 
	strcat(str3, str2);  
	printf("str3: %s\n", str3);
	// 4. strcmp 문자열 비교하는 함수  
	// 문자열이 같으면 0을 리턴 
	// 문자열이 다르면 사전적 순서에 따라 -1, 1을 리턴 
	int ret = strcmp(str3, str4);
	if (ret == 0) { printf("str3: %s 와 str4: %s 문자열이 같습니다.\n", str3, str4); }
	else { printf("str3: %s 와 str4: %s 문자열이 다릅니다..\n", str3, str4); }

	return 0;
}