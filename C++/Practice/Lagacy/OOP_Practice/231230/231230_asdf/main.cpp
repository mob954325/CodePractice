#include <iostream>
#include <string>

using namespace std;

// ī�信�� Barista, Cashier, Guest�� �� ����

	// ���������Լ��� �ϳ��� ������ �ִ� Ŭ������ �߻�Ŭ����
	// �߻� Ŭ������ �ڱ��ڽ��� ��ü�� ���� �� ���Ե�
// �߻�Ŭ������ ��ӹ��� �ڽ� Ŭ������ �ݵ�� �θ��� ���������Լ��� �����ؾߵ�.
class Drink {
private:
	string _name;
public:
	Drink(string name)
		:_name(name) {}

	virtual void MakeDrink() = 0; // ���������Լ�

	string GetName()
	{
		return _name;
	}

};

class Coffee : public Drink {
public:
	Coffee()
		: Drink("Ŀ��") {}

	void MakeDrink() override // �Ϲ��Լ�
	{
		cout << "Ŀ�Ǹ� ����ϴ�." << '\n';
	}
};

class Aid : public Drink {
public:
	Aid()
		: Drink("���̵�") {}

	void MakeDrink() override // �Ϲ��Լ�
	{
		cout << "���̵带 ����ϴ�." << '\n';
	}
};

class Cola : public Drink {
public:
	Cola()
		: Drink("�ݶ�") {}

	void MakeDrink() override // �Ϲ��Լ�
	{
		cout << "�ݶ� ����ϴ�." << '\n';
	}
};

class tea : public Drink {
public:
	tea()
		: Drink("��") {}

	void MakeDrink() override // �Ϲ��Լ�
	{
		cout << "���� ����ϴ�." << '\n';
	}
};

class Barista {
public:
	void MakeADrink(Drink& drink) {
		drink.MakeDrink(); // MakeADrink�� �����Լ����� drink������ ������ ��� Ÿ�Կ� ������ �͸�
	}

};

class Cashier {
private:
	Barista& _refBari;
public:
	Cashier(Barista& refBari) // barista�� ��������
		:_refBari(refBari) {}

	void OrderedDrink(Drink& drink) {
		cout << drink.GetName() << "�����ֹ��� �޽��ϴ�" << "\n";
		_refBari.MakeADrink(drink);
	}
};

class Guest {
public:
	void OrderingDrink(Cashier& cashier, Drink& drink) { // ���������� (Dependency), �Ͻ��� ����
		cout << drink.GetName() <<"���Ḧ �ֹ��մϴ�." << '\n';
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