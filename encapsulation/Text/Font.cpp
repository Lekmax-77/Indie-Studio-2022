/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-zacharie.lawson
** File description:
** Font
*/

#include "Font.hpp"

/********** Font METHODS **********/

ray::Font::Font()
{
    _font = GetFontDefault();
}

ray::Font::Font(const std::string &fileName)
{
    _font = LoadFont(fileName.c_str());
}

ray::Font::~Font()
{
    //UnloadFont(_font);
}

void ray::Font::setFont(const std::string &fileName)
{
    //UnloadFont(_font);
    //_font = LoadFont(fileName.c_str());
}
