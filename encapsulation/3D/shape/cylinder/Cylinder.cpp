/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-zacharie.lawson
** File description:
** Cylinder
*/

#include "Cylinder.hpp"

ray::_3D::shape::Cylinder::Cylinder(Vector3 pos, float height, float radiusBottom, float radiusTop, Color color)
    : _pos(pos), _height(height), _radiusBottom(radiusBottom), _radiusTop(radiusTop), _color(color)
{
}

ray::_3D::shape::Cylinder::Cylinder(const ray::_3D::shape::Cylinder &src)
    : _pos(src._pos), _height(src._height), _radiusBottom(src._radiusBottom), _radiusTop(src._radiusTop), _color(src._color)
{
}

ray::_3D::shape::Cylinder::~Cylinder()
{
}

ray::_3D::shape::Cylinder &ray::_3D::shape::Cylinder::operator=(const ray::_3D::shape::Cylinder &src)
{
    _pos = src._pos;
    _height = src._height;
    _radiusBottom = src._radiusBottom;
    _radiusTop = src._radiusTop;
    _color = src._color;
    return *this;
}

// getters
Vector3 ray::_3D::shape::Cylinder::getPosition() const
{
    return _pos;
}

float ray::_3D::shape::Cylinder::getHeight() const
{
    return _height;
}

float ray::_3D::shape::Cylinder::getRadiusBottom() const
{
    return _radiusBottom;
}

float ray::_3D::shape::Cylinder::getRadiusTop() const
{
    return _radiusTop;
}

Color ray::_3D::shape::Cylinder::getColor() const
{
    return _color;
}

// setters
void ray::_3D::shape::Cylinder::setPosition(Vector3 pos)
{
    _pos = pos;
}

void ray::_3D::shape::Cylinder::setHeight(float height)
{
    _height = height;
}

// methods
void ray::_3D::shape::Cylinder::draw() const
{
    DrawCylinder(_pos, _radiusBottom, _radiusTop, _height, 25, _color);
}