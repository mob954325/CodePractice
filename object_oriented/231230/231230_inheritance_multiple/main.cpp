#include <iostream>

using namespace std;

class ParentA {
public:
	int _value;
	int _value1;

	ParentA(int value, int value1)
		:_value(value), _value1(value1) {}

	void Print()
	{
		cout << "ParentA::_value = " << _value << endl;
		cout << "ParentA::_value1 = " << _value1 << endl;
	}
};

class ParentB{
public:
	int _value;
	int _value2;

	ParentB(int value, int value2)
		:_value(value), _value2(value2){}

	void Print() {
		cout << "ParentB::_value = " << _value << endl;
	}
};

class ChildD : public ParentA, public ParentB {
public:
	ChildD(int valueA, int valueA1, int valueB, int valueB1)
		: ParentA(valueA, valueA1), ParentB(valueB, valueB1){}
};

int main()
{
	ChildD childd(1, 10, 2, 30);

	childd.ParentB::Print();

	childd.ParentB::_value = 20;
}