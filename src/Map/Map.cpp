/*
** EPITECH PROJECT, 2022
** indiestudio
** File description:
** Map
*/

#include <iostream>
#include "Map.hpp"

/**
 * @brief map constructor
 * @param width : width of bomberman map
 * @param height : height of bomberman map
 * @param density : density of the brick in the map
 */
indie::map::Map::Map(int width, int height, int density) : _width(width), _height(height), _map(0)
{
    if (width < 5 || height < 5 || density < 0 || density > 100)
        throw std::runtime_error("Map::Map() : invalid parameters");
    if (width % 2 == 0)
        _width++;
    if (height % 2 == 0)
        _height++;
    generateMap(_width, _height, density);
}

/**
 * @brief Destroy the Map object
 *
 */
indie::map::Map::~Map()
{
}

/**
 * @brief get map vector
 *
 * @return std::vector<std::vector<int>>
 */
std::vector<std::vector<int>> indie::map::Map::getMap() const
{
    return _map;
}

/**
 * @brief get map width
 *
 * @return int
 */
int indie::map::Map::getWidth() const
{
    return _width;
}

/**
 * @brief get map height
 *
 * @return int
 */
int indie::map::Map::getHeight() const
{
    return _height;
}

/**
 * @brief set map vector
 *
 * @param map : map vector
 */
void indie::map::Map::setMap(std::vector<std::vector<int>> map)
{
    _map = map;
}

/**
 * @brief set map width
 *
 * @param width : map width
 */
void indie::map::Map::setWidth(int width)
{
    _width = width;
}

/**
 * @brief set map height
 *
 * @param height : map height
 */
void indie::map::Map::setHeight(int height)
{
    _height = height;
}

/**
 * @brief reset the map in order to generate a new one for a new game
 *
 * @param width : map width
 * @param height : map height
 * @param density : map density
 */
void indie::map::Map::Reset(int width, int height, int density)
{
    _width = width;
    _height = height;
    _map.clear();
    if (width < 5 || height < 5 || density < 0 || density > 100)
        throw std::runtime_error("Map::Reset() : invalid parameters");
    if (width % 2 == 0)
        _width++;
    if (height % 2 == 0)
        _height++;
    generateMap(_width, _height, density);
}

void indie::map::Map::generateMap(int width, int height, int density)
{
    // Initialize map
    height += 2;
    width += 2;
    _map.resize(height);

    // Generate base map
    for (int i = 0; i < height; i++) {
        _map[i].resize(width);
        for (int j = 0; j < width; j++) {
            if (i == 0 || i == height - 1 || j == 0 || j == width - 1) // Border
                _map[i][j] = WALLBLOCK;
            else if (i % 2 == 0 && j % 2 == 0) // Inner wall
                _map[i][j] = WALLBLOCK;
            else // Brick or empty
                _map[i][j] = (rand() % 100 < density) ? BRICKBLOCK : EMPTYBLOCK;
        }
    }

    // Free corners
    // top left corner
    _map[1][1] = EMPTYBLOCK;
    _map[1][2] = EMPTYBLOCK;
    _map[2][1] = EMPTYBLOCK;

    // top right corner
    _map[1][width - 2] = EMPTYBLOCK;
    _map[1][width - 3] = EMPTYBLOCK;
    _map[2][width - 2] = EMPTYBLOCK;

    // bottom left corner
    _map[height - 2][1] = EMPTYBLOCK;
    _map[height - 3][1] = EMPTYBLOCK;
    _map[height - 2][2] = EMPTYBLOCK;

    // bottom right corner
    _map[height - 2][width - 2] = EMPTYBLOCK;
    _map[height - 3][width - 2] = EMPTYBLOCK;
    _map[height - 2][width - 3] = EMPTYBLOCK;
}