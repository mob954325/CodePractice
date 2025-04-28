#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {
	int buff[] = { 10, 20, 30, 40, 50 };
	FILE* fp;

	fp = fopen("binary.bin", "wb");   // ���̳ʸ� ��� ����
	if (fp == NULL) 
	{
		printf("���Ͽ��� ����");  
		return;
	}

	int size = sizeof(buff[0]); 
	int count = sizeof(buff) / sizeof(buff[0]);
	fwrite(buff, size, count, fp); // ���̳ʸ����� ���� �Լ�   
	fclose(fp);

	int output[5]; 
	fp = fopen("binary.bin", "rb");   // ���̳ʸ� ��� �б� ����
	if (fp == NULL) 
	{ 
		printf("���� ���� ����"); 
		return; 
	}

	fread(output, size, count, fp);   // ���̳ʸ� ��� �д� �Լ�
	for (int i = 0; i < count; i++)
	{
		printf("output[%d] = %d\n", i, output[i]);
	}

	fclose(fp);
	return 0;
}