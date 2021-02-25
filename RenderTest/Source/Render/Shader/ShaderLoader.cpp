//
// Created by cleme on 25/02/2021.
//

#include "Render/Shader/ShaderLoader.h"

namespace Rt
{
    void ShaderLoader::Initialize(ShaderLoaderCreateInfo* shaderLoaderCreateInfo)
    {
        m_shaderLoaderCreateInfo = *shaderLoaderCreateInfo;
    }

    uint32_t ShaderLoader::Load() const
    {
        // Création des shaders
        uint32_t vsID = glCreateShader(GL_VERTEX_SHADER);
        uint32_t fsID = glCreateShader(GL_FRAGMENT_SHADER);

        // Lecture du code vertexShader
        std::string vsCode;
        std::ifstream vsStream{m_shaderLoaderCreateInfo.vsPath,
                               std::ios::in};
        if (vsStream.is_open())
        {
            std::stringstream sstr;
            sstr << vsStream.rdbuf();
            vsCode = sstr.str();
            vsStream.close();
        }
        else
        {
            std::cout << "Impossible d'ouvrir " << m_shaderLoaderCreateInfo.vsPath << std::endl;
            getchar();
            return 0;
        }

        // Lecture du code fragmentShader
        std::string fsCode;
        std::ifstream fsStream{m_shaderLoaderCreateInfo.fsPath,
                               std::ios::in};

        if (fsStream.is_open())
        {
            std::stringstream sstr;
            sstr << fsStream.rdbuf();
            fsCode = sstr.str();
            fsStream.close();
        }
        else
        {
            std::cout << "Impossible d'ouvrir " << m_shaderLoaderCreateInfo.fsPath << std::endl;
            getchar();
            return 0;
        }

        int result = GL_FALSE;
        int infoLogLength;

        // Compilation du vertexShader
        std::cout << "Compilation : " << m_shaderLoaderCreateInfo.vsPath << std::endl;
        char const* vsSourcePointer = vsCode.c_str();
        glShaderSource(vsID, 1, &vsSourcePointer, nullptr);
        glCompileShader(vsID);

        // Vérification du vertexShader
        glGetShaderiv(vsID, GL_COMPILE_STATUS, &result);
        glGetShaderiv(vsID, GL_INFO_LOG_LENGTH, &infoLogLength);

        if (infoLogLength > 0)
        {
            std::vector<char> vsErrorMessage(infoLogLength + 1);
            glGetShaderInfoLog(vsID, infoLogLength, nullptr, &vsErrorMessage[0]);
            std::cout << &vsErrorMessage[0] << std::endl;
        }

        // Compilation du fragmentShader
        std::cout << "Compilation : " << m_shaderLoaderCreateInfo.fsPath << std::endl;
        char const* fsSourcePointer = fsCode.c_str();
        glShaderSource(fsID, 1, &fsSourcePointer, nullptr);
        glCompileShader(fsID);

        // Vérification du fragmentShader
        glGetShaderiv(fsID, GL_COMPILE_STATUS, &result);
        glGetShaderiv(fsID, GL_INFO_LOG_LENGTH, &infoLogLength);

        if (infoLogLength > 0)
        {
            std::vector<char> fsErrorMessage(infoLogLength + 1);
            glGetShaderInfoLog(fsID, infoLogLength, nullptr, &fsErrorMessage[0]);
            std::cout << &fsErrorMessage[0] << std::endl;
        }

        // Linkage du programme
        std::cout << "Linkage du programme" << std::endl;
        uint32_t programID = glCreateProgram();
        glAttachShader(programID, vsID);
        glAttachShader(programID, fsID);
        glLinkProgram(programID);

        // Vérification du programme
        glGetProgramiv(programID, GL_LINK_STATUS, &result);
        glGetProgramiv(programID, GL_INFO_LOG_LENGTH, &infoLogLength);

        if (infoLogLength > 0)
        {
            std::vector<char> programErrorMessage(infoLogLength + 1);
            glGetProgramInfoLog(programID, infoLogLength, nullptr, &programErrorMessage[0]);
            std::cout << &programErrorMessage[0] << std::endl;
        }

        glDetachShader(programID, vsID);
        glDetachShader(programID, fsID);

        glDeleteShader(vsID);
        glDeleteShader(fsID);

        return programID;
    }
}
