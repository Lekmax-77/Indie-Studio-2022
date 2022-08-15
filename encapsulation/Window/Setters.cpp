/*
** EPITECH PROJECT, 2022
** encapsulation
** File description:
** Setters
*/

#include "Window.hpp"

void ray::Window::setWindowState(unsigned int flag)
{
    SetWindowState(flag);
}

void ray::Window::setWindowTitle(const std::string &title)
{
    SetWindowTitle(title.c_str());
}

void ray::Window::setWindowPosition(int x, int y)
{
    SetWindowPosition(x, y);
}

void ray::Window::setWindowMonitor(int monitor)
{
    SetWindowMonitor(monitor);
}

void ray::Window::setWindowMinSize(int width, int height)
{
    SetWindowMinSize(width, height);
}

void ray::Window::setWindowSize(int width, int height)
{
    SetWindowSize(width, height);
}

void ray::Window::setClipboardText(const std::string &text)
{
    SetClipboardText(text.c_str());
}
