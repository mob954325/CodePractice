// https://www.acmicpc.net/problem/1150

#include<iostream>
#include<queue>

using namespace std;

int n, k, result = INT32_MAX;
int saved[100000];			// 이전 결과값 저장 변수배열
priority_queue<int> pq;

int main()
{
	saved[0] = 0;

	// 입력
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		int input;
		cin >> input;

		pq.push(-input);
	}

	int temp = 0;	// 회사끼리 연결된 길이
	int prev = 0;	// 
	while (pq.size() > 1)
	{
		temp = result;

		int first = -pq.top();
		pq.pop();		

		int sec = -pq.top();

		temp = min(sec - first, prev); // 최소 길이

		cout << "temp : " << temp << "\n";

		if (result == INT32_MAX)
		{
			result = temp;
		}
		else
		{
			if (temp != result) // 최소 길이 갱신
			{
				pq.pop(); // 연결된 회사 제거
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