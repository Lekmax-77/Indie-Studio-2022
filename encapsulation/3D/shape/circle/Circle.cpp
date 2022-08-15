/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-zacharie.lawson
** File description:
** Circle
*/

#include "Circle.hpp"

ray::_3D::shape::Circle::Circle(Vector3 center, float radius, Color color, Vector3 rotation, float rotationAngle)
    : _center(center), _radius(radius), _rotation(rotation), _rotationAngle(rotationAngle), _color(color)
{
}

ray::_3D::shape::Circle::Circle(const ray::_3D::shape::Circle &src)
    : _center(src._center), _radius(src._radius), _rotation(src._rotation), _rotationAngle(src._rotationAngle), _color(src._color)
{
}

ray::_3D::shape::Circle::~Circle()
{
}

ray::_3D::shape::Circle &ray::_3D::shape::Circle::operator=(const ray::_3D::shape::Circle &src)
{
    _center = src._center;
    _radius = src._radius;
    _rotation = src._rotation;
    _rotationAngle = src._rotationAngle;
    _color = src._color;
    return *this;
}

// getters
Vector3 ray::_3D::shape::Circle::getCenter() const
{
    return _center;
}
float ray::_3D::shape::Circle::getRadius() const
{
    return _radius;
}
Vector3 ray::_3D::shape::Circle::getRotation() const
{
    return _rotation;
}
float ray::_3D::shape::Circle::getRotationAngle() const
{
    return _rotationAngle;
}
Color ray::_3D::shape::Circle::getColor() const
{
    return _color;
}

// setters
void ray::_3D::shape::Circle::setCenter(Vector3 center)
{
    _center = center;
}
void ray::_3D::shape::Circle::setRadius(float radius)
{
    _radius = radius;
}
void ray::_3D::shape::Circle::setRotation(Vector3 rotation)
{
    _rotation = rotation;
}
void ray::_3D::shape::Circle::setRotationAngle(float rotationAngle)
{
    _rotationAngle = rotationAngle;
}
void ray::_3D::shape::Circle::setColor(Color color)
{
    _color = color;
}

// methods

void ray::_3D::shape::Circle::draw() const
{
    DrawCircle3D(_center, _radius, _rotation, _rotationAngle, _color);
}