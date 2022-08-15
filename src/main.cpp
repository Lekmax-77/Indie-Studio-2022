/*
** EPITECH PROJECT, 2022
** indiestudio
** File description:
** main
*/
#include <raylib.h>
#include <ctime>
#include <iostream>
#include <cstdlib>
#include "../cinematic/cinematic.hpp"
#include "Map.hpp"
#include "Biome.hpp"
#include "IndieStudio.hpp"
#include "Window.hpp"
#include "Scene.hpp"
#include "Menu.hpp"
#include "Core.hpp"
#include <memory>
#include "Color.hpp"
#include "Setting.hpp"
#include <tuple>
#include "EndWin.hpp"
#include "PlayerMode.hpp"

int main(void)
{
    indie::Core core;
    indie::Settings setting(1920, 1080, "Bomber-Gang");
    indie::SCENE_ENUM temp = indie::CINEMATIC;
    core.GetScenes()[indie::SCENE_ENUM::CINEMATIC] = std::make_shared<indie::Cinematic>();
    core.GetScenes()[indie::SCENE_ENUM::MENU] = std::make_shared<indie::Menu>();
    core.GetScenes()[indie::SCENE_ENUM::GAME] = std::make_shared<indie::IndieStudio>();
    core.GetScenes()[indie::SCENE_ENUM::SETTING] = std::make_shared<indie::Setting>();
    core.GetScenes()[indie::SCENE_ENUM::MODE_SELECT] = std::make_shared<indie::PlayerMode>();
    core.GetScenes()[indie::SCENE_ENUM::WIN] = std::make_shared<indie::EndWin>();
    while (core.GetCurrentScene() != indie::SCENE_ENUM::END) {
        temp = core.GetScenes()[core.GetCurrentScene()].get()->run(setting);
        if (core.GetCurrentScene() == indie::SCENE_ENUM::WIN) {
            core.GetScenes()[indie::SCENE_ENUM::MENU] = std::make_shared<indie::Menu>();
        }
        setting.setScene(core.GetCurrentScene());
        core.SetPreviousScene(core.GetCurrentScene());
        core.SetScene(temp);
        std::cout << "[EXIT ODE iS:] " << core.GetCurrentScene() << std::endl;

    }
    return 0;
}
