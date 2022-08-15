/*
** EPITECH PROJECT, 2022
** indie
** File description:
** cinematic
*/

#ifndef CINEMATIC_HPP_
#define CINEMATIC_HPP_
#include "../encapsulation/Camera/Camera.hpp"
#include "Window.hpp"
#include "clock.hpp"
#include "Model.hpp"
#include "Texture.hpp"
#include "ModelAnimation.hpp"
#include "raylib.h"
#include "IEvents.hpp"
#include "Texture.hpp"
#include "TimeRelated.hpp"
#include "Text.hpp"
#include "Scene.hpp"
#include "../game_engine/Core.hpp"

namespace indie {
    class Cinematic : public indie::IScene
    {
        public:
            /* LOAD MODELS */
            Cinematic();
            /* UNLOAD */
            ~Cinematic();
            Cinematic(Cinematic &)  = delete;
            void draw();
            void updateAnimation();
            void updatePlayerPosition();
            void updateBombPosition();
            void updateFirePosition();
            void updateTextPosition();
            void initBomb();
            void initFire();
            void initPlayer();
            void initText();
            SCENE_ENUM run(Settings &set);

        private:
            // Camera3D _cam;
            int _animFrameCounter;
            Clock _clock;
            /* Player */
            ray::Vector3 _playerPos;
            float _playerRotate;
            engine::Model _bomberman;
            std::vector<ray::_3D::ModelAnimation> _animsBomberman;
            unsigned int _animsCountBomberman;
            ray::Texture _textureBomberman;
            bool _change;
            /* Bomb */
            ray::Vector3 _bombPos;
            engine::Model _bomb;
            unsigned int _animsCountBomb;
            ray::Texture _textureBomb;
            /* Fire */
            ray::Vector3 _firePos;
            engine::Model _fire;
            unsigned int _animsCountFire;
            std::vector<ray::_3D::ModelAnimation> _animsFire;
            ray::Texture _fireTexture;
            /* Display */
            float _speed;
            bool _displayFire;
            bool _displayTitle;

            ray::Camera3D _camera;
            ray::KeyEvents _key;

            ray::Font _font;
            engine::Text _text;

            engine::Scene _scene;

            engine::Sound _steps;

            float _soundDelay;

            ray::Texture _title;
    };
}

#endif /* !CINEMATIC_HPP_ */
