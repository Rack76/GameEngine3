#pragma once

#include "Component.h"

class Mock1 : public Component<>
{
public:
	int data = 0;
	void setData(){}
	~Mock1() {}
};