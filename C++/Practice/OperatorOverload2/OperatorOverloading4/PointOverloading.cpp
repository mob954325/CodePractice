#include <iostream>

using namespace std;

class IntPtr
{
private:
	int* ptr;
public:
	IntPtr(int* ptr) : ptr(ptr) { }
	~IntPtr() { delete ptr; }

	int a = 0;

	int& operator*() { return *ptr; }
	int* operator->() { return ptr; }
};

class Foo
{
public:
	Foo() {};
	~Foo() {};

private:

};

void main()
{
	IntPtr sptr(new int(1));

	*sptr = 2;
	cout << *sptr << endl;

	IntPtr* pptr = new IntPtr(new int(2));
	pptr->a;
	sptr.a;

	delete pptr;

	// smart pointer
	unique_ptr<Foo> pfoo(new Foo());

	{
		unique_ptr<Foo> mpfoo(new Foo());
	}
}