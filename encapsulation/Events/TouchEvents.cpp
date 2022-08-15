/*
** EPITECH PROJECT, 2022
** indie
** File description:
** TouchEvents
*/

#include "IEvents.hpp"

/*
ray::TouchEvents::TouchEvents()
{
}

ray::TouchEvents::~TouchEvents()
{
}
*/
int ray::TouchEvents::getTouchX(void) const
{
    return GetTouchX();
}

int ray::TouchEvents::getTouchY(void) const
{
    return GetTouchY();
}

Vector2 ray::TouchEvents::getTouchPosition(int index) const
{
    return GetTouchPosition(index);
}

int ray::TouchEvents::getTouchPointId(int index) const
{
    return GetTouchPointId(index);
}

int ray::TouchEvents::getTouchPointCount(void) const
{
    return GetTouchPointCount();
}
