/*
** EPITECH PROJECT, 2022
** indie-studio
** File description:
** EndWin
*/

#include "EndWin.hpp"


indie::EndWin::EndWin():indie::IScene()
{
    _scene = engine::Scene("../game_engine/config/End.yaml");
    initSprite();
    initText();
    initRect();
}

indie::EndWin::~EndWin()
{
    ;
}

void indie::EndWin::initSprite()
{
    _background = _scene.getSprite("background");
    _quit = _scene.getButtonTristate("quit");
}

void indie::EndWin::initRect()
{
    ;
}

void indie::EndWin::initText()
{
    ;
}


void indie::EndWin::draw()
{
    _background.Draw();
    _quit.Draw();
    DrawFPS(150, 50);
}

void indie::EndWin::Update()
{
    _quit.Update();
}

indie::SCENE_ENUM indie::EndWin::run(indie::Settings &set)
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
        if(_quit.IsClicked()) {
            mouse.setMousePosition(1920/2, 1080/2);
            return indie::SCENE_ENUM::MENU;
        }
        draw();
        set.GetWindow().endDrawing();
    }
    return indie::SCENE_ENUM::END;
}