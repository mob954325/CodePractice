/// Q.10828
/// Link : https://www.acmicpc.net/problem/10828
/// 

#include <iostream>
#define MAX_STACK_SIZE 10000

using namespace std;

int arr[MAX_STACK_SIZE];

class Stack
{
private:
	int pointer = 0;
public:
	void init()
	{
		for (int i = 0; i < MAX_STACK_SIZE; i++)
		{
			arr[i] = NULL;
		}
	}

	void push(int value)
	{
		pointer++;
		arr[pointer] = value;
	}

	int pop()
	{
		int popValue = arr[pointer];
		arr[pointer] = NULL;

		pointer > 0 ? pointer-- : pointer = 0;

		return popValue != NULL ? popValue : -1;
	}

	int size()
	{
		return pointer;
	}

	int empty()
	{
		return pointer > 0 ? 0 : 1;
	}

	int top()
	{
		return pointer > 0 ? arr[pointer] : -1;
	}
};

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	Stack s;

	int inputCount;
	cin >> inputCount;

	for (int i = 0; i < inputCount; i++)
	{
		string command;
		int value;

		cin >> command;

		if (command == "push")
		{
			cin >> value;
			s.push(value);
		}
		else if (command == "pop")
		{
			cout << s.pop() << "\n";
		}
		else if (command == "size")
		{
			cout << s.size() << "\n";
		}
		else if (command == "empty")
		{
			cout << s.empty() << "\n";
		}
		else if (command == "top")
		{
			cout << s.top() << "\n";
		}
	}
}