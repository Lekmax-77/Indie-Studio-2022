/*
** EPITECH PROJECT, 2022
** File.cpp
** File description:
** File
*/

#include "Tools.hpp"
#include "raylib.h"

std::string ray::Tools::Files::loadFileData(unsigned int *bytesRead)
{
    std::string str((char *)LoadFileData(_fileName.c_str(), bytesRead));

    return str;
}

void ray::Tools::Files::unloadFileData(std::string &data)
{
    auto data_value = reinterpret_cast<unsigned char*>(const_cast<char*>(data.c_str()));

    UnloadFileData(data_value);
}

bool ray::Tools::Files::saveFileData(void *data, unsigned int bytesToWrite)
{
    return SaveFileData(_fileName.c_str(), data, bytesToWrite);
}

std::string ray::Tools::Files::loadFileText()
{
    std::string str((char *)LoadFileText(_fileName.c_str()));

    return str;
}

void ray::Tools::Files::unloadFileText(std::string const &text)
{
    UnloadFileText(const_cast<char*>(text.c_str()));
}

bool ray::Tools::Files::saveFileText(std::string const &text)
{
    return SaveFileText(_fileName.c_str(), const_cast<char*>(text.c_str()));
}

bool ray::Tools::Files::fileExists(std::string const &fileName)
{
    return FileExists(fileName.c_str());
}

bool ray::Tools::Files::isFileExtension(std::string const &fileName, std::string const &ext)
{
    return IsFileExtension(fileName.c_str(), ext.c_str());
}

bool ray::Tools::Files::isFileDropped()
{
    return IsFileDropped();
}

void ray::Tools::Files::clearDroppedFiles()
{
    ClearDroppedFiles();
}
