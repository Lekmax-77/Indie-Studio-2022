/*
** EPITECH PROJECT, 2022
** indie-studio
** File description:
** ButtonTristate
*/

#include "ButtonTristate.hpp"
#include <iostream>

indie::ButtonTristate::ButtonTristate(const std::string &filename, ray::_2D::Rectangles rec):Texture(filename), _rec(rec)
{
    if (_rec.getPos().x == 0 && _rec.getPos().y == 0 && _rec.getSize().x == 0 && _rec.getSize().y == 0) {
        _rec.setPos(ray::Vector2(0, 0));
        _rec.setSize(ray::Vector2(this->width, this->height));
    }
};

indie::ButtonTristate::~ButtonTristate() {};

void indie::ButtonTristate::Draw(void)
{
    ray::MouseEvents mouse;

    if (mouse.getMouseX() > (this->GetPosition().x - this->GetOrigin().x) &&
    mouse.getMouseX() < (this->GetPosition().x - this->GetOrigin().x) + _rec.getSize().x &&
    mouse.getMouseY() > (this->GetPosition().y - this->GetOrigin().y)  &&
    mouse.getMouseY() < (this->GetPosition().y - this->GetOrigin().y) + _rec.getSize().y) {
        if (mouse.isMouseButtonDown(MOUSE_LEFT_BUTTON))
        this->DrawRec((ray::_2D::Rectangles){(_rec.getPos().x + (_rec.getSize().x * 2)), _rec.getPos().y, _rec.getSize().x, _rec.getSize().y}.getRectangle());
        else if (mouse.isMouseButtonUp(MOUSE_LEFT_BUTTON))
        this->DrawRec((ray::_2D::Rectangles){_rec.getPos().x + _rec.getSize().x, _rec.getPos().y, _rec.getSize().x, _rec.getSize().y}.getRectangle());
    } else {
        this->DrawRec(_rec.getRectangle());
    }
}

bool indie::ButtonTristate::IsClicked(void)
{
    ray::MouseEvents mouse;

    if (mouse.getMouseX() > (this->GetPosition().x - this->GetOrigin().x) &&
    mouse.getMouseX() < (this->GetPosition().x - this->GetOrigin().x) + _rec.getSize().x &&
    mouse.getMouseY() > (this->GetPosition().y - this->GetOrigin().y)  &&
    mouse.getMouseY() < (this->GetPosition().y - this->GetOrigin().y) + _rec.getSize().y) {
        if (mouse.isMouseButtonDown(MOUSE_LEFT_BUTTON))
            return (true);
    }
    return false;
}
