#include "Core/Events/Events.h"
#include <sstream>

//Key event parent class
class KeyEvent: public Event
{
public:
    inline int GetKeyCode() const { return m_KeyCode; }

    EVENT_CLASS_CATEGORY(EventCategoryKey | EventCategoryInput)
protected:
    KeyEvent(int keyCode): m_KeyCode(keyCode) {}
    int m_KeyCode;
};

//Key pressed event class
class KeyPressed: public KeyEvent
{
public:
    KeyPressed(int keyCode, int repeat): KeyEvent(keyCode), m_Repeat(repeat) {}

    inline int GetRepeat() const { return m_Repeat; }

    EVENT_CLASS_TYPE(KeyPressedEvent)

    std::string ToString() const override
    {
        std::stringstream ss;
        ss << "KeyPressed: " << m_KeyCode << " (repeats " << m_Repeat << ")";
        return ss.str();
    }
private:
    int m_Repeat;
};

//Key released event class
class KeyReleased: public KeyEvent
{
public:
    KeyReleased(int keyCode): KeyEvent(keyCode) {}

    EVENT_CLASS_TYPE(KeyReleasedEvent)

    std::string ToString() const override
    {
        std::stringstream ss;
        ss << "KeyReleased: " << m_KeyCode;
        return ss.str();
    }
};

//Mouse moved event class
class MouseMoved: public Event
{
public:
    MouseMoved(float xPos, float yPos): m_XPos(xPos), m_YPos(yPos) {}

    inline float GetXPos() const { return m_XPos; }
    inline float GetYPos() const { return m_YPos; }

    EVENT_CLASS_TYPE(MouseMovedEvent)

    EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

    std::string ToString() const override 
    {
        std::stringstream ss;
        ss << "MouseMoved: " << m_XPos << ", " << m_YPos;
        return ss.str();
    }
private:
    float m_XPos;
    float m_YPos;
};

//Mouse button event parent class
class MouseButtonEvent: public Event
{
public: 
    inline int GetButtonCode() const { return m_ButtonCode; }

    EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryMouseButton | EventCategoryMouse)
protected:
    MouseButtonEvent(int buttonCode): m_ButtonCode(buttonCode) {}
    int m_ButtonCode;
};

//Mouse button pressed event class
class MouseButtonPressed: public MouseButtonEvent
{
public:
    MouseButtonPressed(int buttonCode): MouseButtonEvent(buttonCode) {}

    EVENT_CLASS_TYPE(MouseButtonPressedEvent)

    std::string ToString() const override
    {
        std::stringstream ss;
        ss << "MouseButtonPressed: " << m_ButtonCode;
        return ss.str();
    }
};

//Mouse button released event class
class MouseButtonReleased: public MouseButtonEvent
{
public:
    MouseButtonReleased(int buttonCode): MouseButtonEvent(buttonCode) {}

    EVENT_CLASS_TYPE(MouseButtonReleasedEvent)

    std::string ToString() const override
    {
        std::stringstream ss;
        ss << "MouseButtonReleased: " << m_ButtonCode;
        return ss.str();
    }
};

class SerialInput: public Event
{
public:
    SerialInput(const char* buffer, int size): m_Buffer(buffer), m_Size(size) {}

    inline const char* const GetBuffer() const { return m_Buffer; }
    inline int GetSize() const { return m_Size; }

    EVENT_CLASS_TYPE(SerialInputEvent)
    EVENT_CLASS_CATEGORY(EventCategorySerial)

    std::string ToString() const override
    {
        std::stringstream ss;
        ss << "SerialInput: " << m_Buffer << " (size: " << m_Size << ")";
        return ss.str();
    }
private:
    const char* m_Buffer;
    int m_Size;
};
