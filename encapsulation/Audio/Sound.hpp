/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-zacharie.lawson
** File description:
** Sound
*/

#ifndef SOUND_HPP_
#define SOUND_HPP_

#include <IAudio.hpp>

namespace ray {
    class Sound : virtual public IAudio {
    public:

        /**
        * @brief Construct a new Sound object
        * 
        * @param fileName 
        **/
        Sound(std::string const &fileName);

        /**
        * @brief Destroy the Sound object
        * 
        **/
        ~Sound();

        Sound(Sound &&src) {
            _sound = src._sound;
            src._sound = {};

            std::swap(_volume, src._volume);
            std::swap(_pitch, src._pitch);
            src.isMoved = true;
        };
        Sound &operator=(Sound &&src) {
            _sound = src._sound;
            src._sound = {};
            _volume = 0;
            _pitch = 0;

            std::swap(_volume, src._volume);
            std::swap(_pitch, src._pitch);
            src.isMoved = true;
            return *this;
        };

        /**
        * @brief Play the Sound object
        * 
        **/
        inline void play() override { PlaySound(_sound); }

        /**
        * @brief Stop the Sound object
        * 
        **/
        inline void stop() override { StopSound(_sound); }

        /**
        * @brief Pause the Sound object
        * 
        **/
        inline void pause() override { PauseSound(_sound); }

        /**
        * @brief Resume the Sound object
        * 
        **/
        inline void resume() override { ResumeSound(_sound); }
        
        /**
        * @brief Set the Sound object volume
        * 
        * @param volume 
        **/
        void setVolume(float volume) override;

        /**
        * @brief Get the Sound object volume
        * 
        * @return float 
        **/
        inline float getVolume() override { return _volume; };

        /**
        * @brief Set the Sound object pitch
        * 
        * @param pitch 
        **/
        void setPitch(float pitch) override;

        /**
        * @brief Get the Sound object pitch
        * 
        * @return float 
        **/
        inline float getPitch() override { return _pitch; };

        /**
        * @brief Check if Sound object is playing
        * 
        * @return true 
        * @return false 
        **/
        inline bool isPlaying() { return IsSoundPlaying(_sound); }

        /**
        * @brief Play Sound object on multichannel mode
        * 
        **/
        inline void playMulti() { PlaySoundMulti(_sound); }

        /**
        * @brief Stop Sound object on multichannel mode
        * 
        **/
        inline void stopMulti() { StopSoundMulti(); }

        /**
        * @brief Get the count of Sound object currently playing
        * 
        * @return int 
        **/
        inline int getMultiCount() { return GetSoundsPlaying(); }
    
    private:
        ::Sound _sound;
        float _volume;
        float _pitch = 0.0f;
        bool isMoved = false;
    };
}

#endif /* !SOUND_HPP_ */
