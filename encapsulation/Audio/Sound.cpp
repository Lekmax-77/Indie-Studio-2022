/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-zacharie.lawson
** File description:
** Sound
*/

#include "Sound.hpp"

ray::Sound::Sound(std::string const &fileName)
{
    _sound = LoadSound(fileName.c_str());
}

ray::Sound::~Sound()
{
    if (!isMoved)
        UnloadSound(_sound);
}

void ray::Sound::setVolume(float volume)
{
    _volume = volume;
    SetSoundVolume(_sound, _volume);
}

void ray::Sound::setPitch(float pitch)
{
    _pitch = pitch;
    SetSoundPitch(_sound, _pitch);
}
