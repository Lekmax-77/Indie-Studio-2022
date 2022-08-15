/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-zacharie.lawson
** File description:
** Vector4
*/

#include "Vector4.hpp"

ray::Vector4::Vector4()
    : ::Vector4{0, 0, 0, 0}
{
}

ray::Vector4::Vector4(float x, float y, float z, float w)
    : ::Vector4{x, y, z, w}
{
}

ray::Vector4::Vector4(const Vector4 &other)
    : ::Vector4{other.x, other.y, other.z, other.w}
{
}

ray::Vector4::~Vector4()
{
}

ray::Vector4 &ray::Vector4::operator=(const Vector4 &src)
{
    x = src.x;
    y = src.y;
    z = src.z;
    w = src.w;
    return *this;
}

ray::Vector4 ray::Vector4::operator+(const Vector4 &other) const
{
    return {x + other.x, y + other.y, z + other.z, w + other.w};
}


ray::Vector4 ray::Vector4::operator-(const Vector4 &other) const
{
    return {x - other.x, y - other.y, z - other.z, w - other.w};
}

ray::Vector4 ray::Vector4::operator*(float product) const
{
    return {x * product, y * product, z * product, w * product};
}

ray::Vector4 ray::Vector4::operator/(float quotient) const
{
    return {x / quotient, y / quotient, z / quotient, w / quotient};
}

ray::Vector4 &ray::Vector4::operator+=(const Vector4 &other)
{
    *this = *this + other;
    return *this;
}

ray::Vector4 &ray::Vector4::operator-=(const Vector4 &other)
{
    *this = *this - other;
    return *this;
}

ray::Vector4 &ray::Vector4::operator*=(float product)
{
    *this = *this * product;
    return *this;
}

ray::Vector4 &ray::Vector4::operator/=(float quotient)
{
    *this = *this / quotient;
    return *this;
}

bool ray::Vector4::operator==(const Vector4 &other) const
{
    return (x == other.x && y == other.y && z == other.z && w == other.w);
}

bool ray::Vector4::operator!=(const Vector4 &other) const
{
    return !(*this == other);
}