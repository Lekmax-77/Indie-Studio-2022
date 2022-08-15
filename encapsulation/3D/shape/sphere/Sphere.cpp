/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-zacharie.lawson
** File description:
** Sphere
*/

#include "Sphere.hpp"

ray::_3D::shape::Sphere::Sphere(Vector3 pos, float radius, Color color)
    : _pos(pos), _radius(radius), _color(color)
{
}

ray::_3D::shape::Sphere::Sphere(const ray::_3D::shape::Sphere &src)
    : _pos(src._pos), _radius(src._radius), _color(src._color)
{
}

ray::_3D::shape::Sphere::~Sphere()
{
}

ray::_3D::shape::Sphere &ray::_3D::shape::Sphere::operator=(const ray::_3D::shape::Sphere &src)
{
    _pos = src._pos;
    _radius = src._radius;
    _color = src._color;
    return *this;
}

// getters
Vector3 ray::_3D::shape::Sphere::getPosition() const
{
    return _pos;
}
float ray::_3D::shape::Sphere::getRadius() const
{
    return _radius;
}
Color ray::_3D::shape::Sphere::getColor() const
{
    return _color;
}

// setters
void ray::_3D::shape::Sphere::setPosition(Vector3 pos)
{
    _pos = pos;
}
void ray::_3D::shape::Sphere::setRadius(float radius)
{
    _radius = radius;
}
void ray::_3D::shape::Sphere::setColor(Color color)
{
    _color = color;
}

// methods
void ray::_3D::shape::Sphere::draw() const
{
    DrawSphere(_pos, _radius, _color);
}