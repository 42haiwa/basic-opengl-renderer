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
        virtual void Initialize();
        virtual uint32_t GetVerticesBuffer() const;
        virtual uint32_t GetColorsBuffer() const;

    protected:
        std::vector<float> m_vertices;
        std::vector<float> m_colors;
        uint32_t m_verticesBuffer;
        uint32_t m_colorsBuffer;
    };
}
