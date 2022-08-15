/*
** EPITECH PROJECT, 2022
** indiestudio
** File description:
** IndieStudio
*/

#ifndef INDIESTUDIO_HPP_
#define INDIESTUDIO_HPP_

#include <raylib.h>
#include <unordered_map>
#include <vector>
#include <algorithm>

#include "Map.hpp"
#include "Biome.hpp"
#include "Player.hpp"
#include "End.hpp"
#include "TimeRelated.hpp"
#include "Model.hpp"
#include "Window.hpp"
#include "Core.hpp"
#include "ButtonEngine.hpp"
#include "IEvents.hpp"
#include "Tools.hpp"
#include "Text.hpp"
#include "Font.hpp"
#include "Vector3.hpp"
#include "Texture.hpp"
#include "Exception.hpp"
#include "IA.hpp"
#include "Fire.hpp"
#include "Core.hpp"

namespace indie
{

    class IndieStudio : public IScene {
    public:
        IndieStudio();
        ~IndieStudio();

        SCENE_ENUM run(Settings &set);

        void initPlayers(Settings &set);

        void handle_events(Settings &set);
        void run();
        void createMap();
        void loadBiome();
        void startCamera();
        void switchCameraMode();
        void destroyMap();
        void displayMap();
        void displayEnd(std::vector<IPlayer*> entities, Settings &set);
        void save(Settings &set);
        void loadSave(Settings &set);

    protected:
    private:
        map::Map _map;
        map::Biome _biome;
        game::End _end;
        ray::Camera3D _cam;
        std::unordered_map<std::string, ray::_3D::Model> _models;

        std::vector<Player> _players;
        std::vector<IA> _ia;
        std::vector<IPlayer*> _entity;
        bool _closeview;
        ray::KeyEvents _key;
        std::vector<indie::Fire> _fires;
        engine::ButtonTristate _setting;
    };

} // namespace indie

#endif /* !INDIESTUDIO_HPP_ */
