#pragma once

#include <functional>
#include "EventHandler.h"

template<typename T, typename ...Types >
class Event
{
public:
	static void registerListener(const std::function<void(Types ...args)>& listener)
	{
		handler().registerListener(listener);
	}

	static void call( Types ...args)
	{
		handler().call(args);
	}

private:
	static EventHandler<T>& handler()
	{
		static EventHandler<T> eventHandler;
		return eventHandler;
	}
};