/*
** EPITECH PROJECT, 2022
** encapsulation
** File description:
** Camera
*/

#include "Camera.hpp"
#include "Vector3.hpp"
#include <memory>

ray::Camera3D::Camera3D(): ::Camera{{0, 0, 0}, {0,0,0}, {0,1,0}, 45.0f, 0}
{
}

ray::Camera3D::~Camera3D()
{

}

void ray::Camera3D::setCameraMode(int mode)
{
    SetCameraMode(*this, mode);
}

void ray::Camera3D::updateCamera()
{
    UpdateCamera(this);
}

void ray::Camera3D::setCameraPanControl(int keyPan)
{
    SetCameraPanControl(keyPan);
}

void ray::Camera3D::setCameraAltControl(int keyAlt)
{

    SetCameraAltControl(keyAlt);
}

void ray::Camera3D::setCameraSmoothZoomControl(int keySmoothZoom)
{
    SetCameraSmoothZoomControl(keySmoothZoom);
}

void ray::Camera3D::setCameraMoveControls(int keyFront, int keyBack, int keyRight, int keyLeft, int keyUp, int keyDown)
{
    SetCameraMoveControls(keyFront, keyBack, keyRight, keyLeft, keyUp, keyDown);
}

void ray::Camera3D::setPosition(ray::Vector3 Pos, ray::Vector3 Target, ray::Vector3 Up, float Fovy)
{
    position = Pos;
    target = Target;
    fovy = Fovy;
    up = Up;
}

::Camera3D ray::Camera3D::getCamera()
{
    return *this;
}
