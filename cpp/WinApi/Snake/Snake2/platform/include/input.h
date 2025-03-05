// 입력할 키 정의
#pragma once
#include <windows.h>

struct Button
{
	bool pressed = 0;	// true in the first frame it is pressed
	bool held = 0;		// true while is pressed
	bool released = 0;	// true while is released

	enum
	{
		A = 0,
		B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z,
		Escape,
		BUTTONS_COUNT, // 최종 버튼 enum 개수
	};

	static constexpr int buttonValues[BUTTONS_COUNT] =
	{
		'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L',
		'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
		VK_ESCAPE,
	};
};

struct Input
{
	Button keyBoard[Button::BUTTONS_COUNT];

	bool focused = false;
};

void inputAfter(Input& input);

void resetInput(Input& input);

void pressEventButton(Button& b, bool state);