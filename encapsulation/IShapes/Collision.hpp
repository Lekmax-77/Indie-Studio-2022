/*
** EPITECH PROJECT, 2022
** indiestudio
** File description:
** Collision
*/

#ifndef COLLISION_HPP_
#define COLLISION_HPP_

#include "raylib.h"
#include "Pixel.hpp"
#include "Line.hpp"
#include "Circle.hpp"
#include "Rectangle.hpp"
#include "Triangle.hpp"
#include "Polygons.hpp"

namespace ray
{
    namespace _2D
    {
        class Collision
        {
        public:
            static bool isCollision(Rectangles rec1, Rectangles rec2);
            static bool isCollision(Rectangles rec, Circle circle);
            static bool isCollision(Circle circle, Rectangles rec);
            static bool isCollision(Circle circle1, Circle circle2);
            static bool isCollision(Pixel pixel, Rectangles rec);
            static bool isCollision(Rectangles rec, Pixel pixel);
            static bool isCollision(Pixel pixel, Circle circle);
            static bool isCollision(Circle circle, Pixel pixel);
            static bool isCollision(Pixel pixel, Triangle triangle);
            static bool isCollision(Triangle triangle, Pixel pixel);
            static bool isCollision(Line line1, Line line2, std::vector<Vector2> collisionPoint);
            static bool isCollision(Pixel pixel, Line line, int threshold);
            static bool isCollision(Line line, Pixel pixel, int threshold);
            static Rectangles GetCollisionRec(Rectangles rec1, Rectangles rec2);
        };
    };
};

#endif /* !COLLISION_HPP_ */
