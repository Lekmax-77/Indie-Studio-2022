/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-zacharie.lawson
** File description:
** Triangle
*/

#ifndef TRIANGLE_HPP_
#define TRIANGLE_HPP_

#include <raylib.h>
#include "IDrawable.hpp"
//#include <raygui.h>

namespace ray {
    namespace _3D {
        namespace shape {
            class Triangle : public IDrawable {
                public:
                    /***
                     * @brief Construct a new Triangle object
                     * @param pos1 the position of the first point of the triangle
                     * @param pos2 the position of the second point of the triangle
                     * @param pos3 the position of the third point of the triangle
                     * @param color the color of the triangle, default is black
                     */
                    Triangle(Vector3 v1, Vector3 v2, Vector3 v3, Color color = BLACK);
                    /***
                     * @brief Construct a new Triangle object from another Triangle
                     * @param src the Triangle to copy
                     */
                    Triangle(const Triangle &src);
                    /***
                     * @brief Destroy the Triangle object
                     */
                    ~Triangle();
                    /***
                     * @brief Copy the Triangle object
                     * @param src the Triangle to copy
                     * @return the copied Triangle
                     */
                    Triangle &operator=(const Triangle &src);

                    // getter
                    /***
                     * @brief return the position of the first point of the triangle
                     * @return the position of the first point of the triangle
                     */
                    Vector3 getFirstPos();
                    /***
                     * @brief return the position of the second point of the triangle
                     * @return the position of the second point of the triangle
                     */
                    Vector3 getSecondPos();
                    /***
                     * @brief return the position of the third point of the triangle
                     * @return the position of the third point of the triangle
                     */
                    Vector3 getThirdPos();
                    /***
                     * @brief return the color of the triangle
                     * @return the color of the triangle
                     */
                    Color getColor();

                    // setter
                    /***
                     * @brief set the position of the first point of the triangle
                     * @param pos the position of the first point of the triangle
                     */
                    void setFirstPos(Vector3 pos);
                    /***
                     * @brief set the position of the second point of the triangle
                     * @param pos the position of the second point of the triangle
                     */
                    void setSecondPos(Vector3 pos);
                    /***
                     * @brief set the position of the third point of the triangle
                     * @param pos the position of the third point of the triangle
                     */
                    void setThirdPos(Vector3 pos);
                    /***
                     * @brief set the color of the triangle
                     * @param color the color of the triangle
                     */
                    void setColor(Color color);

                    // methods
                    /***
                     * @brief draw the triangle
                     */
                    void draw() const;

                private:
                    Vector3 _fstPos;
                    Vector3 _sndPos;
                    Vector3 _trdPos;
                    Color _color;
            }; // class Triangle
        }; // namespace shape
    }; // namespace _3D
}; // namespace ray

#endif /* !TRIANGLE_HPP_ */
