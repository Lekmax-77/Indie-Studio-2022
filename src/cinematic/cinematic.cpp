/*
** EPITECH PROJECT, 2022
** indie
** File description:
** cinematic
*/

#include <iostream>
#include "cinematic.hpp"
#include "Camera.hpp"
#include "Window.hpp"
#include "Vector3.hpp"
#include "TimeRelated.hpp"
#include "IEvents.hpp"
#include "Model.hpp"
#include "Scene.hpp"

indie::Cinematic::Cinematic():indie::IScene(), _animFrameCounter(0), _change(false), _speed(0.5), _displayFire(false), _displayTitle(false), _text()
{
    _scene = engine::Scene("../game_engine/config/cinematic.yml");
    _soundDelay = ray::TimeRelated::getTime();
    initPlayer();
    initBomb();
    initFire();
    initText();
}

indie::Cinematic::~Cinematic()
{
}

void indie::Cinematic::initFire()
{
    _fire = _scene.getModel("fire");
    _animsFire = ray::_3D::ModelAnimation::load("../ressources/Assets/IQM/fireAnim.iqm");
}

void indie::Cinematic::initBomb()
{
    _bomb = _scene.getModel("bomb");
}

void indie::Cinematic::initPlayer()
{
    _bomberman = _scene.getModel("player");
    _animsBomberman = ray::_3D::ModelAnimation::load("../ressources/Assets/IQM/bombermanRun.iqm");
}

void indie::Cinematic::initText()
{
    _title = _scene.getSprite("title");
}

void indie::Cinematic::draw()
{
    _fire.draw();
    _bomb.draw();
    _bomberman.draw();
}

void indie::Cinematic::updateAnimation()
{
    _animsFire[0].update(_fire.getModel(), _animFrameCounter);
    _animsBomberman[0].update(_bomberman.getModel(), _animFrameCounter);
    _animFrameCounter++;
}

void indie::Cinematic::updatePlayerPosition()
{
    if (_change == false)
        _bomberman.move({0, 0, _speed * ray::TimeRelated::getFrameTime()});
    else {
        _bomberman.move({0, 0, -(_speed * ray::TimeRelated::getFrameTime())});
    }
    if (ray::TimeRelated::getTime() - _soundDelay > 0.20 && _bomberman.getPosition().z > -1) {
        _soundDelay = ray::TimeRelated::getTime();
        _scene.getSound("steps").playMulti();
    }
    if (_bomberman.getPosition().z > 1) {
        _change = true;
        _bomberman.setRotationAngle(180);
    }
}

void indie::Cinematic::updateFirePosition()
{
    static bool fire = false;

    if (_bomb.getPosition().y < -0.1)
        _displayFire = true;
    if (_displayFire && fire == false) {
        fire = true;
        _scene.getSound("fire").play();
    }
    if (_displayFire && _fire.getPosition().y < -0.1) {
        _fire.move({0, _speed * ray::TimeRelated::getFrameTime(), 0});
        _displayTitle = true;

    }
}

void indie::Cinematic::updateBombPosition()
{
    static bool fall = false;
    static bool explosion = false;

    if (_change == true && _bomberman.getPosition().z < -0.1) {
        _bomb.move({0, -(_speed * ray::TimeRelated::getFrameTime()), 0});
        if (fall == false) {
            _scene.getSound("fall").play();
            _scene.getSound("scream").play();
            fall = true;
        }
    }
    if (fall && explosion == false && ray::TimeRelated::getTime() - _soundDelay > 1) {
        explosion = true;
        _scene.getSound("explosion").play();
    }
}

void indie::Cinematic::updateTextPosition()
{
    if (_displayTitle) {
        _title.Draw();
    }
}

indie::SCENE_ENUM indie::Cinematic::run(indie::Settings &set)
{
    ray::Vector3 position = {1.0f, 0.3f, 0.0f};
    ray::Vector3 target = {0.0f, 0.18f, 0.0f};
    ray::Vector3 up = {0.0f, 1.0f, 0.0f};
    bool playSound = true;

    _camera.setPosition(position, target, up,  20.0f);
    _camera.setCameraMode(CAMERA_PERSPECTIVE);
    ray::TimeRelated::setTargetFPS(60);
    DrawGrid(100, 1);
    
    while(!set.GetWindow().windowShouldClose()) {
        if (_key.isKeyPressed(KEY_SPACE)) {
            return indie::SCENE_ENUM::MENU;
        }
        _camera.updateCamera();
        set.GetWindow().beginDrawing();
        set.GetWindow().beginMode3D(_camera);
        set.GetWindow().clearBackground(ray::Color::Black());
        draw();
        updateAnimation();
        updatePlayerPosition();
        updateBombPosition();
        updateFirePosition();
        set.GetWindow().endMode3D();
        updateTextPosition();
        set.GetWindow().endDrawing();
    }
    return indie::SCENE_ENUM::END;
}
