#include <iostream>
#include <functional>

class CBase
{
public:
	CBase() {};
	~CBase() {};

	void Show() { std::cout << "Call CBase Show() " << iValue << std::endl; };
	void Show2(int a, int b) { std::cout << "Call CBase Show2() " << a << ", " << b << std::endl; }
private:
	int iValue = 1912931293;
};

void GFunc1()
{
	std::cout << "Call GFunc1" << std::endl;
}

void GFunc2(int a, int b)
{
	std::cout << "Call GFunc2 " << "args --> " << a << "," << b << std::endl;
}

int main()
{
	// 일반 함수 저장
	std::function<void()> function1; // 함수를 객체처럼 저장
	function1 = GFunc1;
	function1();

	// 람다 함수 저장
	std::function<void()> function2;
	function2 = [](){ std::cout << "Call lambda expression function" << std::endl; };
	function2();

	// 매개변수 있는 람다 함수 저장
	std::function<void(int, int)> function3;
	function3 = [](int a, int b) { std::cout << "a : " << a << ", b : " << b << std::endl; };
	function3(11, 22);

	// 전역 함수 바인딩
	auto bound1 = std::bind(GFunc2, std::placeholders::_1, std::placeholders::_2);
	bound1(44, 55);

	// 클래스 바인딩
	CBase cbase;
	auto bound2 = std::bind(&CBase::Show, &cbase);
	bound2();

	auto bound3 = std::bind(&CBase::Show2, &cbase, std::placeholders::_1, std::placeholders::_2);
	bound3(88, 99);

	// function으로 함수 래핑 후 bind로 호출하기
	std::function<void()> function4;
	function4 = GFunc1;

	auto bound4 = std::bind(&GFunc1);
	bound4();

	// bind으로 함수 조립 후 callable 객체 호출
	auto bound5 = std::bind(&CBase::Show2, &cbase, std::placeholders::_1, std::placeholders::_2); // 함수와 인자 조립 | std::bind
	std::function<void(int, int)> function5 = bound5; // callable 객체를 저장
	function5(1, 2);
	
	// 캡처 사용
	int data = 22222;
	std::function<void()> function6 = [data]() { std::cout << "Call Capture lambda, Data : " << data << std::endl; };
	function6();

	// 멤버 함수 포인터 + std::Fucntion 직접연결
	std::function<void(CBase*, int, int)> function7 = &CBase::Show2;
	function7(&cbase, 10, 20);

	int a = 0;
}