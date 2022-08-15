/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-zacharie.lawson
** File description:
** Matrix
*/

#ifndef MATRIX_HPP_
#define MATRIX_HPP_

#include <raylib.h>


namespace ray {
    class Matrix : public ::Matrix {
    public:
        Matrix();
        Matrix(float m11, float m12, float m13, float m14,
               float m21, float m22, float m23, float m24,
               float m31, float m32, float m33, float m34,
               float m41, float m42, float m43, float m44);
        Matrix(const Matrix &src);
        ~Matrix();
        Matrix &operator=(const Matrix &src);

        // getters and setters from m0 to m15
        inline float getM0() const { return m0; }
        inline void setM0(float M0) { m0 = M0; }
        inline float getM1() const { return m1; }
        inline void setM1(float M1) { m1 = M1; }
        inline float getM2() const { return m2; }
        inline void setM2(float M2) { m2 = M2; }
        inline float getM3() const { return m3; }
        inline void setM3(float M3) { m3 = M3; }
        inline float getM4() const { return m4; }
        inline void setM4(float M4) { m4 = M4; }
        inline float getM5() const { return m5; }
        inline void setM5(float M5) { m5 = M5; }
        inline float getM6() const { return m6; }
        inline void setM6(float M6) { m6 = M6; }
        inline float getM7() const { return m7; }
        inline void setM7(float M7) { m7 = M7; }
        inline float getM8() const { return m8; }
        inline void setM8(float M8) { m8 = M8; }
        inline float getM9() const { return m9; }
        inline void setM9(float M9) { m9 = M9; }
        inline float getM10() const { return m10; }
        inline void setM10(float M10) { m10 = M10; }
        inline float getM11() const { return m11; }
        inline void setM11(float M11) { m11 = M11; }
        inline float getM12() const { return m12; }
        inline void setM12(float M12) { m12 = M12; }
        inline float getM13() const { return m13; }
        inline void setM13(float M13) { m13 = M13; }
        inline float getM14() const { return m14; }
        inline void setM14(float M14) { m14 = M14; }
        inline float getM15() const { return m15; }
        inline void setM15(float M15) { m15 = M15; }

        // methods
        Matrix operator+(const Matrix &other) const;
        Matrix operator-(const Matrix &other) const;
        Matrix operator*(float product) const;
        Matrix operator/(float quotient) const;
        Matrix &operator+=(const Matrix &other);
        Matrix &operator-=(const Matrix &other);
        Matrix &operator*=(float product);
        Matrix &operator/=(float quotient);
        bool operator==(const Matrix &other) const;
        bool operator!=(const Matrix &other) const;
        Matrix operator*(const Matrix &other) const;
        Matrix &operator*=(const Matrix &other);

        Matrix getTranspose() const;
        Matrix &transpose();

        // static methods
        inline static Matrix Zero() { return {
            0, 0, 0, 0,
            0, 0, 0, 0,
            0, 0, 0, 0,
            0, 0, 0, 0
        }; };
        inline static Matrix Identity() { return {
            1, 0, 0, 0,
            0, 1, 0, 0,
            0, 0, 1, 0,
            0, 0, 0, 1
        }; };

    }; // class Matrix
}; // namespace ray

#endif /* !MATRIX_HPP_ */
