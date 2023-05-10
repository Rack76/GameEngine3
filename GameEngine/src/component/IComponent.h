#pragma once

class IComponent
{
public:
	virtual ~IComponent() {}

	template<class Archive>
	void serialize(Archive& a, const unsigned version) {
		
	}
};