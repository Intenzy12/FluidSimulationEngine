#pragma once
#include "Core/Events/Events.h"
#include <GLFW/glfw3.h>
#include <backends/imgui_impl_glfw.h>
#include <sstream>

class MouseButtonEvent : Event
{
public:
	MouseButtonEvent(GLFWwindow* window, int button, int action, int mods):
		Event(window, EventType::MouseButton, std::bind(ImGui_ImplGlfw_MouseButtonCallback, window, button, action, mods)),
		mbutton(button), maction(action), mmods(mods) {}

	inline virtual std::string GetName() override { return "Mouse Button"; }

	inline virtual std::string ToString() override
	{
		std::stringstream ss;
		ss << "Mouse Button (button: " << mbutton << ", action: " << maction << ", mods: " << mmods << ")";
		return ss.str();
	}

	inline int GetButton() { return mbutton; }

	inline int GetAction() { return maction; }

	inline int GetMods() { return mmods; }

private:
		int mbutton, maction, mmods;

};

class MouseScrollEvent : Event 
{
public:
	MouseScrollEvent(GLFWwindow* window, double xoffset, double yoffset): 
		Event(window, EventType::MouseScroll, std::bind(ImGui_ImplGlfw_ScrollCallback, window, xoffset, yoffset)),
		mxoffset(xoffset), myoffset(yoffset) {}
	
	inline virtual std::string GetName() override { return "Mouse Scroll"; }

	inline virtual std::string ToString() override
	{
		std::stringstream ss;
		ss << "Mouse Scroll (xoffset: " << mxoffset << ", yoffset: " << myoffset << ")";
		return ss.str();
	}

	inline double GetXOffset() { return mxoffset; }
	
	inline double GetYOffset() { return myoffset; }
private:
	double mxoffset, myoffset;
};

class CursorPosEvent : Event
{
public:
	CursorPosEvent(GLFWwindow* window, double xPos, double yPos): 
		Event(window, EventType::CursorPos, std::bind(ImGui_ImplGlfw_CursorPosCallback, window, xPos, yPos)),
		mXPos(xPos), mYPos(yPos) {}
	
	inline virtual std::string GetName() override { return "Cursor Position"; }

	inline virtual std::string ToString() override {
		std::stringstream ss;
		ss << "Cursor Position (xpos: " << mXPos << ", ypos: " << mYPos << ")";
		return ss.str();
	}

	inline double GetXPos() { return mXPos; }

	inline double GetYPos() { return mYPos; }
private:
	double mXPos, mYPos;
};

class KeyEvent : Event
{
public: 
	KeyEvent (GLFWwindow* window, int key, int scancode, int action, int mods): 
		Event(window, EventType::Key, std::bind(ImGui_ImplGlfw_KeyCallback, window, key, scancode, action, mods)),
		mkey(key), mscancode(scancode), maction(action), mmods(mods) {}

	inline virtual std::string GetName() override { return "Key Event"; }

	inline virtual std::string ToString() override {
		std::stringstream ss;
		ss << "Key Event (key: " << mkey << ", scancode: " << mscancode << ", action: " << maction << ", mods: " << mmods << ")";
		return ss.str();
	}

	inline int GetKey() { return mkey; }
	inline int GetScancode() {return mscancode; }
	inline int GetAction() { return maction; } 
	inline int GetMods() { return mmods; }

private:
	int mkey, mscancode, maction, mmods;
};
