#pragma once
#include "Core/Graphics/Shader.h"
#include <vector>
#include <string>
#include <unordered_map>

class ShaderManager
{
public:
	static int LoadShader(const std::string &name, std::string path="shaders/");
	static Shader& UseShader(int id);
	static Shader& UseShader(const std::string& name, std::string path="shaders/");
	static Shader& GetShader(int id);
	static Shader& GetShader(const std::string& name, std::string path="shaders/");

	static void Terminate();
private:
	static std::unordered_map<std::string, int> loadedShaders;
	static std::vector<Shader> shaders;
};
