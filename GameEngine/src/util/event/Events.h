#pragma once

#include "glew.h"
#include "Event.h"
#include <string>

class TERMINATE : public Event<TERMINATE>{};
class SAVE_ENTITIES : public Event<SAVE_ENTITIES, std::string>{};
class LOAD_ENTITIES : public Event<LOAD_ENTITIES, std::string> {};
class ON_ESC_PRESS : public Event<ON_ESC_PRESS> {};
class ON_ENTITY_CREATED : public Event<ON_ENTITY_CREATED, int, int>{};
class ON_PROGRAM_SOURCE_LOADED : public Event<ON_PROGRAM_SOURCE_LOADED, int, int, std::string, std::string>{};
class ON_MODEL3D_PARSED : public Event<ON_MODEL3D_PARSED, std::string, std::vector<GLfloat> , std::vector<GLfloat>> {};