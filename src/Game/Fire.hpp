/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-zacharie.lawson
** File description:
** Fire
*/

#ifndef FIRE_HPP_
#define FIRE_HPP_

namespace indie {
    class Fire;
}

#include "Vector3.hpp"
#include "IPlayer.hpp"
#include "Cube.hpp"
#include <vector>

namespace indie {
    class Fire {
        public:
            Fire(ray::Vector3 pos);
            ~Fire() = default;
            void update(std::vector<IPlayer *> &players);
            void draw();
            inline bool isAlive() { return _isAlive; };
        private:
            ray::Vector3 _pos;
            double _time;
            bool _isAlive;
            ray::_3D::shape::Cube _cube;
    }; // class Fire
}; // namespace indie

#endif /* !FIRE_HPP_ */
