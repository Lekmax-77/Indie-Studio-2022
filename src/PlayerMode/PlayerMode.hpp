/*
** EPITECH PROJECT, 2022
** indie-studio
** File description:
** PlayerMode
*/

#ifndef PLAYERMODE_HPP_
    #define PLAYERMODE_HPP_
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
    #include "SpriteEngine.hpp"
    #include "SliderBar.hpp"
    #include "../game_engine/Core.hpp"


namespace indie {
    
    class PlayerMode : public indie::IScene
    {
    public:
        PlayerMode();
        ~PlayerMode();
        PlayerMode(PlayerMode &) = delete;
        void draw();
        void Update();
        void initSprite();
        void initRect();
        void initText();
        indie::SCENE_ENUM run(Settings &set);
    protected:
        engine::ButtonTristate _quit;
        engine::Sprite _background;
        Clock _clock;
        ray::KeyEvents _key;
        engine::Scene _scene;
        engine::ButtonTexture _solo;
        engine::ButtonTexture _duo;
        engine::ButtonTexture _trio;
        engine::ButtonTexture _quad;
        ray::Text _mode;
        ray::Text _text_solo;
        ray::Text _text_duo;
        ray::Text _text_trio;
        ray::Text _text_quad;
    private:
    };
}


#endif /* !PLAYERMODE_HPP_ */
