//주요 연산자오버로드에 대한 사용예시를 작성하세요.

//산술연산자 + - * %
//비교연산자 < > <= >= == !=
//부호연산자 + -
//출력연산자 
//배열연산자[]
//함수연산자()
//포인터연산자 * ->
#include <iostream>

using namespace std;

class MyClass
{
private:
	int m_data = 0;
	int* ptr = nullptr;
public:
	MyClass(int data) : m_data(data) 
	{
		ptr = new int[3];

		for (int i = 0; i < 3; i++)
		{
			ptr[i] = i + 1;
		}
	};

	~MyClass() {};

	void Show() { cout << m_data << "\n"; }

#pragma region 산술 연산자
	// +
	MyClass operator+(const MyClass& rhs)
	{
		return MyClass(m_data + rhs.m_data);
	}

	// - 
	MyClass operator-(const MyClass& rhs)
	{
		return MyClass(m_data - rhs.m_data);
	}

	// *
	MyClass operator*(const MyClass& rhs)
	{
		return MyClass(m_data * rhs.m_data);
	}

	// %
	MyClass operator%(const MyClass& rhs)
	{
		return MyClass(m_data % rhs.m_data);
	}
#pragma endregion

#pragma region 비교 연산자
	// < 
	bool operator<(const MyClass& rhs) const
	{
		return m_data < rhs.m_data;
	}

	// > 
	bool operator>(const MyClass& rhs) const
	{
		return m_data > rhs.m_data;
	}

	// <= 
	bool operator<=(const MyClass& rhs) const
	{
		return m_data <= rhs.m_data;
	}

	// >=
	bool operator>=(const MyClass& rhs) const
	{
		return m_data >= rhs.m_data;
	}

	// == 
	bool operator==(const MyClass& rhs) const
	{
		return m_data == rhs.m_data;
	}

	// !=
	bool operator!=(const MyClass& rhs) const
	{
		return m_data == rhs.m_data;
	}
#pragma endregion

#pragma region 부호 연산자
	// +
	MyClass operator+()
	{
		if (m_data < 0)
		{
			return MyClass(-m_data);
		}
		else
		{
			return MyClass(m_data);
		}
	}

	// -
	MyClass operator-()
	{
		if (m_data > 0)
		{
			return MyClass(-m_data);
		}
		else
		{
			return MyClass(m_data);
		}
	}
#pragma endregion

#pragma region 출력 연산자
	friend std::ostream& operator<<(std::ostream& os, MyClass myClass);

#pragma endregion

#pragma region 배열 연산자
	int operator[](int index) const
	{
		return ptr[index];
	}

	int& operator[](int index)
	{
		return ptr[index];
	}

#pragma endregion
};

// 출력 연산자
std::ostream& operator<<(std::ostream& os, MyClass myClass)
{
	os << myClass.m_data;
	return os;
}

// 함수 연산자
class Adder
{
public:
	Adder() {};
	~Adder() {};

	int operator()(const int& n1, const int& n2) { return n1 + n2; }
};

int Calc(int n1, int n2, Adder add)
{
	return add(n1, n2);
}

// 포인터 연산자
class SmartPtr
{
private:
	MyClass* ptr;

public:
	SmartPtr(MyClass* pClass) : ptr(pClass) {};
	~SmartPtr() { delete ptr; };

	MyClass& operator*() { return *ptr; }
	MyClass* operator->() { return ptr; }
};

int main()
{
	MyClass a(1);
	MyClass b(2);

	MyClass c = a + b;
	cout << c << "\n";

	c = a - b;
	cout << c << "\n";

	c = a * b;
	cout << c << "\n";

	c = a % b;
	cout << c << "\n";

	cout << "< : " << ((a < b) ? "True" : "False") << "\n";
	cout << "> : " << ((a > b) ? "True" : "False") << "\n";
	cout << "<= : " << ((a <= b) ? "True" : "False") << "\n";
	cout << ">= : " << ((a >= b) ? "True" : "False") << "\n";
	cout << "== : " << ((a == b) ? "True" : "False") << "\n";
	cout << "!= : " << ((a != b) ? "True" : "False") << "\n";
	
	MyClass d(-1);
	cout << +d << "\n"; // 1
	cout << -a << "\n"; // -1

	cout << "Array" << a[1] << "\n";

	cout << "Function : " << Calc(1, 2, Adder()) << "\n";

	cout << "-- Pointer --\n";
	MyClass* e = new MyClass(5);
	SmartPtr ePtr(e);
	(*e).Show();
	e->Show();
}