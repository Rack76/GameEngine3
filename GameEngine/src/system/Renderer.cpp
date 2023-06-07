#include "Renderer.h"
#include "glfw3.h"
#include <cassert>
#include "../util/WindowManager.h"
#include "../component/Shader.h"

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
    GLenum err = glewInit();
    if (GLEW_OK != err)
    {
        /* Problem: glewInit failed, something is seriously wrong. */
        fprintf(stderr, "Error: %s\n", glewGetErrorString(err));
    }

    glViewport(0, 0, 1000, 760);

    Renderer* pr = this;

    ON_ENTITY_CREATED::registerListener("setEntityVBOsAndProgram", [pr](int entityType, int index) {
        if (entityType == (int)EntityTypes::RENDERER)
        {
            pr->loadVertices(entityType, index);
            pr->assignProgram(entityType, index);
        }
        });

    ON_PROGRAM_SOURCE_LOADED::registerListener("storeProgram",  [pr](int vertexShaderName, int fragmentShaderName,
                                                std::string vertexShaderFileName, std::string fragmentShaderFileName) {
        pr->storeProgram(vertexShaderName, fragmentShaderName, vertexShaderFileName, fragmentShaderFileName);
        });
    glClear(GL_COLOR_BUFFER_BIT);
    glfwSwapBuffers(wndMngr->getWindow());

    ON_MODEL3D_PARSED::registerListener("storeBufferData", [pr](std::string filename, std::vector<GLfloat> orderedVertices, std::vector<GLfloat> orderedTextCoord) {
        pr->storeVerticeData(filename, orderedVertices, orderedTextCoord);
        });
    glClear(GL_COLOR_BUFFER_BIT);
    glfwSwapBuffers(wndMngr->getWindow());
}

void Renderer::run()
{
    auto archetypes = ettMngr->getArchetypes((int)EntityTypes::RENDERER);
 
    for (auto& archetype : archetypes) {
        for (int i = 0; i < archetype->getSize(); i++)
        {
            glClear(GL_COLOR_BUFFER_BIT);
            auto entity = archetype->getComponents(i);
            Model3D* mc = (Model3D*)entity.at((int)ComponentTypes::MODEL3D);
            Shader* sc = (Shader*)entity.at((int)ComponentTypes::SHADER);
            auto camera = (Camera*)ettMngr->getComponent((int)EntityTypes::CAMERA, 0, (int)ComponentTypes::CAMERA);
            glUniformMatrix3fv(glGetUniformLocation(sc->program, "cameraOrientation"), 1, GL_FALSE, camera->orientation.getData());
            glUniformMatrix4fv(glGetUniformLocation(sc->program, "perspective"), 1, GL_FALSE, &camera->perspective[0]);
            camera->position = camera->position + camera->xVelocity;
            camera->position = camera->position + camera->yVelocity;
            camera->position = camera->position + camera->zVelocity;
            glUniform3fv(glGetUniformLocation(sc->program, "cameraPosition"), 1, camera->position.data);
            glBindVertexArray(mc->vao);
            glUseProgram(sc->program);
            glDrawArrays(GL_TRIANGLES, 0, mc->vertexCount);
            glfwSwapBuffers(wndMngr->getWindow());
        }
    }
}

void Renderer::loadVertices(int entityType, int index)
{
    auto component = ettMngr->getComponent(entityType, index, (int)ComponentTypes::MODEL3D);
    auto vao = &(((Model3D*)component)->vao);
    auto vbo = ((Model3D*)component)->vbo;
    auto filename = ((Model3D*)component)->filename;
    auto vertices = modelsVertices.at(filename);
    auto textCoord = modelsTextCoord.at(filename);
    ((Model3D*)component)->vertexCount = vertices.size() / 3;
    glGenVertexArrays(1, vao);
    glBindVertexArray(*vao);
    glGenBuffers(2, vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo[VERTICES]);
    int size = vertices.size();
    glBufferData(GL_ARRAY_BUFFER, size * 4 , vertices.data(), GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, vbo[TEXTURE]);
    size = textCoord.size();
    glBufferData(GL_ARRAY_BUFFER, size, textCoord.data(), GL_STATIC_DRAW);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, (void*)0);
    glEnableVertexAttribArray(1);
}

void Renderer::storeProgram(int vertexShaderName, int fragmentShaderName,
    std::string vertexShaderFileName, std::string fragmentShaderFileName) {
    glCompileShader(vertexShaderName);
    glCompileShader(fragmentShaderName);
    GLuint program = glCreateProgram();
    glAttachShader(program, vertexShaderName);
    glAttachShader(program, fragmentShaderName);
    glLinkProgram(program);
    programs[vertexShaderFileName][fragmentShaderFileName] = program;
}

void Renderer::storeVerticeData(std::string filename, std::vector<GLfloat> orderedVertices, std::vector<GLfloat> orderedTextCoord) {
    modelsVertices.insert({ filename, orderedVertices });
    modelsTextCoord.insert({ filename, orderedTextCoord });
}

void Renderer::assignProgram(int entityType, int index) {
    try {
        auto component = ettMngr->getComponent(entityType, index, (int)ComponentTypes::SHADER);
        ((Shader*)component)->program = programs.at(((Shader*)component)->vertexShadername).at(((Shader*)component)->fragmentShadername);
    }
    catch (std::exception& e) {
        std::cerr << e.what();
    }
}