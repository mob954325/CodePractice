#include <stdio.h>
// ����
// ���ٹ���, ���ӱⰣ
// ������ ������ġ�� ���Ǵ� Ű���忡 ���� ������ ������ Ʋ���ϴ�.
int global = 0;     
// �ܺκ���, ��������

int SetScore(int value) {  
	// �Ű����� value �� ���ú���, �ڵ����� 
	static int score = 0;  // ���ú���, �������� 
						   // ���������� �Լ��� ȣ��ɶ� �ѹ����������  
						   // ������ �������� �ʽ��ϴ�. ���α׷� �����ֱ� ���� ������ �˴ϴ�.
	score += value;
	global = 2000;
	return score;
}
int main() {
	int a = 20; // ���ú���, �ڵ�����
	{      
		int c = 100; // ���ú���(��������), �ڵ�����   
	}
	//c = 200;

	for (int i = 0; i < 10; i++) 
	{
		SetScore(i);
	}
	int sum = SetScore(0);  
	printf("Sum = %d\n", sum);

	global = 1000;
	return 0;
}