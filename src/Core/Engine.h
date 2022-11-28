#pragma once

#include <GLFW/glfw3.h>

class Engine
{
public:
	Engine();
	~Engine();
	
	void run();
private:
	Engine* minstance;
	bool mrunning;
	GLFWwindow* mwindow;

	struct WindowData {
		int width, height;
		const char* title;
	};

	WindowData mwindowdata;
	
	void initGlfw();
	void initImGui();
	void initEvents();
	void loop();
	void terminate();
};
