/*
** EPITECH PROJECT, 2022
** indie-studio
** File description:
** Settings
*/

#include <iostream>
#include "Settings.hpp"
#include "../../encapsulation/Window/Window.hpp"
#include "../../encapsulation/TimeRelated/TimeRelated.hpp"
#include "../../encapsulation/Events/IEvents.hpp"
#include "../../encapsulation/Sprite/Texture.hpp"
#include "../../encapsulation/Window/Window.hpp"
#include "../../encapsulation/Events/IEvents.hpp"
#include "../../encapsulation/IShapes/Rectangle.hpp"
#include "../../encapsulation/Color/Color.hpp"
#include "ButtonTristate.hpp"
#include "SliderBar.hpp"
#include "../../encapsulation/Text/Text.hpp"


#define RAYGUI_IMPLEMENTATION

indie::Settings::Settings()
{
}

indie::Settings::~Settings()
{
}

bool indie::Settings::run(ray::Window &window)
{
    ray::_2D::Rectangles table(1920 / 4, 1080/4, 1920/2, 1080/2);
    ray::_2D::Rectangles tables(1920 / 3.65, 1080/3.65, 1920/2.25, 1080/2.25);
    ray::SliderBar bar_fps({850, 500, 240, 40}, "30 fps", "240 fps", "fps:", 30, 240, 60);
    ray::SliderBar bar_sound({850, 600, 240, 40}, "Volume 0", "Volume 100", "Sound:", 0, 100, 60);
    ray::SliderBar bar_music({850, 700, 240, 40}, "Volume 0", "Volume 100", "Music:", 0, 100, 60);
    ray::_2D::Rectangles((ray::Vector2){1105, 2615},(ray::Vector2){193, 180}, ray::Color::Black()));
    while(!window.windowShouldClose()) {
        if (quit.IsClicked()) {
            return false;
        }
        if (keyEvents.isKeyPressed(KEY_ESCAPE))
            break;
        window.beginDrawing();
        window.clearBackground(ray::Color::RayWhite());
        background.DrawRec((Rectangle){0, 0, 1920, 1080});
        table.setColor( ray::Color::Black());
        table.Draw(0.1, 80);
        tables.setColor( ray::Color::RayWhite());
        tables.Draw(0.1, 80);
        bar_fps.Draw();
        bar_sound.Draw();
        bar_music.Draw();
        quit.Draw();
        setting.draw();
        SetTargetFPS(bar_fps.getValue());
        DrawFPS(100, 100);
        window.endDrawing();
    }
    return false;
}
