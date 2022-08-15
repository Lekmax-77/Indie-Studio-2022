/*
** EPITECH PROJECT, 2022
** encapsulation
** File description:
** IWindow
*/

#ifndef IWINDOW_HPP_
#define IWINDOW_HPP_
#include <string>
#include "raylib.h"
#include "Camera.hpp"
#include "Color.hpp"

namespace ray {
    class Window {
        public:
            Window(int width, int height, const std::string &title);
            ~Window();
            /* GETTERS */

            /**
             * @brief Check if window has been initialized successfully
             * 
             * @return true 
             * @return false 
             */
            bool isWindowReady(void) const;
            /**
             * @brief Check if window is currently hidden (only PLATFORM_DESKTOP)
             * 
             * @return true 
             * @return false 
             */
            bool isWindowHidden(void) const;
            /**
             * @brief Check if window is currently focused (only PLATFORM_DESKTOP)
             * 
             * @return true 
             * @return false 
             */
            bool isWindowFocused(void) const;
            /**
             * @brief Check if one specific window flag is enabled
             * 
             * @return true 
             * @return false 
             */
            bool isWindowState(unsigned int flag) const;
            /**
             * @brief Check if window is currently fullscreen
             * 
             * @return true 
             * @return false 
             */
            bool isWindcowFullscreen(void) const;
            /**
             * @brief Check if window has been resized last frame
             * 
             * @return true 
             * @return false 
             */
            bool isWindowResized(void) const;
            /**
             * @brief Check if window is currently maximized (only PLATFORM_DESKTOP)
             * 
             * @return true 
             * @return false 
             */
            bool isWindowMaximized(void) const;
            /**
             * @brief Check if window is currently hidden (only PLATFORM_DESKTOP)
             * 
             * @return true 
             * @return false 
             */
            bool isWindowMinimized(void) const;

            /**
             * @brief Get current screen width
             * 
             * @return int 
             */
            int getScreenWidth(void) const;
            /**
             * @brief Get current screen height
             * 
             * @return int 
             */
            int getScreenHeight(void) const;
            /**
             * @brief Get current screen height
             * 
             * @return int 
             */
            int getMonitorCount(void) const;
            /**
             * @brief Get current connected monitor
             * 
             * @return int 
             */
            int getCurrentMonitor(void) const;
            /**
             * @brief Get specified monitor position
             * 
             * @param monitor int
             * @return Vector2 
             */
            Vector2 getMonitorPosition(int monitor) const;
            /**
             * @brief Get specified monitor width (max available by monitor)
             * 
             * @param monitor int
             * @return int 
             */
            int getMonitorWidth(int monitor) const;
            /**
             * @brief Get specified monitor height (max available by monitor)
             * 
             * @param monitor int windowShouldClose(void
             * @return int 
             */
            int getMonitorHeight(int monitor) const;
            /**
             * @brief Get specified monitor physical width in millimetres
             * 
             * @param monitor int
             * @return int 
             */
            int getMonitorPhysicalWidth(int monitor) const;
            /**
             * @brief Get specified monitor physical height in millimetres
             * 
             * @param monitor int
             * @return int 
             */
            int getMonitorPhysicalHeight(int monitor) const;
            /**
             * @brief Get specified monitor refresh rate
             * 
             * @param monitor int
             * @return int 
             */
            int getMonitorRefreshRate(int monitor) const;
            /**
             * @brief Get window position XY on monitor
             * 
             * @return Vector2 
             */
            Vector2 getWindowPosition(void) const;
            /**
             * @brief Get window scale DPI factor
             * 
             * @return Vector2 
             */
            Vector2 getWindowScaleDPI(void) const;
            /**
             * @brief Get the human-readable, UTF-8 encoded name of the primary monitor
             * 
             * @param monitor int
             * @return const std::string 
             */
            std::string getMonitorName(int monitor) const;
            /**
             * @brief Get clipboard text content
             * 
             * @return const std::string 
             */
            std::string getClipboardText(void) const;

            /* SETTERS */
            /**
             * @brief Set window configuration state using flags
             * 
             * @param flag unsigned int
             */
            void setWindowState(unsigned int flag);
            /**
             * @brief Set title for window (only PLATFORM_DESKTOP)
             * 
             * @param title const std::string
             */
            void setWindowTitle(const std::string &title);
            /**
             * @brief Set window position on screen (only PLATFORM_DESKTOP)
             * 
             * @param x int
             * @param y int
             */
            void setWindowPosition(int x, int y);
            /**
             * @brief Set monitor for the current window (fullscreen mode)
             * 
             * @param monitor int
             */
            void setWindowMonitor(int monitor);
            /**
             * @brief Set window minimum dimensions (for FLAG_WINDOW_RESIZABLE)
             * 
             * @param width 
             * @param height 
             */
            void setWindowMinSize(int width, int height);
            /**
             * @brief Set window dimensions
             * 
             * @param width int
             * @param height int
             */
            void setWindowSize(int width, int height);
            /**
             * @brief Set clipboard text content
             * 
             * @param text const std::string
             */
            void setClipboardText(const std::string &text);

            /* OTHERS */

            /**
             * @brief Clear window configuration state flags
             * 
             * @param flag 
             */
            void clearWindowState(unsigned int flag) ;
            /**
             * @brief Toggle window state: fullscreen/windowed (only PLATFORM_DESKTOP)
             * 
             */
            void toggleFullscreen(void);
            /**
             * @brief Set window state: maximized, if resizable (only PLATFORM_DESKTOP)
             * 
             */
            void maximizeWindow(void);
            /**
             * @brief Set window state: minimized, if resizable (only PLATFORM_DESKTOP)
             * 
             */
            void minimizeWindow(void);
            /**
             * @brief Set window state: not minimized/maximized (only PLATFORM_DESKTOP)
             * 
             */
            void restoreWindow(void);
            /**
             * @brief Check if KEY_ESCAPE pressed or Close icon pressed
             * 
             * @return true 
             * @return false 
             */
            bool windowShouldClose(void) const;
            /**
             * @brief Set background color (framebuffer clear color)
             * 
             * @param color Color
             */
            void clearBackground(Color color);

            /* END */

            /**
             * @brief End canvas drawing and swap buffers (double buffering)
             * 
             */
            void endDrawing(void);
            /**
             * @brief Ends 2D mode with custom camera
             * 
             */
            void endMode2D(void);
            /**
             * @brief Ends 3D mode and returns to default 2D orthographic mode
             * 
             */
            void endMode3D(void);
            /**
             * @brief Ends drawing to render texture
             * 
             */
            void endTextureMode(void);
            /**
             * @brief End custom shader drawing (use default shader)
             * 
             */
            void endShaderMode(void);
            /**
             * @brief End blending mode (reset to default: alpha blending)
             * 
             */
            void endBlendMode(void);
            /**
             * @brief End scissor mode
             * 
             */
            void endScissorMode(void);

            /* BEGIN */

            /**
             * @brief Setup canvas (framebuffer) to start drawing
             * 
             */
            void beginDrawing(void);
            /**
             * @brief Begin 2D mode with custom camera (2D)
             * 
             * @param camera Camera2D
             */
            void beginMode2D(ray::Camera2D &camera);
            /**
             * @brief Begin 3D mode with custom camera (3D)
             * 
             * @param camera Camera3D
             */
            void beginMode3D(ray::Camera3D &camera);
            /**
             * @brief Begin drawing to render texture
             * 
             * @param target RenderTexture2D
             */
            void beginTextureMode(RenderTexture2D target);
            /**
             * @brief Ends drawing to render texture
             * 
             * @param shader Shader
             */
            void beginShaderMode(Shader shader);
            /**
             * @brief Begin blending mode (alpha, additive, multiplied, subtract, custom)
             * 
             * @param mode int
             */
            void beginBlendMode(int mode);
            /**
             * @brief Begin scissor mode (define screen area for following drawing)
             * 
             * @param x int
             * @param y int
             * @param width int
             * @param height int
             */
            void beginScissorMode(int x, int y, int width, int height);
    };
};

#endif /* !IWINDOW_HPP_ */
