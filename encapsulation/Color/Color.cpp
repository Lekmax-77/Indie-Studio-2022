/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-zacharie.lawson
** File description:
** Color
*/

#include "Color.hpp"

ray::Color::Color()
    : ::Color{0, 0, 0, 255}
{
}

ray::Color::Color(unsigned char red, unsigned char green, unsigned char blue, unsigned char alpha)
    : ::Color{red, green, blue, alpha}
{
}

ray::Color::Color(unsigned int hexValue)
    : ::Color{::GetColor(hexValue)}
{
}

ray::Color::Color(const ray::Color &src)
    : ::Color{src}
{
}

ray::Color::Color(const ::Color &src)
    : ::Color{src}
{
}

ray::Color::~Color()
{
}

ray::Color &ray::Color::operator=(const ray::Color &src)
{
    r = src.r;
    g = src.g;
    b = src.b;
    a = src.a;
    return *this;
}