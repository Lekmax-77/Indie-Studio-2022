/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-zacharie.lawson
** File description:
** IA
*/

#include "IA.hpp"
#include "Tools.hpp"

indie::IA::IA(float posx, float posy, float posz, float speed) : Player(posx, posy, posz, speed), _moveDir(0), _moveDelay(0)
{
}

indie::IA &indie::IA::operator=(const IA &src)
{
    Player::operator=(src);

    return *this;
}

#include <iostream>

void indie::IA::moveUpdate(ray::KeyEvents key, map::Map _map)
{
    (void) key;
    if (!_isAlive) {
        return;
    }
    ray::Tools::Misc tool;

    _moveDelay--;
    if (_moveDelay <= 0) {
        _moveDelay = 20;
        _moveDir = tool.getRandomValue(0, 3);
    }
    switch (_moveDir) {
        case 0:
            move(Direction::UP);
            break;
        case 1:
            move(Direction::RIGHT);
            break;
        case 2:
            move(Direction::DOWN);
            break;
        case 3:
            move(Direction::LEFT);
            break;
    }

    if (isInWall(_map)) {
        _moveDelay = 0;
        moveBack();
        throwBomb();
    }
}

void indie::IA::updateBomb(ray::KeyEvents key, map::Map &_map, std::vector<Fire> &_fires) {
    if (!_isAlive)
        return;
    for (auto &bomb : _bombs) {
        bomb.update(_map, _fires);
    }
};