//
// Created by cleme on 25/02/2021.
//

#pragma once

#include "Glew/glew.h"
#include "Glfw/glfw3.h"

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

namespace Rt
{
    struct ShaderLoaderCreateInfo
    {
        std::string vsPath;
        std::string fsPath;
    };

    class ShaderLoader
    {
    public:
        void Initialize(ShaderLoaderCreateInfo* shaderLoaderCreateInfo);
        uint32_t Load() const;

    private:
        ShaderLoaderCreateInfo m_shaderLoaderCreateInfo;
    };
}
