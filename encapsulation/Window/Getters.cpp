/*
** EPITECH PROJECT, 2022
** encapsulation
** File description:
** Window
*/

#include "Window.hpp"

/* INITIALIZATION AND DESTRUCTION */

ray::Window::Window(int width, int height, const std::string &title)
{
    InitWindow(width, height, title.c_str());
    InitAudioDevice();
}

ray::Window::~Window()
{
}

/* GETTERS */

bool ray::Window::isWindowReady(void) const
{
    return IsWindowReady();
}

bool ray::Window::isWindowHidden(void) const
{
    return IsWindowHidden();
}

bool ray::Window::isWindowFocused(void) const
{
    return IsWindowFocused();
}

bool ray::Window::isWindowState(unsigned int flag) const
{
    return IsWindowState(flag);
}

bool ray::Window::isWindcowFullscreen(void) const
{
    return IsWindowFullscreen();
}

bool ray::Window::isWindowResized(void) const
{
    return IsWindowResized();
}

bool ray::Window::isWindowMaximized(void) const
{
    return IsWindowMaximized();
}

bool ray::Window::isWindowMinimized(void) const
{
    return IsWindowMinimized();
}

int ray::Window::getScreenWidth(void) const
{
    return GetScreenWidth();
}

int ray::Window::getScreenHeight(void) const
{
    return GetScreenHeight();
}

int ray::Window::getMonitorCount(void) const
{
    return GetMonitorCount();
}

int ray::Window::getCurrentMonitor(void) const
{
    return GetCurrentMonitor();
}

Vector2 ray::Window::getMonitorPosition(int monitor) const
{
    return GetMonitorPosition(monitor);
}

int ray::Window::getMonitorWidth(int monitor) const
{
    return GetMonitorWidth(monitor);
}

int ray::Window::getMonitorHeight(int monitor) const
{
    return GetMonitorHeight(monitor);
}

int ray::Window::getMonitorPhysicalWidth(int monitor) const
{
    return GetMonitorPhysicalWidth(monitor);
}

int ray::Window::getMonitorPhysicalHeight(int monitor) const
{
    return GetMonitorPhysicalHeight(monitor);
}

int ray::Window::getMonitorRefreshRate(int monitor) const
{
    return GetMonitorRefreshRate(monitor);
}

Vector2 ray::Window::getWindowPosition(void) const
{
    return GetWindowPosition();
}

Vector2 ray::Window::getWindowScaleDPI(void) const
{
    return GetWindowScaleDPI();
}

std::string ray::Window::getMonitorName(int monitor) const
{
    return GetMonitorName(monitor);
}

std::string ray::Window::getClipboardText(void) const
{
    return GetClipboardText();
}
