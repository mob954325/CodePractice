#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <queue>
#include <string>

int const MAX = 10000;
int const commMax = 6;

using namespace std;

void QueueCommand(queue<int> &q, string comm)
{
	int result = -2;

	if (comm == "push")
	{
		int num = -1;
		scanf("%d", &num);

		q.push(num);
	}
	else if (comm == "pop")
	{
		if (q.empty())
		{
			result = -1;
		}
		else
		{
			result = q.front();
			q.pop();
		}
	}
	else if(comm == "size")
	{ 
		result = q.size();
	}
	else if (comm == "empty")
	{
		result = q.empty() ? 1 : 0;
	}
	else if (comm == "front")
	{
		result = q.empty() ? -1 : q.front();
	}
	else if (comm == "back")
	{
		result = q.empty() ? -1 : q.back();
	}
	else
	{
		printf("Wrong Command");
	}

	if (result != -2)
	{
		printf("%d\n", result);
	}
}

int main()
{
	queue<int> q;
	int n;

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		char command[commMax] = "A";

		scanf("%s", command);
		QueueCommand(q, command);
	}
}