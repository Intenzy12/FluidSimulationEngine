#pragma once
#include <functional>
#include <string>
#include <GLFW/glfw3.h>

enum class EventType
{
	WindowExit = 1 << 0,
	WindowResize = 1 << 1,
	MouseButton = 1 << 2,
	CursorPos = 1 << 3,
	MouseScroll = 1 << 4,
	Key = 1 << 5
};

class Event
{
public:
	Event(GLFWwindow* window, EventType type, std::function<void()> imguiFunc): mwindow(window), mtype(type), mimguiFunc(imguiFunc) {}

	virtual ~Event() = 0;

	inline virtual std::string GetName() = 0;

	inline virtual std::string ToString() {
		return GetName();
	}

	inline virtual EventType GetType()
	{
		return mtype;
	}

	inline virtual std::function<void()> GetImGuiFunction() {
		return mimguiFunc;
	}

	inline GLFWwindow* GetWindowHandle() { return mwindow; }

protected:
	GLFWwindow* mwindow;
	EventType mtype;
	std::function<void()> mimguiFunc;
};

