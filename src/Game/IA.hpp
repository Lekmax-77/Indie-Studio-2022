/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-zacharie.lawson
** File description:
** IA
*/

#ifndef IA_HPP_
#define IA_HPP_

#include "Player.hpp"

namespace indie {
    class IA : public Player {
    public:
        IA(float posx = 0, float posy = 0, float posz = 0, float speed = 10);
        ~IA() = default;
        IA &operator=(const IA &src);

    // getters

    // setters

    // methods
        void moveUpdate(ray::KeyEvents key, map::Map _map);
        void updateBomb(ray::KeyEvents key, map::Map &_map, std::vector<Fire> &);
    private:
        int _moveDir;
        int _moveDelay;
    }; // class IA
}; // namespace indie

#endif /* !IA_HPP_ */