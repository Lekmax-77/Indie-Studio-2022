/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-zacharie.lawson
** File description:
** Rectangle
*/

#ifndef RECTANGLE_HPP_
#define RECTANGLE_HPP_

namespace ray
{
    namespace _2D
    {
        class Rectangles;
    }
}

#include "raylib.h"

namespace ray
{
    namespace _2D
    {
        class Rectangles : public Rectangle
        {
        public:
            Rectangles() {};
            // Constructors
            
            /**
             * @brief Construct a new Rectangles object
             *
             * @param x1 : position x of the top left angle
             * @param y1 : position y of the top left angle
             * @param width : width of the rectangle
             * @param height : height of the rectangle
             * @param color : color of the rectangle (optional)
             */
            Rectangles(float x1, float y1, float width, float height, Color color = BLACK) : _pos({x1, y1}), _size({width, height}), _color(color){};

            /**
             * @brief Construct a new Rectangles object
             *
             * @param point : position of the top left angle (x,y)
             * @param size : size of the rectangle (width, height)
             * @param color : color of the rectangle (optional)
             */
            Rectangles(Vector2 point, Vector2 size, Color color = BLACK) : _pos(point), _size(size), _color(color){};

            // Destructor

            /**
             * @brief Destroy the Rectangles object
             *
             */
            ~Rectangles() {};
            
            // Getters

            /**
             * @brief Get the position of the top left angle of the rectangle object (x, y)
             *
             * @return Vector2
             */
            Vector2 getPos() const { return _pos; };

            /**
             * @brief Get the size of the rectangle object (width, height)
             *
             * @return Vector2
             */
            Vector2 getSize() const { return _size; };

            /**
             * @brief Get the Color of the rectangle object
             *
             * @return Color
             */
            Color getColor() const { return _color; };

            /**
             * @brief Get the Rectangle structure of the rectangle object
             *
             * @return Rectangle
             */
            Rectangle getRectangle() const { return {_pos.x, _pos.y, _size.x, _size.y}; };

            // Setters

            /**
             * @brief Set the Position of the top left angle of the rectangle (x,y)
             *
             * @param x1
             */
            void setPos(Vector2 x1) { _pos = x1; };

            /**
             * @brief Set the size of the rectangle (width, height)
             *
             * @param x1
             */
            void setSize(Vector2 x2) { _size = x2; };

            /**
             * @brief Set the Color of the rectangle
             *
             * @param color
             */
            void setColor(Color color) { _color = color; };

            /**
             * @brief Set the Rectangle from rectangle struct
             *
             * @param rect
             */
            void setRectangle(Rectangle rect)
            {
                _pos.x = rect.x;
                _pos.y = rect.y;
                _size.x = rect.width;
                _size.y = rect.height;
            };

            // Methods

            /**
             * @brief draw a rectangle
             *
             */
            void Draw()
            {
                DrawRectangleV(_pos, _size, _color);
            };

            /**
             * @brief draw the rectangle filled or not
             *
             * @param filled
             */
            void Draw(bool filled)
            {
                if (filled)
                    DrawRectangleV(_pos, _size, _color);
                else
                    DrawRectangleLines(_pos.x, _pos.y, _size.x, _size.y, _color);
            };

            /**
             * @brief Draw a color-filled rectangle with pro parameters
             *
             * @param origin
             * @param rotation
             */
            void Draw(Vector2 origin, float rotation)
            {
                DrawRectanglePro(getRectangle(), origin, rotation, _color);
            };

            /**
             * @brief draw a gradient rectangle vertically or horizontally
             *
             * @param color2
             * @param vertical
             */
            void Draw(Color color2, bool vertical = true)
            {
                if (vertical)
                    DrawRectangleGradientV(_pos.x, _pos.y, _size.x, _size.y, _color, color2);
                else
                    DrawRectangleGradientV(_pos.x, _pos.y, _size.x, _size.y, _color, color2);
            };

            /**
             * @brief draw a rectangle with rounded edges
             *
             * @param roundness
             * @param segments
             */
            void Draw(float roundness, int segments)
            {
                DrawRectangleRounded(getRectangle(), roundness, segments, _color);
            };

            /**
             * @brief Get the Collision of two rectangle
             *
             * @param rec2
             * @return Rectangles
             */
            Rectangles GetCollision(Rectangles rec2)
            {
                Rectangle recNew = GetCollisionRec(getRectangle(), rec2.getRectangle());
                Rectangles result2(recNew.x, recNew.y, recNew.width, recNew.height);

                return result2;
            }

        protected:
        private:
            Vector2 _pos;
            Vector2 _size;
            Color _color;
        };

    };
};

#endif /* !RECTANGLE_HPP_ */
