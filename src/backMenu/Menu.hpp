/*
** EPITECH PROJECT, 2022
** indie-studio
** File description:
** Menu
*/

#ifndef MENU_HPP_
    #define MENU_HPP_
    #include "../../encapsulation/Sprite/Texture.hpp"
    #include "../../encapsulation/Window/Window.hpp"
    #include "../../encapsulation/Events/IEvents.hpp"
    #include "../../encapsulation/IShapes/Rectangle.hpp"


namespace indie {
    class Menu {
        public:
            Menu();
            ~Menu();
            bool run(ray::Window &window);
        protected:
        private:
    };
};

#endif /* !MENU_HPP_ */
