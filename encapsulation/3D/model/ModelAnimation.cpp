/*
** EPITECH PROJECT, 2022
** indie_encap
** File description:
** ModelAnimation
*/

#include "ModelAnimation.hpp"

// ray::_3D::ModelAnimation::ModelAnimation(ModelAnimation &&src) : ::ModelAnimation{src}
// {
//     src.boneCount = 0;
//     src.bones = nullptr;
//     src.frameCount = 0;
//     src.framePoses = nullptr;
// }

std::vector<ray::_3D::ModelAnimation> ray::_3D::ModelAnimation::load(const std::string &file)
{
    unsigned int count = 0;
    auto anims = LoadModelAnimations(file.c_str(), &count);
    std::vector<ModelAnimation> res(anims, anims + count);
    free(anims);
    return res;
}

void ray::_3D::ModelAnimation::update(const Model &model, unsigned int frame)
{
    UpdateModelAnimation(model, *this, frame);
}

