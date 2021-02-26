//
// Created by cleme on 25/02/2021.
//

#pragma once

#include "Glm/glm.hpp"
#include "Glm/gtc/matrix_transform.hpp"

#include "Render/Scene/Models/Model.h"
#include "Render/Scene/Models/VboManager.h"

namespace Rt
{
    class TriangleModel : public Model
    {
    public:
        void Initialize() final;
        void Initialize(const glm::vec3& pos, const glm::vec2& size);
        uint32_t GetVerticesBuffer() const final;
        uint32_t GetColorsBuffer() const final;
    };
}
