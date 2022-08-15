/*
** EPITECH PROJECT, 2022
** indiestudio
** File description:
** Collision
*/

#include "Collision.hpp"

/**
 * @brief return true if the rectangles collide else false
 *
 * @param rec1
 * @param rec2
 * @return true
 * @return false
 */
bool ray::_2D::Collision::isCollision(Rectangles rec1, Rectangles rec2)
{
    return CheckCollisionRecs(rec1.getRectangle(), rec2.getRectangle());
}

/**
 * @brief return true if the rectangle and the circle collide else false
 *
 * @param rec
 * @param circle
 * @return true
 * @return false
 */
bool ray::_2D::Collision::isCollision(Rectangles rec, Circle circle)
{
    return CheckCollisionCircleRec(circle.getCenter(), circle.getRadius(), rec.getRectangle());
}

/**
 * @brief
 *
 * @param circle
 * @param rec
 * @return true
 * @return false
 */
bool ray::_2D::Collision::isCollision(Circle circle, Rectangles rec)
{
    return CheckCollisionCircleRec(circle.getCenter(), circle.getRadius(), rec.getRectangle());
}

/**
 * @brief return true if the circles collide else false
 *
 * @param circle1
 * @param circle2
 * @return true
 * @return false
 */
bool ray::_2D::Collision::isCollision(Circle circle1, Circle circle2)
{
    return CheckCollisionCircles(circle1.getCenter(), circle1.getRadius(), circle2.getCenter(), circle2.getRadius());
}

/**
 * @brief return true if the pixel and the rectangle collide else false
 *
 * @param pixel
 * @param rec
 * @return true
 * @return false
 */
bool ray::_2D::Collision::isCollision(Pixel pixel, Rectangles rec)
{
    return CheckCollisionPointRec(pixel.getPos(), rec.getRectangle());
}

/**
 * @brief return true if the pixel and the rectangle collide else false
 *
 * @param rec
 * @param pixel
 * @return true
 * @return false
 */
bool ray::_2D::Collision::isCollision(Rectangles rec, Pixel pixel)
{
    return CheckCollisionPointRec(pixel.getPos(), rec.getRectangle());
}

/**
 * @brief return true if the pixel and the circle collide else false
 *
 * @param pixel
 * @param circle
 * @return true
 * @return false
 */
bool ray::_2D::Collision::isCollision(Pixel pixel, Circle circle)
{
    return CheckCollisionPointCircle(pixel.getPos(), circle.getCenter(), circle.getRadius());
}

/**
 * @brief return true if the pixel and the circle collide else false
 *
 * @param circle
 * @param pixel
 * @return true
 * @return false
 */
bool ray::_2D::Collision::isCollision(Circle circle, Pixel pixel)
{
    return CheckCollisionPointCircle(pixel.getPos(), circle.getCenter(), circle.getRadius());
}

/**
 * @brief return true if the pixel and the triangle collide else false
 *
 * @param pixel
 * @param triangle
 * @return true
 * @return false
 */
bool ray::_2D::Collision::isCollision(Pixel pixel, Triangle triangle)
{
    return CheckCollisionPointTriangle(pixel.getPos(), triangle.getPosA(), triangle.getPosB(), triangle.getPosC());
}

/**
 * @brief return true if the pixel and the triangle collide else false
 *
 * @param triangle
 * @param pixel
 * @return true
 * @return false
 */
bool ray::_2D::Collision::isCollision(Triangle triangle, Pixel pixel)
{
    return CheckCollisionPointTriangle(pixel.getPos(), triangle.getPosA(), triangle.getPosB(), triangle.getPosC());
}

/**
 * @brief Check the collision between two lines defined by two points each, returns collision point by reference
 *
 * @param line1
 * @param line2
 * @param collisionPoint
 * @return true
 * @return false
 */
bool ray::_2D::Collision::isCollision(Line line1, Line line2, std::vector<Vector2> collisionPoint)
{
    return CheckCollisionLines(line1.getPos1(), line1.getPos2(), line2.getPos1(), line2.getPos2(), &collisionPoint[0]);
}

/**
 * @brief Check if point belongs to line created between two points [p1] and [p2]
 *
 * @param pixel
 * @param line
 * @param threshold
 * @return true
 * @return false
 */
bool ray::_2D::Collision::isCollision(Pixel pixel, Line line, int threshold)
{
    return CheckCollisionPointLine(pixel.getPos(), line.getPos1(), line.getPos2(), threshold);
}

/**
 * @brief Check if point belongs to line created between two points [p1] and [p2]
 *
 * @param line
 * @param pixel
 * @param threshold
 * @return true
 * @return false
 */
bool ray::_2D::Collision::isCollision(Line line, Pixel pixel, int threshold)
{
    return CheckCollisionPointLine(pixel.getPos(), line.getPos1(), line.getPos2(), threshold);
}

/**
 * @brief Get collision rectangle for two rectangles collision
 *
 * @param rec1
 * @param rec2
 * @return Rectangles
 */
 ray::_2D::Rectangles ray::_2D::Collision::GetCollisionRec(Rectangles rec1, Rectangles rec2)
{
    Rectangle newrec1 = rec1.getRectangle();
    Rectangle newrec2 = rec2.getRectangle();
    Rectangle recNew = ::GetCollisionRec(newrec1, newrec2);
    Rectangles result2(recNew.x, recNew.y, recNew.width, recNew.height);
    return result2;
}