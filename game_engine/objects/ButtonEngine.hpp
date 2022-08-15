 /*
** EPITECH PROJECT, 2022
** indie
** File description:
** Button
*/

#ifndef BUTTON_HPP_
#define BUTTON_HPP_
    #include "SpriteEngine.hpp"
    #include "../encapsulation/IShapes/Rectangle.hpp"
    #include "../encapsulation/Events/IEvents.hpp"

namespace engine {

    enum GO_TO : int {
        GO_TO_MENU,
        GO_TO_GAME,
        GO_TO_OPTIONS,
        GO_TO_HOW_TO_PLAY,
        GO_TO_EXIT,
        GO_TO_PAUSE,
    };

    enum BUTTON_STATE : int {
        BUTTON_STATE_NORMAL,
        BUTTON_STATE_HOVER,
        BUTTON_STATE_CLICKED,
    };

    class ButtonTristate : public engine::Sprite
    {
        public:
            ButtonTristate() : engine::Sprite(), _rec(0, 0, 0, 0) {};
            ButtonTristate(const std::string &filename, ray::_2D::Rectangles rec):_rec(rec)
            {
                if (_rec.getSize().x == 0 && _rec.getSize().y == 0) 
                    _rec.setSize(ray::Vector2(this->width, this->height));
            }
            ButtonTristate(const ButtonTristate &src) : Sprite(src), _type(src._type), _state(src._state), _rec(src._rec) {};
            ~ButtonTristate() {};
            void Update(void)
            {
                ray::MouseEvents mouse;

                if (mouse.getMouseX() > (this->GetPosition().x - this->GetOrigin().x) &&
                mouse.getMouseX() < (this->GetPosition().x - this->GetOrigin().x) + _rec.getSize().x &&
                mouse.getMouseY() > (this->GetPosition().y - this->GetOrigin().y)  &&
                mouse.getMouseY() < (this->GetPosition().y - this->GetOrigin().y) + _rec.getSize().y) {
                    if (mouse.isMouseButtonDown(MOUSE_LEFT_BUTTON)) {
                        _state = BUTTON_STATE_CLICKED;
                    } else if (mouse.isMouseButtonUp(MOUSE_LEFT_BUTTON)) {
                        _state = BUTTON_STATE_HOVER;
                    }
                } else {
                    _state = BUTTON_STATE_NORMAL;
                }
            }
            void Draw(void)
            {
                ray::MouseEvents mouse;

                if (_state == BUTTON_STATE_CLICKED) {
                    this->DrawRec((ray::_2D::Rectangles){(_rec.getPos().x + (_rec.getSize().x * 2)),
                        _rec.getPos().y, _rec.getSize().x, _rec.getSize().y}.getRectangle());
                } else if (_state == BUTTON_STATE_HOVER) {
                        this->DrawRec((ray::_2D::Rectangles){_rec.getPos().x + _rec.getSize().x,
                        _rec.getPos().y, _rec.getSize().x, _rec.getSize().y}.getRectangle());
                } else {
                    this->DrawRec(_rec.getRectangle());
                }
            }
            bool IsClicked() {if (_state == BUTTON_STATE_CLICKED) return true; else return false;};

            ButtonTristate &operator=(const ButtonTristate &src) {
                Sprite::operator=(src);
                _type = src._type;
                _state = src._state;
                _rec = src._rec;
                return *this;
            };
    
            ButtonTristate &operator=(const Sprite &src) {
                Sprite::operator=(src);
                return *this;
            }

            inline GO_TO getType() const { return _type; };
            inline BUTTON_STATE getState() { return _state; };
            inline void setType(GO_TO type) { _type = type; };
            inline void setState(BUTTON_STATE state) { _state = state; };
            inline void setRectangle(ray::_2D::Rectangles rec) { _rec = rec; };
            inline ray::_2D::Rectangles getRectangle() { return _rec; };
        protected:
            ray::_2D::Rectangles _rec;
            GO_TO _type;
            BUTTON_STATE _state;
    };

    class ButtonTexture : public engine::Sprite
    {
        public:
            ButtonTexture() : engine::Sprite(), _rec(0, 0, 0, 0) {};
            ButtonTexture(const std::string &filename):Sprite(filename), _rec(0, 0, this->width, this->height) {};
            ButtonTexture(const ButtonTexture &src) : Sprite(src), _type(src._type), _state(src._state), _rec(src._rec) {};
            ~ButtonTexture() {};
            void Update(void)
            {
                ray::MouseEvents mouse;

                if (mouse.getMouseX() > (this->GetPosition().x - this->GetOrigin().x * GetScale()) &&
                mouse.getMouseX() < (this->GetPosition().x - this->GetOrigin().x * GetScale()) + _rec.getSize().x * GetScale() &&
                mouse.getMouseY() > (this->GetPosition().y - this->GetOrigin().y * GetScale())  &&
                mouse.getMouseY() < (this->GetPosition().y - this->GetOrigin().y * GetScale()) + _rec.getSize().y * GetScale()) {
                    if (mouse.isMouseButtonDown(MOUSE_LEFT_BUTTON)) {
                        _state = BUTTON_STATE_CLICKED;
                    } else if (mouse.isMouseButtonUp(MOUSE_LEFT_BUTTON)) {
                        _state = BUTTON_STATE_HOVER;
                    }
                } else {
                    _state = BUTTON_STATE_NORMAL;
                }
            }
            void Draw(void)
            {
                if (_state == BUTTON_STATE_CLICKED) {
                    DrawTextureEx(*this, (ray::Vector2){this->GetPosition().x - this->GetOrigin().x * GetScale() * 0.85, this->GetPosition().y - this->GetOrigin().y * GetScale() * 0.85}, this->GetRotation(), this->GetScale() * 0.85, RAYWHITE);
                } else if (_state == BUTTON_STATE_HOVER) {
                    DrawTextureEx(*this, (ray::Vector2){this->GetPosition().x - this->GetOrigin().x * GetScale() * 1.12, this->GetPosition().y - this->GetOrigin().y * GetScale() * 1.12}, this->GetRotation(), this->GetScale() * 1.12, RAYWHITE);
                } else {
                    DrawTextureEx(*this, (ray::Vector2){this->GetPosition().x - this->GetOrigin().x * GetScale(), this->GetPosition().y - this->GetOrigin().y * GetScale()}, this->GetRotation(), this->GetScale(), RAYWHITE);
                }
            }
            
            bool IsClicked() {if (_state == BUTTON_STATE_CLICKED) return true; else return false;};
            ButtonTexture &operator=(const ButtonTexture &src) {
                Sprite::operator=(src);
                _type = src._type;
                _state = src._state;
                _rec = src._rec;
                return *this;
            };
    
            ButtonTexture &operator=(const Sprite &src) {
                Sprite::operator=(src);
                return *this;
            }
            inline GO_TO getType() const { return _type; };
            inline BUTTON_STATE getState() { return _state; };
            inline void setType(GO_TO type) { _type = type; };
            inline void setState(BUTTON_STATE state) { _state = state; };
            inline void setRectangle(ray::_2D::Rectangles rec) { _rec = rec; };
            inline ray::_2D::Rectangles getRectangle() { return _rec; };
        protected:
            ray::_2D::Rectangles _rec;
            GO_TO _type;
            BUTTON_STATE _state;
    };

}; // namespace engine

/*
namespace engine {

    enum GO_TO : int {
        GO_TO_MENU,
        GO_TO_GAME,
        GO_TO_OPTIONS,
        GO_TO_HOW_TO_PLAY,
        GO_TO_EXIT,
        GO_TO_PAUSE,
    };

    enum BUTTON_STATE : int {
        BUTTON_STATE_NORMAL,
        BUTTON_STATE_HOVER,
        BUTTON_STATE_CLICKED,
    };

    class Button : public Sprite {
    public:
        Button() {};
        ~Button() {};
        Button(const std::string &filepath):Sprite(filepath) {};
        Button(const Button &src) : Sprite(src), _type(src._type), _state(src._state) {};
        Button &operator=(const Button &src) {
            Sprite::operator=(src);
            _type = src._type;
            _state = src._state;
            return *this;
        };

        Button &operator=(const Sprite &src) {
            Sprite::operator=(src);
            return *this;
        }

    // getters
        inline GO_TO getType() const { return _type; };
        inline BUTTON_STATE getState() { return _state; };
    // setters
        inline void setType(GO_TO type) { _type = type; };
        inline void setState(BUTTON_STATE state) { _state = state; };
    // methods

    private:
        GO_TO _type;
        BUTTON_STATE _state;
    }; // class Button
}; // namespace engine
*/

#endif /* !BUTTON_HPP_ */


