/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-zacharie.lawson
** File description:
** Line
*/

#ifndef LINE_HPP_
#define LINE_HPP_

namespace ray {namespace _2D {class Line;}}

#include <vector>
#include "raylib.h"

namespace ray
{
    namespace _2D
    {
        class Line {
        public:
            // Constructors
            Line(float x1, float y1, float x2, float y2, Color color = BLACK, float thick = 1) : _pos1({x1, y1}), _pos2({x2, y2}), _color(color), _thick(thick) {};
            Line(Vector2 startPos, Vector2 endPos, Color color = BLACK) : _pos1(startPos), _pos2(endPos), _color(color) {};

            // Destructor
            ~Line();

            // Getters
            Vector2 getPos1() const { return _pos1; };
            Vector2 getPos2() const { return _pos2; };
            float getThick() const { return _thick; };
            Color getColor() const { return _color; };

            // Setters
            void setPos1(Vector2 pos) { _pos1 = pos; };
            void setPos2(Vector2 pos) { _pos2 = pos; };
            void setThick(float thick) { _thick = thick; };
            void setColor(Color color) { _color = color; };

            // Methods
            void Draw();
            void Draw(Vector2 ControlPos);
            void Draw(Vector2 ControlPos1, Vector2 ControlPos2);

        protected:
        private:
            Vector2 _pos1;
            Vector2 _pos2;
            Color _color;
            float _thick;
        };

    };
};

#endif /* !LINE_HPP_ */
