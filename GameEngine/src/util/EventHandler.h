#pragma once

#include <functional>
#include <vector>

template<typename T>
class EventHandler
{
public:
	void registerListener(const std::function<void(T)> listener)
	{
		listeners.push_back(listener);
	}

	void call(T event)
	{
		for (int i = 0; i < listeners.size(); i++)
			listener[i](event);
	}
private:
	std::vector<std::function<void(T)>> listeners;
};