#pragma once

#include <functional>
#include "EventHandler.h"

template<typename T>
class Event
{
public:
	static void registerListener(const std::function<void(T)>& listener)
	{
		handler().registerListener(listener);
	}

	static void call(T event)
	{
		handler().call(event);
	}

private:
	static EventHandler<T>& handler()
	{
		static EventHandler<T> eventHandler;
		return eventHandler;
	}
};