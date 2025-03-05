#pragma once
#include <input.h>
#include <vector>
#include <gameWindowBuffer.h>

struct SnakeCell 
{
	enum Direction
	{
		Up = 0,
		Left,
		Right,
		Down
	};

	COORD coord; // 현재 셀 위치
	SnakeCell* next; // 앞에 있는 SnakeCell, nullptr이면 head
	Direction dir = Direction::Left;

	SnakeCell() : coord({ 0,0 }), next(nullptr) {};
	SnakeCell(COORD curCoord) : coord(curCoord), next(nullptr) {};
	SnakeCell(COORD curCoord, SnakeCell* nextCell) : coord(curCoord), next(nextCell) {};

};

struct Cell
{
	enum State
	{
		Empty = 0,
		Wall,
		Apple
	};

	State state = State::Empty;
};

struct Board 
{
	std::vector<SnakeCell*> snakeCells;
	COORD appleCoord;
	int snakeLength = 0;

	int width = 10;
	int height = 10;
	int cellSize = 4;

	std::vector<std::vector<Cell>> cells;

	bool isGameStart = false;
};

bool initBoard(Board& board, int maxWidth, int maxHeight, int cellSize, COORD spawnCoord);

void drawBoard(Board& board, GameWindowBuffer& gameWindowBuffer);

void drawSnake(Board& board, GameWindowBuffer& gameWindowBuffer);

void moveSnake(Board& board);