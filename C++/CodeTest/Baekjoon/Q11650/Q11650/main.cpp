#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>

using namespace std;

struct coordinate
{
	int x, y;
};

bool compare(coordinate v1, coordinate v2)
{
	bool result = false;

	if (v1.x == v2.x)
	{
		result = v1.y < v2.y;
	}
	else if (v1.x < v2.x)
	{
		result = v1.x < v2.x;
	}

	return result;
}

coordinate arr[100000];

int main()
{
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		int a, b;
		scanf("%d %d", &arr[i].x, &arr[i].y);
	}

	std::sort(arr, arr + n, compare);
	
	for (int i = 0; i < n; i++)
	{
		printf("%d %d\n", arr[i].x, arr[i].y);
	}
}