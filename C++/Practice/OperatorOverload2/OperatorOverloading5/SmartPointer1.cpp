#include <iostream>

class Pos
{
public:
	Pos(int x, int y) : x(x), y(y) { std::cout << "pos 객체 생성\n"; };
	~Pos() {};

	void SetPos(int x, int y) { this->x = x; this->y = y; }

	friend std::ostream& operator<<(std::ostream& os, const Pos& pos);
private:
	int x, y;
};

std::ostream& operator<<(std::ostream& os, const Pos& pos)
{
	os << pos.x << "," << pos.y;
	return os;
}

class SmartPtr
{
public:
	Pos* pos;

	SmartPtr(Pos* pos) : pos(pos) {}
	~SmartPtr() { delete pos; }

	Pos& operator*() { return *pos; }
	Pos* operator->() const { return pos; }
};

int main()
{
	SmartPtr position(new Pos(1, 1));
	position->SetPos(10, 10);
	std::cout << *position << "\n";

	Pos position2(2, 2);

	std::cout << position2;
}