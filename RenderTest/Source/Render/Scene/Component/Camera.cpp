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
        double xPos, yPos;
        double currentTime = glfwGetTime();
        float deltaTime = float(currentTime - lastTime);

        glfwGetCursorPos(m_window, &xPos, &yPos);
        glfwSetCursorPos(m_window, 1280.0 / 2, 720.0 / 2);

        m_horizontalAngle += m_mouseSensivity * deltaTime * float(1280.0/2 - xPos);
        m_verticalAngle   += m_mouseSensivity * deltaTime * float(720.0/2 - yPos);

        glm::vec3 direction{cosf(m_verticalAngle) * sinf(m_horizontalAngle),
                            sinf(m_verticalAngle),
                            cosf(m_verticalAngle) * cosf(m_horizontalAngle)};

        glm::vec3 right{sinf(m_horizontalAngle - 3.14f / 2.f),
                        0,
                        cosf(m_horizontalAngle - 3.14f / 2.f)};

        glm::vec3 up = glm::cross(right, direction);

        if (glfwGetKey(m_window, GLFW_KEY_W) == GLFW_PRESS)
        {
            m_pos += direction * deltaTime * m_speed;
        }

        if (glfwGetKey(m_window, GLFW_KEY_S) == GLFW_PRESS)
        {
            m_pos -= direction * deltaTime * m_speed;
        }

        if (glfwGetKey(m_window, GLFW_KEY_A) == GLFW_PRESS)
        {
            m_pos -= right * deltaTime * m_speed;
        }

        if (glfwGetKey(m_window, GLFW_KEY_D) == GLFW_PRESS)
        {
            m_pos += right * deltaTime * m_speed;
        }

        m_projection = glm::perspective(glm::radians(m_fov),
                                        m_ratX / m_ratY,
                                        m_zNear, m_zFar);

        m_view = glm::lookAt(m_pos, m_pos + direction, up);

        m_mvp = m_projection * m_view * m_model;
    }

    void Camera::Release()
    {
        std::cout << "Camera Released." << std::endl;
    }
}
