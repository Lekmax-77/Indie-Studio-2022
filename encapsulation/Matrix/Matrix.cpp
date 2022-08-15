/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-zacharie.lawson
** File description:
** Matrix
*/

#include "Matrix.hpp"

ray::Matrix::Matrix()
    : ::Matrix{
            0,0,0,0,
            0,0,0,0,
            0,0,0,0,
            0,0,0,0
        }
{
}

ray::Matrix::Matrix(const ray::Matrix &src)
    : ::Matrix{
            src.m0, src.m1, src.m2, src.m3,
            src.m4, src.m5, src.m6, src.m7,
            src.m8, src.m9, src.m10, src.m11,
            src.m12, src.m13, src.m14, src.m15
        }
{
}

ray::Matrix::Matrix(float m0, float m1, float m2, float m3,
                    float m4, float m5, float m6, float m7,
                    float m8, float m9, float m10, float m11,
                    float m12, float m13, float m14, float m15)
    : ::Matrix{
            m0, m1, m2, m3,
            m4, m5, m6, m7,
            m8, m9, m10, m11,
            m12, m13, m14, m15
        }
{
}

ray::Matrix::~Matrix()
{
}

ray::Matrix &ray::Matrix::operator=(const ray::Matrix &src)
{
    m0 = src.m0;
    m1 = src.m1;
    m2 = src.m2;
    m3 = src.m3;
    m4 = src.m4;
    m5 = src.m5;
    m6 = src.m6;
    m7 = src.m7;
    m8 = src.m8;
    m9 = src.m9;
    m10 = src.m10;
    m11 = src.m11;
    m12 = src.m12;
    m13 = src.m13;
    m14 = src.m14;
    m15 = src.m15;
    return *this;
}

ray::Matrix ray::Matrix::operator+(const ray::Matrix &other) const
{
    return {
        m0 + other.m0, m1 + other.m1, m2 + other.m2, m3 + other.m3,
        m4 + other.m4, m5 + other.m5, m6 + other.m6, m7 + other.m7,
        m8 + other.m8, m9 + other.m9, m10 + other.m10, m11 + other.m11,
        m12 + other.m12, m13 + other.m13, m14 + other.m14, m15 + other.m15
    };
}

ray::Matrix ray::Matrix::operator-(const ray::Matrix &other) const
{
    return {
        m0 - other.m0, m1 - other.m1, m2 - other.m2, m3 - other.m3,
        m4 - other.m4, m5 - other.m5, m6 - other.m6, m7 - other.m7,
        m8 - other.m8, m9 - other.m9, m10 - other.m10, m11 - other.m11,
        m12 - other.m13, m13 - other.m13, m14 - other.m14, m15 - other.m15
    };
}


ray::Matrix ray::Matrix::operator*(float product) const
{
    return {
        m0 * product, m1 * product, m2 * product, m3 * product,
        m4 * product, m5 * product, m6 * product, m7 * product,
        m8 * product, m9 * product, m10 * product, m11 * product,
        m12 * product, m13 * product, m14 * product, m15 * product
    };
}

ray::Matrix ray::Matrix::operator/(float quotient) const
{
    return {
        m0 / quotient, m1 / quotient, m2 / quotient, m3 / quotient,
        m4 / quotient, m5 / quotient, m6 / quotient, m7 / quotient,
        m8 / quotient, m9 / quotient, m10 / quotient, m11 / quotient,
        m12 / quotient, m13 / quotient, m14 / quotient, m15 / quotient
    };
}

ray::Matrix &ray::Matrix::operator+=(const ray::Matrix &other)
{
    *this = *this + other;
    return *this;
}

ray::Matrix &ray::Matrix::operator-=(const ray::Matrix &other)
{
    *this = *this - other;
    return *this;
}

ray::Matrix &ray::Matrix::operator*=(float product)
{
    *this = *this * product;
    return *this;
}

ray::Matrix &ray::Matrix::operator/=(float quotient)
{
    *this = *this / quotient;
    return *this;
}

ray::Matrix ray::Matrix::operator*(const ray::Matrix &other) const
{
    return {
        m0 * other.m0 + m1 * other.m4 + m2 * other.m8 + m3 * other.m12,
        m0 * other.m1 + m1 * other.m5 + m2 * other.m9 + m3 * other.m13,
        m0 * other.m2 + m1 * other.m6 + m2 * other.m10 + m3 * other.m14,
        m0 * other.m3 + m1 * other.m7 + m2 * other.m11 + m3 * other.m15,
        m4 * other.m0 + m5 * other.m4 + m6 * other.m8 + m7 * other.m12,
        m4 * other.m1 + m5 * other.m5 + m6 * other.m9 + m7 * other.m13,
        m4 * other.m2 + m5 * other.m6 + m6 * other.m10 + m7 * other.m14,
        m4 * other.m3 + m5 * other.m7 + m6 * other.m11 + m7 * other.m15,
        m8 * other.m0 + m9 * other.m4 + m10 * other.m8 + m11 * other.m12,
        m8 * other.m1 + m9 * other.m5 + m10 * other.m9 + m11 * other.m13,
        m8 * other.m2 + m9 * other.m6 + m10 * other.m10 + m11 * other.m14,
        m8 * other.m3 + m9 * other.m7 + m10 * other.m11 + m11 * other.m15,
        m12 * other.m0 + m13 * other.m4 + m14 * other.m8 + m15 * other.m12,
        m12 * other.m1 + m13 * other.m5 + m14 * other.m9 + m15 * other.m13,
        m12 * other.m2 + m13 * other.m6 + m14 * other.m10 + m15 * other.m14,
        m12 * other.m3 + m13 * other.m7 + m14 * other.m11 + m15 * other.m15
    };
}

ray::Matrix &ray::Matrix::operator*=(const ray::Matrix &other)
{
    *this = *this * other;
    return *this;
}


ray::Matrix ray::Matrix::getTranspose() const
{
    return {
        m0, m4, m8, m12,
        m1, m5, m9, m13,
        m2, m6, m10, m14,
        m3, m7, m11, m15
    };
}

ray::Matrix &ray::Matrix::transpose()
{
    *this = getTranspose();
    return *this;
}
