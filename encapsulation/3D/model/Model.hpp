/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-zacharie.lawson
** File description:
** Model
*/

#ifndef MODEL_HPP_
#define MODEL_HPP_

#include <raylib.h>
#include <string>
#include "IDrawable.hpp"
#include "Vector/Vector3.hpp"
#include "Color/Color.hpp"
#include "BoundingBox/BoundingBox.hpp"

using rayModel = Model;

namespace ray {
    namespace _3D {
        class Model : public ::Model {
            public:
                Model() {}
                Model(const ::Model &model);
                Model(const std::string &file);
                ~Model();
                Model(const Model &);

                Model &operator=(const ::Model &src);
                Model &operator=(const Model &);
                operator ::BoundingBox() const;
                void setTexture(const ::Texture &texture);
                void draw(
                    Vector3 position,
                    Vector3 scale = {1.0f, 1.0f, 1.0f},
                    Color color = Color::White(),
                    float rotationAngle = 0.0f,
                    Vector3 rotationAxis = {0.0f, 0.0f, 0.0f}
                ) const;
                ::BoundingBox getBoundingBox() const;
            private:
                void unload();
                void load(const std::string &file);
                void cpy(const ::Model &model);
                void move(Model&& other);
            }; // class Model
    }; // namespace _3D
}; // namespace ray

#endif /* !MODEL_HPP_ */
