/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-zacharie.lawson
** File description:
** Font
*/

#ifndef Font_HPP_
#define Font_HPP_

#include <raylib.h>
#include <string>

namespace ray {

    class Font {
    public:
        /**
        * @brief Construct a new Font object with default system Font
        * 
        **/
        Font();
        /**
        * @brief Construct a new Font object with specified Font file
        * 
        * @param fileName 
        **/
        Font(const std::string &fileName);
        /**
        * @brief Destroy the Font object
        * 
        **/
        ~Font();
        /**
        * @brief Set the new Font to the Font object
        * 
        * @param fileName 
        **/
        void setFont(const std::string &fileName);
        /**
        * @brief Get the Font object
        * 
        * @return ::Font 
        **/
        inline ::Font getFont() const { return _font; };

    private:
        ::Font _font;
    };

}

#endif /* !Font_HPP_ */
