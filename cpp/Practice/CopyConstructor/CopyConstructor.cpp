#include <iostream>

class MyClass 
{
public:
	MyClass();
	MyClass(const MyClass& other); // 복사 생성자
};

MyClass::MyClass()
{
	std::cout << "기본 생성자\n";
}

MyClass::MyClass(const MyClass& other)
{
	std::cout << "복사 생성자\n";
}

int main()
{
	MyClass a;		// 기본 생성자 호출
	MyClass b = a;  // 복사 생성자 호출
}