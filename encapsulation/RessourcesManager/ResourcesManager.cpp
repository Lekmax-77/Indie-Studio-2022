/*
** EPITECH PROJECT, 2022
** indie-studio
** File description:
** ResourcesManager
*/

#include "ResourcesManager.hpp"
#include <functional>
#include <raylib.h>
#include "Texture.hpp"
#include "Picture.hpp"
#include "Model.hpp"

ray::ResourcesManager::ResourcesManager()
{
    ;
}

ray::ResourcesManager::~ResourcesManager()
{
    std::map<std::string, Texture2D>::iterator p1;
    for(p1 = this->_texture.begin(); p1 != this->_texture.end(); p1++) {
        UnloadTexture(this->_texture[p1->first]);
    }

    std::map<std::string, Image>::iterator p2;
    for(p2 = this->_picture.begin(); p2 != this->_picture.end(); p2++) {
        UnloadImage(this->_picture[p2->first]);
    }

    std::map<std::string, Model>::iterator p3;
    for(p3 = this->_model.begin(); p3 != this->_model.end(); p3++) {
        UnloadModel(this->_model[p3->first]);
    }
}

Texture2D &ray::ResourcesManager::LoadTextures(const std::string &path)
{
    if (this->_texture.find(path) == this->_texture.end() || this->_texture.size() == 0) {
        this->_texture.insert(std::pair<std::string, Texture2D>(path, LoadTexture(path.c_str())));
    }
    return this->_texture[path];
}

Image &ray::ResourcesManager::LoadPictures(const std::string &path)
{
    if (this->_picture.find(path) == this->_picture.end() || this->_picture.size() == 0) {
        this->_picture.insert(std::pair<std::string, Image>(path, LoadImage(path.c_str())));
    }
    return this->_picture[path];
}

Model &ray::ResourcesManager::LoadModels(const std::string &path)
{
    if (this->_model.find(path) == this->_model.end() || this->_model.size() == 0) {
        this->_model.insert(std::pair<std::string, Model>(path, LoadModel(path.c_str())));
    }
    return this->_model[path];
}