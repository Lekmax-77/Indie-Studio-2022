/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-zacharie.lawson
** File description:
** Music
*/

#ifndef MUSIC_HPP_
#define MUSIC_HPP_

#include <IAudio.hpp>

namespace ray {
    class Music : virtual public IAudio {
    public:

        /**
        * @brief Construct a new Music object
        *
        * @param fileName
        **/
        Music() : _music{} {}
        Music(std::string const &fileName);

        Music(Music &&other) {
            _music = other._music;
            other._music = {};

            std::swap(_volume, other._volume);
            std::swap(_pitch, other._pitch);
            other.isMoved = true;
        }
        Music &operator=(Music &&other) {
            _music = other._music;
            other._music = {};
            _volume = 0;
            _pitch = 0;
            std::swap(_volume, other._volume);
            std::swap(_pitch, other._pitch);
            other.isMoved = true;
            return *this;
        }

        /**
        * @brief Destroy the Music object
        *
        **/
        ~Music();

        /**
        * @brief Play the Music object
        * 
        **/
        inline void play() override { PlayMusicStream(_music); }

        inline void update() { UpdateMusicStream(_music); }
        /**
        * @brief Stop the Music object
        * 
        **/
        inline void stop() override { StopMusicStream(_music); }

        /**
        * @brief Pause the Music object
        * 
        **/
        inline void pause() override { PauseMusicStream(_music); }

        /**
        * @brief Resume the Music object
        * 
        **/
        inline void resume() override { ResumeMusicStream(_music); }
        
        /**
        * @brief Set the Music object volume
        * 
        * @param volume 
        **/
        void setVolume(float volume) override;

        /**
        * @brief Get the Music object volume
        * 
        * @return float 
        **/
        inline float getVolume() override { return _volume; };

        /**
        * @brief Set the Music object pitch
        * 
        * @param pitch 
        **/
        void setPitch(float pitch) override;

        /**
        * @brief Get the Music object pitch
        * 
        * @return float 
        **/
        inline float getPitch() override { return _pitch; };
        
        /**
        * @brief Set the Music object loop condition
        * 
        * @param loop 
        **/
        inline void setLoop(bool loop) { _music.looping = loop; }

    private:
        ::Music _music;
        float _volume;
        float _pitch = 0.0f;
        bool isMoved = false;
    };
}

#endif /* !MUSIC_HPP_ */
