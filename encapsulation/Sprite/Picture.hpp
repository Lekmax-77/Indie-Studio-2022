/*
** EPITECH PROJECT, 2022
** indie-studio
** File description:
** Image
*/

#ifndef IMAGE_HPP_
    #define IMAGE_HPP_
    #include <raylib.h>
    #include <string>
    #include "Vector2.hpp"
    #include "Color.hpp"

namespace ray
{
    class Picture {
        public: 
            /**
             * @brief Construct a new Picture object, Load image from file into CPU memory (RAM)
             * 
             * @param fileName path to Image
             */
            Picture(std::string const &fileName);
            /**
             * @brief Destroy the Picture object, Unload image from CPU memory (RAM)
             * 
             */
            ~Picture();
            /**
             * @brief Construct a new Picture object, Load image from RAW file data
             * 
             * @param fileName string to filepath
             * @param width int to Width of Image
             * @param height int to Height of Image
             * @param format int to Format of Image
             * @param headerSize int to Header Size of Image
             */
            Picture(std::string const &fileName, int width, int height, int format, int headerSize);
            /**
             * @brief Construct a new Picture object, Load image sequence from file (frames appended to image.data)
             * 
             * @param fileName path to Image
             * @param frames    int to number of frames
             */
            Picture(std::string const &fileName, int *frames);
            /**
             * @brief Construct a new Picture object, Load image from memory buffer
             * 
             * @param fileName 
             * @param fileData 
             * @param dataSize 
             */
            Picture(std::string const &fileName, std::string const &fileData, int dataSize);
            /**
             * @brief Construct a new Picture object, Load image from GPU texture data
             * 
             * @param tex 
             */
            Picture(Texture2D &tex);
            /**
             * @brief Construct a new Picture object,  Load image from screen buffer and (screenshot)
             * 
             */
            Picture();
            /**
             * @brief Construct a new Picture object, Generate image: plain color
             * 
             * @param width 
             * @param height 
             * @param color 
             */
            Picture(int width, int height, Color color);
            /**
             * @brief Construct a new Picture object, Generate image: vertical gradient and Generate image: horizontal gradient
             * 
             * @param width 
             * @param height 
             * @param top 
             * @param bord 
             * @param side 
             */
            Picture(int width, int height, Color top, Color side, bool vertical);
            /**
             * @brief Construct a new Picture object, Generate image: radial gradient
             * 
             * @param width 
             * @param height 
             * @param density 
             * @param inner 
             * @param outer 
             */
            Picture(int width, int height, float density, Color inner, Color outer);
            /**
             * @brief Construct a new Picture object, Generate image: checked
             * 
             * @param width 
             * @param height 
             * @param checksX 
             * @param checksY 
             * @param col1 
             * @param col2 
             */
            Picture(int width, int height, int checksX, int checksY, Color col1, Color col2);
            /**
             * @brief Construct a new Picture object
             * 
             * @param width 
             * @param height 
             * @param factor 
             */
            Picture(int width, int height, float factor);                                                    // Generate image: white noise
            /**
             * @brief Construct a new Picture object
             * 
             * @param width 
             * @param height 
             * @param tileSize 
             */
            Picture(int width, int height, int tileSize);                                                    // Generate image: cellular algorithm. Bigger tileSize means bigger cells
            /**
             * @brief Construct a new Picture object
             * 
             * @param image 
             */
            Picture(Image image);                                                                            // Create an image duplicate (useful for transformations)
            /**
             * @brief Construct a new Picture object
             * 
             * @param image 
             * @param rec 
             */
            Picture(Image image, Rectangle rec);                                                             // Create an image from another image piece
            /**
             * @brief Construct a new Picture object
             * 
             * @param text 
             * @param fontSize 
             * @param color 
             */
            Picture(std::string const &text, int fontSize, Color color);                                     // Create an image from text (default font)
            /**
             * @brief Construct a new Picture object
             * 
             * @param font 
             * @param text 
             * @param fontSize 
             * @param spacing 
             * @param tint 
             */
            Picture(Font font, std::string const &text, float fontSize, float spacing, Color tint);          // Create an image from text (custom sprite font)
            /**
             * @brief Get the Image object
             * 
             * @return Image 
             */
            Image GetImage() const;                                                                         // get Image
            /**
             * @brief 
             * 
             * @param color 
             */
            void ClearBackground(Color color);                                                              // Clear image background with given color
            /**
             * @brief 
             * 
             * @param position 
             * @param color 
             */
            void DrawPixel(Vector2 position, Color color);                                                  // Draw pixel within an image
            /**
             * @brief 
             * 
             * @param start 
             * @param end 
             * @param color 
             */
            void DrawLine(Vector2 start, Vector2 end, Color color);                                         // Draw line within an image (Vector version)
            /**
             * @brief 
             * 
             * @param center 
             * @param radius 
             * @param color 
             */
            void DrawCircle(Vector2 center, int radius, Color color);                                       // Draw circle within an image (Vector version)
            /**
             * @brief 
             * 
             * @param position 
             * @param size 
             * @param color 
             */
            void DrawRectangle(Vector2 position, Vector2 size, Color color);                                // Draw rectangle within an image (Vector version)
            /**
             * @brief 
             * 
             * @param rec 
             * @param color 
             */
            void DrawRectangleRec(Rectangle rec, Color color);                                              // Draw rectangle within an image
            /**
             * @brief 
             * 
             * @param rec 
             * @param thick 
             * @param color 
             */
            void DrawRectangleLines(Rectangle rec, int thick, Color color);                                 // Draw rectangle lines within an image
            /**
             * @brief 
             * 
             * @param src 
             * @param srcRec 
             * @param dstRec 
             * @param tint 
             */
            void Draw(Image src, Rectangle srcRec, Rectangle dstRec, Color tint);                           // Draw a source image within a destination image (tint applied to source)
            /**
             * @brief 
             * 
             * @param text 
             * @param position 
             * @param fontSize 
             * @param color 
             */
            void DrawText(const std::string &text, Vector2 position, int fontSize, Color color);            // Draw text (using default font) within an image (destination)
            /**
             * @brief 
             * 
             * @param font 
             * @param text 
             * @param position 
             * @param fontSize 
             * @param spacing 
             * @param tint 
             */
            void DrawTextEx(Font font, std::string const &text, Vector2 position, float fontSize, float spacing, Color tint);                                                     // Draw text (custom sprite font) within an image (
            /**
             * @brief 
             * 
             * @param newFormat 
             */
            void Format(int newFormat);                                                                     // Convert image data to desired format
            /**
             * @brief 
             * 
             * @param fill 
             */
            void ToPOT(Color fill);                                                                         // Convert image to POT (power-of-two)
            /**
             * @brief 
             * 
             * @param crop 
             */
            void Crop(Rectangle crop);                                                                      // Crop an image to a defined rectangle
            /**
             * @brief 
             * 
             * @param threshold 
             */
            void AlphaCrop(float threshold);                                                                // Crop image depending on alpha value
            /**
             * @brief 
             * 
             * @param color 
             * @param threshold 
             */
            void AlphaClear(Color color, float threshold);                                                  // Clear alpha channel to desired color
            /**
             * @brief 
             * 
             * @param alphaMask 
             */
            void AlphaMask(Image alphaMask);                                                                // Apply alpha mask to image
            /**
             * @brief 
             * 
             */
            void AlphaPremultiply();                                                                        // Premultiply alpha channel
            /**
             * @brief 
             * 
             * @param newWidth 
             * @param newHeight 
             */
            void Resize(int newWidth, int newHeight);                                                       // Resize image (Bicubic scaling algorithm)
            /**
             * @brief 
             * 
             * @param newWidth 
             * @param newHeight 
             */
            void ResizeNN(int newWidth,int newHeight);                                                      // Resize image (Nearest-Neighbor scaling algorithm)
            /**
             * @brief 
             * 
             * @param newWidth 
             * @param newHeight 
             * @param offsetX 
             * @param offsetY 
             * @param fill 
             */
            void ResizeCanvas(int newWidth, int newHeight, int offsetX, int offsetY, Color fill);           // Resize canvas and fill with color
            /**
             * @brief 
             * 
             */
            void Mipmaps();                                                                                 // Generate all mipmap levels for a provided image
            /**
             * @brief 
             * 
             * @param rBpp 
             * @param gBpp 
             * @param bBpp 
             * @param aBpp 
             */
            void Dither(int rBpp, int gBpp, int bBpp, int aBpp);                                            // Dither image data to 16bpp or lower (Floyd-Steinberg dithering)
            /**
             * @brief 
             * 
             */
            void FlipVertical();                                                                            // Flip image vertically
            /**
             * @brief 
             * 
             */
            void FlipHorizontal();                                                                          // Flip image horizontally
            /**
             * @brief 
             * 
             */
            void RotateCW();                                                                                // Rotate image clockwise 90deg
            /**
             * @brief 
             * 
             */
            void RotateCCW();                                                                               // Rotate image counter-clockwise 90deg
            /**
             * @brief 
             * 
             * @param color 
             */
            void ColorTint(Color color);                                                                    // Modify image color: tint
            /**
             * @brief 
             * 
             */
            void ColorInvert();                                                                             // Modify image color: invert
            /**
             * @brief 
             * 
             */
            void ColorGrayscale();                                                                          // Modify image color: grayscale
            /**
             * @brief 
             * 
             * @param contrast 
             */
            void ColorContrast(float contrast);                                                             // Modify image color: contrast (-100 to 100)
            /**
             * @brief 
             * 
             * @param brightness 
             */
            void ColorBrightness(int brightness);                                                           // Modify image color: brightness (-255 to 255)
            /**
             * @brief 
             * 
             * @param color 
             * @param replace 
             */
            void ColorReplace(Color color, Color replace);                                                  // Modify image color: replace color
            /**
             * @brief Get the Alpha Border object
             * 
             * @param threshold 
             * @return Rectangle 
             */
            Rectangle GetAlphaBorder(float threshold);                                                      // Get image alpha border rectangle
            /**
             * @brief Get the Color object
             * 
             * @param x 
             * @param y 
             * @return Color 
             */
            Color GetColor(int x, int y);                                                                   // Get image pixel color at (x, y) position  
            /**
             * @brief 
             * 
             * @param fileName 
             * @return true 
             * @return false 
             */
            bool Export(std::string const &fileName);                                                       // Export image data to file, returns true on success
            /**
             * @brief 
             * 
             * @param fileName 
             * @return true 
             * @return false 
             */
            bool ExportAsCode(std::string const &fileName);                                                 // Export image as code file defining an array of bytes, returns true on success

            
        private:
            Image _pic;
    };
};

#endif /* !IMAGE_HPP_ */

