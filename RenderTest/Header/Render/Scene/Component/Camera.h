//
// Created by cleme on 26/02/2021.
//

#pragma once

#include "Glm/glm.hpp"
#include "Glm/gtc/matrix_transform.hpp"

namespace Rt
{
    struct CameraCreateInfo
    {
        float fov;
        float zNear;
        float zFar;
        float ratX;
        float ratY;
    };

    class Camera
    {
    public:
        ~Camera();
        void Initialize(CameraCreateInfo* cameraCreateInfo);
        glm::mat4 GetMVP() const;
        void Release();

    private:
        float m_fov = 70.f;
        float m_zNear = 0.1f;
        float m_zFar = 100.f;
        float m_ratX = 16.f;
        float m_ratY = 9.f;

        glm::mat4 m_projection;
        glm::mat4 m_view;
        glm::mat4 m_model;
        glm::mat4 m_mvp;
    };
}
