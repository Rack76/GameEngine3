#pragma once

#include <functional>
#include <vector>

template<class ...T>
class EventHandler {
public:
	void call(T... event)
	{
		for (int i = 0; i < listeners.size(); i++)
			listeners[i](event...);
	}
	void registerListener(const std::function<void(T...)>& listener)
	{
		listeners.push_back(listener);
	}
private:
	std::vector<std::function<void(T...)>> listeners;
};