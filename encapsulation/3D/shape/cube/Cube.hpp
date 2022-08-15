/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-zacharie.lawson
** File description:
** Cube
*/

#ifndef CUBE_HPP_
#define CUBE_HPP_

#include <raylib.h>
#include "IDrawable.hpp"
#include "Color.hpp"
#include "Vector3.hpp"

namespace ray {
    namespace _3D {
        namespace shape {
            class Cube : public IDrawable {
            public:
                /***
                 * @brief Construct a new Cube object
                 * @param pos the position of the cube
                 * @param size the size of the cube
                 * @param color the color of the cube, default is black
                 */
                Cube(Vector3 pos, Vector3 size, Color color = Color::Black());
                /***
                 * @brief Construct a new Cube object with a whole texture
                 * @param pos the position of the cube
                 * @param size the size of the cube
                 * @param texture the texture of the cube
                 * @param color the color of the cube, default is black
                 */
                Cube(Vector3 pos, Vector3 size, Texture2D texture, Color color = Color::White());
                /***
                 * @brief Construct a new Cube object with a part of a texture
                 * @param pos the position of the cube
                 * @param size the size of the cube
                 * @param texture the texture of the cube
                 * @param textureRect the part of the texture to use
                 * @param color the color of the cube, default is black
                 */
                Cube(Vector3 pos, Vector3 size, Texture2D texture, Rectangle textureRect, Color color = Color::White());
                /***
                 * @brief Construct a new Cube object from another Cube
                 * @param src the Cube to copy
                 */
                Cube(const Cube &src);
                /***
                 * @brief Destroy the Cube object
                 */
                ~Cube();

                /***
                 * @brief Copy the Cube object
                 * @param src the Cube to copy
                 * @return the copied Cube
                 */
                Cube &operator=(const Cube &src);

                // getters
                /***
                 * @brief return the position of the cube
                 * @return the position of the cube
                 */
                Vector3 getPosition() const;
                /***
                 * @brief return the size of the cube
                 * @return the size of the cube
                 */
                Vector3 getSize() const;
                /***
                 * @brief return the color of the cube
                 * @return the color of the cube
                 */
                Texture2D getTexture() const;
                /***
                 * @brief return the texture rectangle of the cube
                 * @return the texture rectangle of the cube
                 */
                Rectangle getTextureRect() const;
                /***
                 * @brief return the color of the cube
                 * @return the color of the cube
                 */
                Color getColor() const;
                /***
                 * @brief check if the cube is textured
                 * @return true if the cube is textured, false otherwise
                 */
                bool hasTexture() const;

                // setters
                /***
                 * @brief set the position of the cube
                 * @param pos the position of the cube
                 */
                void setPosition(Vector3 pos);
                /***
                 * @brief set the size of the cube
                 * @param size the size of the cube
                 */
                void setSize(Vector3 size);
                /***
                 * @brief set the texture of the cube
                 * @param texture the texture of the cube
                 */
                void setTexture(Texture2D texture, bool updateRect = true);
                /***
                 * @brief set the texture rectangle of the cube
                 * @param textureRect the texture rectangle of the cube
                 */
                void setTextureRect(Rectangle textureRect);
                /***
                 * @brief set the color of the cube
                 * @param color the color of the cube
                 */
                void setColor(Color color);
                /***
                 * @brief change the texture mode of the cube, if true the cube will use the texture, if false the cube will use the color
                 * @param mode the texture mode of the cube
                 */
                bool setTextureMode(bool mode);

                // methods
                /***
                 * @brief draw the cube
                 */
                void draw() const;

            private:
                Vector3 _pos;
                Vector3 _size;
                Color _color;
                Texture2D _texture;
                Rectangle _textureRect;
                bool _hasTexture;
            };
        }
    }
}

#endif /* !CUBE_HPP_ */
