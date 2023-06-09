#include "ComponentManager.h"
#include "../component/Mock1.h"
#include "../component/Mock2.h"
#include "../component/Model3D.h"
#include "../component/Shader.h"
#include "../component/Camera.h"
#include <exception>
#include <cstdarg>
#include <iterator>
#include <cmath>

void ComponentManager::init()
{
	addComponentType<Mock1>();
	addComponentType<Mock2>();
	addComponentType<Model3D>();
	addComponentType<Shader>();
	addComponentType<Camera>();
}

void ComponentManager::linkComponents(int entityType) {
	return;
}

std::vector<std::pair<int, IComponent*>> ComponentManager::constructComponents(int entityType) {
	std::vector<std::pair<int, IComponent*>> vec;
	try {
		for (auto f : entityType_componentConstructorsTable.at(entityType))
		{
			
			vec.push_back(std::pair<int, IComponent*>({f.first, f.second()}));
		}

		return vec;
	}
	catch (const std::exception& e) {
		std::cerr << e.what();
	}
}