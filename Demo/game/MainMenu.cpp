#include "Menu.h"
#include "../../GameEngine/src/Engine.h"

void MainMenu::load() {
	engine->parser->parseShader("basic.vert", "basic.frag");
	engine->parser->parseCollada("untitled.dae");
	engine->ettMngr->addEntity((int)EntityTypes::CAMERA);
	engine->ettMngr->addEntity((int)EntityTypes::RENDERER);
	Model3D* c = (Model3D*)engine->ettMngr->getComponent((int)EntityTypes::RENDERER, 0, (int)ComponentTypes::MODEL3D);
	c->filename = "untitled.dae";
	ON_ENTITY_CREATED::call((int)EntityTypes::RENDERER, 0);
	engine->ettMngr->serialize("entities2");
}