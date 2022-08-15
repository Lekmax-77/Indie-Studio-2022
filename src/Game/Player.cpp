/*
** EPITECH PROJECT, 2022
** indiestudio
** File description:
** Player
*/

#include "Player.hpp"
#include "Color.hpp"
#include "IEvents.hpp"
/**
 * @brief Construct a new indie::Player::Player object
 *
 * @param posx : x position of the player
 * @param posy : y position of the player
 * @param posz : z position of the player
 * @param speed : speed of the player
 */
indie::Player::Player(float posx, float posy, float posz, float speed, std::array<KeyboardKey,5> moveKey) : _posx(posx), _posy(posy), _posz(posz), _speed(speed), _direction(Direction::DOWN), _bombs(1), _moveKey(moveKey), _power(1), _isAlive(true)
{
    _points = 0;
}

/**
 * @brief Destroy the Player object
 *
 */
indie::Player::~Player()
{
}

/**
 * @brief move the player
 *
 * @param direction : new direction of the player
 */
void indie::Player::move(Direction direction)
{
    setDirection(direction);
    switch (direction) {
        case Direction::UP:
            _posz -= _speed;
            break;
        case Direction::RIGHT:
            _posx += _speed;
            break;
        case Direction::DOWN:
            _posz += _speed;
            break;
        case Direction::LEFT:
            _posx -= _speed;
            break;
    }
    incrementAnim();
}

void indie::Player::moveBack()
{
    switch (_direction) {
        case Direction::UP:
            _posz += _speed;
            break;
        case Direction::RIGHT:
            _posx -= _speed;
            break;
        case Direction::DOWN:
            _posz -= _speed;
            break;
        case Direction::LEFT:
            _posx += _speed;
            break;
    }
}

void indie::Player::setModelAnimated(const std::string &model_path, const std::string &anim_path, const std::string &texture_path)
{
    _model = ray::_3D::Model(model_path);
    _animsCount = 0;
    _anim = ray::_3D::ModelAnimation::load(anim_path);
    _texture = ray::Texture(texture_path);
    _model.setTexture(_texture);
}

void indie::Player::setProfilePicture(std::string const &profilePicture)
{
    _profilePicture = ray::Texture(profilePicture);
}

void indie::Player::draw()
{
    if (!_isAlive)
        return;
    _model.draw({_posx, _posy, _posz}, {0.1, 0.1, 0.1}, ray::Color::White(), static_cast<int>(_direction) * 90, {0, 1, 0});
    _anim[0].update(_model, _animsCount);
    for (auto &bomb : _bombs) {
        if (bomb.getDrawBomb()) {
            bomb.drawBomb();
        }
    }
}

bool indie::Player::isInWall(indie::map::Map &map)
{
    int tabx = static_cast<int>(_posx + (map.getHeight() / 2)+ 1);
    int taby = static_cast<int>(_posz + (map.getWidth() / 2) + 1);

    if (map[tabx][taby] != indie::map::EMPTYBLOCK)
        return true;
    return false;
}

void indie::Player::moveUpdate(ray::KeyEvents key, map::Map _map)
{
    if (!_isAlive)
        return;
    if (key.isKeyDown(_moveKey[0])) {
        move(indie::Direction::UP);
    } else if (key.isKeyDown(_moveKey[1])) {
        move(indie::Direction::RIGHT);
    } else if (key.isKeyDown(_moveKey[2])) {
        move(indie::Direction::DOWN);
    } else if (key.isKeyDown(_moveKey[3])) {
        move(indie::Direction::LEFT);
    }
    if (isInWall(_map))
        moveBack();
}

void indie::Player::updateBomb(ray::KeyEvents key, map::Map &_map, std::vector<Fire> &_fires) {
    if (!_isAlive)
        return;
    if (key.isKeyPressed(_moveKey[4])) {
        throwBomb();
    }
    for (auto &bomb : _bombs) {
        bomb.update(_map, _fires);
    }
};