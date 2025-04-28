#include <iostream>

// base ----------------------------------------------
class Base
{
public:
	Base();
	Base(int value) : n(value) {};
	virtual ~Base();

	int GetValue();

protected:
	int n;
};

Base::Base()
{
	n = 1;
	std::cout << "Base 생성자 호출\n";
}

Base::~Base()
{
	std::cout << "Base 소멸자 호출\n";
}

int Base::GetValue()
{
	return n;
}

// myClass1 ----------------------------------------------
class MyClass1 : public Base
{
public:
	MyClass1();
	MyClass1(int value) : Base(value) {};
	~MyClass1();

private:
};

MyClass1::MyClass1()
{
	std::cout << "Myclass 생성자 호출\n";
}

MyClass1::~MyClass1()
{
	std::cout << "Myclass 소멸자 호출\n";
}

// main ----------------------------------------------

int main()
{
	MyClass1* my1 = new MyClass1(44);
	std::cout << my1->GetValue() << "\n";
	delete my1;

	Base* my2 = new MyClass1();
	std::cout << my2->GetValue() << "\n";
	delete my2;
}