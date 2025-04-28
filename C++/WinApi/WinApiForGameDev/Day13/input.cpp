#include <Windows.h>
#include <input.h>


void processInputAfter(Input& input)
{
	for (int i = 0; i < Button::BUTTONS_COUNT; i++) // 모든 키 초기화
	{
		input.keyBoard[i].pressed = 0;
		input.keyBoard[i].released = 0;
		input.keyBoard[i].altWasDown = 0;
	}

	input.lMouseButton.pressed = 0;
	input.lMouseButton.released = 0;
	input.lMouseButton.altWasDown = 0;

	input.rMouseButton.pressed = 0;
	input.rMouseButton.released = 0;
	input.rMouseButton.altWasDown = 0;
}

void resetInput(Input& input)
{
	input.lMouseButton = {};
	input.rMouseButton = {};

	// https://learn.microsoft.com/en-us/previous-versions/windows/desktop/legacy/aa366920(v=vs.85)
	ZeroMemory(input.keyBoard, sizeof(input.keyBoard)); // 모든 메모리 0으로 채우기 => 메모리 비우기?
	ZeroMemory(input.typedInput, sizeof(input.typedInput));
}

//newState == 1 means pressed else released
void processEventButton(Button& b, bool newState)
{
	if (newState)
	{
		if (!b.held) // 안 눌렀을 때만 처리
		{
			b.pressed = true;
			b.held = true;
			b.released = false;
		}
	}
	else
	{
		b.pressed = false;
		b.held = false;
		b.released = true;
	}
}