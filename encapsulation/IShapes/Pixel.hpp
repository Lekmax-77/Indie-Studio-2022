/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-zacharie.lawson
** File description:
** Pixel
*/

#ifndef PIXEL_HPP_
#define PIXEL_HPP_

namespace ray { namespace _2D { class Pixel; } }

#include <vector>
#include "raylib.h"

namespace ray
{
    namespace _2D
    {
        class Pixel
        {
        public:
            // Constructors

            /**
             * @brief Construct a new Pixel object
             * 
             * @param x : x position
             * @param y : y position
             * @param color : color (optional)
             */
            Pixel(float x, float y, Color color = BLACK) : _pos({x, y}), _color(color){};

            /**
             * @brief Construct a new Pixel object
             * 
             * @param vector : position
             * @param color : color (optional)
             */
            Pixel(Vector2 pos, Color color = BLACK) : _pos(pos), _color(color){};

            // Destructor

            /**
             * @brief Destroy the Pixel object
             */
            ~Pixel();

            // Getters
            Vector2 getPos() const { return _pos; };
            Color getColor() const { return _color; };

            // Setters
            void setPos(Vector2 pos) { _pos = pos; };
            void setColor(Color color) { _color = color; };

            // Methods
            /**
             * @brief Draw a pixel
             */
            void Draw() {
                DrawPixel(_pos.x, _pos.y, _color);
            }

        protected:
        private:
            Vector2 _pos;
            Color _color;
        };

        void DrawLineStrip(std::vector<Vector2> &points, Color color = BLACK)
        {
            DrawLineStrip(&points[0], points.size(), color);
        }
    };
};

#endif /* !PIXEL_HPP_ */
