#pragma once
#include <imgui.h>

class GuiManager
{
public:
    GuiManager();
    ~GuiManager();

    static bool IsActive();
private:
    static bool active;
};