/*
** EPITECH PROJECT, 2022
** indie
** File description:
** IScreenspace
*/

#ifndef ISCREENSPACE_HPP_
#define ISCREENSPACE_HPP_
#include "raylib.h"

namespace ray {
    class Screenspace {
        Screenspace();
        ~Screenspace();
        /**
         * @brief Get a ray trace from mouse position
         *
         * @param mousePosition Vector2f
         * @param camera Camera
         * @return Ray
         */
        Ray getMouseRay(Vector2 mousePosition, Camera camera) const;
        /**
         * @brief Get camera transform matrix (view matrix)
         *
         * @param camera Camera
         * @return Matrix
         */
        Matrix getCameraMatrix(Camera camera) const;
        /**
         * @brief Get camera 2d transform matrix
         *
         * @param camera Camera
         * @return Matrix
         */
        Matrix getCameraMatrix2D(Camera2D camera) const;
        /**
         * @brief Get the screen space position for a 3d world space position
         *
         * @param position Vector3
         * @param camera Camera
         * @return Vector2
         */
        Vector2 getWorldToScreen(Vector3 position, Camera camera) const;
        /**
         * @brief Get size position for a 3d world space position
         *
         * @param position Vector3
         * @param camera Camera
         * @param width int
         * @param height int
         * @return Vector2
         */
        Vector2 getWorldToScreenEx(Vector3 position, Camera camera, int width, int height) const;
        /**
         * @brief Get the screen space position for a 2d camera world space position
         *
         * @param position Vector2
         * @param camera Camera2D
         * @return Vector2
         */
        Vector2 getWorldToScreen2D(Vector2 position, Camera2D camera) const;
        /**
         * @brief Get the world space position for a 2d camera screen
         *
         * @param position Vector2
         * @param camera Camera2D
         * @return Vector2
         */
        Vector2 getScreenToWorld2D(Vector2 position, Camera2D camera) const;
    };
}

#endif /* !ISCREENSPACE_HPP_ */
