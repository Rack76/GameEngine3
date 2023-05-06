#pragma once

#include "Component.h"

class Mock2 : public Component<>
{
public:
	int data = 0;
	void setData() {}
	~Mock2() {}
};