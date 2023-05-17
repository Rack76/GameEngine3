#include "Renderer.h"
#include "glfw3.h"
#include <cassert>
#include "../util/WindowManager.h"
#include "../util/event/Events.h"

void Renderer::init()
{
    wndMngr->CreateWindow();
    auto window = wndMngr->getWindow();
    if (!window)
    {
        glfwTerminate();
        assert(0 && "error : could not create window");
    }
    
    glfwMakeContextCurrent(window);

    EntityManager* pem = ettMngr;

    ON_ENTITY_CREATED::registerListener([pem](int entityType, int index){
        switch (entityType)
        {
        case (int)EntityTypes::VOXEL:
            auto components = pem->getComponents(entityType, index);
            auto vao = &(((Model3D*)components.at((int)ComponentTypes::MODEL3D))->vao);
            auto vbo = ((Model3D*)components.at((int)ComponentTypes::MODEL3D))->vbo;
            auto vertices = ((Model3D*)components.at((int)ComponentTypes::MODEL3D))->vertices;
            glGenVertexArrays(1, vao);
            glBindVertexArray(*vao);
            glGenBuffers(1, vbo);
            glBufferData(vbo[VERTICES], sizeof(vertices), vertices.data(), GL_STATIC_DRAW);
            glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
            glEnableVertexAttribArray(0);
        }
        });
}

void Renderer::run()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glfwSwapBuffers(wndMngr->getWindow());
}

void Renderer::specifyVertices(int entityType, int index)
{
    
}
