/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-zacharie.lawson
** File description:
** End
*/

#ifndef END_HPP_
#define END_HPP_

#include "raylib.h"
#include "Biome.hpp"
#include "Color.hpp"
#include "Vector2.hpp"
#include "Texture.hpp"
#include "Player.hpp"
#include "Tools.hpp"
#include <string>
#include <vector>
#include <iostream>

namespace indie
{
    namespace game
    {

        class End
        {
        public:
            End();
            ~End();

            void init(std::vector<IPlayer*> entities, indie::map::Biome biome);
            void draw();

        private:
            ray::Texture _screenshot;
            ray::Vector2 _screenshotPos;
            ray::Texture _panel;
            ray::Vector2 _panelPos;

            ray::Texture _trophyGold;
            ray::Vector2 _trophyGoldPos;
            ray::Texture _trophySilver;
            ray::Vector2 _trophySilverPos;
            ray::Texture _trophyBronze;
            ray::Vector2 _trophyBronzePos;

            indie::map::Biome _biome;

            ray::Texture _profilePicture;
            std::vector<IPlayer*> _entities;
            std::vector<int> _scores;
            unsigned long int _nbEntities;
            ray::Vector2 _firstPlayerPos;
            ray::Vector2 _secondPlayerPos;
            ray::Vector2 _thirdPlayerPos;
            ray::Vector2 _fourthPlayerPos;  
        };
    }
}

#endif /* !END_HPP_ */
