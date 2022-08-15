/*
** EPITECH PROJECT, 2022
** indiestudio
** File description:
** Line
*/

#include "Line.hpp"

/**
 * @brief Draw a line
 * 
 */
void ray::_2D::Line::Draw()
{
    DrawLineEx(_pos1, _pos2, _thick, _color);
};

/**
 * @brief Draw a line with a control point
 * 
 * @param ControlPos 
 */
void ray::_2D::Line::Draw(Vector2 ControlPos)
{
    DrawLineBezierQuad(_pos1, _pos2, ControlPos, _thick, _color);
};

/**
 * @brief Draw a line with 2 control points
 *
 * @param ControlPos1
 * @param ControlPos2
 */
void ray::_2D::Line::Draw(Vector2 ControlPos1, Vector2 ControlPos2)
{
    DrawLineBezierCubic(_pos1, _pos2, ControlPos1, ControlPos2, _thick, _color);
}
