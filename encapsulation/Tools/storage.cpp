/*
** EPITECH PROJECT, 2022
** storage.cpp
** File description:
** storage
*/

#include "Tools.hpp"
#include "raylib.h"

bool ray::Tools::Storage::saveStorageValue(unsigned int position, int value)
{
    return SaveStorageValue(position, value);
}

int ray::Tools::Storage::loadStorageValue(unsigned int position)
{
    return LoadStorageValue(position);
}