/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-zacharie.lawson
** File description:
** Cube
*/

#include "Cube.hpp"
#include <exception>

ray::_3D::shape::Cube::Cube(Vector3 pos, Vector3 size, Color color)
    : _pos(pos), _size(size), _color(color), _texture({}), _textureRect({}), _hasTexture(false)
{
}


ray::_3D::shape::Cube::Cube(Vector3 pos, Vector3 size, Texture2D texture, Color color)
    : _pos(pos), _size(size), _color(color), _texture(texture), _textureRect({0,0, static_cast<float>(_texture.width), static_cast<float>(_texture.height)}), _hasTexture(true)
{
}


ray::_3D::shape::Cube::Cube(Vector3 pos, Vector3 size, Texture2D texture, Rectangle textureRect, Color color)
    : _pos(pos), _size(size), _color(color), _texture(texture), _textureRect(textureRect), _hasTexture(true)
{
}


ray::_3D::shape::Cube::Cube(const ray::_3D::shape::Cube &src)
    : _pos(src._pos), _size(src._size), _color(src._color), _texture(src._texture), _textureRect(src._textureRect), _hasTexture(src._hasTexture)
{
}


ray::_3D::shape::Cube::~Cube()
{
}


ray::_3D::shape::Cube &ray::_3D::shape::Cube::operator=(const ray::_3D::shape::Cube &src)
{
    _pos = src._pos;
    _size = src._size;
    _color = src._color;
    _texture = src._texture;
    _textureRect = src._textureRect;
    _hasTexture = src._hasTexture;
    return *this;
}

// getters
ray::Vector3 ray::_3D::shape::Cube::getPosition() const
{
    return _pos;
}

ray::Vector3 ray::_3D::shape::Cube::getSize() const
{
    return _size;
}

Texture2D ray::_3D::shape::Cube::getTexture() const
{
    return _texture;
}

Rectangle ray::_3D::shape::Cube::getTextureRect() const
{
    return _textureRect;
}

ray::Color ray::_3D::shape::Cube::getColor() const
{
    return _color;
}

bool ray::_3D::shape::Cube::hasTexture() const
{
    return _hasTexture;
}

// setters
void ray::_3D::shape::Cube::setPosition(Vector3 pos)
{
    _pos = pos;
}

void ray::_3D::shape::Cube::setSize(Vector3 size)
{
    _size = size;
}

void ray::_3D::shape::Cube::setTexture(Texture2D texture, bool updateRect)
{
    _texture = texture;
    if (updateRect)
        _textureRect = {0, 0, static_cast<float>(_texture.width), static_cast<float>(_texture.height)};
}

void ray::_3D::shape::Cube::setTextureRect(Rectangle textureRect)
{
    _textureRect = textureRect;
}

void ray::_3D::shape::Cube::setColor(Color color)
{
    _color = color;
}

bool ray::_3D::shape::Cube::setTextureMode(bool mode)
{
    _hasTexture = mode;
    return _hasTexture;
}

// methods
void ray::_3D::shape::Cube::draw() const
{
    if (_hasTexture)
        DrawCubeTextureRec(_texture, _textureRect, _pos, _size.x, _size.y, _size.z, _color);
    else
        DrawCubeV(_pos, _size, _color);
}