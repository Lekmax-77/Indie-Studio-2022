/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-zacharie.lawson
** File description:
** Scene
*/

#include "Scene.hpp"
#include "yaml-cpp/yaml.h"
#include "RessourcesManager/ResourcesManager.hpp"
#include <functional>
#include "../encapsulation/IShapes/Rectangle.hpp"

namespace YAML {
    template<>
    struct convert<ray::_2D::Rectangles> {
        static bool decode(const Node& node, ray::_2D::Rectangles& rhs) {
            if (node.IsMap()) {
                rhs = ray::_2D::Rectangles(node["x"].as<float>(), node["y"].as<float>(), node["width"].as<float>(), node["height"].as<float>());
                return true;
            }
            if (node.IsSequence()) {
                rhs = ray::_2D::Rectangles(node[0].as<float>(), node[1].as<float>(), node[2].as<float>(), node[3].as<float>());
                return true;
            }
            return false;
        }
    };
    template<>
    struct convert<ray::Vector2> {
        static bool decode(const Node& node, ray::Vector2& rhs) {
            if (node.IsMap()) {
                rhs.x = node["x"].as<float>();
                rhs.y = node["y"].as<float>();
                return true;
            }
            if (node.IsSequence()) {
                rhs.x = node[0].as<float>();
                rhs.y = node[1].as<float>();
                return true;
            }
            return false;
        }
    };
    template<>
    struct convert<ray::Vector3> {
        static bool decode(const Node& node, ray::Vector3& rhs) {
            if (node.IsMap()) {
                rhs.x = node["x"].as<float>();
                rhs.y = node["y"].as<float>();
                rhs.z = node["z"].as<float>();
                return true;
            }
            if (node.IsSequence()) {
                rhs.x = node[0].as<float>();
                rhs.y = node[1].as<float>();
                rhs.z = node[2].as<float>();
                return true;
            }
            return false;
        }
    };

    template<>
    struct convert<ray::Color> {
        static bool decode(const Node& node, ray::Color& rhs) {
            if (node.IsMap()) {
                rhs.r = node["r"].as<float>();
                rhs.g = node["g"].as<float>();
                rhs.b = node["b"].as<float>();
                rhs.a = node["a"].as<float>();
                return true;
            }
            if (node.IsSequence()) {
                rhs.r = node[0].as<float>();
                rhs.g = node[1].as<float>();
                rhs.b = node[2].as<float>();
                rhs.a = node[3].as<float>();
                return true;
            }
            return false;
        }
    };

    template<>
    struct convert<engine::Sprite> {
        static bool decode(const Node& node, engine::Sprite& rhs) {
            if (!node.IsMap())
                return false;

            rhs = ray::Texture(node["file"].as<std::string>());
            try {
                rhs.SetPosition(node["pos"].as<ray::Vector2>());
            } catch (const std::exception& e) {
                rhs.SetPosition(ray::Vector2::Zero());
            }
            try {
                rhs.SetOrigin(node["origin"].as<ray::Vector2>());
            } catch (const std::exception& e) {
                rhs.SetOrigin(ray::Vector2::Zero());
            }
            try {
                rhs.SetRotation(node["rotation"].as<float>());
            } catch (const std::exception& e) {
                rhs.SetRotation(0);
            }
            try {
                rhs.SetScale(node["scale"].as<float>());
            } catch (const std::exception& e) {
                rhs.SetScale(1);
            }
            return true;
        }
    };
    template<>
    struct convert<engine::Model> {
        static bool decode(const Node& node, engine::Model& rhs) {
            if (!node.IsMap())
                return false;
            try {
                rhs.setPosition(node["pos"].as<ray::Vector3>());
            } catch (const std::exception& e) {
                rhs.setPosition(ray::Vector3::Zero());
            }
            ray::_3D::Model model(node["file"].as<std::string>());
            try {
                model.setTexture(ray::Texture(node["texture"].as<std::string>()));
            } catch (const std::exception& e) {}
            rhs.setModel(model);
            try {
                rhs.setRotationAngle(node["rotationAngle"].as<float>());
            } catch(const std::exception& e) {
                rhs.setRotationAngle(0);
            }
            try {
                rhs.setRotationAxis(node["rotationAxis"].as<ray::Vector3>());
            } catch(const std::exception& e) {
                rhs.setRotationAxis(ray::Vector3::Zero());
            }
            try {
                rhs.setScale(node["scale"].as<ray::Vector3>());
            } catch(const std::exception& e) {
                rhs.setScale(ray::Vector3::One());
            }
            return true;
        }
    };
    template<>
    struct convert<engine::Music> {
        static bool decode(const Node& node, engine::Music& rhs) {
            if (!node.IsMap())
                return false;
            ray::Music music(node["file"].as<std::string>());
            rhs.setMusic(music);
            try {
                rhs.setLoop(node["loop"].as<float>());
            } catch(const std::exception& e) {
                rhs.setLoop(true);
            }
            try {
                rhs.setVolume(node["volume"].as<float>());
            } catch(const std::exception& e) {
                rhs.setVolume(1);
            }
            try {
                rhs.setPitch(node["pitch"].as<float>());
            } catch(const std::exception& e) {
                rhs.setPitch(1);
            }
            return true;
        }
    };
    template<>
    struct convert<engine::Sound> {
        static bool decode(const Node& node, engine::Sound& rhs) {
            if (!node.IsMap())
                return false;
            ray::Sound sound(node["file"].as<std::string>());
            rhs.setSound(sound);
            try {
                rhs.setVolume(node["volume"].as<float>());
            } catch (const std::exception& e) {}
            return true;
        }
    };
    
    template<>
        struct convert<engine::ButtonTexture> {
                static bool decode(const Node& node, engine::ButtonTexture& rhs) {

                if (!node.IsMap())
                    return false;

                rhs = engine::Sprite(node["file"].as<std::string>());
                rhs.setRectangle({0, 0, rhs.width, rhs.height});
                rhs.setState(engine::BUTTON_STATE::BUTTON_STATE_NORMAL);
                try {
                    rhs.SetPosition(node["pos"].as<ray::Vector2>());
                } catch (const std::exception& e) {
                    rhs.SetPosition(ray::Vector2::Zero());
                }
                try {
                    rhs.SetOrigin(node["origin"].as<ray::Vector2>());
                } catch (const std::exception& e) {
                    rhs.SetOrigin(ray::Vector2::Zero());
                }
                try {
                    rhs.SetRotation(node["rotation"].as<float>());
                } catch (const std::exception& e) {
                    rhs.SetRotation(0);
                }
                try {
                    rhs.SetScale(node["scale"].as<float>());
                } catch (const std::exception& e) {
                    rhs.SetScale(1);
                }
                return true;
                }
        };
    
    template<>
        struct convert<engine::ButtonTristate> {
        static bool decode(const Node& node, engine::ButtonTristate& rhs) {

            if (!node.IsMap())
                return false;
            rhs = engine::Sprite(node["file"].as<std::string>());
            try {
                rhs.SetPosition(node["pos"].as<ray::Vector2>());
            } catch (const std::exception& e) {
                rhs.SetPosition(ray::Vector2::Zero());
            }
            try {
                rhs.SetOrigin(node["origin"].as<ray::Vector2>());
            } catch (const std::exception& e) {
                rhs.SetOrigin(ray::Vector2::Zero());
            }
            try {
                rhs.SetRotation(node["rotation"].as<float>());
            } catch (const std::exception& e) {
                rhs.SetRotation(0);
            }
            try {
                rhs.SetScale(node["scale"].as<float>());
            } catch (const std::exception& e) {
                rhs.SetScale(1);
            }
            try {
                rhs.setRectangle(node["rect"].as<ray::_2D::Rectangles>());
            } catch (const std::exception& e) {
                rhs.setRectangle(ray::_2D::Rectangles(0, 0, 0, 0));
            }

            return true;
        }
        };

    template<>
        struct convert<engine::Text> {
        static bool decode(const Node& node, engine::Text& rhs) {
            if (!node.IsMap())
                return false;
            try {
                rhs.setPosition(node["pos"].as<ray::Vector2>());
            } catch (const std::exception& e) {
                rhs.setPosition(ray::Vector2::Zero());
            }
            rhs.setText(node["str"].as<std::string>());
            try {
                rhs.setFont(ray::Font(node["font"].as<std::string>()));
            } catch (const std::exception& e) {
                rhs.setFont(ray::Font(""));
            }
            try {
                rhs.setColor(node["color"].as<ray::Color>());
            } catch (const std::exception& e) {
                rhs.setColor(ray::Color::White());
            }
            try {
                rhs.setSpacing(node["spacing"].as<float>());
            } catch (const std::exception& e) {
                rhs.setSpacing(0);
            }
            try {
                rhs.setFontSize(node["size"].as<float>());
            } catch (const std::exception& e) {
                rhs.setFontSize(10);
            }
            return true;
        }
    };
}

engine::Scene::Scene(const std::string &filepath)
    : _sprites(), _models(), _buttonstextures(), _sounds(), _buttonstristates()
    // , _musics()
{
    std::map<std::string, std::function<void(YAML::Node n)>> m = {
        {
            "sprite",
            [this](YAML::Node n) {
                std::cout << "start sprite" << std::endl;
                auto name = n["name"].as<std::string>();
                auto sprite = n.as<engine::Sprite>();
                _sprites[name] = sprite;
                std::cout << "end sprite" << std::endl;
            }
        },
        {
            "model",
            [this](YAML::Node n) {
                std::cout << "start model" << std::endl;
                auto name = n["name"].as<std::string>();
                _models[name] = n.as<engine::Model>();
                std::cout << "end model" << std::endl;
            }
        },
        {
            "buttontristate",
            [this](YAML::Node n) {
                std::cout << "start button" << std::endl;
                auto name = n["name"].as<std::string>();
                auto button = n.as<engine::ButtonTristate>();
                _buttonstristates[name] = button;
                std::cout << "end button" << std::endl;
            }
        },
        {
            "buttontexture",
            [this](YAML::Node n) {
                std::cout << "start button" << std::endl;
                auto name = n["name"].as<std::string>();
                auto button = n.as<engine::ButtonTexture>();
                _buttonstextures[name] = button;
                std::cout << "end button" << std::endl;
            }
        },
        {
            "sound",
            [this](YAML::Node n) {
                std::cout << "start sound" << std::endl;
                auto name = n["name"].as<std::string>();
                auto sound = n.as<engine::Sound>();
                _sounds[name] = std::move(sound);
                std::cout << "end sound" << std::endl;
            }
        },
        {
            "music",
            [this](YAML::Node n) {
                std::cout << "start music" << std::endl;
                auto name = n["name"].as<std::string>();
                auto music = n.as<engine::Music>();
                _musics[name] = std::move(music);
                std::cout << "end music" << std::endl;
            }
        },
        {
            "text",
            [this](YAML::Node n) {
                std::cout << "start text" << std::endl;
                auto name = n["name"].as<std::string>();
                auto text = n.as<engine::Text>();
                _texts[name] = text;
                std::cout << "end text" << std::endl;
            }
        }
    };

    YAML::Node node = YAML::LoadFile(filepath);
    for (auto it : node) {
        std::string name = it.first.as<std::string>();

        if (!m.contains(name))
            throw std::runtime_error("Unknown node type");
        m[name](it.second);
    }
    std::cout << "end scene" << std::endl;
}