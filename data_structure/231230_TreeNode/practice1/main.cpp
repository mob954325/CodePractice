#include <iostream>

using namespace std;

/*
*        A
*       BC
*      DEF..
*/
void pramid()
{
	int input = 0;

	while (!(input % 2))
	{
		cout << "Ȧ�� �Է��ϼ���" << '\n';
		cin >> input;
	}

	int b = 0;
	for (int i = 0; i < input; i++)
	{
		for (int k = input; k - i > 0; k--)
		{
			cout << ' ';
		}

		for (int j = 0; j <= i; j++)
		{
			cout << (char)(65 + (b++ % 26));
		}
		cout << '\n';
	}
}

int main() 
{
	return 0;
}


// 1, 5, 6, 9, 10, 4, 21, 3, 8
// -> �ΰ��� ����
// -> ���� 23�� ������ ����� �� ���
// ->