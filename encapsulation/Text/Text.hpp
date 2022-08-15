/*
** EPITECH PROJECT, 2021
** IText
** File description:
** IText
*/

#ifndef _ITEXT_HPP_
#define _ITEXT_HPP_

#include "Font.hpp"
#include "../IDrawable.hpp"
#include "../Vector/Vector2.hpp"
#include "../Color/Color.hpp"
#include <raylib.h>
#include <string>
#include <vector>

namespace ray {

    class Text : virtual public IDrawable {
    public:

        /**
        * @brief Construct a new Text object
        * 
        * @param font 
        * @param text 
        * @param color optional (default value : Black)
        * @param position optional (default value : [0; 0])
        * @param fontSize optional (default value : 10)
        * @param spacing optional (default value : 0)
        **/
        Text(Font &font, std::string const &text, Color color = Color::Black(), Vector2 position = Vector2::Zero(), float fontSize = 10.0f, float spacing = 0.0f);
        Text() {};
        ~Text() = default;

        inline void setText(std::string const &text) {_text = text;};
        inline void setFont(Font font) {_font = font;};
        /**
        * @brief Set the Font object color
        * 
        * @param color 
        **/
        inline void setColor(Color color) { _color = color; }
        
        /**
        * @brief Get the Font object color
        * 
        * @return Color 
        **/
        inline Color getColor() const { return _color; }

        /**
        * @brief Set the Font object position
        * 
        * @param position 
        **/
        inline void setPosition(Vector2 position) { _position = position; }

        /**
        * @brief Get the Font object position
        * 
        * @return Vector2 
        **/
        inline Vector2 getPosition() const { return _position; }

        /**
        * @brief Set the Font object size
        * 
        * @param fontSize 
        **/
        inline void setFontSize(float fontSize) { _fontSize = fontSize; };


        inline std::string getText() const { return _text; }
        inline ray::Font getFont() const { return _font; }
        /**
        * @brief Get the Font object size
        * 
        * @return float 
        **/
        inline float getFontSize() const { return _fontSize; };
        /**
        * @brief Set the Font object spacing
        * 
        * @param spacing 
        **/
        inline void setSpacing(float spacing) { _spacing = spacing; }
        /**
        * @brief Get the Font object spacing
        * 
        * @return float 
        **/
        inline float getSpacing() const { return _spacing; };
        /**
        * @brief Draw Text object
        * 
        **/
        void draw() const;

    protected:
        std::string _text;
        ray::Font _font;
        Color _color;
        Vector2 _position;
        float _fontSize;
        float _spacing;
    };
}

#endif //_ITEXT_HPP_
