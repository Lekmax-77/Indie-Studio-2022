/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-zacharie.lawson
** File description:
** Scene
*/

#ifndef SCENE_HPP_
#define SCENE_HPP_

#include <string>
#include <map>
#include <vector>
#include <iostream>
#include "raylib.h"

#include "objects/SpriteEngine.hpp"
#include "objects/ModelEngine.hpp"
#include "objects/MusicEngine.hpp"
#include "objects/SoundEngine.hpp"
#include "objects/ButtonEngine.hpp"
#include "objects/TextEngine.hpp"

namespace engine {
    // class Button {};
    // class Sound {};
    // class Music {};
    class Scene {
    public:
        Scene() {}
        Scene(const std::string &filepath);
        Scene(Scene &&other) = default;
        Scene &operator=(Scene &&src) = default;
        ~Scene() {}

    // getters
        inline Sprite &getSprite(const std::string &name) {
            if (!_sprites.contains(name))
                throw std::runtime_error("Sprite " + name + " not found");
            return _sprites[name];
        }
        inline Model &getModel(const std::string &name) {
            if (!_models.contains(name))
                throw std::runtime_error("Model " + name + " not found");
            return _models[name];
        }
        inline ButtonTristate &getButtonTristate(const std::string &name) {
            if (!_buttonstristates.contains(name))
                throw std::runtime_error("ButtonTristate " + name + " not found");
            return _buttonstristates[name];
        }
        inline ButtonTexture &getButtonTexture(const std::string &name) {
            if (!_buttonstextures.contains(name))
                throw std::runtime_error("ButtonTexture " + name + " not found");
            return _buttonstextures[name];
        }
        inline Sound &getSound(const std::string &name) {
            if (!_sounds.contains(name))
                throw std::runtime_error("Sound " + name + " not found");
            return _sounds[name];
        }
        inline Music &getMusic(const std::string &name) {
            if (!_musics.contains(name))
                throw std::runtime_error("Music " + name + " not found");
            return _musics[name];
        }
        inline Text &getText(const std::string &name) {
            if (!_texts.contains(name))
                throw std::runtime_error("Text " + name + " not found");
            return _texts[name];
        }
    // setters

    // methods

    private:
        std::map<std::string, Sprite> _sprites;
        std::map<std::string, Model> _models;
        std::map<std::string, ButtonTexture> _buttonstextures;
        std::map<std::string, ButtonTristate> _buttonstristates;
        std::map<std::string, Sound> _sounds;
        std::map<std::string, Music> _musics;
        std::map<std::string, Text> _texts;
    }; // class Scene
}; // namespace indie

#endif /* !SCENE_HPP_ */