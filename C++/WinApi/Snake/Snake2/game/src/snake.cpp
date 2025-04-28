#include <snake.h>
#include <iostream>
#include <cstdlib>
#include <ctime>

COORD dirArray[4] = { {0,1}, {-1,0}, {1,0}, {0,-1} }; // Up, Left, Right, Down

bool isValidPosition(Board& board, COORD coord)
{
	return coord.X >= 0 && coord.X < board.width && coord.Y >= 0 && coord.Y < board.height;
}

bool isWall(Board& board, COORD coord);

void drawCell(Board& board, GameWindowBuffer& gameWindowBuffer, COORD coord, unsigned char r, unsigned char g, unsigned char b);

void SetApple(Board& board, GameWindowBuffer& gameWindowBuffer);

void CheckIsApple(Board& board, COORD coord);

void ChangeCellState(Board& board, COORD coord, Cell::State chageState);

SnakeCell::Direction GetDirection(COORD coord1, COORD coord2);

// ========================================= ��� �Լ� ����

/// <summary>
/// ���� �ʱ�ȭ �Լ�, ���� ��ġ snakeLength �� ��ŭ ���� ĭ ����α�
/// </summary>
bool initBoard(Board &board, int maxWidth, int maxHeight, int cellSize, COORD spawnCoord)
{
#pragma region board init
	board.width = maxWidth;
	board.height = maxHeight;
	board.cellSize = cellSize;	

	board.appleCoord = { -2, -2 };

	for (int y = 0; y < maxHeight; y++)
	{
		board.cells.push_back(std::vector<Cell>());
		for (int x = 0; x < maxWidth; x++)
		{
			Cell curCell = {};
			board.cells[y].push_back(curCell);
			board.cells[y][x].state = Cell::Empty;
		}
	}

#pragma endregion

#pragma region snake init
	board.snakeLength = 2;

	SnakeCell* head = new SnakeCell({ spawnCoord.X, spawnCoord.Y });
	board.snakeCells.push_back(head);

	for (int i = 1; i < board.snakeLength; i++)
	{
		SnakeCell* front = board.snakeCells[i - 1];
		SnakeCell* cur = new SnakeCell( {(short)(front->coord.X - 1), front->coord.Y}, front);
		board.snakeCells.push_back(cur);
		cur->dir = GetDirection(front->coord, cur->coord);
	}

#pragma endregion

	board.cells[spawnCoord.Y][spawnCoord.X].state = Cell::Wall;

	std::cout << "Snake init Complete...." << "\n";
	board.isGameStart = true;

	return true;
}

void drawBoard(Board& board, GameWindowBuffer &gameWindowBuffer)
{
	// �����ʰ� �ظ� �׸���
	// ������
	for (short i = 0; i <= board.height; i++)
	{
		drawCell(board, gameWindowBuffer, { (short)(board.width * board.cellSize), (short)(i * board.cellSize) }, 255, 255, 255);
	}

	// ��
	for (short i = 0; i <= board.width; i++)
	{
		drawCell(board, gameWindowBuffer, { (short)(i * board.cellSize), (short)(board.height * board.cellSize) }, 255, 255, 255);
	}

	// ��� �׸���
	SetApple(board, gameWindowBuffer);
}

void drawSnake(Board& board, GameWindowBuffer& gameWindowBuffer)
{
	if (!board.isGameStart) return;

	// �迭�� �ִ� ��� �� �׸���
	drawCell(board, gameWindowBuffer, { (short)(board.snakeCells[0]->coord.X * board.cellSize), (short)(board.snakeCells[0]->coord.Y * board.cellSize) }, 0, 255, 255);

	for (int i = 1; i < board.snakeCells.size(); i++)
	{
		SnakeCell* curCell = board.snakeCells[i];
		drawCell(board, gameWindowBuffer, { (short)(curCell->coord.X * board.cellSize), (short)(curCell->coord.Y * board.cellSize) }, 0, 255, 0);
	}
}

void moveSnake(Board& board)
{
	SnakeCell* head = board.snakeCells[0];
	COORD nextCoord = { (short)(head->coord.X + dirArray[head->dir].X), (short)(head->coord.Y + -dirArray[head->dir].Y) };

	// ���� ���� ������ �����
	if (!isValidPosition(board, nextCoord))
	{
		board.isGameStart = false; 
		return;
	}

	// �� Ÿ�Կ� �ε�ġ��
	if (isWall(board, nextCoord))
	{
		board.isGameStart = false; 
		return;
	}

	// ������ snakeCell ����
	for (int i = board.snakeCells.size() - 1; i > 0 ; i--)
	{
		SnakeCell* curCell = board.snakeCells[i];
		ChangeCellState(board, curCell->coord, Cell::Empty);
		curCell->coord.X = curCell->next->coord.X;
		curCell->coord.Y = curCell->next->coord.Y;
	}

	// head ��ġ ����
	ChangeCellState(board, head->coord, Cell::Empty);
	head->coord.X = nextCoord.X;
	head->coord.Y = nextCoord.Y;

	CheckIsApple(board, nextCoord); // ������� ���� Ȯ���ϰ�

	// ��� ������ ������ ��� ���� ���ϱ�
	for (int i = 1; i < board.snakeCells.size(); i++)
	{
		SnakeCell* curCell = board.snakeCells[i];
		SnakeCell* front = board.snakeCells[i - 1];
		curCell->dir = GetDirection(front->coord, curCell->coord);
	}

	// Cell ���� ����
	for (int i = 0; i < board.snakeCells.size(); i++)
	{
		ChangeCellState(board, board.snakeCells[i]->coord, Cell::Wall);
	}
}

// ========================================= snake.cpp �Լ� ����

void drawCell(Board& board, GameWindowBuffer& gameWindowBuffer, COORD coord, 
	unsigned char r, unsigned char g, unsigned char b)
{
	for (int y = 0; y < board.cellSize; y++) // cellSize ��ŭ ���
	{
		for (int x = 0; x < board.cellSize; x++)
		{
			gameWindowBuffer.drawAtSafe(coord.X + x, coord.Y + y, r, g, b);
		}
	}
}

void SetApple(Board& board, GameWindowBuffer& gameWindowBuffer)
{
	srand(time(0)); // �� ���α׷� ���ึ�� �ٸ� ���� �ޱ�

	// ���� ���� ����
	if (board.appleCoord.X == -2 && board.appleCoord.Y == -2) // �ʱⰪ�̸� ��ġ ����
	{
		int count = 0;
		while (count < 1000000)
		{
			int randX = rand() % board.width;
			int randY = rand() % board.height;

			if (board.cells[randY][randX].state != Cell::Empty) continue;
			else
			{
				std::cout << "NEXT apple is.. { " << randX << ", " << randY << " }\n";
				board.appleCoord = { (short)(randX), (short)(randY) };
				ChangeCellState(board, board.appleCoord, Cell::Apple);
				break;
			}
		}

		if (count >= 1000000) std::cout << "INF LOOP";
	}

	// ��� �׸���
	drawCell(board, gameWindowBuffer, { (short)(board.appleCoord.X * board.cellSize), (short)(board.appleCoord.Y * board.cellSize) }, 255, 0, 0);
}

void CheckIsApple(Board &board, COORD coord)
{
	if (board.cells[coord.Y][coord.X].state == Cell::Apple)
	{
		board.snakeLength++;
		std::cout << "Get Apple !!!" << "\n";
		std::cout << "Currnet Length : " << board.snakeLength << "\n";

		// �� �ø���
		SnakeCell* front = board.snakeCells[board.snakeCells.size() - 1];

		short curX = (short)(front->coord.X + dirArray[(int)board.snakeCells[0]->dir].X);
		short curY = (short)(front->coord.Y + dirArray[(int)board.snakeCells[0]->dir].Y);

		if (!isValidPosition(board, { curX, curY })) // ���� ��ġ�� ���� �ƴϸ�
		{
			std::cout << " not vaild" << "\n";
		}
		else // ���� ��� �ٶ󺸴� ��ġ�� ����
		{
			curX = (short)(front->coord.X + dirArray[(int)front->dir].X);
			curY = (short)(front->coord.Y + dirArray[(int)front->dir].Y);

			SnakeCell* cur = new SnakeCell({ curX, curY }, front);
			board.snakeCells.push_back(cur);		
		}

		board.appleCoord = { -2, -2 }; // ��ġ �ʱ�ȭ
	}
}

void ChangeCellState(Board& board, COORD coord, Cell::State chageState)
{
	board.cells[(int)coord.Y][(int)coord.X].state = chageState;
}

bool isWall(Board& board, COORD coord)
{
	return board.cells[coord.Y][coord.X].state == Cell::Wall;
}

SnakeCell::Direction GetDirection(COORD frontCoord, COORD curCoord)
{
	int x = frontCoord.X - curCoord.X;
	int y = frontCoord.Y - curCoord.Y;

	// �밢�������� �������� �ʱ� ������ �ݵ�� �� 4�� ���� �� �ϳ��� �߻���
	if (x == 1) return SnakeCell::Direction::Right;
	else if (x == -1) return SnakeCell::Direction::Left;
	else if (-y == 1) return SnakeCell::Direction::Up;		// ���� ����� 0,0 ��� ������ ������ y���� �����ϱ� ������ �� ����
	else if (-y == -1) return SnakeCell::Direction::Down;

	return SnakeCell::Direction::Left; // Ȥ�� �� if�� ��� ��
}

// TODO
// ~~~1. ��� ��ġ �׸���~~~
// ~~~1. �� ���� ����~~~
// ~~~2. ��� ������ �� ���� �þ��~~~
//
