#include <iostream>
#include <Windows.h>

int main()
{
	const char* name = "AAA";
	int hp = 100;
	int mp = 20;
	int exp = 111;

	int attackPower = 2;
	int defencePower = 1;

	std::cout << "exit : F1 \nsee Info : A \n";
	while (!(GetAsyncKeyState(VK_F1) & 0b1))
	{
		if (GetAsyncKeyState('A') & 0b1)
		{
			std::cout << "name : " << name << "\n";
			std::cout << "name address : " << &name << "\n";
			std::cout << "hp : " << hp << "\n";
			std::cout << "hp address : " << &hp << "\n";
			std::cout << "mp : " << mp << "\n";
			std::cout << "mp address : " << &mp << "\n";
			std::cout << "exp : " << exp << "\n";
			std::cout << "exp address : " << &exp << "\n";
			std::cout << "ap : " << attackPower << "\n";
			std::cout << "ap address : " << &attackPower << "\n";
			std::cout << "dp : " << defencePower << "\n";
			std::cout << "dp address : " << &defencePower << "\n";
			std::cout << "\n";
		}
	}

	std::cin.get();
	return 0;
}