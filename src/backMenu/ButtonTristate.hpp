/*
** EPITECH PROJECT, 2022
** indie-studio
** File description:
** ButtonTristate
*/

#ifndef BUTTONTRISTATE_HPP_
    #define BUTTONTRISTATE_HPP_
    #include "../../encapsulation/Sprite/Texture.hpp"
    #include "../../encapsulation/Window/Window.hpp"
    #include "../../encapsulation/Events/IEvents.hpp"
    #include "../../encapsulation/IShapes/Rectangle.hpp"

namespace indie
{
    class ButtonTristate : public ray::Texture
    {
        public:
            ButtonTristate(const std::string &filename, ray::_2D::Rectangles rec);
            ~ButtonTristate();
            void Draw(void);
            bool IsClicked();
        protected:
            ray::_2D::Rectangles _rec;
    };
    class ButtonTexture : public ray::Texture
    {
        public:
            ButtonTexture(const std::string &filename);
            ~ButtonTexture();
            void Draw(void);
            bool IsClicked();
        protected:
            ray::_2D::Rectangles _rec;
    };
} // namespace name


#endif /* !BUTTONTRISTATE_HPP_ */
