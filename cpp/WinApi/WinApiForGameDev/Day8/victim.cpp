#include <iostream>

int main()
{
	int data = 1234;
	std::cout << &data << "\n";
	std::cin.get();

	while (true)
	{
		std::cout << data << "\n"; // data �� �ݺ� ǥ��
	}

	return 0;
}