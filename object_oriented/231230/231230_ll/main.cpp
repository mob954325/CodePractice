#include <iostream>
using namespace std;
class Arm {
private:   
	string _name;
public:   
	Arm(string name) 
		: _name(name) {}
	  void ShowInfo() 
	  { 
		  cout << _name; 
	  }
};

class unknowunArm : public Arm {
public:
	unknowunArm(string name) 
		:Arm(name) {}
};

class CannonArm : public Arm {
public:   
	CannonArm() 
		: Arm("CannonArm") 
	{   }
};

class RocketArm : public Arm { 
public:   
	RocketArm() 
		: Arm("RocketArm") {   } 
};

class LazerArm : public Arm { 
public:   
	LazerArm() 
		: Arm("LazerArm") {   } 
};

class Robot {
private:   
	Arm* _pLeftArm;   
	Arm* _pRightArm;
public:   
	Robot(Arm* pLeftArm, Arm* pRightArm) 
		: _pLeftArm(pLeftArm), _pRightArm(pRightArm) {}


	void changeLeftArm(Arm* pLeftArm)
	{
		_pLeftArm = pLeftArm;
	}

	void ShowInfo() { 
	  cout << endl;      
	  cout << "Robot" << endl;      
	  cout << "¿ÞÂÊÆÈ: ";      
	  _pLeftArm->ShowInfo();      
	  cout << endl;     
	  cout << "¿À¸¥ÂÊÆÈ: ";  
	  _pRightArm->ShowInfo(); 
	  cout << endl; }
};


int main() {
	CannonArm cannonArm; 
	RocketArm rocketArm; 
	LazerArm lazerArm;
	unknowunArm larzer2("lazer22");

	Robot cannonArmRobot(&cannonArm, &larzer2);
	Robot rocketArmRobot(&rocketArm, &rocketArm);
	Robot lazerArmRobot(&lazerArm, &lazerArm);
	Robot leftCannonArmRightRocketArmRobot(&cannonArm, &rocketArm);

	cannonArmRobot.ShowInfo(); 
	rocketArmRobot.ShowInfo();  
	lazerArmRobot.ShowInfo();  
	leftCannonArmRightRocketArmRobot.ShowInfo();

	leftCannonArmRightRocketArmRobot.changeLeftArm(&lazerArm);
	leftCannonArmRightRocketArmRobot.ShowInfo();

	return 0;
}