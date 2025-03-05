// https://www.acmicpc.net/problem/2346


#include <iostream>
#include <deque>
#include <utility>

using namespace std;

deque<pair<int, int>> dq;			// 풍선 덱
deque<pair<int, int>> reverseDq;	// 풍선 덱 (역방향)
deque<pair<int, int>>::iterator dq_Iter;		// dq iterator
deque<pair<int, int>>::iterator reverseDq_Iter; // reverse iterator

// 큐는 순환한다.
// 풍선이 터지면 해당 풍선은 사라지고 다시 진행한다.
int main()
{
	int count;		// 풍선 개수
	cin >> count;	// 풍선 개수 입력

	// 덱에 풍선 정보 저장
	for (int i = 0; i < count; i++)
	{
		int input;
		cin >> input;
		dq.push_back(make_pair(input, i + 1));
	}

	// reverseDq에 dq에 저장되있던 정보를 거꾸로 저장
	for (int i = dq.size() - 1; i > -1; i--)
	{
		reverseDq.push_back(make_pair(dq[i].first, dq[i].second));
	}

	// 풍선 터트리기
	int dqIndex = 1;	// 현재 가르키는 인덱스 번호

	// iterator 초기화
	dq_Iter = dq.begin();
	reverseDq_Iter = reverseDq.begin();
	for (int i = 0; i < count; i++)
	{
		if (dqIndex > -1)// 풍선 번호가 양수면
		{
			dqIndex--;
			cout << dq[dqIndex].second << " "; 	
			int nextIndex = dq[dqIndex].first < 0 ? dq[dqIndex].first + i : dq[dqIndex].first - i; //

			// dq 제거
			dq_Iter += dqIndex; // 현재 위치로 iterator 이동
			dq.erase(dq_Iter); // 현재 위치 제거
			dq_Iter += dqIndex - i + 1; // iterator 초기화

			// reverseDq 
			reverseDq_Iter += (reverseDq.size() - dqIndex) - 1;
			reverseDq.erase(reverseDq_Iter);
			reverseDq_Iter += (reverseDq.size() - dqIndex) - i - 1;

			dqIndex = nextIndex;
			//dqIndex < 0 ? dqIndex = nextIndex + 1 : dqIndex = nextIndex - 1;
		}
		else // 풍선 번호가 음수면 실행
		{
			dqIndex = -dqIndex--;
			cout << reverseDq[dqIndex].second << " ";
			int nextIndex = reverseDq[dqIndex].first + i; //

			// reverseDq 제거
			reverseDq_Iter += dqIndex;
			reverseDq.erase(reverseDq_Iter); 
			reverseDq_Iter = reverseDq.begin();

			// dq 제거
			dq_Iter += (dq.size() - dqIndex) - 1;
			dq.erase(dq_Iter);
			dq_Iter = dq.begin();

			dqIndex = nextIndex;
		}
	}

	int a = 0;
}