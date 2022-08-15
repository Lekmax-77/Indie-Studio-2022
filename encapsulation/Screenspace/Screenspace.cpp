/*
** EPITECH PROJECT, 2022
** indie
** File description:
** Screenspace
*/

#include "Screenspace.hpp"

ray::Screenspace::Screenspace()
{
}

ray::Screenspace::~Screenspace()
{
}

Ray ray::Screenspace::getMouseRay(Vector2 mousePosition, Camera camera) const
{
    return GetMouseRay(mousePosition, camera);
}

Matrix ray::Screenspace::getCameraMatrix(Camera camera) const
{
    return GetCameraMatrix(camera);
}

Matrix ray::Screenspace::getCameraMatrix2D(Camera2D camera) const
{
    return GetCameraMatrix2D(camera);
}

Vector2 ray::Screenspace::getWorldToScreen(Vector3 position, Camera camera) const
{
    return GetWorldToScreen(position, camera);
}

Vector2 ray::Screenspace::getWorldToScreenEx(Vector3 position, Camera camera, int width, int height) const
{
    return GetWorldToScreenEx(position, camera, width, height);
}

Vector2 ray::Screenspace::getWorldToScreen2D(Vector2 position, Camera2D camera) const
{
    return GetWorldToScreen2D(position, camera);
}

Vector2 ray::Screenspace::getScreenToWorld2D(Vector2 position, Camera2D camera) const
{
    return GetScreenToWorld2D(position, camera);
}