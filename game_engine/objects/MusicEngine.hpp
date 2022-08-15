/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-zacharie.lawson
** File description:
** MusicEngine
*/

#ifndef MUSICENGINE_HPP_
#define MUSICENGINE_HPP_

#include "Music.hpp"

namespace engine {
    class Music {
    public:
        Music() : _music() {};
        Music(Music &&other) = default;
        ~Music() = default;
        Music &operator=(Music &&other) = default;
    // getters
        inline float getVolume() { return _music.getVolume(); };
    // // setters
        inline void setLoop(float loop) { _music.setLoop(loop); }
        inline void setMusic(ray::Music &music) { _music = std::move(music); }
        inline void setVolume(float volume) { _music.setVolume(volume); }
        inline void setPitch(float pitch) { _music.setPitch(pitch); }
    // methods
        inline void play() { _music.play(); };
        inline void stop() { _music.stop(); };
        inline void pause() { _music.pause(); };
        inline void resume() { _music.resume(); };
        inline void update() { _music.update(); };
    private:
        ray::Music _music;
    }; // class Music
}; // namespace engine

#endif /* !MUSICENGINE_HPP_ */
