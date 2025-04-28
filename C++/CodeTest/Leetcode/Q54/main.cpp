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
	// m x n ��Ʈ������ �ִ�.
	// ���� ������ ��� ��Ҹ� ��ȯ�Ѵ�.
	// 1 2 3
	// 4 5 6
	// 7 8 9
	// ��ȯ : 1 -> 2 -> 3 -> 6 -> 9 -> 8 -> 7 -> 4 -> 5

	// �ذ� 
	// ������ �Ʒ� ���� �� ������ �ݺ��ϸ鼭 ��Ʈ���� Ž��
	// Ž�� �Ϸ�� ���� -101�� ���� (���� �� ��)

	std::vector<int> result; // ���
	std::vector<std::vector<int>> dir = { {0,1}, {1,0}, {0,-1}, {-1,0} }; // ���� (y,x)

	int size = matrix.size() * matrix[0].size(); // ��Ʈ���� ũ��	
	int dirOrder = 0;
	int x = 0;
	int y = 0;

	for (int i = 0; i < size; i++)
	{
		if (x == matrix[0].size() || y == matrix.size() || y == -1 || x == -1 // ���� �ʰ�
			|| matrix[y][x] == -101) // �̹� Ž���� ��ġ
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