
#pragma once
#include <glad/glad.h>
#include <string>

class Shader
{
public:
    Shader(std::string vertFilePath, std::string fragFilePath);
    ~Shader();

    void UseShader();
private:
    void loadShader(std::string vertFilePath, std::string fragFilePath);
    void compileShader(std::string filePath, int id);
    void linkShader();
    GLuint m_ProgramId;
    GLuint m_VertId;
    GLuint m_FragId;
};
