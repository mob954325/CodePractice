#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <string.h>


// 랜덤한 단어를 .txt파일에서 추출후 선택
// 6번의 기회안에 맞추면 성공
// 아니면 실패후 해당 단어 보여주기

#define MAX_BUFFER_SIZE 1024

int main()
{
	// 파일 찾기
	char* path = (char*)malloc(MAX_BUFFER_SIZE * sizeof(char));
	GetCurrentDirectoryA(MAX_BUFFER_SIZE, path);
	strcat(path, "\\src\\words.txt");

	// 파일 내용 추출
	char* numStr = (char*)malloc(MAX_BUFFER_SIZE * sizeof(char));
	FILE *file = fopen(path, "r");
	fgets(numStr, MAX_BUFFER_SIZE, file);

	int max_word_size = 0, count = 0;
	while (numStr[count] != '\n')
	{
		max_word_size *= 10;
		max_word_size += (numStr[count] - '0');
		count++;
	}

	// 단어 저장
	count = 0;
	char** words = (char**)malloc(max_word_size * sizeof(char*));
	char* buffer = (char*)malloc(MAX_BUFFER_SIZE * sizeof(char));
	for (int i = 0; i < max_word_size; i++)
	{
		fgets(buffer, MAX_BUFFER_SIZE, file);
		int wordLength = strlen(buffer);
		words[i] = (char*)malloc(max_word_size * sizeof(char));
		strcpy(words[i], buffer);
	}

	free(buffer);
	fclose(file);

	// 단어 뽑기
	srand(time(NULL));
	int randomValue = rand() % max_word_size;
	char* answer = words[randomValue];	// 정답 문자열

	// 게임 시작
	int answerLength = strlen(answer);	// 정답 문자열 길이
	int lifeCount = 6;					// 목숨

	// 문장 정답 확인용 배열
	byte* correct = (byte*)malloc(answerLength * sizeof(byte));
	for (int i = 0; i < answerLength; i++)
	{
		correct[i] = 0;
	}

	while (lifeCount > 0)
	{
		printf("Type alphabet\n");
		char input = (char)malloc(1 * sizeof(char));
		int inputResult = scanf(" %c", &input);
		if (input < 'a' || input > 'z' || inputResult != 1)
		{
			printf("Wrong input\n");
			continue;
		}

		// 정답 체크
		int correctCount = 0;
		for (int i = 0; i < answerLength; i++)
		{
			if (input == answer[i])
			{
				correct[i] = 1;
				correctCount++;
			}
		}

		// 목숨 제거 ( 못맞춤 )
		if (correctCount == 0)
		{
			printf("incorrect...\n");
			lifeCount--;
		}
		else // 맞췄음
		{
			// 전부 맞췄는지 확인하기
			int correctCount = 0;
			for (int i = 0; i < answerLength; i++)
			{
				if (correct[i] == 1) correctCount++;
			}

			// 플레이어가 정답을 맞췄다.
			if (correctCount == answerLength) 
			{
				for (int i = 0; i < answerLength; i++)
				{
					printf("%c ", correct[i]);
				}

				printf("You win !!!");
				return 1;
			}
		}

		// 표시
		for (int i = 0; i < answerLength; i++)
		{
			if (correct[i] == 1) printf("%c ", answer[i]);
			else printf("_ ");
		}

		printf("\n");
	}

	// 목숨 없음
	printf("You lose ....\n");
	printf("Answer is : ");
	for (int i = 0; i < answerLength; i++)
	{
		printf("%c", answer[i]);
	}

	return 1;
}