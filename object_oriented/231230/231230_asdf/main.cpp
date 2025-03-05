#include <iostream>
#include <string>

using namespace std;

// 카페에서 Barista, Cashier, Guest의 각 역할

	// 순수가상함수를 하나라도 가지고 있는 클래스를 추상클래스
	// 추상 클래스는 자기자신의 객체를 만들 수 없게됨
// 추상클래스를 상속받은 자식 클래스는 반드시 부모의 순수가상함수를 구현해야됨.
class Drink {
private:
	string _name;
public:
	Drink(string name)
		:_name(name) {}

	virtual void MakeDrink() = 0; // 순수가상함수

	string GetName()
	{
		return _name;
	}

};

class Coffee : public Drink {
public:
	Coffee()
		: Drink("커피") {}

	void MakeDrink() override // 일반함수
	{
		cout << "커피를 만듭니다." << '\n';
	}
};

class Aid : public Drink {
public:
	Aid()
		: Drink("에이드") {}

	void MakeDrink() override // 일반함수
	{
		cout << "에이드를 만듭니다." << '\n';
	}
};

class Cola : public Drink {
public:
	Cola()
		: Drink("콜라") {}

	void MakeDrink() override // 일반함수
	{
		cout << "콜라를 만듭니다." << '\n';
	}
};

class tea : public Drink {
public:
	tea()
		: Drink("차") {}

	void MakeDrink() override // 일반함수
	{
		cout << "차를 만듭니다." << '\n';
	}
};

class Barista {
public:
	void MakeADrink(Drink& drink) {
		drink.MakeDrink(); // MakeADrink는 가상함수여서 drink참조형 변수에 담긴 타입에 참조한 것만
	}

};

class Cashier {
private:
	Barista& _refBari;
public:
	Cashier(Barista& refBari) // barista를 참조받음
		:_refBari(refBari) {}

	void OrderedDrink(Drink& drink) {
		cout << drink.GetName() << "음료주문을 받습니다" << "\n";
		_refBari.MakeADrink(drink);
	}
};

class Guest {
public:
	void OrderingDrink(Cashier& cashier, Drink& drink) { // 의존적관계 (Dependency), 일시적 관계
		cout << drink.GetName() <<"음료를 주문합니다." << '\n';
		cashier.OrderedDrink(drink);
	}
};

int main() 
{
	Coffee coffee;
	Aid aid;
	Cola cola;
	tea Tea;

	Barista bari;
	Cashier cash(bari);
	Guest guest;

	guest.OrderingDrink(cash, coffee);
	cout << '\n';
	guest.OrderingDrink(cash, aid);
	cout << '\n';
	guest.OrderingDrink(cash, cola);
	cout << endl;
	guest.OrderingDrink(cash, Tea);
	cout << endl;
}