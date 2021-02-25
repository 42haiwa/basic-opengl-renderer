//
// Created by cleme on 25/02/2021.
//

#include "Render/Scene/Models/VboManager.h"

namespace Rt
{
    void VboManager::Initialize(VboManagerCreateInfo* vboManagerCreateInfo)
    {
        m_vertices = vboManagerCreateInfo->data;
        // m_layout = vboManagerCreateInfo->layout;

        glGenBuffers(1, &m_vbo);
        glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
        glBufferData(GL_ARRAY_BUFFER, sizeof(float) * m_vertices.size(), &m_vertices[0], GL_STATIC_DRAW);
    }

    uint32_t VboManager::getVbo()
    {
        return m_vbo;
    }
}
