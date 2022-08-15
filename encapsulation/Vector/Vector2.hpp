/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-zacharie.lawson
** File description:
** Vector2
*/

#ifndef VECTOR2_HPP_
#define VECTOR2_HPP_

#include <raylib.h>


namespace ray {
    class Vector2 : public ::Vector2 {
    public:
        Vector2();
        Vector2(float x, float y);
        Vector2(const Vector2 &src);
        ~Vector2();
        Vector2 &operator=(const Vector2 &src);

        // methods
        Vector2 operator+(const Vector2 &other) const;
        Vector2 operator-(const Vector2 &other) const;
        Vector2 operator*(float product) const;
        Vector2 operator/(float quotient) const;
        Vector2 &operator+=(const Vector2 &other);
        Vector2 &operator-=(const Vector2 &other);
        Vector2 &operator*=(float product);
        Vector2 &operator/=(float quotient);
        bool operator==(const Vector2 &other) const;
        bool operator!=(const Vector2 &other) const;

        // static methods
        inline static Vector2 Zero() { return {0, 0}; };
        inline static Vector2 One() { return {1, 1}; };

    }; // class Vector2
}; // namespace ray

#endif /* !VECTOR2_HPP_ */
