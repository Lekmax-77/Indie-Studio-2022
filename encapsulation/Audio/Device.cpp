/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-zacharie.lawson
** File description:
** Device
*/

#include "Device.hpp"

ray::Device::Device()
{
    InitAudioDevice();
}

ray::Device::~Device()
{
    CloseAudioDevice();
}

void ray::Device::setMasterVolume(float volume)
{
    _masterVolume = volume;
    SetMasterVolume(_masterVolume);
}

float ray::Device::getMasterVolume()
{
    return _masterVolume;
}