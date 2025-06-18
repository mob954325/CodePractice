#include <iostream>

class Adder
{
public:
	Adder() {};
	~Adder() {};

	int operator()(const int& n1, const int& n2) { return n1 + n2; }
};

void Calc(int n1, int n2, Adder adder)
{
	std::cout << adder(n1, n2);
}

int main()
{
	Calc(1, 2, Adder());

	return 0;
}