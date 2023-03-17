
#pragma once
#include <glad/glad.h>
#include <string>
#include <glm/matrix.hpp>

class Shader
{
public:
    Shader(std::string vertFilePath, std::string fragFilePath);
    ~Shader();

	Shader& SetUniformMatrix4fv(std::string name, const glm::mat4& data);
    void UseShader();

private:
    void loadShader(std::string vertFilePath, std::string fragFilePath);
    void compileShader(std::string filePath, int id);
    void linkShader();
    GLuint m_ProgramId;
    GLuint m_VertId;
    GLuint m_FragId;
};
