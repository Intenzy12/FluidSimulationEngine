#include "Core/Graphics/Shader.h"
#include <iostream>
#include <fstream>

Shader::Shader(std::string vertFilePath, std::string fragFilePath): m_ProgramId(0), m_VertId(0), m_FragId(0)
{
    loadShader(vertFilePath, fragFilePath);
}

Shader::~Shader()
{
    glDeleteShader(m_VertId);
    glDeleteShader(m_FragId);
    glDeleteProgram(m_ProgramId);
}

void Shader::loadShader(std::string vertFilePath, std::string fragFilePath)
{
    m_VertId = glCreateShader(GL_VERTEX_SHADER);
    if(m_VertId == 0)
    {
        std::cout << "Failed to create vertex shader\n";
        exit(EXIT_FAILURE);
    }

    m_FragId = glCreateShader(GL_FRAGMENT_SHADER);
    if(m_FragId == 0)
    {
        std::cout << "Failed to create fragment shader\n";
        exit(EXIT_FAILURE);
    }

    m_ProgramId = glCreateProgram();
    if(m_ProgramId == 0)
    {
        std::cout << "Failed to create shader program\n";
        exit(EXIT_FAILURE);
    }

    compileShader(vertFilePath, m_VertId);
    compileShader(fragFilePath, m_FragId);

    linkShader();
}

void Shader::compileShader(std::string filePath, int id)
{
    std::fstream file(filePath.c_str());
    if(file.fail())
    {
        std::cout << "Failed to open file " << filePath << '\n';
        exit(EXIT_FAILURE);
    }

    std::string contents = "";
    std::string line;
    while(std::getline(file, line))
    {
        contents += line;
    }
    const char* fileContentsPtr = contents.c_str();
    glShaderSource(id, 1, &fileContentsPtr, NULL);
    file.close();

    glCompileShader(id);

    int succes;
    char infoLog[256];
    glGetShaderiv(id, GL_COMPILE_STATUS, &succes);
    if(!succes)
    {
        glGetShaderInfoLog(id, 256, NULL, infoLog);
        std::cout << "Failed to compile shader " << filePath << ": " << infoLog;
        exit(EXIT_FAILURE);
    }
}

void Shader::linkShader()
{
    glAttachShader(m_ProgramId, m_VertId);
    glAttachShader(m_ProgramId, m_FragId);

    glLinkProgram(m_ProgramId);
    
    int succes;
    char infoLog[256];
    glGetProgramiv(m_ProgramId, GL_LINK_STATUS, &succes);
    if(!succes)
    {
        glGetProgramInfoLog(m_ProgramId, 256, NULL, infoLog);
        std::cout << "Failed to link program: " << infoLog << "\n";
    }
}

void Shader::UseShader()
{
    glUseProgram(m_ProgramId);
}
