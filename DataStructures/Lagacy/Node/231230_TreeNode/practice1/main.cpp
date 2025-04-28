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
		cout << "홀수 입력하세요" << '\n';
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
// -> 두개를 선택
// -> 합이 23이 나오는 경우의 수 출력
// ->