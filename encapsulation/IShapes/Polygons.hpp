/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-zacharie.lawson
** File description:
** Poly
*/

#ifndef POLY_HPP_
#define POLY_HPP_

namespace ray {namespace _2D {class Poly;}}

#include "raylib.h"

namespace ray
{
    namespace _2D
    {
        class Poly
        {
        public:
            // Constructors
            /**
             * @brief Construct a new Poly object
             *
             * @param x : x position
             * @param y : y position
             * @param radius : radius
             * @param color : color (optional)
             */
            Poly(Vector2 center, int sides, float radius, float rotation = 0, Color color = BLACK) : _center(center), _sides(sides), _radius(radius), _rotation(rotation), _color(color) {};

            // Destructor
            /**
             * @brief Destroy the Poly object
             *
             */
            ~Poly();

            // Getters
            /**
             * @brief Get the Center of the poly
             *
             * @return Vector2
             */
            Vector2 getPosCenter() const { return _center; };
            /**
             * @brief Get the Sides object
             * 
             * @return int 
             */
            int getSides() const { return _sides; };
            /**
             * @brief Get the Radius of the poly
             *
             * @return float
             */
            float getRadius() const { return _radius; };
            /**
             * @brief Get the Rotation of the poly
             *
             * @return float
             */
            float getRotation() const { return _rotation; };
            /**
             * @brief Get the Color of the poly
             *
             * @return Color
             */
            Color getColor() const { return _color; };

            // Setters
            /**
             * @brief Set the Center of the poly
             *
             * @param center : center
             */
            void setPosCenter(Vector2 center) { _center = center; };
            /**
             * @brief Set the Sides of the poly
             * 
             * @param sides 
             */
            void setSides(int sides) { _sides = sides; };
            /**
             * @brief Set the Radius of the poly
             *
             * @param radius : radius
             */
            void setRadius(float radius) { _radius = radius; };
            /**
             * @brief Set the Rotation of the poly
             *
             * @param rotation : rotation
             */
            void setRotation(float rotation) { _rotation = rotation; };
            /**
             * @brief Set the Color of the poly
             *
             * @param color : color
             */
            void setColor(Color color) { _color = color; };

            // Methods
            /**
             * @brief Draw the poly
             */
            void Draw(bool filled = true) {
                if (filled)
                    DrawPoly(_center, _sides, _radius, _rotation,_color);
                else
                    DrawPolyLines(_center, _sides, _radius, _rotation, _color);
            };
            /**
             * @brief Draw the poly with a given thickness
             */
            void Draw(float lineThick) {
                DrawPolyLinesEx(_center, _sides, _radius, _rotation, lineThick, _color);
            };
        protected:
        private:
            Vector2 _center;
            int _sides;
            float _radius;
            float _rotation;
            Color _color;
        };

    };
};

#endif /* !POLY_HPP_ */
