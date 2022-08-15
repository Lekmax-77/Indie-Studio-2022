cmake_minimum_required(VERSION 3.17)
project(bomberman)

set(CMAKE_BUILD_TYPE Release)

set(CMAKE_CXX_STANDARD 20)
set(GRAPHICS GRAPHICS_API_OPENGL_43)
set(OpenGL_GL_PREFERENCE GLVND)

include(cmake/Findraylib.cmake)
include(cmake/FindYMLlib.cmake)

if(CMAKE_COMPILER_IS_GNUCXX)
  add_compile_options(-Wall -Wextra -g3)
endif(CMAKE_COMPILER_IS_GNUCXX)

if (WIN32)
    add_compile_options(-Wall)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG "./build/")
    #set_target_properties (indie_studio.exe PROPERTIES PREFIX "./build/")
endif(WIN32)

#ADD_LIBRARY(MyStaticLib STATIC
add_executable(${PROJECT_NAME}
        src/IndieStudio.cpp
        src/Map/Map.cpp
        src/main.cpp
        game_engine/Core.cpp
        src/End/EndWin.cpp
        src/PlayerMode/PlayerMode.cpp
        src/Menu/Menu.cpp
        src/Game/Player.cpp
        src/Game/Bomb.cpp
        encapsulation/Window/Setters.cpp
        encapsulation/Window/Others.cpp
        encapsulation/Window/Getters.cpp
        encapsulation/Window/End.cpp
        encapsulation/Window/Begin.cpp
        encapsulation/Vector/Vector2.cpp
        encapsulation/Vector/Vector3.cpp
        encapsulation/Vector/Vector4.cpp
        encapsulation/Tools/Directory.cpp
        encapsulation/Tools/File.cpp
        encapsulation/Tools/GetterFiles.cpp
        encapsulation/Tools/Misc.cpp
        encapsulation/Tools/storage.cpp
        encapsulation/RessourcesManager/ResourcesManager.cpp
        encapsulation/TimeRelated/TimeRelated.cpp
        encapsulation/Text/Text.cpp
        encapsulation/Text/Font.cpp
        encapsulation/Sprite/Shaders.cpp
        encapsulation/Sprite/Picture.cpp
        encapsulation/Sprite/Texture.cpp
        encapsulation/Matrix/Matrix.cpp
        encapsulation/Screenspace/Screenspace.cpp
        encapsulation/IShapes/Collision.cpp
        encapsulation/IShapes/Line.cpp
        encapsulation/Color/Color.cpp
        encapsulation/Cursor/Cursor.cpp
        encapsulation/Events/KeyEvents.cpp
        encapsulation/Events/MouseEvents.cpp
        encapsulation/Events/TouchEvents.cpp
        encapsulation/BoundingBox/BoundingBox.cpp
        encapsulation/Audio/Device.cpp
        encapsulation/Audio/Music.cpp
        encapsulation/Audio/Sound.cpp
        encapsulation/3D/model/Model.cpp
        encapsulation/3D/Collision.cpp
        encapsulation/3D/shape/circle/Circle.cpp
        encapsulation/3D/shape/cube/Cube.cpp
        encapsulation/3D/shape/cylinder/Cylinder.cpp
        encapsulation/3D/shape/line/Line.cpp
        encapsulation/3D/shape/point/Point.cpp
        encapsulation/3D/shape/sphere/Sphere.cpp
        encapsulation/3D/shape/triangle/Triangle.cpp
        encapsulation/3D/model/ModelAnimation.cpp
        encapsulation/Camera/Camera2D.cpp
        encapsulation/Camera/Camera3D.cpp
        src/Setting/Setting.cpp
        src/Map/Map.cpp
        src/IndieStudio.cpp
        src/cinematic/cinematic.cpp
        encapsulation/3D/model/ModelAnimation.cpp
        src/Map/Map.cpp
        src/Game/End.cpp
        src/Game/Player.cpp
        src/IndieStudio.cpp
        game_engine/Scene.cpp
        game_engine/Scene.cpp
        src/Game/IA.cpp
        src/Game/Fire.cpp
        )

include_directories(includes
                    encapsulation
                    src/Game
                    encapsulation/Window
                    encapsulation/Vector
                    encapsulation/Tools
                    encapsulation/TimeRelated
                    encapsulation/Text
                    encapsulation/Sprite
                    encapsulation/Screenspace
                    encapsulation/Matrix
                    encapsulation/RessourcesManager
                    src/PlayerMode
                    src/End
                    encapsulation/IShapes
                    encapsulation/Events
                    encapsulation/Cursor
                    encapsulation/Color
                    encapsulation/Camera
                    encapsulation/BoundingBox
                    encapsulation/Audio
                    encapsulation/3D
                    encapsulation/3D/model
                    encapsulation/3D/shape/circle
                    encapsulation/3D/shape/cube
                    encapsulation/3D/shape/cylinder
                    encapsulation/3D/shape/line
                    encapsulation/3D/shape/point
                    encapsulation/3D/shape/sphere
                    encapsulation/3D/shape/triangle
                    src/cinematic
                    src/Setting
                    src/Menu
                    src/
                    src/Map
                    src/Game
                    src/Menu
                    cinematic
                    utils
                    game_engine
                    game_engine/objects)

target_link_libraries(${PROJECT_NAME} raylib yaml-cpp)
