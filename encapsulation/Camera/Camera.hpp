/*
** EPITECH PROJECT, 2022
** encapsulation
** File description:
** ICamera
*/

#ifndef ICAMERA_HPP_
#define ICAMERA_HPP_

#include <memory>
#include "raylib.h"
#include "Vector3.hpp"

namespace ray {
    class Camera3D : public ::Camera {
        public:
            Camera3D();
            ~Camera3D();

            /**
             * @brief Set camera mode (multiple camera modes available)
             * 
             * @param camera Camera
             * @param mode ray::CameraMode
             */
            void setCameraMode(int mode);
            /**
             * @brief 
             * 
             * @param camera std::unique_ptr<Camera> camera
             */
            void updateCamera();
            /**
             * @brief Set camera pan key to combine with mouse movement (free camera)
             * 
             * @param keyPan int
             */
            void setCameraPanControl(int keyPan);
            /**
             * @brief Set camera alt key to combine with mouse movement (free camera)
             * 
             * @param keyAlt int
             */
            void setCameraAltControl(int keyAlt);
            /**
             * @brief 
             *Set camera smooth zoom key to combine with mouse (free camera)
             * 
             * @param keySmoothZoom int
             */
            void setCameraSmoothZoomControl(int keySmoothZoom);
            /**
             * @brief Set camera move controls (1st person and 3rd person cameras)
             * 
             * @param keyFront int
             * @param keyBack int
             * @param keyRight int
             * @param keyLeft int
             * @param keyUp int
             * @param keyDown int
             */
            void setCameraMoveControls(int keyFront, int keyBack, int keyRight, int keyLeft, int keyUp, int keyDown);
            /**
             * @brief Get camera
             * 
             * @return rayCam
             */
            void setPosition(ray::Vector3 Pos, ray::Vector3 Target, ray::Vector3 Up, float Fovy);
            ::Camera3D getCamera();
    };

    class Camera2D : public ::Camera2D {
        public:
            Camera2D();
            ~Camera2D();
            void setPosition(Vector2 Offset, Vector2 Target, float rotation, float zoom);
            ::Camera2D getCamera();
    };
}

#endif /* !ICAMERA_HPP_ */
