#pragma once
#include "Core/Events/Events.h"
#include <sstream>
#include <backends/imgui_impl_glfw.h>
#include "Core/Engine.h"

class WindowResizeEvent : Event 
{
public:
	WindowResizeEvent(GLFWwindow* window, int width, int height): Event(window, EventType::WindowResize, NULL), mwidth(width), mheight(height) {}

	inline virtual std::string ToString() override {
		std::stringstream ss;
		ss << "Window Resize (Width: " << mwidth << ", Height: " << mheight << ')';
		return ss.str();
	}

	inline virtual std::string GetName() override {
		return "Window Resize";
	}

	inline int GetWidth() { return mwidth; };
	inline int GetHeight() { return mheight; };
private:
	int mwidth, mheight;
};

class WindowExitEvent : Event
{
public: 
	WindowExitEvent(GLFWwindow* window): Event(window, EventType::WindowExit, NULL) {}

	inline virtual std::string GetName() override { return "Window Exit"; }
};
