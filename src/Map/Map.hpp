/*
** EPITECH PROJECT, 2022
** indiestudio
** File description:
** Map
*/

#ifndef MAP_HPP_
#define MAP_HPP_

#include <vector>

namespace indie
{
    namespace map
    {
        static const int WALLBLOCK = 2;
        static const int BRICKBLOCK = 1;
        static const int EMPTYBLOCK = 0;

        class Map
        {
        public:
            // Constructor
            Map(int width = 13, int height = 11, int density = 80);

            // Destructor
            ~Map();

            // Getters
            std::vector<std::vector<int>> getMap() const;
            int getWidth() const;
            int getHeight() const;

            // Setters
            void setMap(std::vector<std::vector<int>> map);
            void setWidth(int width);
            void setHeight(int height);

            // Methods
            void Reset(int width = 13, int height = 11, int density = 80);
            void generateMap(int width, int height, int density = 80);

            // Operators
            std::vector<int> &operator[](int x) { return _map[x]; }
        protected:
        private:
            int _width;
            int _height;
            std::vector<std::vector<int>> _map;
        };
    }
}

#endif /* !MAP_HPP_ */
