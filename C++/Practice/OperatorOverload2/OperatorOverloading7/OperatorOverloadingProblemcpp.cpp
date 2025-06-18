#include <iostream>
using namespace std;

class CMyData
{
private:
	int m_nData = 0;
public:
	CMyData(int nParam) : m_nData(nParam) {}

	// +
	CMyData operator+(const CMyData& rhs)
	{
		return CMyData(m_nData + rhs.m_nData);
	}

	// + 단항
	CMyData operator+()
	{
		if (m_nData < 0)
		{
			return CMyData(-m_nData);
		}
		else
		{
			return CMyData(m_nData);
		}
	}

	// ++
	CMyData operator++()
	{
		return CMyData(++m_nData);
	}

	// ++(int)
	CMyData operator++(int)
	{
		CMyData temp = *this;
		m_nData++;

		return temp;
	}

	// <
	bool operator<(const CMyData& rhs) const
	{
		return m_nData < rhs.m_nData;
	}

	// >
	bool operator>(const CMyData& rhs) const
	{
		return m_nData > rhs.m_nData;
	}
};


void main()
{
	CMyData a(1);
	CMyData b(2);

	CMyData c = a + b;

	c = +a;

	c = ++a;

	c = a++;

	cout << (a > b) << endl;
	cout << (a < b) << endl;
}