#pragma once
#define GLFW_INCLUDE_NONE
#include "Core/Events/UserEvents.h"
#include "Core/Events/WindowEvents.h"
#include <GLFW/glfw3.h>
#include "Elements/Plane.h"
#include "Core/Graphics/Shader.h"

class Engine
{
public:
	Engine();
	~Engine();
	
	void run();

	static Engine* GetInstance() { return minstance; }

	GLFWwindow* GetWindowHandle() { return mwindow; }

	struct WindowData {
		int width, height;
		const char* title;
	};

	const WindowData& GetWindowData() { return mwindowdata; }
private:
	static Engine* minstance;
	bool mrunning;
	GLFWwindow* mwindow;

	WindowData mwindowdata;
	Plane* plane;

	void initGlfw();
	void initImGui();
	void initEvents();
	void loop();
	void terminate();
};
