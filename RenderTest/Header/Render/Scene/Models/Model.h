//
// Created by cleme on 25/02/2021.
//

#pragma once

#include "Glm/glm.hpp"
#include "Glm/gtc/matrix_transform.hpp"

#include <iostream>
#include <vector>

namespace Rt
{
    class Model
    {
    public:
        virtual void Initialize() = 0;
        virtual uint32_t GetVerticesBuffer() const = 0;
        virtual uint32_t GetColorsBuffer() const = 0;

    protected:
        std::vector<float> m_vertices;
        std::vector<float> m_colors;
        uint32_t m_verticesBuffer;
        uint32_t m_colorsBuffer;
    };
}
