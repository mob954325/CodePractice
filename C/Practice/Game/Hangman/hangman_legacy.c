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
#include <Windows.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024
#define MAXWRONGCOUNT 6

char path[MAX_PATH];
bool* correct;


bool SearchAlphabetInString(const char* str, char c, int length)
{
	bool res = false;
	for (int i = 0; i < length; i++)
	{
		if (str[i] == c && !correct[i]) correct[i] = true, res = true;
	}

	return res;
}

bool IsAllCorrect(int length)
{
	int count = 0;
	for (int i = 0; i < length; i++)
	{
		if (correct[i] == true) count++;
	}

	return count == length;
}

void ShowWord(const char* str, bool isShowAll, int length)
{
	if (isShowAll)
	{
		for (int i = 0; i < length; i++)
		{
			printf("%c ", str[i]);
		}
	}
	else
	{
		for (int i = 0; i < length; i++)
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

	// 텍스트 파일로 불러오기
	FILE* wordFile = fopen("HangmanWords.txt", "r");
	if (wordFile == NULL)
	{
		printf("No word file at %s", path);
		return 1;
	}

	// 10 : LF -> 다음 줄로 이동
	int ch = 0;
	int num = 0; // 20

	char szBuffer[MAX_BUFFER_SIZE];
	fgets(szBuffer, MAX_BUFFER_SIZE, wordFile);
	int max_word_size = 0;

	for (int i = 0; i < MAX_BUFFER_SIZE; i++)
	{
		if (szBuffer[i] == '\n') break;
		printf("%c", szBuffer[i]);
		max_word_size += (szBuffer[i] - '0') * (10 << i);
	}

	char** c = (char**)malloc(max_word_size * sizeof(char*));

	int count = 0;
	while (true)
	{
		fgets(szBuffer, MAX_BUFFER_SIZE, wordFile);
		if (feof(wordFile)) break;

		int i = 0;
		for (i = 0; i < MAX_BUFFER_SIZE; i++)
		{
			if (szBuffer[i] == '\n') break;
		}

		c[count] = (char*)malloc(i * sizeof(char));

		for (int j = 0; j < i; j++)
		{
			c[count][j] = szBuffer[j];
		}

		count++;
	}

	srand(time(NULL));
	int randValue = rand() % max_word_size;

	answer = c[randValue];
	correct = (bool*)malloc((sizeof(answer) / sizeof(char)) * sizeof(bool));

	for (int i = 0; i < (sizeof(answer) / sizeof(char)); i++)
	{
		correct[i] = false;
	}

	int wrongCount = 0;
	char player;

	while (wrongCount < MAXWRONGCOUNT)
	{
		printf("type small alphabet ...\n");
		scanf(" %c", &player);

		if ((int)player < 97 || (int)player > 122)
		{
			printf("you typed wrong !!! \n");
			continue;
		}

		if (SearchAlphabetInString(answer, player, sizeof(answer) / sizeof(char)))
		{
			// 정답
			printf("%c is correct !!\n", player);
			ShowWord(answer, false, sizeof(answer) / sizeof(char));
		}
		else
		{
			// 오답
			printf("%c is wrong ...\n", player);
			ShowWord(answer, false, sizeof(answer) / sizeof(char));
			wrongCount++;
		}

		if (IsAllCorrect(sizeof(answer) / sizeof(char)))
		{
			// 게임 끝
			printf("You win !!!!\n");
			ShowWord(answer, true, sizeof(answer) / sizeof(char));
			return 0;
		}
	}

	// 패배
	printf("You lose !!!!\n");
	printf("Answer is : ");
	ShowWord(answer, true, sizeof(answer) / sizeof(char));
	return 0;
}