/*
** EPITECH PROJECT, 2022
** indie-studio
** File description:
** Core
*/

#ifndef CORE_HPP_
    #define CORE_HPP_
    #include <vector>
    #include <string>
    #include <map>
    #include <memory>
    #include <tuple>
    #include "Window.hpp"

namespace indie
{
    enum SCENE_ENUM : int {
        CINEMATIC,
        MENU,
        SETTING,
        MODE_SELECT,
        HOW_TO_PLAY,
        GO_TO_EXIT,
        GAME,
        PAUSE,
        WIN,
        END
    };
    class Settings
    {
        public:
            inline Settings(size_t width, size_t height, const std::string &title):_window(width, height, title), _volume_music(50), _volume_sound(50), _n_player(1) {}
            inline ray::Window &GetWindow() { return _window; }
            inline void SetWindow(ray::Window &window) { _window = window; }
            inline void setMusic(float music) { _volume_music = music; }
            inline float getMusic() { return _volume_music; }
            inline void setSound(float sound) { _volume_sound = sound; }
            inline float getSound() { return _volume_sound; }
            inline void setPlayer(int player) { _n_player = player; }
            inline int &getPlayer() { return _n_player; }
            inline void setScene(SCENE_ENUM scene) { _prev_scene = scene; }
            inline SCENE_ENUM &getScene() { return _prev_scene; }
            ~Settings() = default;
        private:
            ray::Window _window;
            float _volume_music;
            float _volume_sound;
            int _n_player;
            SCENE_ENUM _prev_scene;
    };

    class IScene
    {
        public:
            virtual ~IScene() = default;
            virtual indie::SCENE_ENUM run(Settings &set) = 0;
    };

    class Core {
        public:
            Core();
            ~Core() = default;
            inline SCENE_ENUM GetCurrentScene() const { return _current_scene; }
            inline void SetScene(SCENE_ENUM scene) { _current_scene = scene; }
            inline std::map<SCENE_ENUM, std::shared_ptr<IScene>> &GetScenes() { return _scenes; }
            inline void SetPreviousScene(SCENE_ENUM scene) { _prev_scene = scene; }
            inline SCENE_ENUM GetPreviousScene() const { return _prev_scene; }
        protected:
            std::map<SCENE_ENUM, std::shared_ptr<IScene>> _scenes;
            SCENE_ENUM _current_scene;
            SCENE_ENUM _prev_scene;
        private:
    };

} // namespace name




#endif /* !CORE_HPP_ */
