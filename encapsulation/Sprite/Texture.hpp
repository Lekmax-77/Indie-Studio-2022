/*
** EPITECH PROJECT, 2022
** indie-studio
** File description:
** Texture
*/

#ifndef TEXTURE_HPP_
    #define TEXTURE_HPP_
    #include <string>
    #include <raylib.h>
    #include "Vector/Vector2.hpp"
    #include "Color.hpp"
    #include "Picture.hpp"

namespace ray
{
    class Texture : public ::Texture {
        public:
            /**
             * @brief Construct a new Texture object
             */
            Texture();
            /**
             * @brief Construct a new Texture object
             * @details Load texture from file into GPU memory (VRAM)
             *
             * @param filename filepath to file to load
             */
            Texture(const std::string &filename);
            /**
             * @brief Destroy the Texture object
             * @details Unload texture from GPU memory (VRAM)
             *
             */
            ~Texture();
            Texture(const Texture &src);
            Texture &operator=(const Texture &texture);
            Texture &operator=(const ::Texture2D &texture);
            /**
             * @brief Get the Position object
             * @return Vector2 position of texture
             */
            Vector2 GetPosition() const;
            /**
             * @brief Set the Position object
             * @details Set position of texture
             * @param position of type Vector2
             */
            void SetPosition(Vector2 position);
            /**
             * @brief Get the Scale object
             * @return float scale of texture
             * @details Get scale of texture
             */
            float GetScale() const;
            /**
             * @brief Set the Scale object
             * @details Set scale of texture
             * @param scale of type float
             */
            void SetScale(float scale);
            /**
             * @brief Get the Scale object
             * @return float scale of texture
             * @details Get scale of texture
             */
            float GetRotation() const;
            /**
             * @brief Set the Rotation object
             * @details Set rotation of texture
             * @param rotation of type float
             */
            void SetRotation(float rotation);
            /**
             * @brief Set the Color object
             * @details Set color of texture
             * @param color of type Color
             */
            void setColor(Color color);
            /**
             * @brief Get the Color object
             * @return Color color of texture
             * @details Get color of texture
             **/
            Color getColor() const;
            /**
             * @brief Get the Origin object
             * 
             * @return Vector2 
             */
            Vector2 GetOrigin() const;
            /**
             * @brief Set the Origin object
             * 
             * @param origin 
             */
            void SetOrigin(Vector2 origin);
            /**
             * @brief Get the Texture object
             * @return Texture2D texture
             * @details Get texture
             **/   
            Texture2D getTexture() const;
            /**
             * @brief Generate a Mipmap for the texture
             * 
             */
            void GenMipmapsTexture();
            /**
             * @brief Set the Filter Texture object
             * 
             * @param filter    of type int
             */
            void SetFilterTexture(int filter);
            /**
             * @brief Set the Wrap Texture object
             * 
             * @param wrap      of type int
             **/
            void SetWrapTexture(int wrap);
            /**
             * @brief Update the Texture object
             * 
             * @param pixels    of type void*
             */
            void Update(const void *pixels);
            /**
             * @brief Update GPU texture rectangle with new data
             * 
             * @param rec      of type Rectangle
             * @param pixels    of type void*
             */
            void UpdateRec(Rectangle rec, const void *pixels);
            /**
             * @brief Draw a Texture2D with extended parameters
             * 
             */
            void Draw();
            /**
             * @brief Draw a part of a texture defined by a rectangle
             * 
             * @param source    of type Rectangle
             */
            void DrawRec(Rectangle source);
            /**
             * @brief Draw texture quad with tiling and offset parameters
             * 
             * @param tiling    of type Vector2
             * @param offset    of type Vector2
             * @param quad      of type Rectangle
             */
            void DrawQuad(Vector2 tiling, Vector2 offset, Rectangle quad);
            /**
             * @brief Draw part of a texture
             * 
             * @param source    of type Rectangle
             * @param dest      of type Rectangle
             * @param origin    of type Vector2
             */
            void DrawTiled(Rectangle source, Rectangle dest, Vector2 origin);
            /**
             * @brief Draws a texture (or part of it) that stretch
             * 
             * @param nPatchInfo of type NPatchInfo
             * @param dest of type Rectangle
             * @param origin of type Vector2
             */
            void DrawNPatch(NPatchInfo nPatchInfo, Rectangle dest, Vector2 origin);
            /**
             * @brief Draw a textured polygon
             * 
             * @param center of type Vector2
             * @param points of type Vector2*
             * @param texcoords of type Vector2*
             * @param pointsCount of type int
             */
            void DrawPoly(Vector2 center, Vector2 *points, Vector2 *texcoords, int pointsCount);
        protected:
            /**
             * @brief Vector2 of position of texture
             **/
            /**
             * @brief Vector2 of position of texture
             **/
            Vector2 _position;
            /**
            * @brief float of scale of texture
             **/
            float _rotation;
            /**
             * @brief float of scale of texture
             **/
            Color _color;
            /**
             * @brief float of scale of texture
             **/
            float _scale;
            /**
             * @brief Vector2 of Origin of texture
             *
             */
            Vector2 _origin;
            inline void cpy(const ::Texture &texture) {
                id = texture.id;
                width = texture.width;
                height = texture.height;
                mipmaps = texture.mipmaps;
                format = texture.format;
            }
        private:
    };
};

#endif /* !TEXTURE_HPP_ */
