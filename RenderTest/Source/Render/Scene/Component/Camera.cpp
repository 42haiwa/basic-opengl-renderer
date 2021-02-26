//
// Created by cleme on 26/02/2021.
//

#include "Render/Scene/Component/Camera.h"

#include <iostream>

namespace Rt
{
    Camera::~Camera()
    {
        Release();
    }

    void Camera::Initialize(CameraCreateInfo* cameraCreateInfo)
    {
        m_window = cameraCreateInfo->window;
        m_fov = cameraCreateInfo->fov;
        m_zNear = cameraCreateInfo->zNear;
        m_zFar = cameraCreateInfo->zFar;
        m_ratX = cameraCreateInfo->ratX;
        m_ratY = cameraCreateInfo->ratY;

        if (!m_window)
        {
            std::cerr << "CAMERA >> WINDOW IS NULL" << std::endl;
        }

        m_projection = glm::perspective(glm::radians(m_fov),
                                        m_ratX / m_ratY,
                                        m_zNear,
                                        m_zFar);

        m_view = glm::lookAt(glm::vec3(4, 3, 3),
                             glm::vec3(0, 0, 0),
                             glm::vec3(0, 1, 0));

        m_model = glm::mat4(1.f);

        m_mvp = m_projection * m_view * m_model;

        std::cout << "Camera Initialized." << std::endl;
    }

    glm::mat4 Camera::GetMVP() const
    {
        return m_mvp;
    }

    void Camera::Input()
    {

    }

    void Camera::Release()
    {
        std::cout << "Camera Released." << std::endl;
    }
}
