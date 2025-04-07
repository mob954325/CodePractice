#include <stdio.h>
#include <random>

// 게임 규칙
// 1. 랜덤한 숫자 3개를 생성하고 플레이어는 숫자 3개를 마춘다.
// 2. 6회 시도안에 맞추면 축하 메세지 출력
// 3. 맞추기 실패마다 Ball(자리x, 숫자o), Strike(자리o, 숫자o), Out(자리x, 숫자x)의 수를 알려준다.
// 4. 최대 6회까지 맞추지 못하면 랜덤 숫자를 알려주고 종료한다.

#define MAX_BALLVALUE 11
#define MAXBALLSIZE 3

void SetNum(int balls[])
{
	bool Used[MAX_BALLVALUE] = { false, };
	srand(time(NULL)); // 의사 번호 생성기 초기값 설정
	int index = 0;
	int valueInMax = rand() % MAX_BALLVALUE;

	while (Used[valueInMax] == false)
	{
		if (Used[valueInMax]) continue;
		Used[valueInMax] = true;
		balls[index++] = valueInMax;
		if (index == MAXBALLSIZE) break;
		valueInMax = rand() % MAX_BALLVALUE;
	}
}

int CheckNum(int arr[], int num)
{
	for (int i = 0; i < MAXBALLSIZE; i++)
	{
		if (arr[i] == num) return i; // 인덱스 반환
	}

	return -1;
}

int main()
{
	// 초기화
	int count = 0;
	int MAX_COUNT = 6;

	// 랜덤 숫자 생성
	int balls[3] = { 0 ,0, 0 };
	int player[3] = { 0, 0, 0 };
	SetNum(balls);

	// 제출 전 주석 할 것
	for (int i = 0; i < MAXBALLSIZE; i++)
	{
		printf("%d ", *(balls + i));
	}
	printf("\n");

	int outCount = 3, strikeCount = 0, ballCount = 0;
	while (count < MAX_COUNT)
	{
		scanf_s("%d %d %d", &player[0], &player[1], &player[2]);

		// 확인
		for (int i = 0; i < MAXBALLSIZE; i++)
		{
			for (int j = 0; j < MAXBALLSIZE; j++)
			{
				if (i == j && balls[i] == player[j]) // strike
				{
					strikeCount++;
					outCount--;
					break;
				}
				else if (i != j && balls[i] == player[j]) // ball
				{
					ballCount++;
					outCount--;
					break;
				}
			}
		}

		printf("ball : %d\n", ballCount);
		printf("strike : %d\n", strikeCount);
		printf("out : %d\n", outCount);


		if (strikeCount == 3)
		{
			printf("You Win !!!\n\n");
			printf("Count : %d\n", count);
			break;
		}

		ballCount = 0;
		strikeCount = 0;
		outCount = 3;
		count++;
	} // while end

	if (strikeCount != 3)
	{
		printf("\n");
		printf("You Lose ... \n");
		printf("Answer is : ");
		for (int i = 0; i < MAXBALLSIZE; i++)
		{
			printf("%d ", *(balls + i));
		}
	}
	// 랜덤 숫자 출력
}