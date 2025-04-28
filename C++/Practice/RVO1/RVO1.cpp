#include <iostream>

class Foo 
{
public:
	Foo(const std::string& name)
	{
		this->name = name;
		std::cout << "This is " << name << " constructor.\n";
	}
	~Foo()
	{
		std::cout << "This is " << this->name << " desstructor.\n";
	}
	Foo(const Foo& rhs)
	{
		this->name = rhs.name;
		std::cout << "This is " << rhs.name << " copy constructor.\n";
	}
	Foo& operator=(const Foo& rhs)
	{
		std::cout << "This is " << this->name << " copy operator.\n";
		return *this;
	}

private:
	std::string name;
};

// NRVO ( Named Return Value Optimization )
Foo MakeFoo(const std::string& name)
{
	Foo foo(name);
	return foo;
}

// RVO ( Return Value Optimization )
Foo MakeFoo2(const std::string& name)
{
	return Foo(name);
}

int main()
{
	auto foo = MakeFoo("foo1");		// 복사 생성자가 호출되어아햐는데 최적회되서 기본생성자로 호출됨
	auto foo2 = MakeFoo2("foo2");

	std::cout << "-- end --\n";
	return 0;
}