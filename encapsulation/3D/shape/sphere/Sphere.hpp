/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-zacharie.lawson
** File description:
** Sphere
*/

#ifndef SPHERE_HPP_
#define SPHERE_HPP_

#include <raylib.h>
#include "IDrawable.hpp"

namespace ray {
    namespace _3D {
        namespace shape {
            class Sphere : public IDrawable {
            public:
                /***
                 * @brief Construct a new Sphere object
                 * @param pos the position of the sphere
                 * @param radius the radius of the sphere
                 * @param color the color of the sphere, default is black
                 */
                Sphere(Vector3 pos, float radius, Color color = BLACK);
                /***
                 * @brief Construct a new Sphere object from another Sphere
                 * @param src the Sphere to copy
                 */
                Sphere(const Sphere &src);
                /***
                 * @brief Destroy the Sphere object
                 */
                ~Sphere();
                /***
                 * @brief Copy the Sphere object
                 * @param src the Sphere to copy
                 * @return the copied Sphere
                 */
                Sphere &operator=(const Sphere &src);

                // getters
                /***
                 * @brief return the position of the sphere
                 * @return the position of the sphere
                 */
                Vector3 getPosition() const;
                /***
                 * @brief return the radius of the sphere
                 * @return the radius of the sphere
                 */
                float getRadius() const;
                /***
                 * @brief return the rotation of the sphere
                 * @return the rotation of the sphere
                 */
                Color getColor() const;

                // setters
                /***
                 * @brief set the position of the sphere
                 * @param pos the new position of the sphere
                 */
                void setPosition(Vector3 pos);
                /***
                 * @brief set the radius of the sphere
                 * @param radius the new radius of the sphere
                 */
                void setRadius(float radius);
                /***
                 * @brief set the color of the sphere
                 * @param color the new color of the sphere
                 */
                void setColor(Color color);

                // methods
                /***
                 * @brief draw the sphere
                 */
                void draw() const;
            private:
                Vector3 _pos;
                float _radius;
                Color _color;
            };
        }
    }
}

#endif /* !SPHERE_HPP_ */
