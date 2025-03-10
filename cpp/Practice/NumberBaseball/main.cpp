// c
// 숫자 야구
// 사용되는 수는 0 - 9이다. 숫자는 중복되지 않는다.
// 숫자는 맞지만 위치가 틀렸으면 BALL
// 숫자와 위치가 전부 맞으면 STRIKE
// 숫자와 위치가 전부 틀리면 OUT
// 기회는 6번, 숫자의 개수는 3개

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <random>

#define MAXINPUTCOUNT 6	// 인풋기회
#define MAXBALLCOUNT 3	// 공 개수

// 공 설정 함수
void SetBallsNum(int arr[])
{
	bool used[10] { false, }; // 사용한 숫자

	int arrIndex = 0;
	while (arrIndex < MAXBALLCOUNT)
	{	
		int randomNum = rand() % 10;
		if (!used[randomNum])
		{
			used[randomNum] = true;
			arr[arrIndex++] = randomNum;
		}
	}
}

int IsVaildInput(int arr[])
{
	bool used[10]{ false, }; // 사용한 숫자

	for (int i = 0; i < MAXBALLCOUNT; i++)
	{
		if (arr[i] < 0 || arr[i] > 9 || used[arr[i]]) return 0;
		used[i] = true;
	}

	return 1;
}

int main()
{
	int balls[3] = { -1, -1, -1 };
	int player[3] = { -1, -1, -1 };
	int count = MAXINPUTCOUNT, strike = 0, ball = 0, out = MAXBALLCOUNT;

	srand(time(NULL));
	SetBallsNum(balls);

	while(count > 0)
	{
		scanf("%d %d %d", &player[0], &player[1], &player[2]);
		if (!IsVaildInput(player))
		{
			printf("Invaild Input ! Enter unique numbers between 0 - 9 \n");
			continue;
		}

		for (int i = 0; i < MAXBALLCOUNT; i++) // balls
		{
			for (int j = 0; j < MAXBALLCOUNT; j++) // player
			{
				if (player[i] == balls[j])
				{
					if (i == j) strike++;
					else ball++;

					out--;
					break;
				}
			}
		}

		// 정답
		if (strike == 3)
		{
			printf("You win !!! \n");
			printf("strike %d, ball %d, out %d\n", strike, ball, out);
			return 0;
		}
		else // 정답아님
		{
			printf("strike %d, ball %d, out %d\n", strike, ball, out);
			printf("Incorrect .. \n");
			printf("%d left until defeat\n", --count);
		}

		strike = 0, ball = 0, out = MAXBALLCOUNT;
	}

	printf("You lose .. \n");
	for (int i = 0; i < MAXBALLCOUNT; i++)
	{
		printf("%d ", balls[i]);
	}
}