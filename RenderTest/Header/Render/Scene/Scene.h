//
// Created by cleme on 25/02/2021.
//

#pragma once

#include "Glew/glew.h"
#include "Glfw/glfw3.h"

#include "Render/Scene/Models/TriangleModel.h"
#include "Render/Shader/ShaderLoader.h"

namespace Rt
{
    class Scene
    {
    public:
        ~Scene();
        void Initialize();
        void Release();
        void Render();
        void Update();

    private:
        uint32_t m_programID;
        uint32_t m_verticesBuffer;
        uint32_t m_colorsBuffer;
    };
}
