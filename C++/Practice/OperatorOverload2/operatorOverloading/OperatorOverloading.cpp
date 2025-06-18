#include <iostream>

class Complex
{
private:
	int real;
	int image;
public:
	Complex(int r = 0, int i = 0);
	void Show();

	Complex& operator++()
	{
		++this->real;
		++this->image;
		return *this;
	}

	Complex operator++(int)
	{
		Complex temp = *this;

		++this->real;
		++this->image;

		return temp;
	}

	friend Complex& operator--(Complex& c)
	{
		--c.real;
		--c.image;

		return c;
	}

	friend Complex operator--(Complex& c, int)
	{
		Complex temp = c;
		--c.real;
		--c.image;

		return temp;
	}
};

Complex::Complex(int r, int i)
{
	real = r;
	image = i;
}

void Complex::Show()
{
	std::cout << image << " " << real << "\n";
}

void main()
{
	int n = 0;

	Complex a(10, 20);
	Complex b;

	std::cout << "--- 선행 처리 ---\n";
	b = ++a;
	a.Show();
	b.Show();

	std::cout << "--- 후행 처리 ---\n";
	b = a++;
	a.Show();
	b.Show();

	std::cout << "--- 후행 처리 ---\n";
	b = a--;
	a.Show();
	b.Show();
	b.Show();
}