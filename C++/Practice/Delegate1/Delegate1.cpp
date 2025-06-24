#include <iostream>
#include <vector>
#include <functional>

using namespace std;

// Event
class CppEventClass
{
public:
	void Execute()
	{
		std::cout << "CppEventClass Executed : "<< endl;
	}
};


// Action
class Action
{
public:
	using FuncType = std::function<void()>;

	void Add(const FuncType& func)
	{
		listeners.push_back(func);
	}

	void Invoke()
	{
		for (const auto& e : listeners)
		{
			e();
		}
	}

private:
	std::vector<FuncType> listeners;
};

// Player 
class Player
{
private:
	CppEventClass cec{};
	Action OnHit;

public:
	Player() {};
	~Player() {};

	void OnStart()
	{
		OnHit.Add([this]() { cec.Execute(); });
	}

	void Hit()
	{
		OnHit.Invoke();
	}
};

void TestEvent()
{
	cout << "Call TestEvent Function\n";
}

int main()
{
	Player p;
	p.OnStart();
	p.Hit();  // 출력: CppEventClass Executed

	Action action1;
	CppEventClass* cec1 = new CppEventClass();
	action1.Add([&cec1]() { cec1->Execute(); });
	action1.Invoke();

	delete cec1;

	action1.Invoke(); // ?? 
}