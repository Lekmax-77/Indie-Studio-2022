/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-zacharie.lawson
** File description:
** Circle
*/

#ifndef CIRCLE_HPP_
#define CIRCLE_HPP_

#include <raylib.h>
#include "IDrawable.hpp"

namespace ray {
    namespace _3D {
        namespace shape {
            class Circle : public IDrawable {
                public:
                    /***
                     * @brief Construct a new Circle object
                     * @param pos the position of the circle
                     * @param radius the radius of the circle
                     * @param color the color of the circle, default is black
                     * @param rotation the rotation of the circle, default is vector zero
                     * @param rotationAngle the rotation angle of the circle, default is zero
                     */
                    Circle(Vector3 center, float radius, Color color = BLACK, Vector3 rotation = {0,0,0}, float rotationAngle = 0);
                    /***
                     * @brief Construct a new Circle object from another Circle
                     * @param src the Circle to copy
                     */
                    Circle(const Circle &src);
                    /***
                     * @brief Destroy the Circle object
                     */
                    ~Circle();
                    /***
                     * @brief Copy the Circle object
                     * @param src the Circle to copy
                     * @return the copied Circle
                     */
                    Circle &operator=(const Circle &src);

                    // getter
                    /***
                     * @brief return the center of the circle
                     * @return the center of the circle
                     */
                    Vector3 getCenter() const;
                    /***
                     * @brief return the radius of the circle
                     * @return the radius of the circle
                     */
                    float getRadius() const;
                    /***
                     * @brief return the rotation of the circle
                     * @return the rotation of the circle
                     */
                    Vector3 getRotation() const;
                    /***
                     * @brief return the rotation angle of the circle
                     * @return the rotation angle of the circle
                     */
                    float getRotationAngle() const;
                    /***
                     * @brief return the color of the circle
                     * @return the color of the circle
                     */
                    Color getColor() const;

                    // setter
                    /***
                     * @brief set the center of the circle
                     * @param center the center of the circle
                     */
                    void setCenter(Vector3 center);
                    /***
                     * @brief set the radius of the circle
                     * @param radius the radius of the circle
                     */
                    void setRadius(float radius);
                    /***
                     * @brief set the rotation of the circle
                     * @param rotation the rotation of the circle
                     */
                    void setRotation(Vector3 rotation);
                    /***
                     * @brief set the rotation angle of the circle
                     * @param rotationAngle the rotation angle of the circle
                     */
                    void setRotationAngle(float rotationAngle);
                    /***
                     * @brief set the color of the circle
                     * @param color the color of the circle
                     */
                    void setColor(Color color);

                    // methods
                    /***
                     * @brief draw the circle
                     */
                    void draw() const;

                private:
                    Vector3 _center;
                    float _radius;
                    Vector3 _rotation;
                    float _rotationAngle;
                    Color _color;
            }; // class Circle
        }; // namespace shape
    }; // namespace _3D
}; // namespace ray

#endif /* !CIRCLE_HPP_ */
