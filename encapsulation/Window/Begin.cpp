/*
** EPITECH PROJECT, 2022
** indie
** File description:
** Begin
*/

#include "Window.hpp"
#include "Camera.hpp"

void ray::Window::beginDrawing(void)
{
    BeginDrawing();
}

void ray::Window::beginMode2D(ray::Camera2D &camera)
{
    BeginMode2D(camera);
}

void ray::Window::beginMode3D(ray::Camera3D &camera)
{
    BeginMode3D(camera);
}

void ray::Window::beginTextureMode(RenderTexture2D target)
{
    BeginTextureMode(target);
}

void ray::Window::beginShaderMode(Shader shader)
{
    BeginShaderMode(shader);
}

void ray::Window::beginBlendMode(int mode)
{
    BeginBlendMode(mode);
}

void ray::Window::beginScissorMode(int x, int y, int width, int height)
{
    BeginScissorMode(x, y, width, height);
}
