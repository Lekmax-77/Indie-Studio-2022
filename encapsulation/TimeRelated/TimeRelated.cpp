/*
** EPITECH PROJECT, 2022
** indie
** File description:
** TimeRelated
*/

#include "raylib.h"
#include "TimeRelated.hpp"

ray::TimeRelated::TimeRelated()
{
}

ray::TimeRelated::~TimeRelated()
{
}

void ray::TimeRelated::setTargetFPS(int fps)
{
    SetTargetFPS(fps);
}

int ray::TimeRelated::getFPS(void)
{
    return GetFPS();
}

void ray::TimeRelated::drawFPS(int x, int y)
{
    return DrawFPS(x, y);
}

float ray::TimeRelated::getFrameTime(void)
{
    return GetFrameTime();
}

double ray::TimeRelated::getTime(void)
{
    return GetTime();
}
