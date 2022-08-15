/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-zacharie.lawson
** File description:
** Music
*/

#include "Music.hpp"

ray::Music::Music(std::string const &fileName)
{
    _music = LoadMusicStream(fileName.c_str());
}

ray::Music::~Music()
{
    if (!isMoved)
        UnloadMusicStream(_music);
}

void ray::Music::setVolume(float volume)
{
    _volume = volume;
    SetMusicVolume(_music, _volume);
}

void ray::Music::setPitch(float pitch)
{
    _pitch = pitch;
    SetMusicPitch(_music, _pitch);
}
