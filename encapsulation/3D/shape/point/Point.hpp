/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-zacharie.lawson
** File description:
** Point
*/

#ifndef POINT_HPP_
#define POINT_HPP_

#include <raylib.h>
#include "IDrawable.hpp"

namespace ray {
    namespace _3D {
        namespace shape {
            class Point : public IDrawable {
                public:
                    /***
                     * @brief Construct a new Point object
                     * @param pos the position of the point
                     * @param color the color of the point, default is black
                     */
                    Point(Vector3 pos, Color color = BLACK);
                    /***
                     * @brief Construct a new Point object from another Point
                     * @param src the Point to copy
                     */
                    Point(const Point &src);
                    /***
                     * @brief Destroy the Point object
                     */
                    ~Point();
                    /***
                     * @brief Copy the Point object
                     * @param src the Point to copy
                     * @return the copied Point
                     */
                    Point &operator=(const Point &src);

                    // getter
                    /***
                     * @brief return the position of the point
                     * @return the position of the point
                     */
                    Vector3 getPos() const;
                    /***
                     * @brief return the color of the point
                     * @return the color of the point
                     */
                    Color getColor() const;

                    // setter
                    /***
                     * @brief set the position of the point
                     * @param pos the new position of the point
                     */
                    void setPosition(Vector3 pos);
                    /***
                     * @brief set the color of the point
                     * @param color the new color of the point
                     */
                    void setColor(Color color);

                    // methods
                    /***
                     * @brief draw the point
                     */
                    void draw() const;

                private:
                    Vector3 _pos;
                    Color _color;
            }; // class Point
        }; // namespace shape
    }; // namespace _3D
}; // namespace ray

#endif /* !POINT_HPP_ */
