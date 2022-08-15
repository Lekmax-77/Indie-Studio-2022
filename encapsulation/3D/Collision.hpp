/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-zacharie.lawson
** File description:
** Collision
*/

#ifndef COLLISION_HPP_
#define COLLISION_HPP_

#include <raylib.h>
#include "BoundingBox/BoundingBox.hpp"

namespace ray {
    namespace _3D {
        class Collision {
        public:
            Collision();
            ~Collision();
            static bool isCollision(BoundingBox box1, BoundingBox box2);
            static bool isCollision(BoundingBox box, Vector3 center, float radius);
            static bool isCollision(Vector3 center1, float radius1, Vector3 center2, float radius2);
        }; // class Collision
    }; // namespace _3D
}; // namespace ray

#endif /* !COLLISION_HPP_ */
