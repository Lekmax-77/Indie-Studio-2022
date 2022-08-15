/*
** EPITECH PROJECT, 2022
** indiestudio
** File description:
** Biome
*/

#ifndef BIOME_HPP_
#define BIOME_HPP_

#include "Color.hpp"
#include <string>
#include <utility>
#include <fstream>
#include <vector>

namespace indie
{
    namespace map
    {

        class Block {
        public:
            // Constructor

            /**
             * @brief Construct a new Block object
             *
             * @param path_obj : path to the obj file
             * @param texture : path to the texture file
             */
            Block(std::string const path_obj, std::string texture) : _path_obj(path_obj), _texture(texture) {};

            // Destructor
            /**
             * @brief Destroy the Block object
             */
            ~Block() {};

            // Getters
            /**
             * @brief Get the Path to .obj of the Block
             *
             * @return std::string
             */
            inline std::string getPathObj() const { return _path_obj; };
            /**
             * @brief Get the Path to the texture file of the Block
             *
             * @return std::string
             */
            inline std::string getTexture() const { return _texture; };

            // Setters
            /**
             * @brief Set the Path to .obj of the Block
             *
             * @param path_obj : path to the obj file
             */
            inline void setPathObj(std::string path_obj) { _path_obj = path_obj; };
            /**
             * @brief Set the Path to the texture file of the Block
             *
             * @param texture : path to the texture file
             */
            inline void setTexture(std::string texture) { _texture = texture; };

            bool operator==(const Block &other) const{
               return (_path_obj == other.getPathObj() && _texture == other.getTexture());
            }
        private:
            std::string _path_obj;
            std::string _texture;
        };

        //classic
        const Block base_ground("../ressources/Assets/OBJ/stone06.obj", "../ressources/Assets/Textures/stone06.png");
        const Block base_wall("../ressources/Assets/OBJ/stone05.obj", "../ressources/Assets/Textures/stone05.png");
        const Block base_brick("../ressources/Assets/OBJ/wallBrick01.obj", "../ressources/Assets/Textures/wallBrick01.png");

        //ice
        const Block ice_ground("../ressources/Assets/OBJ/groundSnow.obj", "../ressources/Assets/Textures/ice01.png");
        const Block ice_wall("../ressources/Assets/OBJ/ice01.obj", "../ressources/Assets/Textures/wallBrick04.png");
        const Block ice_brick("../ressources/Assets/OBJ/snow.obj", "../ressources/Assets/Textures/snow.png");

        //lava
        const Block lava_ground("../ressources/Assets/OBJ/stone07.obj", "../ressources/Assets/Textures/stone07.png");
        const Block lava_wall("../ressources/Assets/OBJ/lava01.obj", "../ressources/Assets/Textures/lava01.png");
        const Block lava_brick("../ressources/Assets/OBJ/groundMud.obj", "../ressources/Assets/Textures/groundMud.png");

        //desert
        const Block desert_ground("../ressources/Assets/OBJ/groundMud.obj", "../ressources/Assets/Textures/groundMud.png");
        const Block desert_wall("../ressources/Assets/OBJ/groundMud.obj", "../ressources/Assets/Textures/groundMud.png");
        const Block desert_brick("../ressources/Assets/OBJ/wallBrick02.obj", "../ressources/Assets/Textures/wallBrick02.png");

        //end
        const Block end_ground("../ressources/Assets/OBJ/stone01.obj", "../ressources/Assets/Textures/stone01.png");
        const Block end_wall("../ressources/Assets/OBJ/stone07.obj", "../ressources/Assets/Textures/stone07.png");
        const Block end_brick("../ressources/Assets/OBJ/wallBrick05.obj", "../ressources/Assets/Textures/wallBrick05.png");

        class Biome
        {
        public:
            // Constructor
            /**
             * @brief Construct a new Biome object
             *
             * @param groundblock : Block of the ground
             * @param wallblock : Block of the wall
             * @param brickblock : Block of the brick
             * @param background : Background of the biome
             */
            Biome(Block groundblock = base_ground, Block wallblock = base_wall, Block brickblock = base_brick, ray::Color background = ray::Color::White(), ray::Color textColor = ray::Color::Red())
                : _pathGround(groundblock), _pathWall(wallblock), _pathBrick(brickblock), _background(background), _textColor(textColor){};
            /**
             * @brief Copy Construct a new Biome object
             *
             * @param biome : copy of the biome
             */
            Biome(const Biome &biome) : _pathGround(biome._pathGround), _pathWall(biome._pathWall), _pathBrick(biome._pathBrick), _background(biome._background), _textColor(biome._textColor) {};

            // Destructor
            /**
             * @brief Destroy the Biome object
             */
            ~Biome(){};

            // Getters
            /**
             * @brief Get the path to the ground block
             *
             * @return Block
             */
            inline Block getPathGround() const { return _pathGround; }
            /**
             * @brief Get the path to the wall block
             *
             * @return Block
             */
            inline Block getPathWall() const { return _pathWall; }
            /**
             * @brief Get the path to the brick block
             *
             * @return Block
             */
            inline Block getPathBrick() const { return _pathBrick; }
            /**
             * @brief Get the path to the background
             *
             * @return std::string
             */
            inline ray::Color getBackground() const { return _background; }

            /**
            * @brief Get the text color of the Biome object
            * 
            * @return ray::Color 
            **/
            inline ray::Color getTextColor() const { return _textColor; }


            // Setters
            /**
             * @brief Set the path to the ground block
             *
             * @param pathGround : path to the ground block
             */
            inline void setPathGround(Block path) { _pathGround = path; }
            /**
             * @brief Set the path to the wall block
             *
             * @param pathWall : path to the wall block
             */
            inline void setPathBrick(Block path) { _pathBrick = path; }
            /**
             * @brief Set the path to the brick block
             *
             * @param pathBrick : path to the brick block
             */
            inline void setPathWall(Block path) { _pathWall = path; }
            /**
             * @brief Set the path to the background
             *
             * @param pathBackground : path to the background
             */
            inline void setPathBackground(ray::Color path) { _background = path; }
            /**
            * @brief Set the text color of the Biome object
            * 
            * @param textColor 
            **/
            inline void setTextColor(ray::Color textColor) { _textColor = textColor; }


            // Operators
            /**
             * @brief Copy assignment operator
             *
             * @param biome : biome to copy
             * @return Biome&
             */
            Biome &operator=(const Biome &biome)
            {
                _pathGround = biome._pathGround;
                _pathWall = biome._pathWall;
                _pathBrick = biome._pathBrick;
                _background = biome._background;
                _textColor = biome._textColor;
                return *this;
            }

            bool operator==(const Biome &other) const{
               return (_pathGround == other.getPathGround() && _pathWall == other.getPathWall() && _pathBrick == other.getPathBrick());
            }

        protected:
        private:
            Block _pathGround;
            Block _pathWall;
            Block _pathBrick;
            ray::Color _background;
            ray::Color _textColor;
        };

        const Biome classic(base_ground, base_wall, base_brick, SKYBLUE, GOLD);
        const Biome lava(lava_ground, lava_wall, lava_brick, ORANGE, BLUE);
        const Biome ice(ice_ground, ice_wall, ice_brick, SKYBLUE, DARKGRAY);
        const Biome end(end_ground, end_wall, end_brick, DARKPURPLE, PINK);
        const Biome desert(desert_ground, desert_ground, desert_brick, GOLD, DARKPURPLE);
    }
}

#endif /* !BIOME_HPP_ */
