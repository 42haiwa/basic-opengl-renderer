//
// Created by cleme on 25/02/2021.
//

#include "Render/Scene/Scene.h"

#include <iostream>

namespace Rt
{
    Scene::~Scene()
    {
        Release();
    }

    void Scene::Initialize(GLFWwindow* window)
    {
        m_window = window;

        ShaderLoader sl;
        ShaderLoaderCreateInfo shaderLoaderCreateInfo;
        shaderLoaderCreateInfo.vsPath = "../Res/Shader/main.vert";
        shaderLoaderCreateInfo.fsPath = "../Res/Shader/main.frag";
        sl.Initialize(&shaderLoaderCreateInfo);

        m_programID = sl.Load();

        TriangleModel triangleModel;
        triangleModel.Initialize(glm::vec3{0, 0, 0},
                                 glm::vec2{0.5f, 0.5f});

        TriangleModel triangleModel1;
        triangleModel1.Initialize(glm::vec3{1, 0, 0},
                                  glm::vec2{0.5f, 0.5f});

        TriangleModel triangleModel2;
        triangleModel2.Initialize(glm::vec3{0.5f, 1, 0},
                                  glm::vec2{0.5f, 0.5f});

        // m_verticesBuffer = triangleModel.GetVerticesBuffer();
        // m_colorsBuffer = triangleModel.GetColorsBuffer();

        m_models.push_back(std::make_shared<TriangleModel>(triangleModel));
        m_models.push_back(std::make_shared<TriangleModel>(triangleModel1));
        m_models.push_back(std::make_shared<TriangleModel>(triangleModel2));

        // Init cam
        CameraCreateInfo cameraCreateInfo;
        cameraCreateInfo.window = m_window;
        cameraCreateInfo.fov = 70.f;
        cameraCreateInfo.zNear = 0.1f;
        cameraCreateInfo.zFar = 100.f;
        cameraCreateInfo.ratX = 16.f;
        cameraCreateInfo.ratY = 9.f;

        m_cam.Initialize(&cameraCreateInfo);
        mvpID = glGetUniformLocation(m_programID, "MVP");
    }

    void Scene::Release()
    {

    }

    void Scene::Update()
    {
        m_cam.Input();
    }

    void Scene::Render()
    {
        for (const auto& model : m_models)
        {
            // First Attributes
            glEnableVertexAttribArray(0);
            glBindBuffer(GL_ARRAY_BUFFER, model->GetVerticesBuffer());
            std::cout << "Vertices Buffer : " << model->GetVerticesBuffer() << std::endl;
            glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, nullptr);

            // Second Attributes
            glEnableVertexAttribArray(1);
            glBindBuffer(GL_ARRAY_BUFFER, model->GetColorsBuffer());
            std::cout << "Colors Buffer : " << model->GetColorsBuffer() << std::endl;
            glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, nullptr);

            glUniformMatrix4fv(mvpID, 1, GL_FALSE, &m_cam.GetMVP()[0][0]);

            glUseProgram(m_programID);
            glDrawArrays(GL_TRIANGLES, 0, 3);
            glDisableVertexAttribArray(0);
        }
    }
}
