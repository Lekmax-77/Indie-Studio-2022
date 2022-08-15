/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-zacharie.lawson
** File description:
** Triangle
*/

#ifndef TRIANGLE_HPP_
#define TRIANGLE_HPP_

namespace ray
{
    namespace _2D
    {
        class Triangle;
    };
};

#include "raylib.h"

namespace ray
{
    namespace _2D
    {
        class Triangle
        {
        public:
            // Constructors

            /**
             * @brief Construct a new Triangle object
             *
             * @param x1 : coordinate x of the first point
             * @param y1 : coordinate y of the first point
             * @param x2 : coordinate x of the second point
             * @param y2 : coordinate y of the second point
             * @param x3 : coordinate x of the third point
             * @param y3 : coordinate y of the third point
             * @param color : color of the figure (optional)
             */
            Triangle(float x1, float y1, float x2, float y2, float x3, float y3, Color color = BLACK) : _a({x1, y1}), _b({x2, y2}), _c({x3, y3}), _color(color){};

            /**
             * @brief Construct a new Triangle object
             *
             * @param a : coordinate of the first point
             * @param b : coordinate of the second point
             * @param c : coordinate of the third point
             * @param color : color of the figure (optional)
             */
            Triangle(Vector2 a, Vector2 b, Vector2 c, Color color = BLACK) : _a(a), _b(b), _c(c), _color(color){};

            // Destructor

            /**
             * @brief Destroy the Triangle object
             *
             */
            ~Triangle();

            // Getters
            /**
             * @brief Get the pos of the point A of the triangle
             *
             * @return Vector2
             */
            Vector2 getPosA() const { return _a; };

            /**
             * @brief Get the pos of the point B of the triangle
             *
             * @return Vector2
             */
            Vector2 getPosB() const { return _b; };

            /**
             * @brief Get the pos of the point C of the triangle
             *
             * @return Vector2
             */
            Vector2 getPosC() const { return _c; };

            /**
             * @brief Get the pos of the point A of the triangle
             *
             * @return Vector2
             */
            Color getColor() const { return _color; };

            // Setters

            /**
             * @brief Set the pos of the point A of the triangle
             *
             * @param a
             */
            void setPosA(Vector2 a) { _a = a; };
            /**
             * @brief Set the pos of the point B of the triangle
             *
             * @param b
             */
            void setPosB(Vector2 b) { _b = b; };
            /**
             * @brief Set the pos of the point C of the triangle
             *
             * @param c
             */
            void setPosC(Vector2 c) { _c = c; };
            /**
             * @brief Set the pos of the point Color of the triangle
             *
             * @param color
             */
            void setColor(Color color) { _color = color; };

            // Methods

            /**
             * @brief Draw the triangle
             * 
             */
            void Draw()
            {
                DrawTriangle(_a, _b, _c, _color);
            };

            /**
             * @brief draw a triangle
             * 
             * @param filled : if you want to fill or not the triangle
             */
            void Draw(bool filled)
            {
                if (filled)
                    DrawTriangle(_a, _b, _c, _color);
                else
                    DrawTriangleLines(_a, _b, _c, _color);
            };

        protected:
        private:
            Vector2 _a;
            Vector2 _b;
            Vector2 _c;
            Color _color;
        };

    };
};

#endif /* !TRIANGLE_HPP_ */
