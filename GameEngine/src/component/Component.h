#pragma once

#include "IComponent.h"

template <typename ...Types>
class Component : public IComponent
{
public:
	virtual void setData(Types ...args){}
	virtual ~Component(){}
};