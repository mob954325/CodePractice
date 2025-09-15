// Hangman
// 숨겨진 단어를 추측하여 알바벳을 선택하면서 최종 단어를 완성한다
// 최종 단어는 코드의 단어 목록중 랜덤 출력
// 1. 단어에 없는 알파벳을 선택하면 WrongCount 증가
// 2. 단어에 있는 알파벳이면 해당 알파벳을 보여준다.
// 2.1 한 번 입력한 알파벳의 목록을 알려주며 감점 처리가 안됨
// 3. 시도 제한 횟수가 되기전에 맞추면 성공, 제한 횟수가 되면 게임에서 패배
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <random>


#define MAXWORDCOUNT 8
#define MAXWORDLENGTH 10 // 1O글자
#define MAXWRONGCOUNT 6
 
int correct[MAXWORDLENGTH] = { 0, };

const char* wordList[MAXWORDCOUNT] =
{
	"consistent",
	"generation",
	"importance",
	"reasonably",
	"experiment",
	"processing",
	"university",
	"understand"
};

const char* SetWord()
{
	srand(time(NULL));
	int randValue = rand() % MAXWORDCOUNT;

	return wordList[randValue];
}


int SearchAlphabetInString(const char* str, char c)
{
	int res = 0;
	for (int i = 0; i < MAXWORDLENGTH; i++)
	{
		if (str[i] == c && !correct[i]) correct[i] = 1, res = 1;
	}

	return res;
}

int IsAllCorrect()
{
	int count = 0;
	for (int i = 0; i < MAXWORDLENGTH; i++)
	{
		if (correct[i] == 1) count++;
	}

	return count == MAXWORDLENGTH;
}

void ShowWord(const char* str, int isShowAll)
{
	if (isShowAll)
	{
		for (int i = 0; i < MAXWORDLENGTH; i++)
		{
			printf("%c ", str[i]);
		}
	}
	else
	{
		for (int i = 0; i < MAXWORDLENGTH; i++)
		{
			if (correct[i]) printf("%c ", str[i]);
			else printf("_ ");
		}
	}

	printf("\n\n");
}

int main()
{
	const char* answer = " ";
	answer = SetWord();

	int wrongCount = 0;
	char player;

	while (wrongCount < MAXWRONGCOUNT)
	{
		printf("type small alphabet ...\n");
		scanf(" %c", &player);

		if ((int)player < 'a' || (int)player > 'z')
		{
			printf("you typed wrong !!! \n");
			continue;
		}

		if (SearchAlphabetInString(answer, player))
		{
			// 정답
			printf("%c is correct !!\n", player);
			ShowWord(answer, 0);
		}
		else
		{
			// 오답
			printf("%c is wrong ...\n", player);
			ShowWord(answer, 0);
			wrongCount++;
		}

		if (IsAllCorrect())
		{
			// 게임 끝
			printf("You win !!!!\n");
			ShowWord(answer, 1);
			return 0;
		}
	}

	// 패배
	printf("You lose !!!!\n");
	printf("Answer is : ");
	ShowWord(answer, 1);

	free(answer);
	return 0;
}