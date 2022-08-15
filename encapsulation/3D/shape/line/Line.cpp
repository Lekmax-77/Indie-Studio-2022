/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-zacharie.lawson
** File description:
** Line
*/

#include "Line.hpp"

ray::_3D::shape::Line::Line(Vector3 start, Vector3 end, Color color)
    : _start(start), _end(end), _color(color)
{
}

ray::_3D::shape::Line::Line(const ray::_3D::shape::Line &src)
    : _start(src._start), _end(src._end), _color(src._color)
{
}

ray::_3D::shape::Line::~Line()
{
}

ray::_3D::shape::Line &ray::_3D::shape::Line::operator=(const ray::_3D::shape::Line &src)
{
    _start = src._start;
    _end = src._end;
    _color = src._color;
    return *this;
}

// getters
Vector3 ray::_3D::shape::Line::getStartPosition() const
{
    return _start;
}
Vector3 ray::_3D::shape::Line::getEndPosition() const
{
    return _end;
}
Color ray::_3D::shape::Line::getColor() const
{
    return _color;
}

// setters
void ray::_3D::shape::Line::setStartPosition(Vector3 start)
{
    _start = start;
}
void ray::_3D::shape::Line::setEndPosition(Vector3 end)
{
    _end = end;
}
void ray::_3D::shape::Line::setColor(Color color)
{
    _color = color;
}

// methods

void ray::_3D::shape::Line::draw() const
{
    DrawLine3D(_start, _end, _color);
}