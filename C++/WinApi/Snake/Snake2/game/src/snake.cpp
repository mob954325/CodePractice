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

// ========================================= 헤더 함수 정의

/// <summary>
/// 보드 초기화 함수, 스폰 위치 snakeLength 값 만큼 왼쪽 칸 비워두기
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
	// 오른쪽과 밑만 그리기
	// 오른쪽
	for (short i = 0; i <= board.height; i++)
	{
		drawCell(board, gameWindowBuffer, { (short)(board.width * board.cellSize), (short)(i * board.cellSize) }, 255, 255, 255);
	}

	// 밑
	for (short i = 0; i <= board.width; i++)
	{
		drawCell(board, gameWindowBuffer, { (short)(i * board.cellSize), (short)(board.height * board.cellSize) }, 255, 255, 255);
	}

	// 사과 그리기
	SetApple(board, gameWindowBuffer);
}

void drawSnake(Board& board, GameWindowBuffer& gameWindowBuffer)
{
	if (!board.isGameStart) return;

	// 배열에 있는 모든 셀 그리기
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

	// 보드 범위 밖으로 벗어나면
	if (!isValidPosition(board, nextCoord))
	{
		board.isGameStart = false; 
		return;
	}

	// 벽 타입에 부딪치면
	if (isWall(board, nextCoord))
	{
		board.isGameStart = false; 
		return;
	}

	// 나머지 snakeCell 변경
	for (int i = board.snakeCells.size() - 1; i > 0 ; i--)
	{
		SnakeCell* curCell = board.snakeCells[i];
		ChangeCellState(board, curCell->coord, Cell::Empty);
		curCell->coord.X = curCell->next->coord.X;
		curCell->coord.Y = curCell->next->coord.Y;
	}

	// head 위치 변경
	ChangeCellState(board, head->coord, Cell::Empty);
	head->coord.X = nextCoord.X;
	head->coord.Y = nextCoord.Y;

	CheckIsApple(board, nextCoord); // 사과인지 먼저 확인하고

	// 헤드 제외한 나머지 블록 방향 정하기
	for (int i = 1; i < board.snakeCells.size(); i++)
	{
		SnakeCell* curCell = board.snakeCells[i];
		SnakeCell* front = board.snakeCells[i - 1];
		curCell->dir = GetDirection(front->coord, curCell->coord);
	}

	// Cell 정보 변경
	for (int i = 0; i < board.snakeCells.size(); i++)
	{
		ChangeCellState(board, board.snakeCells[i]->coord, Cell::Wall);
	}
}

// ========================================= snake.cpp 함수 정의

void drawCell(Board& board, GameWindowBuffer& gameWindowBuffer, COORD coord, 
	unsigned char r, unsigned char g, unsigned char b)
{
	for (int y = 0; y < board.cellSize; y++) // cellSize 만큼 출력
	{
		for (int x = 0; x < board.cellSize; x++)
		{
			gameWindowBuffer.drawAtSafe(coord.X + x, coord.Y + y, r, g, b);
		}
	}
}

void SetApple(Board& board, GameWindowBuffer& gameWindowBuffer)
{
	srand(time(0)); // 매 프로그램 실행마다 다른 값을 받기

	// 랜덤 숫자 생성
	if (board.appleCoord.X == -2 && board.appleCoord.Y == -2) // 초기값이면 위치 설정
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

	// 사과 그리기
	drawCell(board, gameWindowBuffer, { (short)(board.appleCoord.X * board.cellSize), (short)(board.appleCoord.Y * board.cellSize) }, 255, 0, 0);
}

void CheckIsApple(Board &board, COORD coord)
{
	if (board.cells[coord.Y][coord.X].state == Cell::Apple)
	{
		board.snakeLength++;
		std::cout << "Get Apple !!!" << "\n";
		std::cout << "Currnet Length : " << board.snakeLength << "\n";

		// 뱀 늘리기
		SnakeCell* front = board.snakeCells[board.snakeCells.size() - 1];

		short curX = (short)(front->coord.X + dirArray[(int)board.snakeCells[0]->dir].X);
		short curY = (short)(front->coord.Y + dirArray[(int)board.snakeCells[0]->dir].Y);

		if (!isValidPosition(board, { curX, curY })) // 다음 위치가 벽이 아니면
		{
			std::cout << " not vaild" << "\n";
		}
		else // 이전 블록 바라보는 위치에 생성
		{
			curX = (short)(front->coord.X + dirArray[(int)front->dir].X);
			curY = (short)(front->coord.Y + dirArray[(int)front->dir].Y);

			SnakeCell* cur = new SnakeCell({ curX, curY }, front);
			board.snakeCells.push_back(cur);		
		}

		board.appleCoord = { -2, -2 }; // 위치 초기화
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

	// 대각선방향은 존재하지 않기 때문에 반드시 밑 4개 조건 중 하나만 발생함
	if (x == 1) return SnakeCell::Direction::Right;
	else if (x == -1) return SnakeCell::Direction::Left;
	else if (-y == 1) return SnakeCell::Direction::Up;		// 왼쪽 상단을 0,0 잡고 밑으로 갈수록 y값이 증가하기 때문에 값 반전
	else if (-y == -1) return SnakeCell::Direction::Down;

	return SnakeCell::Direction::Left; // 혹시 모를 if문 벗어날 때
}

// TODO
// ~~~1. 사과 위치 그리기~~~
// ~~~1. 셀 상태 변경~~~
// ~~~2. 사과 먹으면 뱀 길이 늘어나기~~~
//
