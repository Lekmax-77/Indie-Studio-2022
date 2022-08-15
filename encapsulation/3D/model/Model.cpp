/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-zacharie.lawson
** File description:
** Model
*/

#include "ResourcesManager.hpp"
#include "Model.hpp"

ray::_3D::Model::Model(const ::Model &model)
{
    cpy(model);
}

ray::_3D::Model::Model(const std::string &file)
{
    load(file);
}

ray::_3D::Model::~Model()
{
}

ray::_3D::Model::Model(const Model &other)
{
    cpy(other);
}

ray::_3D::Model &ray::_3D::Model::operator=(const ::Model &src)
{
    cpy(src);
    return *this;
}

ray::_3D::Model &ray::_3D::Model::operator=(const Model& other)
{
    cpy(other);
    return *this;
}

::BoundingBox ray::_3D::Model::getBoundingBox() const {
    return ::GetModelBoundingBox(*this);
}

ray::_3D::Model::operator ::BoundingBox() const
{
    return getBoundingBox();
}

void ray::_3D::Model::setTexture(const ::Texture &texture)
{
    SetMaterialTexture(materials, MATERIAL_MAP_DIFFUSE, texture);
}

void ray::_3D::Model::draw(Vector3 position, Vector3 scale, Color color, float rotationAngle, Vector3 rotationAxis) const
{
    DrawModelEx(*this, position, rotationAxis, rotationAngle, scale, color);
}

void ray::_3D::Model::unload()
{
    if (meshes != nullptr || materials != nullptr) {
        ::UnloadModel(*this);
        meshes = nullptr;
        materials = nullptr;
    }
}

void ray::_3D::Model::load(const std::string &file)
{
    // ::LoadModel(file.c_str())
    cpy(rManager.LoadModels(file));
}

void ray::_3D::Model::cpy(const ::Model &model) {
    transform = model.transform;
    meshCount = model.meshCount;
    materialCount = model.materialCount;
    meshes = model.meshes;
    materials = model.materials;
    meshMaterial = model.meshMaterial;
    boneCount = model.boneCount;
    bones = model.bones;
    bindPose = model.bindPose;
}
