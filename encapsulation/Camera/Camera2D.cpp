/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-zacharie.lawson
** File description:
** Camera2D
*/

#include "Camera.hpp"

ray::Camera2D::Camera2D()
{
}

ray::Camera2D::~Camera2D()
{
}

void ray::Camera2D::setPosition(Vector2 Offset, Vector2 Target, float rotation, float zoom)
{
    offset = Offset;
    target = Target;
    rotation = rotation;
    zoom = zoom;
}

::Camera2D ray::Camera2D::getCamera()
{
    return *this;
}