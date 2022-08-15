/*
** EPITECH PROJECT, 2022
** encapsulation
** File description:
** Others
*/

#include "Window.hpp"

void ray::Window::clearWindowState(unsigned int flag)
{
    ClearWindowState(flag);
}

void ray::Window::toggleFullscreen(void)
{
    ToggleFullscreen();
}

void ray::Window::maximizeWindow(void)
{
    MaximizeWindow();
}

void ray::Window::minimizeWindow(void)
{
    MinimizeWindow();
}

void ray::Window::restoreWindow(void)
{
    RestoreWindow();
}

void ray::Window::clearBackground(ray::Color color)
{
    ClearBackground(color);
}

bool ray::Window::windowShouldClose(void) const
{
    return WindowShouldClose();
}