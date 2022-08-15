/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-zacharie.lawson
** File description:
** Line
*/

#ifndef LINE_HPP_
#define LINE_HPP_


#include <raylib.h>
#include "IDrawable.hpp"

namespace ray {
    namespace _3D {
        namespace shape {
            class Line : public IDrawable {
                public:
                    /***
                     * @brief Construct a new Line object
                     * @param pos1 the position of the first point of the line
                     * @param pos2 the position of the second point of the line
                     * @param color the color of the line, default is black
                     */
                    Line(Vector3 start, Vector3 end, Color color = BLACK);
                    /***
                     * @brief Construct a new Line object from another Line
                     * @param src the Line to copy
                     */
                    Line(const Line &src);
                    /***
                     * @brief Destroy the Line object
                     */
                    ~Line();
                    /***
                     * @brief Copy the Line object
                     * @param src the Line to copy
                     * @return the copied Line
                     */
                    Line &operator=(const Line &src);

                    // getter
                    /***
                     * @brief return the position of the first point of the line
                     * @return the position of the first point of the line
                     */
                    Vector3 getStartPosition() const;
                    /***
                     * @brief return the position of the second point of the line
                     * @return the position of the second point of the line
                     */
                    Vector3 getEndPosition() const;
                    /***
                     * @brief return the color of the line
                     * @return the color of the line
                     */
                    Color getColor() const;

                    // setter
                    /***
                     * @brief set the position of the first point of the line
                     * @param pos the position of the first point of the line
                     */
                    void setStartPosition(Vector3 start);
                    /***
                     * @brief set the position of the second point of the line
                     * @param pos the position of the second point of the line
                     */
                    void setEndPosition(Vector3 end);
                    /***
                     * @brief set the color of the line
                     * @param color the color of the line
                     */
                    void setColor(Color color);

                    // methods
                    /***
                     * @brief draw the line
                     */
                    void draw() const;

                private:
                    Vector3 _start;
                    Vector3 _end;
                    Color _color;
            }; // class Line
        }; // namespace shape
    }; // namespace _3D
}; // namespace ray

#endif /* !LINE_HPP_ */
