#include <iostream>
#include <memory>

using namespace std;

class Object
{
public:
	Object() { cout << "Object 생성됨\n"; }
	~Object() { cout << "Object 소멸됨\n"; }
	void Show() { cout << "Call Show() function " << a << endl; }
private:
	int a = 11;
};

// 소유권을 이동받아 Object포인터 사용
void Play(std::unique_ptr<Object> o)
{
	o->Show(); // 소유권을 받은 객체 사용
} // o의 수명 끝

int main()
{
	std::unique_ptr<Object> obj1 = std::make_unique<Object>();

	obj1->Show();
	Play(std::move(obj1)); // obj1의 소유권?을 Play함수로 이동
	
	if (!obj1)
	{
		cout << "obj1은 nullptr 입니다.\n";
	}

	std::unique_ptr<Object> obj2 = std::make_unique<Object>();
	obj2.swap(obj1); // obj2의 내용dmf obj1으로 이동 : obj2은 nullptr
	if (!obj2)
	{
		cout << "obj1은 nullptr 입니다.\n";
	}

} // obj1은 더 이상 Object객체를 소유하고 있지않음