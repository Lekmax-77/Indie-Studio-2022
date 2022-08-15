/*
** EPITECH PROJECT, 2022
** indie
** File description:
** cinematic
*/

#ifndef MENU_HPP_
    #define MENU_HPP_
    #include "../encapsulation/Window/Window.hpp"
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
    #include "SpriteEngine.hpp"
    #include "../game_engine/Core.hpp"

namespace indie {
    
    class Menu : public indie::IScene
    {
        public:
            /* LOAD MODELS */
            Menu();
            /* UNLOAD */
            ~Menu();
            Menu(Menu &)  = delete;
            void draw();
            void UpdateButton();
            void initSprite();
            void initText();
            indie::SCENE_ENUM run(Settings &set) override;

        private:    
            engine::Sprite _title;
            engine::ButtonTristate _quit;
            engine::ButtonTristate _setting;
            engine::ButtonTexture _play;
            engine::Sprite _background;
            ray::KeyEvents _key;
            ray::Font _font;
            engine::Scene _scene;
    };
}

#endif /* !CINEMATIC_HPP_ */
