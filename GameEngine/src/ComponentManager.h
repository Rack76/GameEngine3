#pragma once

class ComponentManager
{
public:
	void init();
	Component* createComponent(int componentType);
private:
	std::map<int, std::function<Component* (void)>> constructors;
};