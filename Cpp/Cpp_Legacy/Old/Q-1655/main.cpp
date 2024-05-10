#include <iostream>
#include <queue>

using namespace std;

int n;
priority_queue<int> pq_max; // �߾Ӱ����� ���� ���� �������� ť
priority_queue<int, vector<int>, greater<int>> pq_min; // �߾Ӱ����� ���� ���� �������� ť

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n;

	int input;
	for (int i = 1; i <= n; i++)
	{
		cin >> input;
		if (pq_max.size() == pq_min.size())
		{
			pq_max.push(input);
		}
		else
		{
			pq_min.push(input);
		}

		if (!pq_max.empty() && !pq_min.empty()
			&& pq_max.top() > pq_min.top())
		{
			int min_value, max_value;
			min_value = pq_min.top();
			max_value = pq_max.top();

			pq_min.push(max_value);
			pq_max.push(min_value);

			pq_max.pop();
			pq_min.pop();
		}

		cout << "value : " << pq_max.top() << "\n";
	}
	return 0;
}