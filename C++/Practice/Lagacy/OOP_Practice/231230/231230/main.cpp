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
    
	parent = childA; // �ڽ�Ÿ���� ��ü�� ���� �θ�Ÿ���� ��ü�� �����ϴ� ��� -> ���� ���� �߻�
	                 // ��ü Ÿ���� ������ ���� ����Ÿ���̳� ������ Ÿ������ �����Ѵ�.
	                 // �ڽ�Ÿ���� ��ü�� �θ�Ÿ���� ������ ������ ������ �������� ������ �ϴ� ���� -> UpCasting

	//childA = parent; // �� �ݴ�� DownCasting
	                 // �Ϲ����� ��쿡���� ������� ���� -> �ڽ��� �θ𺸴� ������ ���� ����


	// ����

	Parent& refParent = childA; // ��ĳ���� , childA��ü�� refParent�� ��Ī -> refParent�� �׻� childA�� ����Ų��.

	refParent._value = 200;

	// refParent�� childA�� Parent��ӹ��� �κи� ���ٰ��� -> Parent& Ÿ���̱� ����.
	cout << "refParent._value = " << refParent._value << endl;

	// �ٿ�ĳ������ ���Ǵ� ���
	// �Ϲ����� ��쿡�� �ٿ�ĳ������ ������ ������ �� ���� ����̵�
	// ChildAŸ���� Parent& Ÿ������ �޾Ҵٰ� �ٽ� ChildA�� ����Ÿ��(&)���� �����ϴ� ��쿡�� �����ϴ�
	ChildA& refChildA = (ChildA&)refParent;

	cout << "refChildA._value = " << refChildA._value << endl;
	cout << "refchildA._valueA = " << refChildA._valueA << endl;

	// ������
	
	Parent* pParent; // ParentŸ�� �ּҰ������ϴ� ����
	
	// ��ĳ����
	pParent = &childA; // childA�� �ּҰ��� pPrant������ ���� 

	pParent->_value;
	// pParnet �������� ������ ���� �� �� �ִ� ���� �θ��� ������ ������ �����ϴ�.

	cout << "pParent->_value = " << pParent->_value << endl;

	ChildA* pChildA = (ChildA*)pParent; // �ٿ� ĳ����

	cout << "ChildA->_value = " << pChildA->_value << endl;
	cout << "pChildA->_value = " << pChildA->_value << endl;

	return 0;
}