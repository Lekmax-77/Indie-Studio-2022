/*
** EPITECH PROJECT, 2022
** indie-studio
** File description:
** Shaders
*/

#ifndef SHADERS_HPP_
    #define SHADERS_HPP_
    #include <string>
    #include <raylib.h>

namespace ray
{
    class Shaders {
        public:
            /**
             * @brief Construct a new Shaders object
             * @details Load shader from files and bind default locations
             * @details Load shader from code strings and bind default locations
             * 
             * @param vsFileName 
             * @param fsFileName 
             */
            Shaders(std::string const &vsFileName, std::string const &fsFileName, bool FormMemory);
            /**
             * @brief Destroy the Shaders object
             * 
             */
            ~Shaders();
            /**
             * @brief Get the Location object
             * @details Get shader uniform location
             * @param uniformName 
             * @return int 
             */
            int GetLocation(std::string const &uniformName);
            /**
             * @brief Get the Location Attrib object
             * @details Get shader attribute location
             * @param attribName 
             * @return int 
             */
            int GetLocationAttrib(std::string const &attribName);
            /**
             * @brief Set the Value object
             * @details Set shader uniform value
             * @param locIndex 
             * @param value 
             * @param uniformType 
             */
            void SetValue(int locIndex, const void *value, int uniformType);
            /**
             * @brief Set the Value V object
             * @details Set shader uniform value vector
             * @param locIndex 
             * @param value 
             * @param uniformType 
             * @param count 
             */
            void SetValueV(int locIndex, const void *value, int uniformType, int count);
            /**
             * @brief Set the Value Matrix object
             * @details Set shader uniform value (matrix 4x4)
             * @param locIndex 
             * @param mat 
             */
            void SetValueMatrix(int locIndex, Matrix mat);
            /**
             * @brief Set the Value Texture object
             * @details Set shader uniform value for texture (sampler2d)
             * @param locIndex 
             * @param texture 
             */
            void SetValueTexture(int locIndex, Texture2D texture);
        private:
            /**
             * @brief Shader of the Shaders
             * 
             */
            Shader _shad;
    };
}

#endif /* !SHADERS_HPP_ */
