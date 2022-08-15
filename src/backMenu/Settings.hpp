/*
** EPITECH PROJECT, 2022
** indie-studio
** File description:
** Settings
*/

#ifndef SETTINGS_HPP_
    #define SETTINGS_HPP_
    #include "../../encapsulation/Window/Window.hpp"

namespace indie
{
    class Settings {
        public:
            Settings();
            ~Settings();
            bool run(ray::Window &window);
        protected:
        private:
    };

} // namespace name

#endif /* !SETTINGS_HPP_ */
