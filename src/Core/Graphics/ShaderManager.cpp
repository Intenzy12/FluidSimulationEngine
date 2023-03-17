#include "Core/Graphics/ShaderManager.h"
#include <unordered_map>
#include <sstream>
#include "Core/Error.h"

std::unordered_map<std::string, int> ShaderManager::loadedShaders;
std::vector<Shader> ShaderManager::shaders;

void ShaderManager::Terminate()
{
	shaders = {};
}

int ShaderManager::LoadShader(const std::string &name, std::string path)
{
	if (loadedShaders.find(name) != loadedShaders.end())
		return loadedShaders[name];

	shaders.emplace_back(path + name + ".vert", path + name + ".frag");
	loadedShaders[name] = shaders.size() - 1;
	return shaders.size() - 1;
}

Shader& ShaderManager::UseShader(int id)
{
	Shader& o = GetShader(id);
	o.UseShader();
	return o;
}

Shader& ShaderManager::UseShader(const std::string& name, std::string path)
{
	Shader& o = GetShader(name, path);
	o.UseShader();
	return o;
}

Shader& ShaderManager::GetShader(int id)
{
	
	if (id >= (int) shaders.size() || id < 0)
	{
		std::stringstream ss;
		ss << "Shader with ID of " << id << " does not exist\n";
		FatalError(ss.str());
	}

	return shaders[id];
}

Shader& ShaderManager::GetShader(const std::string& name, std::string path)
{
	
	if (loadedShaders.find(name) == loadedShaders.end())
		LoadShader(name, path);

	return shaders[loadedShaders[name]];
}
