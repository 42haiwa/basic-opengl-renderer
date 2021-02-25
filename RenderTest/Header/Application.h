//
// Created by cleme on 25/02/2021.
//

#pragma once

#include "Render/Display/DisplayWindow.h"
#include "Render/Scene/Scene.h"

namespace Rt
{
    struct ApplicationCreateInfo
    {
        DisplayWindowCreateInfo p_displayWindowCreateInfo;
    };

    class Application
    {
    public:
        ~Application();
        void Initialize(const ApplicationCreateInfo* applicationCreateInfo);
        void Release();
        void Run();

    private:
        bool m_initialized = false;
        GLFWwindow* m_window;
        DisplayWindow m_displayWindow;

        Scene m_scene;
    };
}
