/*
** EPITECH PROJECT, 2022
** indie
** File description:
** MouseEvents
*/

#include "IEvents.hpp"

/*
ray::MouseEvents::MouseEvents()
{
}

ray::MouseEvents::~MouseEvents()
{
}*/

bool ray::MouseEvents::isMouseButtonPressed(int button) const
{
    return IsMouseButtonPressed(button);
}

bool ray::MouseEvents::isMouseButtonDown(int button) const
{
    return IsMouseButtonDown(button);
}

bool ray::MouseEvents::isMouseButtonReleased(int button) const
{
    return IsMouseButtonReleased(button);
}

bool ray::MouseEvents::isMouseButtonUp(int button) const
{
    return IsMouseButtonUp(button);
}

int ray::MouseEvents::getMouseX(void) const
{
    return GetMouseX();
}

int ray::MouseEvents::getMouseY(void) const
{
    return GetMouseY();
}

Vector2 ray::MouseEvents::getMousePosition(void) const
{
    return GetMousePosition();
}

Vector2 ray::MouseEvents::getMouseDelta(void) const
{
    return GetMouseDelta();
}

void ray::MouseEvents::setMousePosition(int x, int y)
{
    SetMousePosition(x, y);
}

void ray::MouseEvents::setMouseOffset(int offsetX, int offsetY)
{
    SetMouseOffset(offsetX, offsetY);
}

void ray::MouseEvents::setMouseScale(float scaleX, float scaleY)
{
    SetMouseScale(scaleX, scaleY);
}

float ray::MouseEvents::getMouseWheelMove(void) const
{
    return GetMouseWheelMove();
}

void ray::MouseEvents::setMouseCursor(int cursor)
{
    SetMouseCursor(cursor);
}
