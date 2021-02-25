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

    void Scene::Initialize()
    {
        ShaderLoader sl;
        ShaderLoaderCreateInfo shaderLoaderCreateInfo;
        shaderLoaderCreateInfo.vsPath = "../Res/Shader/main.vert";
        shaderLoaderCreateInfo.fsPath = "../Res/Shader/main.frag";
        sl.Initialize(&shaderLoaderCreateInfo);

        m_programID = sl.Load();

        TriangleModel triangleModel;
        triangleModel.Initialize();

        m_verticesBuffer = triangleModel.GetVerticesBuffer();
        m_colorsBuffer = triangleModel.GetColorsBuffer();
    }

    void Scene::Release()
    {

    }

    void Scene::Update()
    {

    }

    void Scene::Render()
    {
        // First Attributes
        glEnableVertexAttribArray(0);
        glBindBuffer(GL_ARRAY_BUFFER, m_verticesBuffer);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, nullptr);

        glEnableVertexAttribArray(1);
        glBindBuffer(GL_ARRAY_BUFFER, m_colorsBuffer);
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, nullptr);

        glUseProgram(m_programID);
        glDrawArrays(GL_TRIANGLES, 0, 3);
        glDisableVertexAttribArray(0);
    }
}
