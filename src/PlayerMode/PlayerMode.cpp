/*
** EPITECH PROJECT, 2022
** indie-studio
** File description:
** PlayerMode
*/

#include "PlayerMode.hpp"


indie::PlayerMode::PlayerMode():indie::IScene()
{
    _scene = engine::Scene("../game_engine/config/playerMode.yaml");
    initSprite();
    initText();
    initRect();
}

indie::PlayerMode::~PlayerMode()
{
    ;
}

void indie::PlayerMode::initSprite()
{
    _background = _scene.getSprite("background");
    _quit = _scene.getButtonTristate("quit");
    _solo = _scene.getButtonTexture("solo");
    _duo = _scene.getButtonTexture("duo");
    _trio = _scene.getButtonTexture("trio");
    _quad = _scene.getButtonTexture("quad");
}

void indie::PlayerMode::initRect()
{
    ;
}

void indie::PlayerMode::initText()
{
    _text_solo = _scene.getText("text_solo");
    _text_duo = _scene.getText("text_duo");
    _text_trio = _scene.getText("text_trio");
    _text_quad = _scene.getText("text_quad");
    _mode = _scene.getText("mode");
}


void indie::PlayerMode::draw()
{
    _background.Draw();
    _quit.Draw();
    _solo.Draw();
    _duo.Draw();
    _trio.Draw();
    _quad.Draw();
    _mode.draw();
    _text_solo.draw();
    _text_duo.draw();
    _text_trio.draw();
    _text_quad.draw();
    DrawFPS(150, 50);
}

void indie::PlayerMode::Update()
{
    _quit.Update();
    _solo.Update();
    _duo.Update();
    _trio.Update();
    _quad.Update();
}

indie::SCENE_ENUM indie::PlayerMode::run(indie::Settings &set)
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
            return set.getScene();
        }
        if (_solo.IsClicked()) {
            set.setPlayer(1);
            return indie::SCENE_ENUM::GAME;
        }
        if (_duo.IsClicked()) {
            set.setPlayer(2);
            return indie::SCENE_ENUM::GAME;
        }
        if (_trio.IsClicked()) {
            set.setPlayer(3);
            return indie::SCENE_ENUM::GAME;
        }
        if (_quad.IsClicked()) {
            set.setPlayer(4);
            return indie::SCENE_ENUM::GAME;
        }
        draw();
        set.GetWindow().endDrawing();
    }
    return indie::SCENE_ENUM::END;
}