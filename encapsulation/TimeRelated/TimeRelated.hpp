/*
** EPITECH PROJECT, 2022
** indie
** File description:
** ITimeRelated
*/

#ifndef ITIMERELATED_HPP_
#define ITIMERELATED_HPP_

namespace ray {
    class TimeRelated {
        public:
        TimeRelated();
        ~TimeRelated();
        /**
         * @brief Set target FPS (maximum)
         *
         * @param fps int
         */
        static void setTargetFPS(int fps);
        /**
         * @brief Get current FPS
         *
         * @return int
         */
        static int getFPS(void);
        /**
         * @brief Get time in seconds for last frame drawn (delta time)
         *
         * @return float
         */
        static float getFrameTime(void);
        /**
         * @brief Get elapsed time in seconds since InitWindow()
         *
         * @return double
         */
        static double getTime(void);
        static void drawFPS(int x, int y);
    };
}

#endif /* !ITIMERELATED_HPP_ */
