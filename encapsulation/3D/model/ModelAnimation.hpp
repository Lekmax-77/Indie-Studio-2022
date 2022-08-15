/*
** EPITECH PROJECT, 2022
** indie_encap
** File description:
** ModelAnimation
*/

#ifndef MODELANIMATION_HPP_
#define MODELANIMATION_HPP_

#include "raylib.h"
#include "Model.hpp"
#include <vector>
#include <string>

namespace ray {
    namespace _3D {
        class ModelAnimation : public ::ModelAnimation {
        public:
            ModelAnimation() {}
            ModelAnimation(const ::ModelAnimation &src) : ::ModelAnimation{src} {}
            ModelAnimation(ModelAnimation &src) {
                *this = src;
            };
            ModelAnimation(ModelAnimation &&src) {
                *this = src;
            };
            ~ModelAnimation() {
                unload();
            };

            ModelAnimation &operator=(const ::ModelAnimation &src) {
                cpy(src);
                return *this;
            }
            ModelAnimation &operator=(ModelAnimation &a) {
                *this = std::move(a);
                return *this;
            };
            ModelAnimation &operator=(ModelAnimation &&src) {
                cpy(src);
                src.boneCount = 0;
                src.bones = nullptr;
                src.frameCount = 0;
                src.framePoses = nullptr;
                return *this;
            }

        // getters

        // setters

        // methods
            static std::vector<ModelAnimation> load(const std::string &file);
            void update(const Model &model, unsigned int frame);

        private:
            inline void unload() {
                if (bones != nullptr || framePoses) {
                    UnloadModelAnimation(*this);
                    bones = nullptr;
                    framePoses = nullptr;
                }
            }
            inline void cpy(const ::ModelAnimation &src) {
                boneCount = src.boneCount;
                frameCount = src.frameCount;
                bones = src.bones;
                framePoses = src.framePoses;
            }
        }; // class ModelAnimation

    }; // namespace _3D
}; // namespace ray

#endif /* !MODELANIMATION_HPP_ */