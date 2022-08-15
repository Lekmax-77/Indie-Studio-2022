/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-zacharie.lawson
** File description:
** Vector3
*/

#include "Vector3.hpp"

ray::Vector3::Vector3()
    : ::Vector3{0, 0, 0}
{
}

ray::Vector3::Vector3(float x, float y, float z)
    : ::Vector3{x, y, z}
{
}

ray::Vector3::Vector3(const Vector3 &src)
    : ::Vector3{src}
{
}

ray::Vector3::~Vector3()
{
}

ray::Vector3 &ray::Vector3::operator=(const ray::Vector3 &src)
{
    x = src.x;
    y = src.y;
    z = src.z;
    return *this;
}

ray::Vector3 ray::Vector3::operator+(const Vector3 &other) const
{
    return {x + other.x, y + other.y, z + other.z};
}

ray::Vector3 ray::Vector3::operator-(const Vector3 &other) const
{
    return {x - other.x, y - other.y, z - other.z};
}

ray::Vector3 ray::Vector3::operator*(float product) const
{
    return {x * product, y * product, z * product};
}

ray::Vector3 ray::Vector3::operator/(float quotient) const
{
    return {x / quotient, y / quotient, z / quotient};
}

ray::Vector3 &ray::Vector3::operator+=(const Vector3 &other)
{
    *this = *this + other;
    return *this;
}

ray::Vector3 &ray::Vector3::operator-=(const Vector3 &other)
{
    *this = *this - other;
    return *this;
}

ray::Vector3 &ray::Vector3::operator*=(float product)
{
    *this = *this * product;
    return *this;
}

ray::Vector3 &ray::Vector3::operator/=(float quotient)
{
    *this = *this / quotient;
    return *this;
}

bool ray::Vector3::operator==(const Vector3 &other) const
{
    return x == other.x && y == other.y && z == other.z;
}

bool ray::Vector3::operator!=(const Vector3 &other) const
{
    return !(*this == other);
}