#pragma once

#include <functional>
#include <vector>

template<typename ...Types>
class EventHandler
{
public:
	void registerListener(const std::function<void(Types ... args)> listener)
	{
		listeners.push_back(listener);
	}

	void call(Types ...args)
	{
		for (int i = 0; i < listeners.size(); i++)
			listeners[i](args);
	}
private:
	std::vector<std::function<void(Types ...args)>> listeners;
};