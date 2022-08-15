/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-zacharie.lawson
** File description:
** Point
*/

#include "Point.hpp"

ray::_3D::shape::Point::Point(Vector3 pos, Color color)
    : _pos(pos), _color(color)
{
}

ray::_3D::shape::Point::Point(const ray::_3D::shape::Point &src)
    : _pos(src._pos), _color(src._color)
{
}

ray::_3D::shape::Point::~Point()
{
}

ray::_3D::shape::Point &ray::_3D::shape::Point::operator=(const ray::_3D::shape::Point &src)
{
    _pos = src._pos;
    _color = src._color;
    return *this;
}

// getters
Vector3 ray::_3D::shape::Point::getPos() const
{
    return _pos;
}
Color ray::_3D::shape::Point::getColor() const
{
    return _color;
}

// setters
void ray::_3D::shape::Point::setPosition(Vector3 pos)
{
    _pos = pos;
}
void ray::_3D::shape::Point::setColor(Color color)
{
    _color = color;
}

// methods

void ray::_3D::shape::Point::draw() const
{
    DrawPoint3D(_pos, _color);
}