//
// Created by cleme on 25/02/2021.
//

#pragma once

#include "Glew/glew.h"
#include "Glfw/glfw3.h"

#include <iostream>

namespace Rt
{
    struct DisplayWindowCreateInfo
    {
        int width;
        int height;
        std::string title;
    };

    class DisplayWindow
    {
    public:
        ~DisplayWindow();
        void Initialize(const DisplayWindowCreateInfo* displayWindowCreateInfo);
        void Release();

        GLFWwindow* getWindow();

    private:
        bool m_initialized = false;
        GLFWwindow* m_window = nullptr;
    };
}
