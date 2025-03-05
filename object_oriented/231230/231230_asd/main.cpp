#include <iostream>
#include <string>

using namespace std;

class Phone {
private:   
	string _phoneNumber;
public:   
	Phone(string phoneNumber) 
		: _phoneNumber(phoneNumber) {}
	  void Call(string callNumber) 
	  { 
		  cout << callNumber << "�� " << _phoneNumber << "���� ��ȭ�� �մϴ�." << endl; 
	  }
	  void SendMessage(string message) 
	  { 
		  cout << "[ " << message << " ]�� �����ϴ�." << endl; 
	  }
	  void ReceiveMessage(string message) 
	  {
		  cout << "[ " << message << " ]�� �޽��ϴ�." << endl; 
	  }
};

class Computer {
private:   
	string _id;
public:   
	Computer(string id) 
		: _id(id) {}
	  void PlayGame(string name) 
	  { 
		  cout << name << "�� ������ �մϴ�." << endl; 
	  }
};

class SmartPhone : public Phone, public Computer { 
public:   
	SmartPhone(string phoneNumber, string id) 
		: Phone(phoneNumber), Computer(id) {} 
};

int main() {
	SmartPhone smartPhone("010-1111-1111", "monster");
	smartPhone.Call("010-222-2222");   
	smartPhone.PlayGame("������");

	return 0;
}