#include <iostream>

// Fn = Fn-1 + Fn-2

int fib(int n)
{
	int i;
	int saved[45] = { 0, 1 };

	if (n == 0) return 0;
	else if (n == 1) return 1;
	else // 2ÀÌ»ף
	{
		for (i = 1; i < n; i++)
		{
			saved[i + 1] = saved[i] + saved[i - 1];
		}
	}

	return saved[i];
}

int main()
{
	int n;

	std::cin >> n;
	std::cout << fib(n);
}