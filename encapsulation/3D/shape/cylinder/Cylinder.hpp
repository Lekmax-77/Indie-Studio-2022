/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-zacharie.lawson
** File description:
** Cylinder
*/

#ifndef CYLINDER_HPP_
#define CYLINDER_HPP_

#include <raylib.h>
#include "IDrawable.hpp"

namespace ray {
    namespace _3D {
        namespace shape {
            class Cylinder : public IDrawable {
            public:
                /***
                 * @brief Construct a new Cylinder object
                 * @param pos the position of the cylinder
                 * @param radius the radius of the cylinder
                 * @param height the height of the cylinder
                 * @param color the color of the cylinder, default is black
                 */
                Cylinder(Vector3 pos, float height, float radiusBottom, float radiusTop, Color color = BLACK);
                /***
                 * @brief Construct a new Cylinder object from another Cylinder
                 * @param src the Cylinder to copy
                 */
                Cylinder(const Cylinder &src);
                /***
                 * @brief Destroy the Cylinder object
                 */
                ~Cylinder();
                /***
                 * @brief Copy the Cylinder object
                 * @param src the Cylinder to copy
                 * @return the copied Cylinder
                 */
                Cylinder &operator=(const Cylinder &src);

                // getters
                /***
                 * @brief return the position of the cylinder
                 * @return the position of the cylinder
                 */
                Vector3 getPosition() const;
                /***
                 * @brief return the height of the cylinder
                 * @return the height of the cylinder
                 */
                float getHeight() const;
                /***
                 * @brief return the radius of the bottom of the cylinder
                 * @return the radius of the bottom of the cylinder
                 */
                float getRadiusBottom() const;
                /***
                 * @brief return the radius of the top of the cylinder
                 * @return the radius of the top of the cylinder
                 */
                float getRadiusTop() const;
                /***
                 * @brief return the color of the cylinder
                 * @return the color of the cylinder
                 */
                Color getColor() const;

                // setters
                /***
                 * @brief set the position of the cylinder
                 * @param pos the position of the cylinder
                 */
                void setPosition(Vector3 pos);
                /***
                 * @brief set the height of the cylinder
                 * @param height the height of the cylinder
                 */
                void setHeight(float height);
                /***
                 * @brief set the radius of the bottom of the cylinder
                 * @param radiusBottom the radius of the bottom of the cylinder
                 */
                void setRadiusBottom(float radiusBottom);
                /***
                 * @brief set the radius of the top of the cylinder
                 * @param radiusTop the radius of the top of the cylinder
                 */
                void setRadiusTop(float radiusTop);
                /***
                 * @brief set the color of the cylinder
                 * @param color the color of the cylinder
                 */
                void setColor(Color color);

                // methods
                /***
                 * @brief draw the cylinder
                 */
                void draw() const;
            private:
                Vector3 _pos;
                float _height;
                float _radiusBottom;
                float _radiusTop;
                Color _color;
            };
        }
    }
}

#endif /* !CYLINDER_HPP_ */
