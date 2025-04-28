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
		  cout << callNumber << "로 " << _phoneNumber << "에서 전화를 합니다." << endl; 
	  }
	  void SendMessage(string message) 
	  { 
		  cout << "[ " << message << " ]를 보냅니다." << endl; 
	  }
	  void ReceiveMessage(string message) 
	  {
		  cout << "[ " << message << " ]를 받습니다." << endl; 
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
		  cout << name << "의 게임을 합니다." << endl; 
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
	smartPhone.PlayGame("리니지");

	return 0;
}