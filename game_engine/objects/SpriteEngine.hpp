/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-zacharie.lawson
** File description:
** SpriteEngine
*/

#ifndef SPRITEENGINE_HPP_
#define SPRITEENGINE_HPP_

    #include "Vector2.hpp"
    #include "Texture.hpp"
    #include "Picture.hpp"

namespace engine {
    class Sprite : public ray::Texture {
        public:
            Sprite() : ray::Texture() {};
            Sprite(const std::string &filepath):ray::Texture(filepath) {};
            Sprite(const Sprite &src) : ray::Texture(src) {};
            Sprite &operator=(const Sprite &src) {
                ray::Texture::operator=(src);
                return *this;
            }
            Sprite &operator=(const ::Texture &src) {
                ray::Texture::operator=(src);
                return *this;
            };
            ~Sprite() {};

        //setters

        //methods
        inline void move(ray::Vector2 move) {_position += move;};

        protected:
    };
};

#endif /* !SPRITEENGINE_HPP_ */
