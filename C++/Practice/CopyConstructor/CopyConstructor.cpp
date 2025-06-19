#include <iostream>
#include <string.h>

class Person
{
public:
	Person(const char* str)
	{
		name = new char[strlen(str) + 1];
		strcpy_s(name, strlen(str) + 1, str);
	};
	Person(const Person& per)
	{
		name = new char[strlen(per.name) + 1];
		strcpy_s(name, strlen(per.name) + 1, per.name);
	}

	Person& operator=(const Person& other)
	{
		if (this != &other)
		{
			delete name;
			name = new char[strlen(other.name) + 1];
			strcpy_s(name, strlen(other.name) + 1, other.name);
		}

		return *this;
	}

	~Person() { delete[] name; };

private:
	char* name = nullptr;
};

int main()
{
	Person p1("name");
	Person p2 = p1;

	p2 = p1;

	int a = 0;
}