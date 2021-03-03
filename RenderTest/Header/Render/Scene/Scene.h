//
// Created by cleme on 25/02/2021.
//

#pragma once

#include "Glew/glew.h"
#include "Glfw/glfw3.h"

#include "Glm/glm.hpp"
#include "Glm/gtc/matrix_transform.hpp"

#include "Render/Scene/Models/Model.h"
#include "Render/Scene/Models/TriangleModel.h"
#include "Render/Shader/ShaderLoader.h"
#include "Render/Scene/Component/Camera.h"

#include <memory>
#include <vector>

namespace Rt
{
    class Scene
    {
    public:
        ~Scene();
        void Initialize(GLFWwindow* window);
        void Release();
        void Render();
        void Update();

    private:
        GLFWwindow* m_window;

        uint32_t m_programID;
        std::vector<std::shared_ptr<TriangleModel>> m_models;

        Camera m_cam;
        uint32_t mvpID;

        // uint32_t m_verticesBuffer;
        // uint32_t m_colorsBuffer;
    };
}
