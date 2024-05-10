#include <iostream>
#define MAX_SIZE 125
using namespace std;

int graphSize;
int graph [MAX_SIZE][MAX_SIZE];

void show()
{
	for (int y = 0; y < graphSize; y++)
	{
		for (int x = 0; x < graphSize; x++)
		{
			cout << graph[y][x] << " ";
		}
		cout << endl;
	}
}

void GetPath()
{

}

int main()
{
	cin >> graphSize;

	for (int y = 0; y < graphSize; y++)
	{
		for (int x = 0; x < graphSize; x++)
		{
			int input;
			cin >> input;
			graph[y][x] = input;
		}
	}

	show();
}