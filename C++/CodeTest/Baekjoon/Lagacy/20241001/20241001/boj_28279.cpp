// https://www.acmicpc.net/problem/28279

#include <iostream>
#include <deque>

using namespace std;

void command(deque<int> &curDq, int comm)
{
	int input = -1;

	switch (comm)
	{
		case 1:
			cin >> input;
			curDq.push_front(input);
			break;
		case 2:
			cin >> input;
			curDq.push_back(input);
			break;
		case 3:
			if (curDq.empty()) cout << -1 << "\n";
			else
			{
				cout << curDq.front() << "\n";
				curDq.pop_front();
			}
			break;
		case 4:
			if (curDq.empty()) cout << -1 << "\n";
			else
			{
				cout << curDq.back() << "\n";
				curDq.pop_back();
			}
			break;
		case 5:
			cout << curDq.size() << "\n";
			break;
		case 6:
			curDq.empty() ? cout << 1 << "\n" : cout << 0 << "\n";
			break;
		case 7:
			if (curDq.empty()) cout << -1 << "\n";
			else cout << curDq.front() << "\n";
			break;
		case 8:
			if (curDq.empty()) cout << -1 << "\n";
			else cout << curDq.back() << "\n";
			break;
	}
}

int main()
{
	deque<int> dq;

	int commCount = -1;
	int commInput = -1;

	cin >> commCount;

	for (int i = 0; i < commCount; i++)
	{
		cin >> commInput;
		command(dq, commInput);
	}
}