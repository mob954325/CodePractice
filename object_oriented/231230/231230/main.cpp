#include <iostream>

using namespace std;

class Parent {
public:   
	int _value;

	  Parent(int value) 
		  : _value(value) {}

	  Parent() 
		  : _value(0) {}
};
class ChildA : public Parent {
public:   
	int _valueA;

	  ChildA(int value, int valueA) 
		  : Parent(value), _valueA(valueA) {}

	  ChildA() 
		  : _valueA(0) {}
};

class ChildB : public Parent 
{
public:   
	int _valueB;

	  ChildB(int value, int valueB) 
		  : Parent(value), _valueB(valueB) {}

	  ChildB() 
		  : _valueB(0) {}
};

int main() 
{
	Parent parent(100);

	ChildA childA(200, 300); 
	ChildB childB(400, 500);
    
	parent = childA; // 자식타입의 객체의 값을 부모타입의 객체를 대입하는 경우 -> 값의 유실 발생
	                 // 객체 타입을 대입할 때는 참조타입이나 포인터 타입으로 대입한다.
	                 // 자식타입의 객체를 부모타입의 참조형 변수나 포인터 형변수에 대입을 하는 것을 -> UpCasting

	//childA = parent; // 그 반대는 DownCasting
	                 // 일반적인 경우에서는 허용하지 않음 -> 자식이 부모보다 가진게 많기 때문


	// 참조

	Parent& refParent = childA; // 업캐스팅 , childA객체가 refParent로 별칭 -> refParent는 항상 childA를 가르킨다.

	refParent._value = 200;

	// refParent는 childA의 Parent상속받은 부분만 접근가능 -> Parent& 타입이기 때문.
	cout << "refParent._value = " << refParent._value << endl;

	// 다운캐스팅이 허용되는 경우
	// 일반적인 경우에는 다운캐스팅이 허용되지 않지만 이 경우는 허용이됨
	// ChildA타입을 Parent& 타입으로 받았다가 다시 ChildA의 참조타입(&)으로 대입하는 경우에는 가능하다
	ChildA& refChildA = (ChildA&)refParent;

	cout << "refChildA._value = " << refChildA._value << endl;
	cout << "refchildA._valueA = " << refChildA._valueA << endl;

	// 포인터
	
	Parent* pParent; // Parent타입 주소값저장하는 변수
	
	// 업캐스팅
	pParent = &childA; // childA의 주소값을 pPrant변수에 받음 

	pParent->_value;
	// pParnet 포인터형 변수로 접근 할 수 있는 것은 부모의 영역만 접근이 가능하다.

	cout << "pParent->_value = " << pParent->_value << endl;

	ChildA* pChildA = (ChildA*)pParent; // 다운 캐스팅

	cout << "ChildA->_value = " << pChildA->_value << endl;
	cout << "pChildA->_value = " << pChildA->_value << endl;

	return 0;
}