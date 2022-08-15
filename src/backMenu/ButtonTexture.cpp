/*
** EPITECH PROJECT, 2022
** indie-studio
** File description:
** ButtonTexture
*/

#include "ButtonTristate.hpp"
#include <iostream>

indie::ButtonTexture::ButtonTexture(const std::string &filename):Texture(filename), _rec(0, 0, this->width, this->height)
{
    this->SetOrigin((ray::Vector2){this->width / 2 , this->height / 2});
};

indie::ButtonTexture::~ButtonTexture() {};

void indie::ButtonTexture::Draw(void)
{
    ray::MouseEvents mouse;

    if (mouse.getMouseX() > (this->GetPosition().x - this->GetOrigin().x * GetScale()) &&
    mouse.getMouseX() < (this->GetPosition().x - this->GetOrigin().x * GetScale()) + _rec.getSize().x * GetScale() &&
    mouse.getMouseY() > (this->GetPosition().y - this->GetOrigin().y * GetScale())  &&
    mouse.getMouseY() < (this->GetPosition().y - this->GetOrigin().y * GetScale()) + _rec.getSize().y * GetScale()) {
        if (mouse.isMouseButtonDown(MOUSE_LEFT_BUTTON)) {
            DrawTextureEx(*this, (ray::Vector2){this->GetPosition().x - this->GetOrigin().x * GetScale() * 0.85, this->GetPosition().y - this->GetOrigin().y * GetScale() * 0.85}, this->GetRotation(), this->GetScale() * 0.85, RAYWHITE);
        } else if (mouse.isMouseButtonUp(MOUSE_LEFT_BUTTON)) {
            DrawTextureEx(*this, (ray::Vector2){this->GetPosition().x - this->GetOrigin().x * GetScale() * 1.12, this->GetPosition().y - this->GetOrigin().y * GetScale() * 1.12}, this->GetRotation(), this->GetScale() * 1.12, RAYWHITE);
        }
    } else {
        DrawTextureEx(*this, (ray::Vector2){this->GetPosition().x - this->GetOrigin().x * GetScale(), this->GetPosition().y - this->GetOrigin().y * GetScale()}, this->GetRotation(), this->GetScale(), RAYWHITE);
    }
}

bool indie::ButtonTexture::IsClicked(void)
{
    ray::MouseEvents mouse;

    if (mouse.getMouseX() > (this->GetPosition().x - this->GetOrigin().x * GetScale()) &&
    mouse.getMouseX() < (this->GetPosition().x - this->GetOrigin().x * GetScale()) + _rec.getSize().x * GetScale() &&
    mouse.getMouseY() > (this->GetPosition().y - this->GetOrigin().y * GetScale())  &&
    mouse.getMouseY() < (this->GetPosition().y - this->GetOrigin().y * GetScale()) + _rec.getSize().y * GetScale()) {
        if (mouse.isMouseButtonDown(MOUSE_LEFT_BUTTON)) {
            return (true);
        }
    }
    return false;
}
