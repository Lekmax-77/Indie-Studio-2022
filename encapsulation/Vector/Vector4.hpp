/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-zacharie.lawson
** File description:
** Vector4
*/

#ifndef VECTOR4_HPP_
#define VECTOR4_HPP_

#include <raylib.h>


namespace ray {
    using Quaternion = Vector4;
    class Vector4 : public ::Vector4 {
        public:
            Vector4();
            Vector4(float x, float y, float z, float w);
            Vector4(const Vector4 &other);
            ~Vector4();

            Vector4 &operator=(const Vector4 &src);

            // methods
            Vector4 operator+(const Vector4 &other) const;
            Vector4 operator-(const Vector4 &other) const;
            Vector4 operator*(float product) const;
            Vector4 operator/(float quotient) const;
            Vector4 &operator+=(const Vector4 &other);
            Vector4 &operator-=(const Vector4 &other);
            Vector4 &operator*=(float product);
            Vector4 &operator/=(float quotient);
            bool operator==(const Vector4 &other) const;
            bool operator!=(const Vector4 &other) const;

            // static methods
            inline static Vector4 Zero() { return {0, 0, 0, 0}; };
            inline static Vector4 One() { return {1, 1, 1, 1}; };
    };
}; // namespace ray

#endif /* !VECTOR4_HPP_ */
