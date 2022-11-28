#pragma once

#include <string>
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
	virtual EventType GetType() = 0;
	virtual std::string GetName() = 0;

	virtual std::string ToString() {
		return GetName();
	}
};
