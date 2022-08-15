/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-zacharie.lawson
** File description:
** Device
*/

#ifndef DEVICE_HPP_
#define DEVICE_HPP_

#include <IAudio.hpp>

namespace ray {
    class Device {
    public:

        /**
        * @brief Construct a new Device object
        * 
        **/
        Device();

        /**
        * @brief Destroy the Device object
        * 
        **/
        ~Device();

        /**
        * @brief Set the Device object master volume
        * 
        * @param volume 
        **/
        void setMasterVolume(float volume);

        /**
        * @brief Get the Device object master volume
        * 
        * @return float 
        **/
        float getMasterVolume();
        
    private:
        float _masterVolume;
    };
}

#endif /* !DEVICE_HPP_ */
