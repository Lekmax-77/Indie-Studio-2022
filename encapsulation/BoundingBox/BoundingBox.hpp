/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-zacharie.lawson
** File description:
** BoundingBox
*/

#ifndef BOUNDINGBOX_HPP_
#define BOUNDINGBOX_HPP_

#include <raylib.h>
#include "Vector/Vector3.hpp"

using rayBoundingBox = BoundingBox;

namespace ray {
    class BoundingBox : public ::BoundingBox {
        public:
            BoundingBox();
            BoundingBox(Vector3 min, Vector3 max);
            ~BoundingBox();
            BoundingBox(const ::BoundingBox &src);
            BoundingBox &operator=(const BoundingBox &src);
    }; // class BoundingBox
}; // namespace ray

#endif /* !BOUNDINGBOX_HPP_ */