#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

int testCount;
int dp[2][41];

int main()
{
	dp[0][0] = 1;
	dp[1][1] = 1;

	for (int i = 2; i < 41; i++)
	{
		dp[0][i] = dp[0][i - 1] + dp[0][i - 2];
		dp[1][i] = dp[1][i - 1] + dp[1][i - 2];
	}

	scanf("%d", &testCount);

	for (int i = 0; i < testCount; i++)
	{
		int num;
		scanf("%d", &num);
		printf("%d %d\n", dp[0][num], dp[1][num]);
	}
}