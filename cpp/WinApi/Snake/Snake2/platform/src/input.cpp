#include <Windows.h>
#include <input.h>

void inputAfter(Input& input)
{
	for (int i = 0; i < Button::BUTTONS_COUNT; i++)
	{
		input.keyBoard[i].pressed = 0;
		input.keyBoard[i].released = 0;
	}
}

void resetInput(Input& input)
{
	ZeroMemory(input.keyBoard, sizeof(input.keyBoard));
}

void pressEventButton(Button& b, bool state)
{
	if (state)
	{
		if (!b.held)
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
		b.released = false;
	}
}