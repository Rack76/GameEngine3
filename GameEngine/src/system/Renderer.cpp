#include "Renderer.h"
#include "glfw3.h"
#include <cassert>
#include "../util/WindowManager.h"


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
}

void Renderer::run()
{
    glClear(GL_COLOR_BUFFER_BIT);

    //draw...

    glfwSwapBuffers(wndMngr->getWindow());
}
