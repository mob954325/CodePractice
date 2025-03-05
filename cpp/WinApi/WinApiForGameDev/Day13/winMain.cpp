#include <iostream>
#include <Windows.h>
#include <input.h> // �ش� ������Ʈ�� ���ǵ� �ش�����

// Day 12�� �ٸ� �� : ���콺 ��ǲ, ���콺 ��ġ, Ű���� �Է� �ް� ���

struct WindowStuff 
{
	bool running = true;
	Input input;
};

WindowStuff windowStuff;

//this is the function that will process all of the windows' messages.
LRESULT windProc(HWND wind, UINT msg, WPARAM wp, LPARAM lp)
{
	LRESULT rez = 0; // ������ �˸� �޼��� ��

	bool pressed = 0;

	switch (msg)
	{
		//if the window is closed we want to handle that case and signal that to our program
	case WM_CLOSE:
		windowStuff.running = false;
	break;

	case WM_LBUTTONDOWN:
		processEventButton(windowStuff.input.lMouseButton, true);
		break;
	case WM_LBUTTONUP:
		processEventButton(windowStuff.input.lMouseButton, false);
		break;
	case WM_RBUTTONDOWN:
		processEventButton(windowStuff.input.rMouseButton, true);
		break;
	case WM_RBUTTONUP:
		processEventButton(windowStuff.input.rMouseButton, false);
		break;

	case WM_SYSKEYDOWN: // Ű ����
	case WM_KEYDOWN:
		pressed = 1;
	case WM_SYSKEYUP:
	case WM_KEYUP:
	{
		// this tells us if alt was down, lp is the last parameter of windProc
		bool altWasDown = lp & (1 << 29); // ??

		for (int i = 0; i < Button::BUTTONS_COUNT; i++)
		{
			if (wp == Button::buttonValues[i]) // wp : �ش� �Ķ���Ϳ��� Ű�Է��� ����
			{
				processEventButton(windowStuff.input.keyBoard[i], pressed);
				windowStuff.input.keyBoard[i].altWasDown = altWasDown;	// ��� ��ư alt �÷��� ����
			}
		}

		if (pressed)
		{
			for (int i = 0; i < sizeof(windowStuff.input.typedInput) - 1; i++)
			{
				if (windowStuff.input.typedInput[i] == 0)
				{
					windowStuff.input.typedInput[i] = wp; // �Է� �޴� Ű �迭�� ����
					break;
				}
			}
		}

		// so altf4 works
		rez = DefWindowProc(wind, msg, wp, lp);
	}break;

	case WM_SETFOCUS: // Ű���� ��Ŀ�� �˸� (Ű���� �Է� �˸�)
		windowStuff.input.focused = true;
		break;

	case WM_KILLFOCUS: // Ű���� ��Ŀ�� ����
		windowStuff.input.focused = false;
		break;
	default:
		//there are many messages that we didn't treat so we want to call the default window callback for those...
		rez = DefWindowProc(wind, msg, wp, lp); // �� �� defualt �˸� ó��
	break;
	}

	return rez;
}

int main()
{
	WNDCLASS wc = { sizeof(WNDCLASS) };

	wc.hCursor = LoadCursor(0, IDC_ARROW);	// so we have a cursor for our window
	wc.hInstance = GetModuleHandle(0);		// program instance
	wc.lpszClassName = "EpicWindowClass";
	wc.style = CS_HREDRAW | CS_VREDRAW;		// refresh window on resize
	wc.lpfnWndProc = windProc;				// pass our callback function
	
	if (!RegisterClass(&wc)) { return 0; };

	HWND wind = CreateWindowA(
		wc.lpszClassName,
		"We have a Window!",				//window title
		WS_OVERLAPPEDWINDOW | WS_VISIBLE,	//default window
		CW_USEDEFAULT,						//position x
		CW_USEDEFAULT,						//position y
		CW_USEDEFAULT,						//size x
		CW_USEDEFAULT,						//size y
		0, 0, GetModuleHandle(0), 0			//other uninteresting stuff
	);

	while (windowStuff.running)
	{
#pragma region get message
		MSG msg = {};
		while (PeekMessage(&msg, wind, 0, 0, PM_REMOVE) > 0) //remove all mesages from queue
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
#pragma endregion


#pragma region other input

		if (!windowStuff.input.focused)
		{
			resetInput(windowStuff.input);
		}

		POINT point;
		GetCursorPos(&point);
		ScreenToClient(wind, &point);
		windowStuff.input.cursorX = point.x;
		windowStuff.input.cursorY = point.y;

#pragma endregion

#pragma region KeyInput
		// typed input
		{
			bool shiftWasPressed = windowStuff.input.keyBoard[Button::Shift].held;

			// CapsLock is on
			if ((GetKeyState(VK_CAPITAL) & 0x0001) != 0)
			{
				shiftWasPressed = !shiftWasPressed;
			}

			for (int i = 0; i < sizeof(windowStuff.input.typedInput) - 1; i++)
			{
				char& c = windowStuff.input.typedInput[i];
				if (c == 0) break;

				if (c > 0 && std::isalpha(c)) // isAlpha�� ������ ������ crash��?
				{
					if (shiftWasPressed)
					{
						c = std::toupper(c);
					}
					else
					{
						c = std::tolower(c);
					}
				}
				else if (c > 0 && std::isdigit(c))
				{
					// ���� �Է�
					char nums[] = { '1', '2', '3', '4', '5', '6', '7', '8', '9', '0' };
	
					for (int j = 0; j < sizeof(nums); j++)
					{
						if (c == nums[j])
						{
							c = nums[j];
						}
					}
				}
				else // Ư�� ����
				{
					char codes[] = { VK_SPACE, VK_RETURN, VK_BACK,
									VK_OEM_PLUS, VK_OEM_PERIOD, VK_OEM_MINUS,
									VK_OEM_COMMA, VK_OEM_1, VK_OEM_2, VK_OEM_3,
									VK_OEM_7, VK_OEM_5, VK_OEM_4, VK_OEM_6 };

					char chars[] = { ' ', '\n', '\b', '+', '.', '-', ',', ';', '/', '`',
						'\'', '\\', '[', ']' };

					static_assert(sizeof(codes) == sizeof(chars)); // size ������ Ȯ��

					bool found = false;
					for (int j = 0; j < sizeof(chars); j++)
					{
						if (c == codes[j])
						{
							c = chars[j];
							found = true;
						}
					}

					if (!found)
					{
						//remove this character completely from the array
						for (int j = i; i < sizeof(windowStuff.input.typedInput) - 1; i++)
						{
							windowStuff.input.typedInput[j] = windowStuff.input.typedInput[j + 1]; // �������� �Ѱܼ� ����
						}
					}
				}
			}
		}

#pragma endregion
		// game code and other stuff
		// 
		
		//if (windowStuff.input.keyBoard[Button::A].pressed)
		//{
		//	std::cout << "Pressed!\n";
		//}
		
		//std::cout << (int)windowStuff.input.keyBoard[Button::A].held << "\n";

		//std::cout << (int)windowStuff.input.focused << "\n";

		//if (windowStuff.input.keyBoard[Button::A].released)
		//{
		//	std::cout << "Released!\n";
		//}

		//if (windowStuff.input.lMouseButton.pressed)
		//{
		//	std::cout << "Pressed!\n";
		//}

		//if (windowStuff.input.rMouseButton.pressed)
		//{
		//	std::cout << "Pressed!\n";
		//}
		
		//std::cout << windowStuff.input.cursorX << " " << windowStuff.input.cursorY << "\n";

		if (windowStuff.input.keyBoard[Button::A].pressed
			&& windowStuff.input.keyBoard[Button::A].altWasDown)
		{
			std::cout << "Pressed! + Alt\n";
		}

		//std::cout << windowStuff.input.typedInput << "\n";

		processInputAfter(windowStuff.input);
	}

	return 0;
}

// Ű �Է� ��ũ��Ʈ 
// ����ؾ��� ���� : ��ư�� ��� ���� �� (������ ȯ���� �Է��� ����� ���������� �Է��ϴ� ������ ����)
//				   ��ư ���� ������ �˸��� ���� �� ( ��� : ���� ���·� â ��Ŀ�� �����)