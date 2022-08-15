/*
** EPITECH PROJECT, 2022
** Bomb.cpp
** File description:
** Bomb
*/

#include "3D/Collision.hpp"
#include "Bomb.hpp"
#include "TimeRelated.hpp"

indie::Bomb::Bomb()
    : _size(1), _draw(false),
      _bombModel("../ressources/Assets/IQM/bomb.iqm"),
      _bombTexture("../ressources/Assets/Textures/bomb.png"),
      _explosionModel("../ressources/Assets/IQM/fire.iqm"),
      _explosionTexture("../ressources/Assets/Textures/fire.png"),
      _isReady(true)
{
        _bombModel.setTexture(_bombTexture);
        _explosionModel.setTexture(_explosionTexture);
}

void indie::Bomb::setPower(int power)
{
    _size = power;
}

void indie::Bomb::throwBomb(float x, float y, float z)
{
    _draw = true;
    _pos = {x, y, z};
    _pos.x = static_cast<int>(_pos.x) + 0.5 - (1 * (_pos.x < 0));
    _pos.z = static_cast<int>(_pos.z) - 0.5 + (1 * (_pos.z > 0));
    _isReady = false;
    _time = ray::TimeRelated::getTime();
}

void indie::Bomb::update(map::Map &_map, std::vector<Fire> &_fires)
{
    if (_draw) {
        if (ray::TimeRelated::getTime() - _time > 2) {
            _draw = false;
            _time = 0;
            _isReady = true;
            explode(_map, _fires);
        } else {
            _draw = true;
        }
    }
}

bool indie::Bomb::getDrawBomb()
{
    return _draw;
}

void indie::Bomb::explode(map::Map &map, std::vector<Fire> &_fires)
{
    ray::Vector2 pos = {_pos.x, _pos.z};
    pos.x += +0.5 + map.getHeight() / 2;
    pos.y += +0.5 + map.getWidth() / 2;

    _fires.emplace_back(ray::Vector3{pos.x - map.getHeight() / 2 - 0.5, 1, pos.y - map.getWidth() / 2 -0.5});
    explodeDir(map, pos + ray::Vector2{0, -1}, {0, -1}, _size, _fires);
    explodeDir(map, pos + ray::Vector2{1, 0}, {1, 0}, _size, _fires);
    explodeDir(map, pos + ray::Vector2{0, 1}, {0, 1}, _size, _fires);
    explodeDir(map, pos + ray::Vector2{-1, 0}, {-1, 0}, _size, _fires);
}

void indie::Bomb::explodeDir(map::Map &map, ray::Vector2 pos, ray::Vector2 dir, int power, std::vector<Fire> &_fires)
{
    if (power <= 0)
        return;
    if (map[pos.x][pos.y] == map::WALLBLOCK)
        return;
    if (map[pos.x][pos.y] == map::BRICKBLOCK) {
        map[pos.x][pos.y] = map::EMPTYBLOCK;
        // draw explosion
        _fires.emplace_back(ray::Vector3{pos.x - map.getHeight() / 2 - 0.5, 1, pos.y - map.getWidth() / 2-0.5});
        return;
    }
    // draw explosion
    _fires.emplace_back(ray::Vector3{pos.x - map.getHeight() / 2 - 0.5, 1, pos.y - map.getWidth() / 2 -0.5});
    explodeDir(map, pos + dir, dir, power - 1, _fires);
}