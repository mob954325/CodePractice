#include <iostream>

class MyClass 
{
public:
	MyClass();
	MyClass(const MyClass& other); // ���� ������
};

MyClass::MyClass()
{
	std::cout << "�⺻ ������\n";
}

MyClass::MyClass(const MyClass& other)
{
	std::cout << "���� ������\n";
}

int main()
{
	MyClass a;		// �⺻ ������ ȣ��
	MyClass b = a;  // ���� ������ ȣ��
}