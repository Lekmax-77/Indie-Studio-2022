/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-zacharie.lawson
** File description:
** Vector3
*/

#ifndef VECTOR3_HPP_
#define VECTOR3_HPP_


#include <raylib.h>


namespace ray {
    class Vector3 : public ::Vector3 {
    public:
        Vector3();
        Vector3(float x, float y, float z);
        Vector3(const Vector3 &src);
        ~Vector3();
        Vector3 &operator=(const Vector3 &src);

        // methods
        Vector3 operator+(const Vector3 &other) const;
        Vector3 operator-(const Vector3 &other) const;
        Vector3 operator*(float product) const;
        Vector3 operator/(float quotient) const;
        Vector3 &operator+=(const Vector3 &other);
        Vector3 &operator-=(const Vector3 &other);
        Vector3 &operator*=(float product);
        Vector3 &operator/=(float quotient);
        bool operator==(const Vector3 &other) const;
        bool operator!=(const Vector3 &other) const;

        // static methods
        inline static Vector3 Zero() { return {0, 0, 0}; };
        inline static Vector3 One() { return {1, 1, 1}; };

    }; // class Vector3
}; // namespace ray

#endif /* !VECTOR3_HPP_ */