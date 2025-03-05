#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>

struct coorinate
{
	int x, y;
};

bool compare(coorinate v1, coorinate v2)
{
	bool result = false;

	if (v1.y == v2.y)
	{
		result = v1.x < v2.x;
	}
	else if (v1.y < v2.y)
	{
		result = v1.y < v2.y;
	}

	return result;
}

int n;
coorinate dot[100000];

int main()
{
	scanf("%d", &n);


	for (int i = 0; i < n; i++)
	{
		scanf("%d %d", &dot[i].x, &dot[i].y);
	}

	std::sort(dot, dot + n, compare);

	for (int i = 0; i < n; i++)
	{
		printf("%d %d\n", dot[i].x, dot[i].y);
	}
}