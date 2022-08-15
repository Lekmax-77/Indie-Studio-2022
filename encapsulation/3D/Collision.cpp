/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-zacharie.lawson
** File description:
** Collision
*/

#include "Collision.hpp"

ray::_3D::Collision::Collision()
{
}

ray::_3D::Collision::~Collision()
{
}

bool ray::_3D::Collision::isCollision(BoundingBox box1, BoundingBox box2)
{
    return CheckCollisionBoxes(box1, box2);
}

bool ray::_3D::Collision::isCollision(BoundingBox box, Vector3 center, float radius)
{
    return CheckCollisionBoxSphere(box, center, radius);
}

bool ray::_3D::Collision::isCollision(Vector3 center1, float radius1, Vector3 center2, float radius2)
{
    return CheckCollisionSpheres(center1, radius1, center2, radius2);
}