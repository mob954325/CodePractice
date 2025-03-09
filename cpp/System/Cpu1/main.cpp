#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue>
#include <vector>

#pragma warning(disable:4996)
#define _CRT_SECURE_NO_WARNNING

using namespace std;

typedef struct {
	int AX, BX, CX, DX; // 레지스터
	int CMPX;			// 비교 레지스터 (0 : 값없음, 1 : true, 2 : false)
	int memory[256];	// 메모리 배열 
} CPU;

CPU cpu{ 0, 0, 0, 0, {0}}; // 초기화

// 명령어를 배열로 저장하기
const int MAXSIZE = 10;
const char* instructions[MAXSIZE];

int programCounter = 0;

void Fetch(const char* instruction)
{
	for (int i = 0; i < MAXSIZE; i++)
	{
		if (instructions[i] == NULL)
		{
			instructions[i] = instruction;
			break;
		}
	}
}

void Execute()
{
	// pc 값 초과시
	if (programCounter >= MAXSIZE)
	{
		programCounter = 0; // 포인터 초기화
	}
	// 배열값이 없음
	if (instructions[programCounter] == "")
	{
		printf("No instruction\n");
		return;
	}

	// 명령어 순차적 수행
	const char* instruction = instructions[programCounter];

	char op[10], arg1[10], arg2[10];
	sscanf(instruction, "%s %s %s", op, arg1, arg2);

	// MOV, ADD, SUB
	if (strcmp(op, "MOV") == 0)
	{
		if (strcmp(arg1, "AX") == 0)
		{
			cpu.AX = atoi(arg2);
		}
		else if (strcmp(arg1, "BX") == 0)
		{
			cpu.BX = atoi(arg2);
		}
		else if (strcmp(arg1, "CX") == 0)
		{
			cpu.CX = atoi(arg2);
		}
		else if (strcmp(arg1, "DX") == 0)
		{
			cpu.DX = atoi(arg2);
		}
		else // cpu 주소 저장
		{
			int address = atoi(arg1);
			if (strcmp(arg2, "AX") == 0) cpu.memory[address] = cpu.AX;
			else if(strcmp(arg2, "BX") == 0) cpu.memory[address] = cpu.BX;
			else if(strcmp(arg2, "CX") == 0) cpu.memory[address] = cpu.CX;
			else if(strcmp(arg2, "DX") == 0) cpu.memory[address] = cpu.DX;
		}
	}
	else if (strcmp(op, "ADD") == 0)
	{
		if (strcmp(arg1, "AX") == 0)
		{
			if (strcmp(arg2, "BX") == 0)
			{
				cpu.AX = cpu.AX + cpu.BX;
			}
		}
	}
	else if (strcmp(op, "SUB") == 0)
	{
		if (strcmp(arg1, "AX") == 0)
		{
			if (strcmp(arg2, "BX") == 0)
			{
				cpu.AX = cpu.AX - cpu.BX;
			}
		}
	}
	else if (strcmp(op, "PRINT") == 0)
	{
		if (strcmp(arg1, "AX") == 0)
		{
			printf("%d\n", cpu.AX);
		}
		else if (strcmp(arg1, "BX") == 0)
		{
			printf("%d\n", cpu.BX);
		}
		else if (strcmp(arg1, "CX") == 0)
		{
			printf("%d\n", cpu.CX);
		}
		else if (strcmp(arg1, "DX") == 0)
		{
			printf("%d\n", cpu.DX);
		}
	}
	else if (strcmp(op, "JMP") == 0)
	{
		int count = atoi(arg1);
		programCounter = count;
		Execute();
	}
	else if (strcmp(op, "JZ") == 0)
	{
		if (cpu.CMPX == 1)
		{
			int count = atoi(arg1);
			programCounter = count;
			cpu.CMPX = 0;
		}
	}
	else if (strcmp(op, "JNZ") == 0)
	{
		if (cpu.CMPX == 2)
		{
			int count = atoi(arg1);
			programCounter = count;
			cpu.CMPX = 0;
		}
	}
	else if (strcmp(op, "JUMP") == 0)
	{
		int count = atoi(arg1);
		programCounter = count;
		return;
	}
	else if (strcmp(op, "CMP") == 0)
	{
		if (strcmp(arg1, "AX") == 0)
		{
			int value = atoi(arg2);
			if (cpu.AX == value)
			{
				cpu.CMPX = 1;
			}
			else
			{
				cpu.CMPX = 2;
			}
		}
		if (strcmp(arg1, "BX") == 0)
		{
			int value = atoi(arg2);
			if (cpu.BX == value)
			{
				cpu.CMPX = 1;
			}
			else
			{
				cpu.CMPX = 2;
			}
		}
		if (strcmp(arg1, "CX") == 0)
		{
			int value = atoi(arg2);
			if (cpu.CX == value)
			{
				cpu.CMPX = 1;
			}
			else
			{
				cpu.CMPX = 2;
			}
		}
		if (strcmp(arg1, "DX") == 0)
		{
			int value = atoi(arg2);
			if (cpu.DX == value)
			{
				cpu.CMPX = 1;
			}
			else
			{
				cpu.CMPX = 2;
			}
		}
	}

	instructions[programCounter] = ""; // 명령초기화
	programCounter >= MAXSIZE ? programCounter = 0 : programCounter++;
}

int main()
{
	Fetch("MOV AX 2");
	Fetch("MOV BX 3");
	Fetch("ADD AX BX");
	Fetch("PRINT AX");
	Fetch("MOV AX 2");
	Fetch("SUB AX BX");
	Fetch("JUMP 8");
	Fetch("");
	Fetch("MOV 2 AX");
	Fetch("MOV 1 BX");

	for (int i = 0; i < MAXSIZE; i++)
	{
		Execute();
	}

	return 0;
}