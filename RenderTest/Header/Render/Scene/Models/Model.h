//
// Created by cleme on 25/02/2021.
//

#pragma once

#include <iostream>
#include <vector>

namespace Rt
{
    class Model
    {
    public:
        virtual void Initialize() = 0;

    protected:
        std::vector<float> m_vertices;
        std::vector<float> m_colors;
        uint32_t m_verticesBuffer;
        uint32_t m_colorsBuffer;
    };
}
