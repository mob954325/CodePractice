#include <Windows.h>
#include <iostream>
#include <cstdio>
#include <chrono>

struct PlayerPosition
{
	int x; // x ��ǥ ��ġ
	int y; // y ��ǥ ��ġ

	void setPosition(int curX, int curY)
	{
		x = curX;
		y = curY;
	}
};

PlayerPosition curPosition;

int boardWidth = 10;
int boardHeight = 10;

bool IsVaildPosition(int x, int y)
{
	return x >= 0 && y >= 0 && x < boardWidth && y < boardHeight;
}

void DrawGame(int boardX, int boardY, PlayerPosition pos)
{
	int curPosX = pos.x + 1;
	int curPosY = pos.y + 1;

	// �� �𼭸� ���
	for (int x = 0; x < boardX + 2; x++)
	{
		std::cout << "-";
	}

	std::cout << "\n";

	// ���� ���� ���� ��� (���� ��� : (1, 1), ���� �ϴ�(boardX, boradY)
	for (int y = 1; y < boardY + 1; y++)
	{
		// ���� "|" ���
		for (int x = 0; x < boardX + 2; x++)
		{
			if (x == 0 || x == boardX + 1)
			{
				std::cout << "|";
			}
			else if (curPosX == x && curPosY == y)
			{
				std::cout << "O";
			}
			else
			{
				std::cout << " ";
			}

		}

		std::cout << "\n";
	}

	// �Ʒ� �𼭸� ���
	for (int x = 0; x < boardX + 2; x++)
	{
		std::cout << "-";
	}
}

int main()
{
	PlayerPosition nextPosition;

	curPosition.setPosition(0, 0);	// set position
	nextPosition.setPosition(0, 0);	// ����� ���� ��ġ��

	auto start = std::chrono::high_resolution_clock::now();
	while (true)
	{
		std::system("cls"); //clear the screen

		auto stop = std::chrono::high_resolution_clock::now();
		float deltaTime = (std::chrono::duration_cast<std::chrono::microseconds>(stop - start)).count() / 1'000'000.0f;
		start = stop;

		static float counter = 0.5; //0.5 secconds
		counter -= deltaTime;
		if (counter <= 0)
		{
			counter += 0.5; //0.5 secconds

			//move player
			if (IsVaildPosition(nextPosition.x, nextPosition.y))
			{
				curPosition.setPosition(nextPosition.x, nextPosition.y);
			}
			else
			{
				curPosition.setPosition(curPosition.x, curPosition.y);
				nextPosition = curPosition;
			}
		}

		//get the player's input here
		for (int i = 0; i < 256; i++)
		{
			// check key input
			if (GetAsyncKeyState(i) & 0b1)
			{
				int nextX = curPosition.x;
				int nextY = curPosition.y;

				if (i == VK_UP)
				{
					nextY--;
				}
				else if (i == VK_DOWN)
				{
					nextY++;
				}
				else if (i == VK_LEFT)
				{
					nextX--;
				}
				else if (i == VK_RIGHT)
				{
					nextX++;
				}

				nextPosition.setPosition(nextX, nextY);
			}
		}

		//draw the game using std::cout
		int curPosX = nextPosition.x + 1;
		int curPosY = nextPosition.y + 1;

		// �� �𼭸� ���
		for (int x = 0; x < boardWidth + 2; x++)
		{
			std::cout << "-";
		}

		std::cout << "\n";

		// ���� ���� ���� ��� (���� ��� : (1, 1), ���� �ϴ�(boardX, boradY)
		for (int y = 1; y < boardHeight + 1; y++)
		{
			// ���� "|" ���
			for (int x = 0; x < boardWidth + 2; x++)
			{
				if (x == 0 || x == boardWidth + 1)
				{
					std::cout << "|";
				}
				else if (curPosX == x && curPosY == y)
				{
					std::cout << "O";
				}
				else
				{
					std::cout << " ";
				}

			}

			std::cout << "\n";
		}

		// �Ʒ� �𼭸� ���
		for (int x = 0; x < boardWidth + 2; x++)
		{
			std::cout << "-";
		}
	}

	std::cin.get();
	return 0;
}