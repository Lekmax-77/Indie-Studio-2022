/*
** EPITECH PROJECT, 2022
** indie
** File description:
** Cursor
*/

#include "ICursor.hpp"
#include "raylib.h"

ray::Cursor::Cursor()
{
    EnableCursor();
    ShowCursor();
}

ray::Cursor::~Cursor()
{
    HideCursor();
    DisableCursor();
}

void ray::Cursor::showCursor(void)
{
    ShowCursor();
}

void ray::Cursor::hideCursor(void)
{
    HideCursor();
}

bool ray::Cursor::isCursorHidden(void)
{
    return IsCursorHidden();
}

void ray::Cursor::enableCursor(void)
{
    EnableCursor();
}

void ray::Cursor::disableCursor(void)
{
    DisableCursor();
}

bool ray::Cursor::isCursorOnScreen(void)
{
    return IsCursorOnScreen();
}
