/*
** EPITECH PROJECT, 2022
** indiestudio
** File description:
** IndieStudio
*/

#include "IndieStudio.hpp"
#include "Vector3.hpp"
#include "Core.hpp"
#include "Texture.hpp"
#include <fstream>
#include <iostream>

/**
 * @brief Construct a new indie::Indie Studio::Indie Studio object
 *
 */

static const std::array<ray::Vector3, 4> corner = {
    ray::Vector3(1, 0, 1),
    ray::Vector3(0, 0, 0),
    ray::Vector3(0, 0, 1),
    ray::Vector3(1, 0, 0)
};
static const std::array<std::string, 4> iqm_path = {
    "../ressources/Assets/IQM/bomberman.iqm",
    "../ressources/Assets/IQM/bomberman2.iqm",
    "../ressources/Assets/IQM/bomberman3.iqm",
    "../ressources/Assets/IQM/bomberman4.iqm"
};

static const std::array< std::array<KeyboardKey,5>, 4> keys = {
    std::array{KeyboardKey::KEY_W, KeyboardKey::KEY_D, KeyboardKey::KEY_S, KeyboardKey::KEY_A, KeyboardKey::KEY_E},
    std::array{KeyboardKey::KEY_UP, KeyboardKey::KEY_RIGHT, KeyboardKey::KEY_DOWN, KeyboardKey::KEY_LEFT, KeyboardKey::KEY_RIGHT_CONTROL},
    std::array{KeyboardKey::KEY_I, KeyboardKey::KEY_L, KeyboardKey::KEY_K, KeyboardKey::KEY_J, KeyboardKey::KEY_O},
    std::array{KeyboardKey::KEY_G, KeyboardKey::KEY_N, KeyboardKey::KEY_B, KeyboardKey::KEY_V, KeyboardKey::KEY_H}
};

indie::IndieStudio::IndieStudio():indie::IScene(), _map(), _closeview(false)
{
    _setting = engine::ButtonTristate("../ressources/Assets/Menu/Button.png", {-1, 4818, 193, 180});
    ray::TimeRelated::setTargetFPS(60);
    startCamera();
    createMap();
}

void indie::IndieStudio::initPlayers(Settings &set)
{
    int nbPlayers = set.getPlayer();
    int i = 0;
    for (; i < nbPlayers; ++i) {
        ray::Vector3 pPos = {
            corner[i].x == 1 ? 1 - _map.getHeight() / 2.0f : _map.getHeight() / 2.0f,
            0.5,
            corner[i].z == 1 ? 1 - _map.getWidth() / 2.0f : _map.getWidth() / 2.0f,
        };
        _players.emplace_back(pPos.x, pPos.y, pPos.z, 0.1, keys[i]);
    }
    for (int j = 0; j < nbPlayers; ++j) {
        _players[j].setModelAnimated(iqm_path[j], "../ressources/Assets/IQM/bombermanRun.iqm", "../ressources/Assets/Textures/bomberman.png");
    }
    for (; i < 4; ++i) {
        ray::Vector3 aPos = {
            corner[i].x == 1 ? 1 - _map.getHeight() / 2.0f : _map.getHeight() / 2.0f,
            0.5,
            corner[i].z == 1 ? 1 - _map.getWidth() / 2.0f : _map.getWidth() / 2.0f,
        };
        _ia.emplace_back(aPos.x, aPos.y, aPos.z, 0.1f);
    }
    for (int j = 0; j < 4 - nbPlayers; ++j) {
        _ia[j].setModelAnimated(iqm_path[j + nbPlayers], "../ressources/Assets/IQM/bombermanRun.iqm", "../ressources/Assets/Textures/bomberman.png");
    }
    for (auto &player : _players)
        _entity.push_back(&player);
    for (auto &ia : _ia)
        _entity.push_back(&ia);
}

/**
 * @brief init a base camera
 *
 */
void indie::IndieStudio::startCamera()
{
    ray::Vector3 position = {0.0f, static_cast<float>(_map.getHeight()) * 2, static_cast<float>(_map.getHeight())};
    ray::Vector3 target = {0.0f, 0.0f, 0.0f};
    ray::Vector3 up = {0.0f, 1.0f, 0.0f};
    float fovy = 45.0f;
    _cam.setPosition(position, target, up, fovy);
    _cam.setCameraMode(CAMERA_PERSPECTIVE);
}

/**
 * @brief Destroy the indie::Indie Studio::Indie Studio object
 *
 */
indie::IndieStudio::~IndieStudio()
{
    destroyMap();
}

/**
 * @brief Create a new map and its textures
 *
 */
void indie::IndieStudio::createMap()
{
    std::vector<indie::map::Biome> temp = {indie::map::classic, indie::map::ice, indie::map::lava, indie::map::end, indie::map::desert};

    _biome = temp[std::rand() % temp.size()];
    loadBiome();
}

/**
* @brief Load Biome
*
**/
void indie::IndieStudio::loadBiome()
{
    _models["ground"] = ray::_3D::Model(_biome.getPathGround().getPathObj().c_str());
    _models["ground"].setTexture(ray::Texture(_biome.getPathGround().getTexture()));
    _models["wall"] = ray::_3D::Model(_biome.getPathWall().getPathObj().c_str());
    _models["wall"].setTexture(ray::Texture(_biome.getPathWall().getTexture()));
    _models["brick"] = ray::_3D::Model(_biome.getPathBrick().getPathObj().c_str());
    _models["brick"].setTexture(ray::Texture(_biome.getPathBrick().getTexture()));
}

/**
 * @brief Destroy the map
 *
 */
void indie::IndieStudio::destroyMap()
{
}

/**
 * @brief switch camera mode relative to the player
 *
 */
void indie::IndieStudio::switchCameraMode()
{
    _closeview = !_closeview;
    if (!_closeview)
        startCamera();
}

#include <iostream>
/**
 * @brief handle events of the game scene
 *
 */
void indie::IndieStudio::handle_events(Settings &set)
{
    if (_key.isKeyPressed(KEY_SPACE))
        createMap();
    if (_key.isKeyPressed(KEY_X))
        save(set);
    if (_key.isKeyPressed(KEY_C))
        loadSave(set);
    for (auto &entity : _entity) {
        entity->moveUpdate(_key, _map);
        entity->updateBomb(_key, _map, _fires);
    }
    for (auto &fire : _fires) {
        fire.update(_entity);
    }
    _fires.erase(std::remove_if(_fires.begin(), _fires.end(), [](indie::Fire &fire) { return !fire.isAlive(); }), _fires.end());
}

void indie::IndieStudio::save(Settings &set)
{
    ray::Tools::Misc misc;
    std::ofstream myfile;
    myfile.open ("map.save");
    myfile << _map.getHeight() << " " << _map.getWidth() << std::endl;
    for (int i = 0; i < _map.getHeight() + 2; i++) {
        for (int j = 0; j < _map.getWidth() + 2; j++) {
            myfile << _map.getMap()[i][j] << std::endl;
        }
    }
    myfile << _entity.size() << std::endl;
    for (auto &entity : _entity)
        myfile << static_cast<int>(entity->getPosX()) + 0.5 << " " << entity->getPosY() << " " << static_cast<int>(entity->getPosZ()) + 0.5 << " " << entity->getSpeed() << std::endl;
    if (_biome == indie::map::ice)
        myfile << "1" << std::endl;
    else if (_biome == indie::map::lava)
        myfile << "2" << std::endl;
    else if (_biome == indie::map::end)
        myfile << "3" << std::endl;
    else if (_biome == indie::map::desert)
        myfile << "4" << std::endl;
    else
        myfile << "0" << std::endl;
    myfile.close();

    misc.takeScreenshot("../ressources/Assets/Textures/screenshot.png");
    Texture2D background = LoadTexture("../ressources/Assets/Textures/screenshot.png");
    set.GetWindow().endMode3D();
    int posx = -1000;
    while (!set.GetWindow().windowShouldClose()) {
        if (_key.isKeyReleased(KEY_SPACE))
            break;
        set.GetWindow().beginDrawing();
        set.GetWindow().clearBackground(WHITE);
        DrawTexture(background, 0, 0, WHITE);

        DrawRectangle(0, 370, 1920, 300, {r: 156, g: 156, b: 156, a: 80});
        DrawText("SAVING...", posx, 430, 200, _biome.getTextColor());
        posx += 20;
        if (posx >= 2000)
            break;
        set.GetWindow().endDrawing();
    }
    set.GetWindow().beginMode3D(_cam);
}

void indie::IndieStudio::loadSave(Settings &set)
{
    ray::Tools::Misc misc;
    std::ifstream myfile;
    float x, y, z, speed;
    std::vector<std::vector<int>> newmap;
    int height, width;
    int value;

    myfile.open ("map.save");
    myfile >> height >> width;
    _map.setHeight(height);
    _map.setWidth(width);
    newmap.resize(height + 2);
    for (int i = 0; i < _map.getHeight() + 2; i++) {
        newmap[i].resize(width + 2);
        for (int j = 0; j < _map.getWidth() + 2; j++)
            myfile >> newmap[i][j];
    }
    _map.setMap(newmap);
    newmap.clear();
    int size = 0;
    myfile >> size;
    for (int i = 0; i < size; i++) {
        myfile >> x >> y >> z >> speed;
        _entity[i]->setPosX(x);
        _entity[i]->setPosY(y);
        _entity[i]->setPosZ(z);
        _entity[i]->setSpeed(speed);
    }
    myfile >> value;
    std::vector<indie::map::Biome> temp = {indie::map::classic, indie::map::ice, indie::map::lava, indie::map::end, indie::map::desert};
    _biome = temp[value];
    loadBiome();
    startCamera();
    temp.clear();
    myfile.close();

    misc.takeScreenshot("../ressources/Assets/Textures/screenshot.png");
    Texture2D background = LoadTexture("../ressources/Assets/Textures/screenshot.png");
    set.GetWindow().endMode3D();
    int posx = -1500;
    while (!set.GetWindow().windowShouldClose()) {
        if (_key.isKeyReleased(KEY_SPACE))
            break;
        set.GetWindow().beginDrawing();
        set.GetWindow().clearBackground(WHITE);
        DrawTexture(background, 0, 0, WHITE);

        DrawRectangle(0, 370, 1920, 300, {r: 156, g: 156, b: 156, a: 80});
        DrawText("LOADING MAP...", posx, 430, 200, _biome.getTextColor());
        posx += 20;
        if (posx >= 2000)
            break;
        set.GetWindow().endDrawing();
    }
    set.GetWindow().beginMode3D(_cam);
}

void indie::IndieStudio::displayMap(void)
{
    for (int i = 0; i < _map.getHeight() + 2; ++i)
        for (int j = 0; j < _map.getWidth() + 2; ++j) {
            _models["ground"].draw({i - _map.getHeight() / 2.0f, 0, j - _map.getWidth() / 2.0f}, {0.01, 0.01, 0.01});
            if (_map[i][j] == indie::map::WALLBLOCK)
                _models["wall"].draw({i - _map.getHeight() / 2.0f, 1, j - _map.getWidth() / 2.0f}, {0.01, 0.01, 0.01});
            if (_map[i][j] == indie::map::BRICKBLOCK)
                _models["brick"].draw({i - _map.getHeight() / 2.0f, 1, j - _map.getWidth() / 2.0f}, {0.01, 0.01, 0.01});
        }
}

void indie::IndieStudio::displayEnd(std::vector<IPlayer*> entities, Settings &set)
{
    set.GetWindow().endMode3D();
    _end.init(entities, _biome);

    while (!set.GetWindow().windowShouldClose()) {
        if (_key.isKeyReleased(KEY_SPACE))
            break;
        set.GetWindow().beginDrawing();
        set.GetWindow().clearBackground(WHITE);
        _end.draw();
        set.GetWindow().endDrawing();
    }
    set.GetWindow().beginMode3D(_cam);
}

static void PauseMode(indie::Settings &set, ray::Color color)
{
    TakeScreenshot("../ressources/Assets/Textures/screenshot.png");
    engine::Sprite background("../ressources/Assets/Textures/screenshot.png");
    ray::KeyEvents key;
    int posx = -1000;
    
   // set.GetWindow().endDrawing();
    while (!set.GetWindow().windowShouldClose()) {
        set.GetWindow().beginDrawing();
        if (key.isKeyReleased(KEY_BACKSPACE))
            break;
        set.GetWindow().clearBackground(WHITE);
        background.Draw();

        DrawRectangle(0, 370, 1920, 300, {r: 156, g: 156, b: 156, a: 80});
        DrawText("PAUSE", posx, 430, 200, color);
        posx += 20;
        if (posx >= 2000)
            posx = -1000;
        set.GetWindow().endDrawing();
    }
    set.GetWindow().beginDrawing();
}

/**
 * @brief IndieStudio::run
 * @return
 */
indie::SCENE_ENUM indie::IndieStudio::run(Settings &set)
{
    initPlayers(set);
    bool pause_mode = false;
    while (!set.GetWindow().windowShouldClose())
    {
        if (_closeview) {
            _cam.position = {_players[0].getPosX(), _players[0].getPosY() + 5, _players[0].getPosZ() + 2};
            _cam.target = {_players[0].getPosX(), _players[0].getPosY() + 1, _players[0].getPosZ()};
        }
        if (_key.isKeyPressed(KEY_ESCAPE)) {
            return indie::SCENE_ENUM::END;
        }
        if (_key.isKeyPressed(KEY_BACKSPACE)) {
            return indie::SCENE_ENUM::MENU;
        }
        if (_key.isKeyPressed(KEY_TAB)) {
            return indie::SCENE_ENUM::SETTING;
        }
        if (_key.isKeyPressed(KEY_P)) {
            pause_mode = !pause_mode;
        }
        _cam.updateCamera();
        if (!pause_mode) {
            handle_events(set);
        }
        auto countAlive = [this]() {
            int count = 0;
            for (auto &e : _entity)
                if (e->isAlive())
                    count++;
            return count;
        };
        if (countAlive() <= 1) {
            displayEnd(_entity, set);
            return indie::SCENE_ENUM::WIN;
        }
        set.GetWindow().beginDrawing();
        set.GetWindow().clearBackground(_biome.getBackground());
        set.GetWindow().beginMode3D(_cam);
        for (auto &entity : _entity)
            entity->draw();
        for (auto &fire : _fires)
            fire.draw();
        if (!pause_mode)
            handle_events(set);
        
        //_players.draw();
        displayMap();
        set.GetWindow().endMode3D();
        if (pause_mode) {
            PauseMode(set, _biome.getBackground());
            pause_mode = false;
        }
        set.GetWindow().endDrawing();
    }
}
