/*
** EPITECH PROJECT, 2022
** GetterFiles.cpp
** File description:
** GetterFiles
*/

#include "Tools.hpp"
#include "raylib.h"

std::string ray::Tools::Files::getFileExtension(std::string const &fileName)
{
    std::string str((char *)GetFileExtension(fileName.c_str()));

    return str;
}

std::string ray::Tools::Files::getFileName(std::string const &filePath)
{
    std::string str((char *)GetFileName(filePath.c_str()));

    return str;
}

std::string ray::Tools::Files::getFileNameWithoutExt(std::string const &filePath)
{
    std::string str((char *)GetFileNameWithoutExt(filePath.c_str()));

    return str;
}

std::string ray::Tools::Files::getDirectoryPath(std::string const &filePath)
{
    std::string str((char *)GetDirectoryPath(filePath.c_str()));

    return str;
}

std::string ray::Tools::Files::getPrevDirectoryPath(std::string const &dirPath)
{
    std::string str((char *)GetPrevDirectoryPath(dirPath.c_str()));

    return str;
}

std::string ray::Tools::Files::getWorkingDirectory()
{
    std::string str((char *)GetWorkingDirectory());

    return str;
}

std::vector<std::string> ray::Tools::Files::getDirectoryFiles(std::string const &dirPath, int *count)
{
    char **names = GetDirectoryFiles(dirPath.c_str(), count);
    std::vector<std::string> retval;
    std::string str;

    for (int i = 0; names[i] != nullptr; i++)
        retval.push_back(str.assign(names[i]));
    retval.emplace_back(nullptr);
    return retval;
}

std::vector<std::string> ray::Tools::Files::getDroppedFiles(int *count)
{
    char **names = GetDroppedFiles(count);
    std::vector<std::string> retval;
    std::string str;

    for (int i = 0; names[i] != nullptr; ++i)
        retval.push_back(str.assign(names[i]));
    retval.emplace_back(nullptr);
    return retval;
}

long ray::Tools::Files::getFileModTime(std::string const &fileName)
{
    return GetFileModTime(fileName.c_str());
}
