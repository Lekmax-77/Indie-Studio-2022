/*
** EPITECH PROJECT, 2022
** indie
** File description:
** TextEngine
*/

#ifndef TEXTENGINE_HPP_
#define TEXTENGINE_HPP_

#include "Vector/Vector3.hpp"
#include "Text.hpp"
#include "Color.hpp"
#include "Texture.hpp"

namespace engine {
    class Text : public ray::Text {
    public:
    // getters

    // setters

    // methods
        inline void move(ray::Vector2 move) {_position += move;};

    private:
        // ray::Font _font;
        // ray::Text _text;
        // ray::Vector2 _pos;
        // float _scale;
        // float _spacing;
        // std::string _txt;
        // ray::Color _color;
    }; // class text
}; // namespace engine

#endif
