/*
** EPITECH PROJECT, 2022
** indie-studio
** File description:
** Menu
*/

#include "Menu.hpp"
#include "../../encapsulation/Text/Text.hpp"
#include "../../encapsulation/Text/Font.hpp"
#include "../../encapsulation/TimeRelated/TimeRelated.hpp"
#include "../../encapsulation/Events/IEvents.hpp"
#include <iostream>
#include "ButtonTristate.hpp"
#include "Settings.hpp"

indie::Menu::Menu() {};

indie::Menu::~Menu() {};

bool indie::Menu::run(ray::Window &window)
{
    ray::TimeRelated time;
    ray::KeyEvents keyEvents;

    time.setTargetFPS(60);
    while(!window.windowShouldClose()) {

        window.beginDrawing();
        window.clearBackground(ray::Color::Black());

        if (quit.IsClicked())
            return false;
        if (setting.IsClicked()) {
            indie::Settings set;
            set.run(window);
        }
        if (start.IsClicked()) {
            if (play_mode(window) == true) {
                return true;
            }
        }







        
        if (keyEvents.isKeyPressed(KEY_ESCAPE))
            break;
        DrawFPS(150, 50);
        window.endDrawing();
    }
    return true;
}