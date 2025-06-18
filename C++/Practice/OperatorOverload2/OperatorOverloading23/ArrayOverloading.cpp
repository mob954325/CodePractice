#include <iostream>

class MyArray
{
public:
	int* arr;
	int size = 0;

	MyArray(int n) { size = n; arr = new int[size]; }
	~MyArray() { size = 0; delete[] arr; };

	int size() { return size; }

	int& operator[](int index) { return arr[index]; }
	int operator[](int index) const { return arr[index]; }
};



int main()
{
	MyArray arr(8);
	arr[0] = 1;
	std::cout << arr[0] << "\n";

	const MyArray carr(4);
	std::cout << carr[0];
	std::cout << carr[0] << "\n";
}