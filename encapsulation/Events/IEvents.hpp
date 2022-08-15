/*
** EPITECH PROJECT, 2022
** indie
** File description:
** IEvents
*/

#ifndef IEVENTS_HPP_
#define IEVENTS_HPP_
#include "raylib.h"

namespace ray {
    class KeyEvents {
        public:
        /**
         * @brief Check if a key has been pressed once
         *
         * @param key int
         * @return true
         * @return false
         */
        bool isKeyPressed(int key) const;
        /**
         * @brief Check if a key is being pressed
         * 
         * @param key int
         * @return true 
         * @return false 
         */
        bool isKeyDown(int key) const;
        /**
         * @brief Check if a key has been released once
         * 
         * @param key int
         * @return true 
         * @return false 
         */
        bool isKeyReleased(int key) const;
        /**
         * @brief Check if a key is NOT being pressed
         * 
         * @param key int
         * @return true 
         * @return false 
         */
        bool isKeyUp(int key) const;
        /**
         * @brief set a custom key to exit program (default is ESC)
         * 
         * @param key int
         */
        void setExitKey(int key);
        /**
         * @brief get key pressed (keycode), call it multiple times for keys queued, returns 0 when the queue is empty
         * 
         * @return int 
         */
        int getKeyPressed(void) const;
        /**
         * @brief get char pressed (unicode), call it multiple times for chars queued, returns 0 when the queue is empty
         * 
         * @return int 
         */
        int getCharPressed(void) const;
    };

    class MouseEvents/* : virtual public IEvents*/ {
        public:
        /**
         * @brief Check if a mouse button has been pressed once
         * 
         * @param button int
         * @return true 
         * @return false 
         */
        bool isMouseButtonPressed(int button) const;
        /**
         * @brief Check if a mouse button is being pressed
         * 
         * @param button int
         * @return true 
         * @return false 
         */
        bool isMouseButtonDown(int button) const;
        /**
         * @brief Check if a mouse button has been released once
         * 
         * @param button int
         * @return true 
         * @return false 
         */
        bool isMouseButtonReleased(int button) const;
        /**
         * @brief Check if a mouse button is NOT being pressed
         * 
         * @param button int
         * @return true 
         * @return false 
         */
        bool isMouseButtonUp(int button) const;
        /**
         * @brief get mouse position X
         * 
         * @return int
         */
        int getMouseX(void) const;
        /**
         * @brief get mouse position Y
         * 
         * @return int 
         */
        int getMouseY(void) const;
        /**
         * @brief get mouse position XY
         * 
         * @return Vector2 
         */
        Vector2 getMousePosition(void) const;
        /**
         * @brief get mouse delta between frames
         * 
         * @return Vector2 
         */
        Vector2 getMouseDelta(void) const;
        /**
         * @brief set mouse position XY
         * 
         * @param x int
         * @param y int
         */
        void setMousePosition(int x, int y);
        /**
         * @brief set mouse offset
         * 
         * @param offsetX int
         * @param offsetY int
         */
        void setMouseOffset(int offsetX, int offsetY);
        /**
         * @brief set mouse scaling
         * 
         * @param scaleX float
         * @param scaleY float
         */
        void setMouseScale(float scaleX, float scaleY);
        /**
         * @brief get mouse wheel movement Y
         * 
         * @return float 
         */
        float getMouseWheelMove(void) const;
        /**
         * @brief set mouse cursor
         * 
         * @param cursor int
         */
        void setMouseCursor(int cursor);
    };

    class TouchEvents   {
        public:
        /**
         * @brief get touch position X for touch point 0 (relative to screen size)
         * 
         * @return int 
         */
        int getTouchX(void) const;
        /**
         * @brief get touch position Y for touch point 0 (relative to screen size)
         * 
         * @return int 
         */
        int getTouchY(void) const;
        /**
         * @brief get touch position XY for a touch point index (relative to screen size)
         * 
         * @param index int
         * @return Vector2 
         */
        Vector2 getTouchPosition(int index) const;
        /**
         * @brief get touch point position for given index
         * 
         * @param index int
         * @return int 
         */
        int getTouchPointId(int index) const;
        /**
         * @brief get touch point identifier for given index
         * 
         * @return int 
         */
        int getTouchPointCount(void) const;
    };
};

#endif /* !IEVENTS_HPP_ */
