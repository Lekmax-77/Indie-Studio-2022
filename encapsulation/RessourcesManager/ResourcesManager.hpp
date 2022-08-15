/*
** EPITECH PROJECT, 2022
** indie-studio
** File description:
** ResourcesManager
*/

#ifndef RESOURCESMANAGER_HPP_
    #define RESOURCESMANAGER_HPP_
    #include <string>
    #include <functional>
    #include <map>
    #include <vector>

#include "Texture.hpp"
#include "Picture.hpp"
#include "Model.hpp"
#include <raylib.h>

namespace ray {
    class ResourcesManager {
    public:
        /**
         * @brief Construct a new Resources Manager object
         * 
         */
        ResourcesManager();
        /**
         * @brief Destroy the Resources Manager object
         * 
         */
        ~ResourcesManager();
        /**
         * @brief Load a Texture once time for optimisation
         * 
         * @param path string to filepath for the texture
         * @return Texture2D& 
         */
        Texture2D &LoadTextures(const std::string &path);
        /**
         * @brief Load a Image once time for optimisation
         * 
         * @param path string to filepath for the picture
         * @return Image& 
         */
        Image &LoadPictures(const std::string &path);
        /**
         * @brief Load a Modzl once time for optimisation
         * 
         * @param path string to filepath for the model
         * @return Model& 
         */
        Model &LoadModels(const std::string &path);

    protected:
        std::map<const std::string, Texture2D> _texture;
        std::map<const std::string, Image> _picture;
        std::map<std::string, Model> _model;
    private:
    };

    static ResourcesManager rManager;
}

#endif /* !RESOURCESMANAGER_HPP_ */
