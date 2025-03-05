#include <stdio.h>
#include <stdlib.h>// �����޸�

int main() {
	int size = 10;

	// malloc�� �����޸� ������ �Ҵ�ް� �ʱ�ȭ�� ���� �ʽ��ϴ�. 
	double* parray = (double*)malloc(sizeof(double) * size); // �����޸� ������ �Ҵ�
	printf("-- malloc --\n");
	for (int i = 0; i < size; i++)
	{
		printf("parray[%d] = %lf\n", i, parray[i]); 
	}

	free(parray);   // �����޸� ��ȯ
	printf("\n\n");

	// calloc�� �Ҵ�� �����޸𸮸� 0���� �ʱ�ȭ�Ѵ�.   
	parray = (double*)calloc(size, sizeof(double));
	printf("\n--- calloc ---\n");
	for (int i = 0; i < size; i++) 
	{ 
		printf("parray[%d] = %lf\n", i, parray[i]);
	}
	printf("\n\n");
	size = 20;

	// realloc�� �Ҵ���� �޸𸮰����� ���Ҵ� �Ҷ� ����մϴ�.  
	parray = (double*)realloc(parray, sizeof(double) * size);
	printf("\n--- realloc ----\n");  
	for (int i = 0; i < size; i++)
	{
		printf("parray[%d] = %lf\n", i, parray[i]);
	}

	printf("\n\nprintArray\n");
	// double�� ��������� int ����������� �ٲ�  

	int* pintArray = (int*)parray;
	for (int i = 0; i < size * 2; i++) 
	{ 
		pintArray[i] = i; 
	}
	printf("\ndouble�� ��������� int�� ����������� ����ȯ�Ͽ� ���� �����ϰ� ���\n");   // �޸𸮰����� �����ϴ� ���� Ȯ�������� �ʴ�.   for (int i = 0; i < size * 2; i++) {      printf("pintArray[%d] = %d\n", i, pintArray[i]);   }
	free(pintArray);

	return 0;
}