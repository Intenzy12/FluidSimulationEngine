#pragma once
#define BIT(x) (1 << x)
#include <iostream>
#include <functional>

//The event system will work by creating a class for every event that will be instanced when the event takes place
//each event class will have different parameters which can then be accesed
//some of the parameters will be part of all events (such as the event type and category flags)
//however other parameters will be exclusive to that certain type of event (such as the mouse position in the mouse moved event)
//the reason why this is better than just getting information straight from an api
//is because this abstracts everything in such a way so that I could change the api rather easilly
//this is very helpfull especially if I want to keep this cross platform

//Event Type that each event will have
enum class EventType
{
    None = 0,
    KeyPressedEvent, KeyReleasedEvent,
    MouseMovedEvent, MouseButtonPressedEvent, MouseButtonReleasedEvent,
    WindowClosedEvent, WindowResizedEvent, WindowMovedEvent,
    SerialInputEvent
};

//Event Category that each event will have
enum EventCategory
{
    //Each event category is set to a different bit so that an int can express multiple event categories
    None = 0,
    EventCategoryKey = BIT(0),
    EventCategoryMouse = BIT(1),
    EventCategoryMouseButton = BIT(2),
    EventCategorySerial = BIT(3),
    EventCategoryInput = BIT(4),
    EventCategoryApplication = BIT(5)
};

//Macros just so I don't have to retype the following a thousand times
#define EVENT_CLASS_TYPE(type) static EventType GetStaticType() { return EventType::type; }\
                                EventType GetEventType() const override { return GetStaticType(); }\
                                const char* GetName() const override { return #type; }
                                
#define EVENT_CLASS_CATEGORY(category) int GetCategoryFlags() const override { return category; }

//Abstract Event Parent Class
class Event
{
public:
    virtual ~Event() = default;

    //All events should have the following
    virtual EventType GetEventType() const = 0;
    virtual int GetCategoryFlags() const = 0;
    virtual const char* GetName() const = 0;
    virtual std::string ToString() const { return GetName(); }

    bool IsCategory(int category) const { return category & GetCategoryFlags(); }

private:
    bool m_Handled = false;
    friend class Dispatcher;
};

//The dispatcher is a class that is very helpfull because it will allow me to pass in functions
//which will only be called if the event type is the same as what is needed for the function
class Dispatcher
{
    template<typename T>
    using EventFn = std::function<bool(T&)>;
public:
    Dispatcher(Event& event): m_Event(event) {}

    //Dispatch will only call the function given if the event type matches that of the function
    template<typename T>
    bool Dispatch(EventFn<T> EventFunction)
    {
        if(m_Event.GetEventType() == T::GetStaticType() && !m_Event.m_Handled)
        {
            m_Event.m_Handled = EventFunction(*(T*)&m_Event);
            return true;
        }

        return false;
    }
private:
    Event& m_Event;
};

//For debuging convinience
inline std::ostream& operator<<(std::ostream& stream, const Event& event)
{
    return stream << event.ToString();
}
