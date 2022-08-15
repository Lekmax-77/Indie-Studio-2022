/*
** EPITECH PROJECT, 2021
** IText
** File description:
** IText
*/

#include "Text.hpp"

/********** TEXT METHODS **********/

ray::Text::Text(Font &font, std::string const &text, Color color, ray::Vector2 position, float fontSize, float spacing)
{
    _font = font;
    _text = text;
    _color = color;
    _position = position;
    _fontSize = fontSize;
    _spacing = spacing;
}

void ray::Text::draw() const
{
    DrawTextEx(_font.getFont(), _text.c_str(), _position, _fontSize, _spacing, _color);
}