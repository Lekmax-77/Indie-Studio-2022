/*
** EPITECH PROJECT, 2022
** Directory.cpp
** File description:
** Directory
*/

#include "Tools.hpp"
#include "raylib.h"

void ray::Tools::Files::clearDirectoryFiles(void)
{
    ClearDirectoryFiles();
}

bool ray::Tools::Files::changeDirectory(std::string const &dir)
{
    return ChangeDirectory(dir.c_str());
}

bool ray::Tools::Files::directoryExists(std::string const &dirPath)
{
    return DirectoryExists(dirPath.c_str());
}