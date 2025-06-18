#include <iostream>

using namespace std;

class MyClass
{
public:
	MyClass();
	MyClass(const MyClass& obj);
	~MyClass();
	MyClass& operator=(const MyClass& obj);

	void Show() { cout << n << "\n"; }
	int n = 0;
private:
	int* np = 0; // 배열
};

MyClass::MyClass()
{
	np = new int[3];
	cout << "MyClass()\n";
}

MyClass::~MyClass()
{
	delete[] np;
	cout << "~MyClass()\n";
}

MyClass::MyClass(const MyClass& obj)
{
	n = obj.n;
	np = new int[3];
	for (int i = 0; i < 3; i++) { np[i] = obj.np[i]; } // deep copy

	cout << "MyClass(const MyClass&)\n";
}

MyClass& MyClass::operator=(const MyClass& obj)
{
	n = obj.n;
	// np = obj.np; // shallow copy

	if (&obj == this) return *this;

	delete[] np;

	// deep copy
	np = new int[3];
	for (int i = 0; i < 3; i++) { np[i] = obj.np[i]; }
}

int main()
{
	MyClass a;
	a.n = 3;
	a.Show();

	MyClass b = a;	// 복사 생성자 호출
	b.Show();

	MyClass c;

	c = a; // 복사 대입연산자 호출

	return 0;
}