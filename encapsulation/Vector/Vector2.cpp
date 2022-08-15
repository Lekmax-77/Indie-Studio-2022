/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-zacharie.lawson
** File description:
** Vector2
*/

#include "Vector2.hpp"

ray::Vector2::Vector2()
    : ::Vector2{0, 0}
{
}

ray::Vector2::Vector2(float x, float y)
    : ::Vector2{x, y}
{
}

ray::Vector2::Vector2(const Vector2 &src)
    : ::Vector2{src}
{
}

ray::Vector2::~Vector2()
{
}

ray::Vector2 &ray::Vector2::operator=(const ray::Vector2 &src)
{
    x = src.x;
    y = src.y;
    return *this;
}

ray::Vector2 ray::Vector2::operator+(const Vector2 &other) const
{
    return {x + other.x, y + other.y};
}

ray::Vector2 ray::Vector2::operator-(const Vector2 &other) const
{
    return {x - other.x, y - other.y};
}

ray::Vector2 ray::Vector2::operator*(float product) const
{
    return {x * product, y * product};
}

ray::Vector2 ray::Vector2::operator/(float quotient) const
{
    return {x / quotient, y / quotient};
}

ray::Vector2 &ray::Vector2::operator+=(const Vector2 &other)
{
    *this = *this + other;
    return *this;
}

ray::Vector2 &ray::Vector2::operator-=(const Vector2 &other)
{
    *this = *this - other;
    return *this;
}

ray::Vector2 &ray::Vector2::operator*=(float product)
{
    *this = *this * product;
    return *this;
}

ray::Vector2 &ray::Vector2::operator/=(float quotient)
{
    *this = *this / quotient;
    return *this;
}

bool ray::Vector2::operator==(const Vector2 &other) const
{
    return x == other.x && y == other.y;
}

bool ray::Vector2::operator!=(const Vector2 &other) const
{
    return !(*this == other);
}