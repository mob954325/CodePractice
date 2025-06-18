// =	// 대입연산자 정의하기  // 복사 대입 연산자 (복사 생성자를 참고하세요)

#include <iostream>
using namespace std;

class CMyData
{
private:
	int m_nData = 0;
public:
	//변환 생성자
	CMyData(int nParam) : m_nData(nParam) {
		cout << "CMyData(int)" << endl;
	}

	// +	// CMyData 리턴
	CMyData operator+(const CMyData& rhs)
	{
		//cout << "operator+" << endl;
		CMyData result(0);
		result.m_nData = this->m_nData + rhs.m_nData;
		return result;
	}

	// =	// 대입연산자 정의하기	// CMyData& 리턴
	CMyData& operator=(const CMyData& rhs)
	{
		m_nData = rhs.m_nData;
		return *this;
	}

	friend std::ostream& operator<<(std::ostream& o, const CMyData& rhs);
};

std::ostream& operator<<(std::ostream& o, const CMyData& rhs)
{
	std::cout << rhs.m_nData;
	return o;
}

int main()
{
	CMyData a(0), b(3), c(4);

	a = b + c;	// 연산을 수행하면 이름 없는 임시 객체가 만들어지며 a에 대입하는 것은 이 임시객체다.
	(a = b) = c;

	cout << a << endl;

	a = b;		// = 연산자 정의 없이도 실행됨 이유는?   //자동으로 생성되는 '특수 맴버함수'

	return 0;
}
