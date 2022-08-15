/*
** EPITECH PROJECT, 2022
** indie-studio
** File description:
** Setting
*/

#ifndef SETTING_HPP_
    #define SETTING_HPP_
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
    
    class Setting : public indie::IScene
    {
    public:
        Setting();
        ~Setting();
        Setting(Setting &) = delete;
        void draw();
        void Update();
        void initSprite();
        void initRect();
        void initText();
        indie::SCENE_ENUM run(Settings &set);
    protected:
        ray::_2D::Rectangles _table;
        ray::_2D::Rectangles _tables;
        engine::ButtonTristate _quit;
        engine::Sprite _background;
        ray::TimeRelated time;
        int _animFrameCounter;
        ray::Text _text_setting;
        Clock _clock;
        ray::KeyEvents _key;
        engine::Scene _scene;
        ray::SliderBar _bar_fps;
        ray::SliderBar _bar_sound;
        ray::SliderBar _bar_music;
    private:
    };
}
#endif /* !SETTING_HPP_ */
