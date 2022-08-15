/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-zacharie.lawson
** File description:
** Fire
*/

#include "Fire.hpp"
#include "TimeRelated.hpp"

indie::Fire::Fire(ray::Vector3 pos) : _pos(pos), _time(ray::TimeRelated::getTime()), _isAlive(true), _cube(pos, {0.9f, 0.9f, 0.9f}, ray::Color::Orange())
{
}

#include <iostream>
void indie::Fire::update(std::vector<IPlayer *> &players)
{
    if (!_isAlive)
        return;
    if (ray::TimeRelated::getTime() - _time > 0.5) {
        _isAlive = false;
    }
    for (auto &player : players) {
        ray::Vector3 playerPos = player->getPos();
        if (playerPos.x <= _pos.x + 0.5 && playerPos.x >= _pos.x - 0.5 && playerPos.z <= _pos.z + 0.5 && playerPos.z >= _pos.z - 0.5) {
            player->die();
        }
    }
}


void indie::Fire::draw()
{
    if (_isAlive) {
        _cube.draw();
    }
}
