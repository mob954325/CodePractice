// https://www.acmicpc.net/problem/2346


#include <iostream>
#include <deque>
#include <utility>

using namespace std;

deque<pair<int, int>> dq;			// ǳ�� ��
deque<pair<int, int>> reverseDq;	// ǳ�� �� (������)
deque<pair<int, int>>::iterator dq_Iter;		// dq iterator
deque<pair<int, int>>::iterator reverseDq_Iter; // reverse iterator

// ť�� ��ȯ�Ѵ�.
// ǳ���� ������ �ش� ǳ���� ������� �ٽ� �����Ѵ�.
int main()
{
	int count;		// ǳ�� ����
	cin >> count;	// ǳ�� ���� �Է�

	// ���� ǳ�� ���� ����
	for (int i = 0; i < count; i++)
	{
		int input;
		cin >> input;
		dq.push_back(make_pair(input, i + 1));
	}

	// reverseDq�� dq�� ������ִ� ������ �Ųٷ� ����
	for (int i = dq.size() - 1; i > -1; i--)
	{
		reverseDq.push_back(make_pair(dq[i].first, dq[i].second));
	}

	// ǳ�� ��Ʈ����
	int dqIndex = 1;	// ���� ����Ű�� �ε��� ��ȣ

	// iterator �ʱ�ȭ
	dq_Iter = dq.begin();
	reverseDq_Iter = reverseDq.begin();
	for (int i = 0; i < count; i++)
	{
		if (dqIndex > -1)// ǳ�� ��ȣ�� �����
		{
			dqIndex--;
			cout << dq[dqIndex].second << " "; 	
			int nextIndex = dq[dqIndex].first < 0 ? dq[dqIndex].first + i : dq[dqIndex].first - i; //

			// dq ����
			dq_Iter += dqIndex; // ���� ��ġ�� iterator �̵�
			dq.erase(dq_Iter); // ���� ��ġ ����
			dq_Iter += dqIndex - i + 1; // iterator �ʱ�ȭ

			// reverseDq 
			reverseDq_Iter += (reverseDq.size() - dqIndex) - 1;
			reverseDq.erase(reverseDq_Iter);
			reverseDq_Iter += (reverseDq.size() - dqIndex) - i - 1;

			dqIndex = nextIndex;
			//dqIndex < 0 ? dqIndex = nextIndex + 1 : dqIndex = nextIndex - 1;
		}
		else // ǳ�� ��ȣ�� ������ ����
		{
			dqIndex = -dqIndex--;
			cout << reverseDq[dqIndex].second << " ";
			int nextIndex = reverseDq[dqIndex].first + i; //

			// reverseDq ����
			reverseDq_Iter += dqIndex;
			reverseDq.erase(reverseDq_Iter); 
			reverseDq_Iter = reverseDq.begin();

			// dq ����
			dq_Iter += (dq.size() - dqIndex) - 1;
			dq.erase(dq_Iter);
			dq_Iter = dq.begin();

			dqIndex = nextIndex;
		}
	}

	int a = 0;
}