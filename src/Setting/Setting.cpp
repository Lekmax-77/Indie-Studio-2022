/*
** EPITECH PROJECT, 2022
** indie-studio
** File description:
** Setting
*/

#include "Setting.hpp"


indie::Setting::Setting():indie::IScene(), _bar_fps({850, 500, 240, 40}, "30 fps", "240 fps", "fps:", 30, 240, 60), _bar_sound({850, 600, 240, 40}, "Volume 0", "Volume 100", "Sound:", 0, 100, 60), _bar_music({850, 700, 240, 40}, "Volume 0", "Volume 100", "Music:", 0, 100, 60)
{
    _scene = engine::Scene("../game_engine/config/Setting.yaml");
    initSprite();
    initText();
    initRect();
}

indie::Setting::~Setting()
{
    ;
}

void indie::Setting::initSprite()
{
    _background = _scene.getSprite("background");
    _quit = _scene.getButtonTristate("quit");
}

void indie::Setting::initRect()
{
    _table = ray::_2D::Rectangles(1920 / 4, 1080/4, 1920/2, 1080/2);
    _tables = ray::_2D::Rectangles(535, 300, 1920/2.25, 1080/2.25);
}

void indie::Setting::initText()
{
    _text_setting = _scene.getText("setting");
}


void indie::Setting::draw()
{
    _background.Draw();
    _table.setColor( ray::Color::Black());
    _table.Draw(0.1, 80);
    _tables.setColor( ray::Color::RayWhite());
    _tables.Draw(0.1, 80);
    _quit.Draw();
    _text_setting.draw();
    _bar_fps.Draw();
    _bar_sound.Draw();
    _bar_music.Draw();
    DrawFPS(150, 50);
}

void indie::Setting::Update()
{
    _quit.Update();
    SetTargetFPS(_bar_fps.getValue());
}

indie::SCENE_ENUM indie::Setting::run(indie::Settings &set)
{
    ray::TimeRelated::setTargetFPS(60);
    ray::MouseEvents mouse;
    //DrawGrid(100, 1);
    while(!set.GetWindow().windowShouldClose()) {
        if (_key.isKeyPressed(KEY_ESCAPE)) {
            return indie::SCENE_ENUM::END;
        }
        set.GetWindow().beginDrawing();
        set.GetWindow().clearBackground(ray::Color::White());
        Update();
        set.setMusic(_bar_music.getValue());
        set.setSound(_bar_sound.getValue());
        if(_quit.IsClicked()) {
            mouse.setMousePosition(1920/2, 1080/2);
            return set.getScene();
        }
        draw();
        set.GetWindow().endDrawing();
    }
    return indie::SCENE_ENUM::END;
}