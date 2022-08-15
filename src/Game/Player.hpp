/*
** EPITECH PROJECT, 2022
** indiestudio
** File description:
** Player
*/

#ifndef PLAYER_HPP_
#define PLAYER_HPP_

#include "Map.hpp"
#include "raylib.h"
#include "ModelAnimation.hpp"
#include "Model.hpp"
#include "Texture.hpp"
#include "Bomb.hpp"
#include "Direction.hpp"
#include "IEvents.hpp"
#include "IPlayer.hpp"
#include <array>

namespace indie
{
    class Player : public IPlayer
    {
    public:
        Player(float posx = 0, float posy = 0, float posz = 0, float speed = 10, std::array<KeyboardKey, 5> moveKey = {KeyboardKey::KEY_W, KeyboardKey::KEY_D, KeyboardKey::KEY_S, KeyboardKey::KEY_A, KeyboardKey::KEY_Q});
        ~Player();

        // Getters
        inline float getPosX() const { return _posx; };
        inline float getPosY() const { return _posy; };
        inline float getPosZ() const { return _posz; };
        inline ray::Vector3 getPos() { return {_posx, _posy, _posz}; };
        inline float getSpeed() const { return _speed; };
        inline Direction getDirection() const { return _direction; };
        inline int getRotation() const { return static_cast<int>(_direction) * 90; };
        inline unsigned int getPoints() const { return _points; };
        inline ray::Texture getProfilePicture() const { return _profilePicture; };
        // Setters
        inline void setPosX(float posx) { _posx = posx; };
        inline void setPosY(float posy) { _posy = posy; };
        inline void setPosZ(float posz) { _posz = posz; };


        inline void setSpeed(float speed) { _speed = speed; };
        inline void setDirection(Direction direction) { _direction = direction; };
        void setModelAnimated(const std::string &model_path, const std::string &anim_path, const std::string &texture_path);
        void setProfilePicture(std::string const &profilePicture);

        // Methods
        void move(Direction direction);
        void moveBack();
        void draw();
        void incrementAnim() { _animsCount++; };
        void updateBomb(ray::KeyEvents key, map::Map &_map, std::vector<Fire> &);
        void die() { _isAlive = false; };
        bool isAlive() { return _isAlive; };

        // Bomb
        inline void throwBomb() {
            for (auto &bomb : _bombs) {
                if (bomb.isReady()) {
                    bomb.setPower(_power);
                    bomb.throwBomb(_posx, _posy, _posz);
                    break;
                }
            }
        };
        void moveUpdate(ray::KeyEvents key, map::Map _map);
        bool isInWall(indie::map::Map &map);

        void Score(unsigned int points) { _points += points; };
    protected:
        float _posx;
        float _posy;
        float _posz;
        float _speed;
        Direction _direction;

        std::vector<Bomb> _bombs;
        ray::_3D::Model _model;
        std::vector<ray::_3D::ModelAnimation> _anim;
        unsigned int _animsCount;
        ray::Texture _texture;
        int _power;
        bool _isAlive;
    private:
        std::array<KeyboardKey,5> _moveKey;
        unsigned int _points;
        ray::Texture _profilePicture;
    };
}

#endif /* !PLAYER_HPP_ */
