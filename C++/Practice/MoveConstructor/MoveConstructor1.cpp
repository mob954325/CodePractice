#include <iostream>
#include <string.h>

using namespace std;

class CTest
{
public:
	CTest() { cout << "CTest()\n"; };
	CTest(const CTest& cTest) { cout << "CTest(const CTest& cTest)\n"; }
	CTest& operator= (const CTest&) { cout << "Test& operator= (const CTest&)\n"; return *this; }
	CTest(CTest&&) noexcept { cout << "CTest(CTest&&) \n"; }
	CTest& operator= (const CTest&&) noexcept { cout << "CTest& operator= (const CTest&&)\n"; return *this; }
	~CTest() { cout << "~CTest()\n"; };

};

int main() 
{
	CTest t1;				// 생성자
	CTest t2(t1);			// 복사 생성자
	t2 = t1;				// 복사 대입 생성자
	CTest t3(move(t1));		// 이동 생성자
	t3 = CTest();			// 이동 대입 생성자
}