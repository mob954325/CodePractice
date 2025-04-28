#include <iostream>
#include <vector>

std::vector<int> spiralOrder(std::vector<std::vector<int>>& matrix);

int main()
{
	std::vector<std::vector<int>> v = // y, x
	{
		{1,2,3},
		{4,5,6},
		{7,8,9}
	};


	spiralOrder(v);
}

std::vector<int> spiralOrder(std::vector<std::vector<int>>& matrix)
{
	// m x n 매트릭스가 있다.
	// 나선 순서로 모든 요소를 반환한다.
	// 1 2 3
	// 4 5 6
	// 7 8 9
	// 반환 : 1 -> 2 -> 3 -> 6 -> 9 -> 8 -> 7 -> 4 -> 5

	// 해결 
	// 오른쪽 아래 왼쪽 위 순서로 반복하면서 매트릭스 탐색
	// 탐색 완료된 값은 -101로 지정 (범위 밖 값)

	std::vector<int> result; // 결과
	std::vector<std::vector<int>> dir = { {0,1}, {1,0}, {0,-1}, {-1,0} }; // 방향 (y,x)

	int size = matrix.size() * matrix[0].size(); // 매트릭스 크기	
	int dirOrder = 0;
	int x = 0;
	int y = 0;

	for (int i = 0; i < size; i++)
	{
		if (x == matrix[0].size() || y == matrix.size() || y == -1 || x == -1 // 범위 초과
			|| matrix[y][x] == -101) // 이미 탐색한 위치
		{
			x -= dir[dirOrder][1];
			y -= dir[dirOrder][0];

			dirOrder++;
			dirOrder %= 4;

			x += dir[dirOrder][1];
			y += dir[dirOrder][0];
		}

		result.push_back(matrix[y][x]);
		matrix[y][x] = -101;

		x += dir[dirOrder][1];
		y += dir[dirOrder][0];
	}

	return result;
}