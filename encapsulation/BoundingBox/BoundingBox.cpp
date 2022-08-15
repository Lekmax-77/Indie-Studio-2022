/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-zacharie.lawson
** File description:
** BoundingBox
*/

#include "BoundingBox.hpp"

ray::BoundingBox::BoundingBox()
    : ::BoundingBox{}
{
}

ray::BoundingBox::BoundingBox(Vector3 min, Vector3 max)
    : ::BoundingBox{min, max}
{
}


ray::BoundingBox::~BoundingBox()
{
}

ray::BoundingBox::BoundingBox(const ::BoundingBox &src)
    : ::BoundingBox{src}
{
}

ray::BoundingBox &ray::BoundingBox::operator=(const BoundingBox &src)
{
    this->min = src.min;
    this->max = src.max;
    return *this;
}