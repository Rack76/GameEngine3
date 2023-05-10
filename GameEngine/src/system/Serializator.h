#pragma once

#include "../util/event/Events.h"
#include "EntityManager.h"
#include "../util/Parser.h"

class Serializator
{
public:
	Serializator(EntityManager* ettMnger) : ettMnger(ettMnger) {

	}
	void init();

	template < typename ...Types>
	std::tuple<Types...> genTuplesImplImpl(Types ...args) {
		return std::make_tuple(args...);
	}

	template <typename F, size_t ...sizes>
	auto genTuplesImpl(F func, std::index_sequence<sizes...>, std::vector<void*> vec) {
		return genTuplesImplImpl(func(sizes, vec)...);
	}

	template<const int  N, typename F>
	auto genTuples(F func, std::vector<void*> vec) {
		return genTuplesImpl(func, std::make_index_sequence<N>(), vec);
	}
private:
	
	Parser* parser;
	EntityManager* ettMnger;
};