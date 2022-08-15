/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-zacharie.lawson
** File description:
** Circle
*/

#ifndef CIRCLE_HPP_
#define CIRCLE_HPP_

namespace ray
{
    namespace _2D
    {
        class Circle;
    }
}

#include "raylib.h"

namespace ray
{
    namespace _2D
    {
        class Circle
        {
        public:
            // Constructors
            /**
             * @brief Construct a new Circle object
             *
             * @param x : x position
             * @param y : y position
             * @param radius : radius
             * @param color : color (optional)
             */
            Circle(float x, float y, float radius, Color color = BLACK) : _center({x, y}), _radius(radius), _color(color){};

            /**
             * @brief Construct a new Circle object
             *
             * @param vector : position
             * @param radius : radius
             * @param color : color (optional)
             */
            Circle(Vector2 pos, float radius, Color color = BLACK) : _center(pos), _radius(radius), _color(color){};

            // Destructor
            /**
             * @brief Destroy the Circle object
             *
             */
            ~Circle(){};

            // Getters
            /**
             * @brief Get the Center of the circle
             *
             * @return Vector2
             */
            Vector2 getCenter() const { return _center; };

            /**
             * @brief Get the Radius of the circle
             *
             * @return float
             */
            float getRadius() const { return _radius; };

            /**
             * @brief Get the Color of the circle
             *
             * @return Color
             */
            Color getColor() const { return _color; };

            // Setters
            /**
             * @brief Set the Center of the circle
             *
             * @param center : new center
             */
            void setCenter(Vector2 center) { _center = center; };

            /**
             * @brief Set the Radius of the circle
             *
             * @param radius : new radius
             */
            void setRadius(float radius) { _radius = radius; };

            /**
             * @brief Set the Color of the circle
             *
             * @param color : new color
             */
            void setColor(Color color) { _color = color; };

            // Methods

            /**
             * @brief 2D circle classic Draw method
             */
            void Draw()
            {
                DrawCircleV(_center, _radius, _color);
            };

            /**
             * @brief 2D circle Draw method
             *
             * @param filled : bool to know if the circle is filled or not
             */
            void Draw(bool filled)
            {
                if (filled)
                    DrawCircleV(_center, _radius, _color);
                else
                    DrawCircleLines(_center.x, _center.y, _radius, _color);
            };

            /**
             * @brief Draw a piece of a circle or sector outline depending on line
             *
             * @param startAngle
             * @param endAngle
             * @param segments
             * @param line : bool to know if the circle is filled or not (optional)
             */
            void Draw(float startAngle, float endAngle, int segments, bool line = false)
            {
                if (line)
                    DrawCircleSector(_center, _radius, startAngle, endAngle, segments, _color);
                else
                    DrawCircleSectorLines(_center, _radius, startAngle, endAngle, segments, _color);
            };

            /**
             * @brief Draw circle with a color gradient
             *
             * @param colorGradient
             */
            void Draw(Color colorGradient) { DrawCircleGradient(_center.x, _center.y, _radius, _color, colorGradient); };

            /**
             * @brief draw ellipse formed by the circle
             *
             * @param radius : radius of the ellipse
             * @param filled : bool to know if the circle is filled or not (optional)
             */
            void Draw(float radius, bool filled = true)
            {
                if (filled)
                    DrawEllipse(_center.x, _center.y, _radius, radius, _color);
                else
                    DrawEllipseLines(_center.x, _center.y, _radius, radius, _color);
            };

            /**
             * @brief  Draw a ring formed by the circle
             *
             * @param inner_radius
             * @param startAngle
             * @param endAngle
             * @param segments
             * @param filled : (optional) bool to know if the circle is filled or not
             */
            void Draw(float inner_radius, float startAngle, float endAngle, int segments, bool filled = true)
            {
                if (filled)
                    DrawRing(_center, inner_radius, _radius, startAngle, endAngle, segments, _color);
                else
                    DrawRingLines(_center, inner_radius, _radius, startAngle, endAngle, segments, _color);
            };

        protected:
        private:
            Vector2 _center;
            float _radius;
            Color _color;
        };
    };
};
#endif /* !CIRCLE_HPP_ */
