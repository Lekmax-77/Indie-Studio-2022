/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-zacharie.lawson
** File description:
** IPlayer
*/

#ifndef IPLAYER_HPP_
#define IPLAYER_HPP_

#include "IEvents.hpp"
#include "Map.hpp"
#include "Fire.hpp"

namespace indie {
    class IPlayer {
    public:
        virtual ~IPlayer() = default;
        virtual void moveUpdate(ray::KeyEvents key, map::Map _map) = 0;
        virtual void draw() = 0;
        virtual void updateBomb(ray::KeyEvents key, map::Map &_map, std::vector<Fire> &) = 0;
        virtual void die() = 0;
        virtual ray::Vector3 getPos() = 0;
        // Getters
        virtual float getPosX() const = 0;
        virtual float getPosY() const = 0;
        virtual float getPosZ() const = 0;
        virtual float getSpeed() const = 0;
        virtual unsigned int getPoints() const = 0;

        // Setters
        virtual inline void setPosX(float posx) = 0;
        virtual inline void setPosY(float posy) = 0;
        virtual inline void setPosZ(float posz) = 0;
        virtual inline void setSpeed(float speed) = 0;
        virtual bool isAlive() = 0;

    };
}; // namespace indie

#endif /* !IPLAYER_HPP_ */