/*
** EPITECH PROJECT, 2022
** indie-studio
** File description:
** Shaders
*/

#include "Shaders.hpp"

ray::Shaders::Shaders(std::string const &vsFileName, std::string const &fsFileName, bool FormMemory)
{
    if (FormMemory)
        this->_shad = LoadShaderFromMemory(vsFileName.c_str(), fsFileName.c_str());
    else
        this->_shad = LoadShader(vsFileName.c_str(), fsFileName.c_str());
}

ray::Shaders::~Shaders()
{
    UnloadShader(this->_shad);
}


int ray::Shaders::GetLocation(std::string const &uniformName)
{
    return GetShaderLocation(this->_shad, uniformName.c_str());    
}

int ray::Shaders::GetLocationAttrib(std::string const &attribName)
{
    return GetShaderLocationAttrib(this->_shad, attribName.c_str());    
}

void ray::Shaders::SetValue(int locIndex, const void *value, int uniformType)
{
    SetShaderValue(this->_shad, locIndex, value, uniformType);    
}

void ray::Shaders::SetValueV(int locIndex, const void *value, int uniformType, int count)
{
    SetShaderValueV(this->_shad, locIndex, value, uniformType, count);    
}

void ray::Shaders::SetValueMatrix(int locIndex, Matrix mat)
{
    SetShaderValueMatrix(this->_shad, locIndex, mat);    
}

void ray::Shaders::SetValueTexture(int locIndex, Texture2D texture)
{
    SetShaderValueTexture(this->_shad, locIndex, texture);    
}

