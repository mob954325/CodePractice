#include <iostream>

int main()
{
	int data = 1234;
	std::cout << &data << "\n";
	std::cin.get();

	while (true)
	{
		std::cout << data << "\n"; // data 값 반복 표시
	}

	return 0;
}