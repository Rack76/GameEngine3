#pragma once

#include <functional>
#include <vector>
#include <map>

template<class ...T>
class EventHandler {
public:
	void call(T... event)
	{
		for (auto& listener : listeners)
			listener.second(event...);
	}
	void registerListener(std::string &str, const std::function<void(T...)>& listener)
	{
		listeners.insert({str, listener});
	}
private:
	std::map<std::string, std::function<void(T...)>> listeners;
};