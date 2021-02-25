//
// Created by cleme on 25/02/2021.
//

#include "Application.h"

namespace Rt
{
    Application::~Application()
    {
        Release();
    }

    void Application::Initialize(const ApplicationCreateInfo* applicationCreateInfo)
    {
        if (m_initialized)
            Release();

        m_initialized = true;

        if (!glfwInit())
            std::cerr << "GLFW init error !" << std::endl;

        m_displayWindow.Initialize(&applicationCreateInfo->p_displayWindowCreateInfo);

        m_window = m_displayWindow.getWindow();

        if (!m_window)
            std::cerr << "Window creation error !" << std::endl;

        glfwMakeContextCurrent(m_window);

        if (glewInit() != GLEW_OK)
        {
            std::cerr << "GLEW init error !" << std::endl;
        }

        std::cout << "Application initialized." << std::endl;

        m_scene.Initialize();
    }

    void Application::Release()
    {
        if (m_initialized)
        {
            m_initialized = false;

            std::cout << "Application released." << std::endl;
        }
    }

    void Application::Run()
    {
        while (!glfwWindowShouldClose(m_window))
        {
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            m_scene.Update();
            m_scene.Render();
            glfwSwapBuffers(m_window);
            glfwPollEvents();
        }
    }
}
