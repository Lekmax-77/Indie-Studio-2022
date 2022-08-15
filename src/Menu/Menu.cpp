/*
** EPITECH PROJECT, 2022
** indie
** File description:
** cinematic
*/

#include <iostream>
#include "Menu.hpp"
#include "Window.hpp"
#include "Vector3.hpp"
#include "TimeRelated.hpp"
#include "IEvents.hpp"
#include "Model.hpp"
#include "Scene.hpp"
#include "TimeRelated.hpp"
#include "IEvents.hpp"

indie::Menu::Menu():indie::IScene()
{
    _scene = engine::Scene("../game_engine/config/Menu.yaml");
    initSprite();
    _scene.getMusic("music").play();
}

indie::Menu::~Menu()
{
    ;
}

void indie::Menu::initSprite()
{
    _background = _scene.getSprite("background");
    _title = _scene.getSprite("frontground");
    _setting = _scene.getButtonTristate("setting");
    _quit = _scene.getButtonTristate("quit");
    _play = _scene.getButtonTexture("play");
}

void indie::Menu::initText()
{
    ;//_text = ray::Text(_font, "Bomberman", ray::Color::Pink(), {700, 450}, 100, 3);
}

void indie::Menu::draw()
{
    _background.Draw();
    _title.Draw();
    _setting.Draw();
    _play.Draw();
    _quit.Draw();
}

void indie::Menu::UpdateButton()
{
    _play.Update();
    _quit.Update();
    _setting.Update();
}

indie::SCENE_ENUM indie::Menu::run(indie::Settings &set)
{
    ray::TimeRelated::setTargetFPS(60);

    //DrawGrid(100, 1);
    while(!set.GetWindow().windowShouldClose()) {
        if (_key.isKeyPressed(KEY_ESCAPE)) {
            return indie::SCENE_ENUM::END;
        }
        set.GetWindow().beginDrawing();
        set.GetWindow().clearBackground(ray::Color::White());
        UpdateButton();
        _scene.getMusic("music").update();
        if (_quit.IsClicked()) {
            _scene.getSound("clic").play();
            return indie::SCENE_ENUM::END;
        }
        if (_key.isKeyPressed(KEY_BACKSPACE)) {
            _scene.getSound("clic").play();
            return indie::SCENE_ENUM::CINEMATIC;
        }
        if (_setting.IsClicked())
            return indie::SCENE_ENUM::SETTING;
        /*if (_play.IsClicked()) {
            if (play_mode(window) == true) {
                return true;
            }
        }*/
        if (_play.IsClicked()) {
            _scene.getSound("clic").play();
            return indie::SCENE_ENUM::MODE_SELECT;
        }
        draw();
        ray::TimeRelated::drawFPS(150, 50);
        set.GetWindow().endDrawing();
    }
    return indie::SCENE_ENUM::END;
}
