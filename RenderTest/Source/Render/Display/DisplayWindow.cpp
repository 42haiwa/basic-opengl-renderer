//
// Created by cleme on 25/02/2021.
//

#include "Render/Display/DisplayWindow.h"

namespace Rt
{
    DisplayWindow::~DisplayWindow()
    {
        Release();
    }

    void DisplayWindow::Initialize(const DisplayWindowCreateInfo* displayWindowCreateInfo)
    {
        if (m_initialized)
            Release();

        m_initialized = true;

        glfwWindowHint(GLFW_SAMPLES, 4);

        m_window = glfwCreateWindow(displayWindowCreateInfo->width,
                                    displayWindowCreateInfo->height,
                                    &displayWindowCreateInfo->title[0],
                                    nullptr,
                                    nullptr);

        std::cout << "Window initialized." << std::endl;
    }

    void DisplayWindow::Release()
    {
        if (m_initialized)
        {
            m_initialized = false;

            if (m_window != nullptr)
            {
                m_window = nullptr;
            }
        }
        std::cout << "Window released." << std::endl;
    }

    GLFWwindow* DisplayWindow::getWindow()
    {
        return m_window;
    }
}
