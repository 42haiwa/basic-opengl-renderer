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
        virtual void Initialize() override;
        virtual void Initialize(const glm::vec3& pos, const glm::vec2& size);
        virtual uint32_t GetVerticesBuffer() const override;
        virtual uint32_t GetColorsBuffer() const override;
    };
}
