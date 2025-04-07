#include <iostream>

struct Vector2
{
	Vector2(float _x, float _y) : x(_x), y(_y) {}
	Vector2 operator+(Vector2& other);
	void Display() { printf("%.2f, %.2f\n", x, y); }
private:
	float x;
	float y;
};

Vector2 Vector2::operator+(Vector2& other)
{
	return Vector2(x + other.x, y + other.y);
}

int main()
{
	Vector2 v1 = Vector2(1.2f, 2.4f);
	Vector2 v2 = Vector2(2.3f, 3.6f);
	Vector2 v3 = Vector2(0.0f, 0.0f);

	v3.Display();
	v3 = v1 + v2;
	v3.Display();
}


