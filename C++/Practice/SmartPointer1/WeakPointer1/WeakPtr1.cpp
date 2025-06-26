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

int main()
{
	std::weak_ptr<Object> weakObj; // 소유권이 없는 Object 선언

	{
		// Object 인스턴스 생성 및 컨트롤 블록 생성
		std::shared_ptr<Object> obj1 = std::make_shared<Object>();
		std::shared_ptr<Object> obj2 = obj1; // obj1 참조 카운트 증가
		weakObj = obj1;	// weak_ptr는 참조 카운트 증가 x

		if (auto shared = weakObj.lock()) // lock() : shared pointer로 변환
		{
			shared->Show(); // 유효한 객체 사용
		}

		// obj1이 유효화면 weakObj도 유효함
	} // shared_tpr 소멸 -> Object 객체 삭제됨

	// weakObj는 expired 상태
	if(weakObj.expired()) // expired() : use_count == 0인지 확인
	{
		std::cout << "Object는 소멸되었습니다.\n";
	}

	// 다시 lock해도 nullptr 반환
	if (auto shared = weakObj.lock())
	{
		shared->Show(); // 호출안됨
	}
	else
	{
		std::cout << "weakObj는 더 이상 사용할 수 없습니다.";
	}

} // obj1은 더 이상 Object객체를 소유하고 있지않음