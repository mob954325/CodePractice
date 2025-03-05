// https://www.acmicpc.net/problem/1150

#include<iostream>
#include<queue>

using namespace std;

int n, k, result = INT32_MAX;
int saved[100000];			// ���� ����� ���� �����迭
priority_queue<int> pq;

int main()
{
	saved[0] = 0;

	// �Է�
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		int input;
		cin >> input;

		pq.push(-input);
	}

	int temp = 0;	// ȸ�糢�� ����� ����
	int prev = 0;	// 
	while (pq.size() > 1)
	{
		temp = result;

		int first = -pq.top();
		pq.pop();		

		int sec = -pq.top();

		temp = min(sec - first, prev); // �ּ� ����

		cout << "temp : " << temp << "\n";

		if (result == INT32_MAX)
		{
			result = temp;
		}
		else
		{
			if (temp != result) // �ּ� ���� ����
			{
				pq.pop(); // ����� ȸ�� ����
				result -= prev;
			}

			result = temp;
		}

		prev = result;

		cout << "result : " << result << "\n";
		cout << "prev : " << prev << "\n\n";
	}

	cout << result;
}