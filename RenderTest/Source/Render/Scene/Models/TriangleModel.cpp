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

        m_verticesBuffer = verticesBufferManager.getVbo();
        m_colorsBuffer = colorsBufferManager.getVbo();
    }

    void TriangleModel::Initialize(const glm::vec3& pos, const glm::vec2& size)
    {
        m_vertices = {
                -size.x + pos.x, -size.y + pos.y, 0.0f + pos.z,
                0.0f + pos.x, size.y + pos.y, 0.0f + pos.z,
                size.x + pos.x, -size.y + pos.y, 0.0f + pos.z
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

        m_verticesBuffer = verticesBufferManager.getVbo();
        m_colorsBuffer = colorsBufferManager.getVbo();
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
