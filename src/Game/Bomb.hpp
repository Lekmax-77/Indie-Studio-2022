/*
** EPITECH PROJECT, 2022
** explosion.hpp
** File description:
** explosion
*/

#ifndef _EXPLOSION_HPP_
#define _EXPLOSION_HPP_

#include <string>
#include <vector>
#include "Map.hpp"
#include "Model.hpp"
#include "Texture.hpp"
#include "Vector3.hpp"
#include "Direction.hpp"
#include "Map.hpp"
#include "Fire.hpp"

namespace indie {
    class Bomb {
    public:
        /**
        * @brief explosion constructor
        * @param power : size of the default explosion
        */
        explicit Bomb();
        ~Bomb() = default;

        void throwBomb(float x, float y, float z);
        void setPower(int power);
        [[nodiscard]] bool getDrawBomb();
        inline void drawBomb() { _bombModel.draw(_pos, {3, 3, 3}); };
        inline bool isReady() { return _isReady; };
        void update(map::Map &_map, std::vector<Fire> &_fires);
        void explode(map::Map &map, std::vector<Fire> &_fires);

    private:
        int _size;
        bool _draw;

        double _time;
        ray::Vector3 _pos;
        ray::_3D::Model _bombModel;
        ray::Texture _bombTexture;
        ray::_3D::Model _explosionModel;
        ray::Texture _explosionTexture;

        bool _isReady;

        void explodeDir(map::Map &map, ray::Vector2 pos, ray::Vector2 dir, int power, std::vector<Fire> &_fires);

    };
};


#endif /* _EXPLOSION_HPP_ */
