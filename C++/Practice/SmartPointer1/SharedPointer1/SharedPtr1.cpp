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

// Object객체를 공유해서 사용 -> 참조 카운트 증가
void Play(std::shared_ptr<Object> o)
{
	o->Show(); // 공유된 인스턴스 사용
} // 참조 카운트 감소

int main()
{
	std::shared_ptr<Object> obj1 = std::make_shared<Object>();

	Play(obj1);
	// Play(std::move(obj1)); -> 소유권 이전으로 제거됨 unique_ptr과 동일

	obj1->Show();
} // obj1 소멸자 호출