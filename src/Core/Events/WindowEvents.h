#include "Core/Events/Events.h"
#include <sstream>

//Window moved event class
class WindowMoved: public Event
{
public:
    WindowMoved(int xPos, int yPos): m_XPos(xPos), m_YPos(yPos) {}

    inline int GetXPos() const { return m_XPos; }
    inline int GetYPos() const { return m_YPos; } 

    EVENT_CLASS_CATEGORY(EventCategoryApplication)

    EVENT_CLASS_TYPE(WindowMovedEvent)

    std::string ToString() const override 
    {
        std::stringstream ss;
        ss << "WindowMoved: " << m_XPos << ", " << m_YPos;
        return ss.str();
    }
private:
    int m_XPos;
    int m_YPos;
};

//Window resized event class
class WindowResized: public Event
{
public:
    WindowResized(int width, int height): m_Width(width), m_Height(height) {}

    inline int GetXPos() const { return m_Width; }
    inline int GetYPos() const { return m_Height; } 

    EVENT_CLASS_CATEGORY(EventCategoryApplication)

    EVENT_CLASS_TYPE(WindowResizedEvent)

    std::string ToString() const override 
    {
        std::stringstream ss;
        ss << "WindowResized: " << m_Width << ", " << m_Height;
        return ss.str();
    }
private:
    int m_Width;
    int m_Height;
};

//Window closed event class
class WindowClosed: public Event
{
public:
    WindowClosed() {}

    EVENT_CLASS_CATEGORY(EventCategoryApplication)

    EVENT_CLASS_TYPE(WindowClosedEvent)
};
