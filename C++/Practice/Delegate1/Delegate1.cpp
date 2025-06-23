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
	Player();
	~Player();

	void OnStart()
	{
		OnHit.Add([this]() { cec.Execute(); });
	}

	void Hit()
	{
		OnHit.Invoke();
	}
};

Player::Player()
{
}

Player::~Player()
{
}

int main()
{
	Player p;
	p.OnStart();
	p.Hit();  // Ãâ·Â: CppEventClass Executed
}