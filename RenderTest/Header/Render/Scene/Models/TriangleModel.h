//
// Created by cleme on 25/02/2021.
//

#pragma once

#include "Render/Scene/Models/Model.h"
#include "Render/Scene/Models/VboManager.h"

namespace Rt
{
    class TriangleModel : public Model
    {
    public:
        void Initialize() final;
        uint32_t GetVerticesBuffer() const;
        uint32_t GetColorsBuffer() const;
    };
}
