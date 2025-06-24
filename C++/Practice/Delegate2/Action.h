#pragma once
#include <iostream>
// Unity C#
// 
// 1. 등록 
// Action<...> OnAction = 함수명;
// + = += -=
// 
// 2. 실행
// OnAction.Invoke(...);

template <typename ...Args>
class Action
{
	struct Event
	{
		void* ListenerID;
		std::function<void(Args...)> func;
	};

public:
	void Add(void* instance, const std::function<void(Args...)>& refFunc)
	{
		listeners.push_back({ instance, refFunc });
	}

	void Remove(void* targetID)
	{
		auto it = listeners.begin();
		for (; it != listeners.end();)
		{
			if (it->ListenerID == targetID)
			{
				it = listeners.erase(it);
			}
			else
			{
				it++;
			}
		}
	}

	void Clear()
	{
		listeners.clear();
	}

	void Invoke(Args... args) const
	{
		for (const Event& e : listeners)
		{
			e.func(args...);
		}
	}

public:
	Action() {} = default;
	~Action() {} = default;

private:
	std::vector<Event> listeners;
};