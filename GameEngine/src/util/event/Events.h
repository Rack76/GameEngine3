#pragma once

#include "Event.h"
#include <string>

class EscPress : public Event<EscPress>{};
class SAVE_ENTITIES : public Event<SAVE_ENTITIES, std::string>{};
class LOAD_ENTITIES : public Event<LOAD_ENTITIES, std::string> {};
