/*
** EPITECH PROJECT, 2022
** indie
** File description:
** KeyEvents
*/

#include <raylib.h>
#include "IEvents.hpp"

/*
ray::Events::KeyEvents::KeyEvents()
{
}

ray::Events::KeyEvents::~KeyEvents()
{
}
*/
bool ray::KeyEvents::isKeyPressed(int key) const
{
    return IsKeyPressed(key);
}

bool ray::KeyEvents::isKeyDown(int key) const
{
    return IsKeyDown(key);
}

bool ray::KeyEvents::isKeyReleased(int key) const
{
    return IsKeyReleased(key);
}

bool ray::KeyEvents::isKeyUp(int key) const
{
    return IsKeyUp(key);
}

void ray::KeyEvents::setExitKey(int key)
{
    SetExitKey(key);
}

int ray::KeyEvents::getKeyPressed(void) const
{
    return GetKeyPressed();
}

int ray::KeyEvents::getCharPressed(void) const
{
    return GetCharPressed();
}
