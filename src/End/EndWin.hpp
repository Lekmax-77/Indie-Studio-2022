/*
** EPITECH PROJECT, 2022
** indie-studio
** File description:
** EndWin
*/

#ifndef EndWin_HPP_
    #define EndWin_HPP_
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
    
    class EndWin : public indie::IScene
    {
    public:
        EndWin();
        ~EndWin();
        EndWin(EndWin &) = delete;
        void draw();
        void Update();
        void initSprite();
        void initRect();
        void initText();
        indie::SCENE_ENUM run(Settings &set);
    protected:
        engine::ButtonTristate _quit;
        engine::Sprite _background;
        ray::KeyEvents _key;
        engine::Scene _scene;
    };
}


#endif /* !EndWin_HPP_ */
