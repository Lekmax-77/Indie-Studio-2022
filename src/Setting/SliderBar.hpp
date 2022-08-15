/*
** EPITECH PROJECT, 2022
** indie-studio
** File description:
** SliderBar
*/

#ifndef SLIDERBAR_HPP_
    #define SLIDERBAR_HPP_
    #include "../../encapsulation/IShapes/Rectangle.hpp"
    #include "../../encapsulation/Events/IEvents.hpp"
    #include "../../encapsulation/Color/Color.hpp"
    #include <string>
    #include <iostream>
    #include <iostream>

namespace ray
{
class SliderBar {
    public:
        SliderBar():_rec({0, 0, 0, 0}), _load({0, 0, 0, 0}) {};
        SliderBar(ray::_2D::Rectangles rec, const std::string &left_text, const std::string &right_text, const std::string &title, float minvalue, float maxvalue, float value):_rec(rec), _load(rec)
        {
            this->_left_text = left_text;
            this->_right_text = right_text;
            this->_title = title;
            this->_minvalue = minvalue;
            this->_maxvalue = maxvalue;
            if (value < minvalue)
                this->_value = minvalue;
            else if (value > maxvalue)
                this->_value = maxvalue;
            else
                this->_value = value;
            this->_pos = _value - minvalue;
        }
        ~SliderBar() {};
        SliderBar(SliderBar &other) {
            this->_rec.setPos(other._rec.getPos());
            this->_rec.setSize(other._rec.getSize());
            this->_rec.setColor(other._rec.getColor());
            this->_load.setPos(other._load.getPos());
            this->_load.setSize(other._load.getSize());
            this->_load.setColor(other._load.getColor());
            this->_left_text = other._left_text;
            this->_right_text = other._right_text;
            this->_title = other._title;
            this->_minvalue = other._minvalue;
            this->_maxvalue = other._maxvalue;
            this->_value = other._value;
            this->_pos = other._pos;
        }
        SliderBar &operator=(SliderBar &other) {
            this->_rec = other._rec;
            this->_load = other._load;
            this->_left_text = other._left_text;
            this->_right_text = other._right_text;
            this->_title = other._title;
            this->_minvalue = other._minvalue;
            this->_maxvalue = other._maxvalue;
            this->_value = other._value;
            this->_pos = other._pos;
            return *this;
        }
        void Draw(void)
        {
            ray::MouseEvents mouse;

            if (mouse.isMouseButtonDown(MOUSE_LEFT_BUTTON)) {
                if (mouse.getMouseX() >= _rec.getPos().x && mouse.getMouseX() <= _rec.getPos().x + _rec.getSize().x &&
                    mouse.getMouseY() >= _rec.getPos().y && mouse.getMouseY()  <= _rec.getPos().y + _rec.getSize().y) {
                    _pos = mouse.getMouseX() - _rec.getPos().x;
                    }
            }
            _value = (_maxvalue - _minvalue) / _rec.getSize().x * _pos + _minvalue;
            _load.setColor(ray::Color::Green());
            _load.setRectangle({_load.getPos().x, _load.getPos().y, _pos, _load.getSize().y});
            _load.Draw(true);
            _rec.setColor( ray::Color::Blue());
            _rec.Draw(false);
            DrawText(_left_text.c_str(), _rec.getPos().x - _left_text.length() * 15, _rec.getPos().y + 10, 20, ray::Color::Red());
            DrawText(_right_text.c_str(), _rec.getPos().x + _rec.getSize().x, _rec.getPos().y + 10, 20, ray::Color::Red());
            DrawText((_title + std::to_string((int)_value)).c_str(), _rec.getPos().x + _rec.getSize().x / 2 - 10, _rec.getPos().y - 30, 20, ray::Color::Red());
        }
        float getValue(void) const
        {
            return _value;
        }
    protected:
    private:
        ray::_2D::Rectangles _load;
        std::string _title;
        float _pos;
        ray::_2D::Rectangles _rec;
        std::string _left_text;
        std::string _right_text;
        float _minvalue;
        float _maxvalue;
        float _value;
    private:
};
    
} // namespace ray


#endif /* !SLIDERBAR_HPP_ */
