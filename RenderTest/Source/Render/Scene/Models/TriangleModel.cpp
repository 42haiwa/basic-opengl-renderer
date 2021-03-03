//
// Created by cleme on 25/02/2021.
//

#include "Render/Scene/Models/TriangleModel.h"

namespace Rt
{
    void TriangleModel::Initialize()
    {
        m_vertices = {
                -1.0f, -1.0f, 0.0f,
                0.0f, 1.0f, 0.0f,
                1.0f, -1.0f, 0.0f
        };
        VboManagerCreateInfo vboVerticesCreateInfo;
        vboVerticesCreateInfo.data = m_vertices;

        VboManager verticesBufferManager;
        verticesBufferManager.Initialize(&vboVerticesCreateInfo);

        m_colors = {
                1, 0, 0,
                0, 1, 0,
                0, 0, 1
        };

        VboManagerCreateInfo vboColorsCreateInfo;
        vboColorsCreateInfo.data = m_colors;

        VboManager colorsBufferManager;
        colorsBufferManager.Initialize(&vboColorsCreateInfo);

        m_verticesBuffer = verticesBufferManager.GetVbo();
        m_colorsBuffer = colorsBufferManager.GetVbo();
    }

    void TriangleModel::Initialize(const glm::vec3& pos, const glm::vec2& size)
    {
        m_vertices = {
                -size.x + pos.x, -size.y + pos.y, 0.0f + pos.z,
                0.0f + pos.x, size.y + pos.y, 0.0f + pos.z,
                size.x + pos.x, -size.y + pos.y, 0.0f + pos.z
        };

        m_pos = pos;

        VboManagerCreateInfo vboVerticesCreateInfo;
        vboVerticesCreateInfo.data = m_vertices;
        vboVerticesCreateInfo.drawMode = GL_DYNAMIC_DRAW;

        VboManager verticesBufferManager;
        verticesBufferManager.Initialize(&vboVerticesCreateInfo);

        m_colors = {
                1, 0, 0,
                0, 1, 0,
                0, 0, 1
        };

        VboManagerCreateInfo vboColorsCreateInfo;
        vboColorsCreateInfo.data = m_colors;

        VboManager colorsBufferManager;
        colorsBufferManager.Initialize(&vboColorsCreateInfo);

        m_verticesBuffer = verticesBufferManager.GetVbo();
        m_colorsBuffer = colorsBufferManager.GetVbo();
    }

    void TriangleModel::Update()
    {
        std::cout << "TIRANGLE UPDATED" << std::endl;
        m_i += 0.0000001f;
        // m_vertices[0] = m_vertices[0] + m_i;
        // m_vertices[3] = m_vertices[3] + m_i;
        // m_vertices[6] = m_vertices[6] + m_i;

        m_vertices[0] -= m_pos.x;
        m_vertices[1] -= m_pos.y;
        m_vertices[2] -= m_pos.z;
        m_vertices[3] -= m_pos.x;
        m_vertices[4] -= m_pos.y;
        m_vertices[5] -= m_pos.z;
        m_vertices[6] -= m_pos.x;
        m_vertices[7] -= m_pos.y;
        m_vertices[8] -= m_pos.z;

        std::vector<glm::vec3> vertex = {
                glm::vec3{m_vertices[0], m_vertices[1], m_vertices[2]},
                glm::vec3{m_vertices[3], m_vertices[4], m_vertices[5]},
                glm::vec3{m_vertices[6], m_vertices[7], m_vertices[8]}
        };

        vertex[0] = glm::vec4(vertex[0], 1) * glm::rotate(glm::mat4(1.f), 3.14f * 0.001f, glm::vec3(0, 1, 0));
        vertex[1] = glm::vec4(vertex[1], 1) * glm::rotate(glm::mat4(1.f), 3.14f * 0.001f, glm::vec3(0, 1, 0));
        vertex[2] = glm::vec4(vertex[2], 1) * glm::rotate(glm::mat4(1.f), 3.14f * 0.001f, glm::vec3(0, 1, 0));

        m_vertices[0] = vertex[0].x;
        m_vertices[1] = vertex[0].y;
        m_vertices[2] = vertex[0].z;
        m_vertices[3] = vertex[1].x;
        m_vertices[4] = vertex[1].y;
        m_vertices[5] = vertex[1].z;
        m_vertices[6] = vertex[2].x;
        m_vertices[7] = vertex[2].y;
        m_vertices[8] = vertex[2].z;

        m_vertices[0] += m_pos.x;
        m_vertices[1] += m_pos.y;
        m_vertices[2] += m_pos.z;
        m_vertices[3] += m_pos.x;
        m_vertices[4] += m_pos.y;
        m_vertices[5] += m_pos.z;
        m_vertices[6] += m_pos.x;
        m_vertices[7] += m_pos.y;
        m_vertices[8] += m_pos.z;


        glBindBuffer(GL_ARRAY_BUFFER, m_verticesBuffer);
        glBufferData(GL_ARRAY_BUFFER, sizeof(float) * m_vertices.size(), &m_vertices[0], GL_DYNAMIC_DRAW);
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }

    uint32_t TriangleModel::GetVerticesBuffer() const
    {
        return m_verticesBuffer;
    }

    uint32_t TriangleModel::GetColorsBuffer() const
    {
        return m_colorsBuffer;
    }
}
