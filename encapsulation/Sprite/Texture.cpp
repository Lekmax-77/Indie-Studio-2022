/*
** EPITECH PROJECT, 2022
** indie-studio
** File description:
** ISprite
*/

#include "Texture.hpp"
#include "Picture.hpp"
#include <iostream>
#include "ResourcesManager.hpp"

ray::Texture::Texture()
{
    this->_scale = 1;
    this->_rotation = 0;
    this->_position = ray::Vector2::Zero();
    this->_color = ray::Color::White();
    this->_origin = ray::Vector2::Zero();
}

ray::Texture::Texture(const std::string &filename)
    : ::Texture2D{rManager.LoadTextures(filename)}
{
    this->_scale = 1;
    this->_rotation = 0;
    this->_position = ray::Vector2::Zero();
    this->_color = ray::Color::White();
    this->_origin = ray::Vector2::Zero();
}

ray::Texture::Texture(const Texture &src)
{
    id = src.id;
    width = src.width;
    height = src.height;
    mipmaps = src.mipmaps;
    format = src.format;

    _position = src._position;
    _rotation = src._rotation;
    _color = src._color;
    _scale = src._scale;
    _origin = src._origin;
}

ray::Texture::~Texture()
{
    ;
}

ray::Texture &ray::Texture::operator=(const Texture &other)
{
    id = other.id;
    width = other.width;
    height = other.height;
    mipmaps = other.mipmaps;
    format = other.format;

    _position = other._position;
    _rotation = other._rotation;
    _color = other._color;
    _scale = other._scale;
    _origin = other._origin;
    return *this;
}

ray::Texture &ray::Texture::operator=(const ::Texture2D &other)
{
    id = other.id;
    width = other.width;
    height = other.height;
    mipmaps = other.mipmaps;
    format = other.format;
    return *this;
}


ray::Vector2 ray::Texture::GetPosition() const
{
    return this->_position;
}

void ray::Texture::SetPosition(ray::Vector2 position)
{
    this->_position = position;
}

void ray::Texture::GenMipmapsTexture()
{
    GenTextureMipmaps(this);
}

void ray::Texture::SetFilterTexture(int filter)
{
    SetTextureFilter(*this , filter);
}

void ray::Texture::SetWrapTexture(int wrap)
{
    SetTextureWrap(*this , wrap);
}

void ray::Texture::Update(const void *pixels)
{
    UpdateTexture(*this , pixels);
}

void ray::Texture::UpdateRec(Rectangle rec, const void *pixels)
{
    UpdateTextureRec(*this , rec, pixels);
}

#include <iostream>

void ray::Texture::Draw()
{
    Vector2 pos = (Vector2){(this->_position.x - this->_origin.x * this->_scale), (this->_position.y - this->_origin.y * this->_scale)};
    DrawTextureEx(*this , pos, this->_rotation, this->_scale, this->_color);
}

void ray::Texture::DrawRec(Rectangle source)
{
    Vector2 pos = (Vector2){(this->_position.x - this->_origin.x * this->_scale), (this->_position.y - this->_origin.y * this->_scale)};
    DrawTextureRec(*this , source, pos, this->_color);
}

void ray::Texture::DrawQuad(Vector2 tiling, Vector2 offset, Rectangle quad)
{
    DrawTextureQuad(*this , tiling, offset, quad, this->_color);
}

void ray::Texture::DrawTiled(Rectangle source, Rectangle dest, ray::Vector2 origin)
{
    DrawTextureTiled(*this , source, dest, origin, this->_rotation, this->_scale, this->_color);
}

void ray::Texture::DrawNPatch(NPatchInfo nPatchInfo, Rectangle dest, ray::Vector2 origin)
{
    DrawTextureNPatch(*this , nPatchInfo, dest, origin, this->_rotation, this->_color);
}

void ray::Texture::DrawPoly(ray::Vector2 center, ray::Vector2 *points, ray::Vector2 *texcoords, int pointsCount)
{
    DrawTexturePoly(*this , center, points, texcoords, pointsCount, this->_color);
}

Texture2D ray::Texture::getTexture() const
{
    return *this ;
}

float ray::Texture::GetScale() const
{
    return this->_scale;
}

void ray::Texture::SetScale(float scale)
{
    this->_scale = scale;
}

float ray::Texture::GetRotation() const
{
    return this->_rotation;
}

void ray::Texture::SetRotation(float rotation)
{
    this->_rotation = rotation;
}

ray::Color ray::Texture::getColor() const
{
    return this->_color;
}

void ray::Texture::setColor(Color color)
{
    this->_color = color;
}

ray::Vector2 ray::Texture::GetOrigin() const
{
    return this->_origin;
}

void ray::Texture::SetOrigin(ray::Vector2 origin)
{
    this->_origin = origin;
}
