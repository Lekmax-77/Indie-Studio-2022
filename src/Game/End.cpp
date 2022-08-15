/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-zacharie.lawson
** File description:
** End
*/

#include "End.hpp"
#include <algorithm>
#include <iostream>

indie::game::End::End()
{
    _panel = ray::Texture("../ressources/Assets/Textures/win_panel.png");
    _profilePicture = ray::Texture("../ressources/Assets/Textures/icon_bomberman_white.png");
    _panelPos = ray::Vector2(720, 375);
    _screenshotPos = ray::Vector2(0, 0);

    _trophyGold = ray::Texture("../ressources/Assets/Textures/icon_first_place.png");
    _trophySilver = ray::Texture("../ressources/Assets/Textures/icon_second_place.png");
    _trophyBronze = ray::Texture("../ressources/Assets/Textures/icon_third_place.png");

    _trophyGoldPos = ray::Vector2(740, 390);
    _trophySilverPos = ray::Vector2(740, 505);
    _trophyBronzePos = ray::Vector2(740, 625);

    _firstPlayerPos = ray::Vector2(850.0f, 390.0f);
    _secondPlayerPos = ray::Vector2(850.0f, 505.0f);
    _thirdPlayerPos = ray::Vector2(850.0f, 625.0f);
    _fourthPlayerPos = ray::Vector2(850.0f, 745.0f);
}

indie::game::End::~End()
{
}

void indie::game::End::init(std::vector<IPlayer*> entities, indie::map::Biome biome)
{
    ray::Tools::Misc misc;
    misc.takeScreenshot("../ressources/Assets/Textures/screenshot.png");
    _screenshot = ray::Texture("../ressources/Assets/Textures/screenshot.png");
    _entities = entities;
    _nbEntities = _entities.size();
    _biome = biome;
}

void indie::game::End::draw()
{
    _scores.clear();
    DrawTextureEx(_screenshot, _screenshotPos, 0.0f, 1.0f, WHITE);
    DrawText("SCOREBOARD", 260, 75, 200, _biome.getTextColor());
    DrawTextureEx(_panel, _panelPos, 0.0f, 1.0f, _biome.getTextColor());
    DrawTextureEx(_trophyGold, _trophyGoldPos, 0.0f, 0.4f, WHITE);
    DrawTextureEx(_trophySilver, _trophySilverPos, 0.0f, 0.4f, WHITE);
    DrawTextureEx(_trophyBronze, _trophyBronzePos, 0.0f, 0.4f, WHITE);

    std::vector<int> indexes;
    for (auto &entity : _entities)
        _scores.push_back(entity->getPoints());
    int minimumValue = *min_element(_scores.begin(), _scores.end());
    std::cout << "Min value : " << minimumValue << std::endl << std::endl;

    for (unsigned long int i = 0; indexes.size() < _nbEntities; i++, minimumValue += 1) {
        for (unsigned long int j = 0; j < _nbEntities; j++) {
            if (_scores[j] == minimumValue) {
                indexes.push_back(j);
                // std::cout << "index : " << j << std::endl;
                // std::cout << "minimumValue : " << minimumValue << std::endl;
            }
        }
    }
    // std::cout << "__after__" << std::endl;
    // std::cout << "[Rank] | [Index] | [Score]" << std::endl;
    // std::cout << "  [1]  |    " << indexes[0] << "   |   " << scores[indexes[0]] << std::endl;
    // std::cout << "  [2]  |    " << indexes[1] << "   |   " << scores[indexes[1]] << std::endl;
    // std::cout << "  [3]  |    " << indexes[2] << "   |   " << scores[indexes[2]] << std::endl;
    // std::cout << "  [4]  |    " << indexes[3] << "   |   " << scores[indexes[3]] << std::endl;
    
    // for (int i = 0 ;i < _nbPlayers; i++) {

    // }
    if (_nbEntities >= 1) {
        // DrawTextureEx(_entities[indexes[0]].getProfilePicture(), _firstPlayerPos, 0.0f, 0.4f, WHITE);
        DrawTextureEx(_profilePicture, _firstPlayerPos, 0.0f, 3.0f, WHITE);
        DrawText(std::to_string(_scores[indexes[0]]).c_str(), _firstPlayerPos.x + 120, _firstPlayerPos.y, 100, _biome.getTextColor());
    }
    if (_nbEntities >= 2) {
        // DrawTextureEx(_entities[indexes[1]].getProfilePicture(), _secondPlayerPos, 0.0f, 0.4f, WHITE);
        DrawTextureEx(_profilePicture, _secondPlayerPos, 0.0f, 3.0f, WHITE);
        DrawText(std::to_string(_scores[indexes[1]]).c_str(), _secondPlayerPos.x + 120, _secondPlayerPos.y, 100, _biome.getTextColor());
    }
    if (_nbEntities >= 3) {
        // DrawTextureEx(_entities[indexes[2]].getProfilePicture(), _secondPlayerPos, 0.0f, 0.4f, WHITE);
        DrawTextureEx(_profilePicture, _thirdPlayerPos, 0.0f, 3.0f, WHITE);
        DrawText(std::to_string(_scores[indexes[2]]).c_str(), _thirdPlayerPos.x + 120, _thirdPlayerPos.y, 100, _biome.getTextColor());
    }
    if (_nbEntities >= 4) {
        // DrawTextureEx(_entities[indexes[3]].getProfilePicture(), _secondPlayerPos, 0.0f, 0.4f, WHITE);
        DrawTextureEx(_profilePicture, _fourthPlayerPos, 0.0f, 3.0f, WHITE);
        DrawText(std::to_string(_scores[indexes[3]]).c_str(), _fourthPlayerPos.x + 120, _fourthPlayerPos.y, 100, _biome.getTextColor());
    }
}