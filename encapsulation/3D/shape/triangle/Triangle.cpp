/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-zacharie.lawson
** File description:
** Triangle
*/

#include "Triangle.hpp"

ray::_3D::shape::Triangle::Triangle(Vector3 v1, Vector3 v2, Vector3 v3, Color color)
    : _fstPos(v1), _sndPos(v2), _trdPos(v3), _color(color)
{
}

ray::_3D::shape::Triangle::Triangle(const ray::_3D::shape::Triangle &src)
    : _fstPos(src._fstPos), _sndPos(src._sndPos), _trdPos(src._trdPos), _color(src._color)
{
}

ray::_3D::shape::Triangle::~Triangle()
{
}

ray::_3D::shape::Triangle &ray::_3D::shape::Triangle::operator=(const ray::_3D::shape::Triangle &src)
{
    _fstPos = src._fstPos;
    _sndPos = src._sndPos;
    _trdPos = src._trdPos;
    _color = src._color;
    return *this;
}

// getters
Vector3 ray::_3D::shape::Triangle::getFirstPos()
{
    return _fstPos;
}

// triangle getters
Vector3 ray::_3D::shape::Triangle::getSecondPos()
{
    return _sndPos;
}

Vector3 ray::_3D::shape::Triangle::getThirdPos()
{
    return _trdPos;
}

Color ray::_3D::shape::Triangle::getColor()
{
    return _color;
}

// setters
void ray::_3D::shape::Triangle::setFirstPos(Vector3 pos)
{
    _fstPos = pos;
}

void ray::_3D::shape::Triangle::setSecondPos(Vector3 pos)
{
    _sndPos = pos;
}

void ray::_3D::shape::Triangle::setThirdPos(Vector3 pos)
{
    _trdPos = pos;
}

void ray::_3D::shape::Triangle::setColor(Color color)
{
    _color = color;
}

// methods
void ray::_3D::shape::Triangle::draw() const
{
    DrawTriangle3D(_fstPos, _sndPos, _trdPos, _color);
}