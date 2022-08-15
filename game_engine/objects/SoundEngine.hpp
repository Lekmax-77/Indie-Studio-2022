/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-zacharie.lawson
** File description:
** SoundEngine
*/

#ifndef SOUNDENGINE_HPP_
#define SOUNDENGINE_HPP_

#include "Sound.hpp"

namespace engine {
    class Sound {
    public:
        Sound() : _sound("") {};
        Sound(Sound &&src) = default;
        ~Sound() {};
        Sound &operator=(Sound &&src) = default;
    // getters
        inline bool getIsPlaying() { return _sound.isPlaying(); };
        inline float getVolume() { return _sound.getVolume(); };
    // setters
        inline void setSound(ray::Sound &sound) { _sound = std::move(sound); };
        inline void setVolume(float volume) { _sound.setVolume(volume); };
    // methods
        inline void play() { _sound.play(); };
        inline void playMulti() { _sound.playMulti(); };
        inline void stop() { _sound.stop(); };
        inline void pause() { _sound.pause(); };
        inline void resume() { _sound.resume(); };

    private:
        ray::Sound _sound;
    }; // class Sound
}; // namespace engine

#endif /* !SOUNDENGINE_HPP_ */
