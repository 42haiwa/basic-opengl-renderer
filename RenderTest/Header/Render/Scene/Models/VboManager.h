//
// Created by cleme on 25/02/2021.
//

#pragma once

#include "Glew/glew.h"
#include "Glfw/glfw3.h"

#include <iostream>
#include <vector>

namespace Rt
{
    struct VboManagerCreateInfo
    {
        std::vector<float> data;
        // uint32_t layout; // for shader
    };

    class VboManager
    {
    public:
        void Initialize(VboManagerCreateInfo* vboManagerCreateInfo);
        uint32_t getVbo();

    private:
        std::vector<float> m_vertices;
        // uint32_t m_layout;
        uint32_t m_vbo;
    };
}
