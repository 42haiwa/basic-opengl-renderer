//
// Created by cleme on 27/02/2021.
//

#pragma once

#include "Render/Scene/Models/Model.h"
#include "Render/Scene/Models/VboManager.h"

namespace Rt
{
    class CustomModel : public Model
    {
    public:
        void Initialize() override;
        uint32_t GetVerticesBuffer() const override;
        uint32_t GetColorsBuffer() const override;
    };
}
