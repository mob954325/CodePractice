#include <iostream>

class CTest
{
public:
	CTest() {};
	explicit CTest(int a) : num(a) {};
	explicit operator int() { return num; }

private:
	int num = 10;
};

int main()
{
	CTest t = CTest(1);
	int a = (int)t;
}