#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <memory.h>
#include <string.h>
int main() {
	FILE* fp; 
	char file_buff[100];
	fp = fopen("test_line.txt", "w");
	if (fp == NULL) 
	{
		printf("���� ���� ����"); 
		return;
	}
	for (int i = 0; i < 3; i++) {
		printf("���Ͽ� �� ������ �Է��ϼ���: (%d��° ����): ", i + 1);  
		memset(file_buff, 0, sizeof(file_buff));   
		scanf("%s", file_buff);     
		file_buff[strlen(file_buff)] = '\n';   
		fputs(file_buff, fp);   // file_buff �迭�� �Է¹��� ���ڿ��� ��ũ�� ����
	}
	fclose(fp);
	fp = fopen("test_line.txt", "r");
	if (fp == NULL) { printf("���� ���� ����");  
	return; 
	}
	while (fgets(file_buff, sizeof(file_buff), fp) != NULL)
	{
		printf("%s", file_buff);   
		memset(file_buff, 0, sizeof(file_buff)); 
	}
	fclose(fp);

	return 0;
}