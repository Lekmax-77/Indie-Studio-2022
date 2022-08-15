/*
** EPITECH PROJECT, 2022
** Misc.cpp
** File description:
** Misc fonction
*/

#include "Tools.hpp"
#include "raylib.h"

int ray::Tools::Misc::getRandomValue(int min, int max)
{
    return GetRandomValue(min, max);
}

void ray::Tools::Misc::setRandomSeed(unsigned int seed)
{
    SetRandomSeed(seed);
}

void ray::Tools::Misc::takeScreenshot(std::string const &fileName)
{
    TakeScreenshot(fileName.c_str());
}

void ray::Tools::Misc::setConfigFlags(unsigned int flags)
{
    SetConfigFlags(flags);
}

void ray::Tools::Misc::openURL(std::string const &url)
{
    OpenURL(url.c_str());
}
