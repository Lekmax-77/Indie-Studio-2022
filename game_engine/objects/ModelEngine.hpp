/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-zacharie.lawson
** File description:
** ModelEngine
*/

#ifndef MODELENGINE_HPP_
#define MODELENGINE_HPP_

#include "Vector/Vector3.hpp"
#include "Model.hpp"
#include "ModelAnimation.hpp"

namespace engine {
    class Model {
    public:
        Model() {
            _color = ray::Color::White();
        }
        Model(const Model &src) {
            *this = src;
        };
        ~Model() {}
        Model &operator=(const Model &src) {
            _model = src._model;
            _pos = src._pos;
            _rotationAngle = src._rotationAngle;
            _rotationAxis = src._rotationAxis;
            _scale = src._scale;
            _texture = src._texture;
            return *this;
        }

    // getters
        inline ray::Vector3 getPosition() { return _pos; }
        inline ray::Vector3 getRotationAxis() { return _rotationAxis; }
        inline float getRotationAngle() { return _rotationAngle; }
        inline ray::Vector3 getScale() { return _scale; }
        inline ray::_3D::Model getModel() { return _model; }
        inline ray::Color getColor() { return _color; }

    // setters
        inline void setModel(::Model model) { _model = model; }
        inline void setPosition(ray::Vector3 pos) { _pos = pos; }
        inline void setRotationAxis(ray::Vector3 rotationAxis) { _rotationAxis = rotationAxis; }
        inline void setRotationAngle(float rotationAngle) { _rotationAngle = rotationAngle; }
        inline void setScale(ray::Vector3 scale) { _scale = scale; }
        inline void setTexture(const std::string &texture) { _texture = ray::Texture(texture); _model.setTexture(_texture); }
        inline void setColor(ray::Color color) { _color = color; }

    // methods
        inline void draw() {_model.draw(_pos, _scale, _color, _rotationAngle, _rotationAxis);};
        inline void move(ray::Vector3 move) {_pos += move;};
    private:
        ray::_3D::Model _model;
        ray::Vector3 _pos;
        ray::Vector3 _rotationAxis;
        float _rotationAngle;
        ray::Vector3 _scale;
        ray::Texture _texture;
        ray::Color _color;
    }; // class Model
}; // namespace engine

#endif /* !MODELENGINE_HPP_ */
