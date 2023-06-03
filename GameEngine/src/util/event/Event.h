#pragma once

#include <functional>
#include "EventHandler.h"

template<class dif, class ...T>
class Event {
public:
	static void call(T... event)
	{
		handler().call(event...);
	}
	static void registerListener(std::string str, const std::function<void(T...)>&listener)
	{
		handler().registerListener(str, listener);
	}
private:
	static EventHandler<T...>& handler()
	{
		static EventHandler<T...> eh;
		return eh;
	}
};