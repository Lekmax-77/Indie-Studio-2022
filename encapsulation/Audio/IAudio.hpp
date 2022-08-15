/*
** EPITECH PROJECT, 2021
** IAudio
** File description:
** IAudio
*/

#ifndef _IAUDIO_HPP_
#define _IAUDIO_HPP_

#include <raylib.h>
#include <string>

namespace ray {

    class IAudio {
    public:
        virtual ~IAudio() = default;

        virtual void play() = 0;
        virtual void stop() = 0;
        virtual void pause() = 0;
        virtual void resume() = 0;
        
        virtual void setVolume(float volume) = 0;
        virtual float getVolume() = 0;
        virtual void setPitch(float pitch) = 0;
        virtual float getPitch() = 0;
    };

}

#endif //_IAUDIO_HPP_
