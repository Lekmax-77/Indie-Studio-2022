/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-zacharie.lawson
** File description:
** Color
*/

#ifndef COLOR_HPP_
#define COLOR_HPP_

#include <raylib.h>


#define BASE_COLOR_METHOD(name, val) inline static Color name() { return val; }

namespace ray {
    class Color : public ::Color {
        public:
            Color();
            Color(unsigned char red, unsigned char green, unsigned char blue, unsigned char alpha = 255);
            Color(unsigned int hexValue);
            Color(const Color &src);
            Color(const ::Color &src);
            ~Color();
            Color &operator=(const Color &src);

            // methods
            inline int getHexValue() const { return ::ColorToInt(*this); };

            // static methods
            BASE_COLOR_METHOD(LightGray, LIGHTGRAY);
            BASE_COLOR_METHOD(Gray, GRAY);
            BASE_COLOR_METHOD(DarkGray, DARKGRAY);
            BASE_COLOR_METHOD(Yellow, YELLOW);
            BASE_COLOR_METHOD(Gold, GOLD);
            BASE_COLOR_METHOD(Orange, ORANGE);
            BASE_COLOR_METHOD(Pink, PINK);
            BASE_COLOR_METHOD(Red, RED);
            BASE_COLOR_METHOD(Maroon, MAROON);
            BASE_COLOR_METHOD(Green, GREEN);
            BASE_COLOR_METHOD(Lime, LIME);
            BASE_COLOR_METHOD(DarkGreen, DARKGREEN);
            BASE_COLOR_METHOD(SkyBlue, SKYBLUE);
            BASE_COLOR_METHOD(Blue, BLUE);
            BASE_COLOR_METHOD(DarkBlue, DARKBLUE);
            BASE_COLOR_METHOD(Purple, PURPLE);
            BASE_COLOR_METHOD(Violet, VIOLET);
            BASE_COLOR_METHOD(DarkPurple, DARKPURPLE);
            BASE_COLOR_METHOD(Beige, BEIGE);
            BASE_COLOR_METHOD(Brown, BROWN);
            BASE_COLOR_METHOD(DarkBrown, DARKBROWN);
            BASE_COLOR_METHOD(White, WHITE);
            BASE_COLOR_METHOD(Black, BLACK);
            BASE_COLOR_METHOD(Blank, BLANK);
            BASE_COLOR_METHOD(Magenta, MAGENTA);
            BASE_COLOR_METHOD(RayWhite, RAYWHITE);
    }; // class Color
}; // namespace ray

#endif /* !COLOR_HPP_ */
