/*
** EPITECH PROJECT, 2022
** indie-studio
** File description:
** Picture
*/

#include "Picture.hpp"
#include "Texture.hpp"

ray::Picture::Picture(std::string const &fileName)
{
    this->_pic = LoadImage(fileName.c_str());
}

ray::Picture::Picture(std::string const &fileName, int width, int height, int format, int headerSize)
{
    this->_pic = LoadImageRaw(fileName.c_str(), width, height, format, headerSize);
}

ray::Picture::Picture(std::string const &fileName, int *frames)
{
    this->_pic = LoadImageAnim(fileName.c_str(), frames);
}

ray::Picture::Picture(std::string const &fileName, std::string const &fileData, int dataSize)
{
    this->_pic = LoadImageFromMemory(fileName.c_str(), (const unsigned char *)fileData.c_str(), dataSize);
}

ray::Picture::Picture(Texture2D &tex)
{
    this->_pic = LoadImageFromTexture(tex);
}

ray::Picture::Picture()
{
    this->_pic = LoadImageFromScreen();
}

ray::Picture::~Picture()
{
}

Image ray::Picture::GetImage() const
{
    return this->_pic;
}

void ray::Picture::ClearBackground(Color color)
{
    ImageClearBackground(&this->_pic, color);
}

void ray::Picture::DrawPixel(Vector2 position, Color color)
{
    ImageDrawPixelV(&this->_pic, position, color);
}

void ray::Picture::DrawLine(Vector2 start, Vector2 end, Color color)
{
    ImageDrawLineV(&this->_pic, start, end, color);
}

void ray::Picture::DrawCircle(Vector2 center, int radius, Color color)
{
    ImageDrawCircleV(&this->_pic, center, radius, color);
}

void ray::Picture::DrawRectangle(Vector2 position, Vector2 size, Color color)
{
    ImageDrawRectangleV(&this->_pic, position, size, color);
}

void ray::Picture::DrawRectangleRec(Rectangle rec, Color color)
{
    ImageDrawRectangleRec(&this->_pic, rec, color);
}

void ray::Picture::DrawRectangleLines(Rectangle rec, int thick, Color color)
{
    ImageDrawRectangleLines(&this->_pic, rec, thick, color);
}

void ray::Picture::Draw(Image src, Rectangle srcRec, Rectangle dstRec, Color tint)
{
    ImageDraw(&this->_pic, src, srcRec, dstRec, tint);
}

void ray::Picture::DrawText(std::string const &text, Vector2 position, int fontSize, Color color)
{
    ImageDrawText(&this->_pic, text.c_str(), position.x, position.y, fontSize, color);
} 

void ray::Picture::DrawTextEx(Font font, std::string const &text, Vector2 position, float fontSize, float spacing, Color tint)
{
    ImageDrawTextEx(&this->_pic, font, text.c_str(), position, fontSize, spacing, tint);
}


void ray::Picture::Format(int newFormat)
{
    ImageFormat(&this->_pic, newFormat);
}

void ray::Picture::ToPOT(Color fill)
{
    ImageToPOT(&this->_pic, fill);
}

void ray::Picture::Crop(Rectangle crop)
{
    ImageCrop(&this->_pic, crop);
}

void ray::Picture::AlphaCrop(float threshold)
{
    ImageAlphaCrop(&this->_pic, threshold);
}

void ray::Picture::AlphaClear(Color color, float threshold)
{
    ImageAlphaClear(&this->_pic, color, threshold);
}

void ray::Picture::AlphaMask(Image alphaMask)
{
    ImageAlphaMask(&this->_pic, alphaMask);
}

void ray::Picture::AlphaPremultiply()
{
    ImageAlphaPremultiply(&this->_pic);
}

void ray::Picture::Resize(int newWidth, int newHeight)
{
    ImageResize(&this->_pic, newWidth, newHeight);
}

void ray::Picture::ResizeNN(int newWidth,int newHeight)
{
    ImageResizeNN(&this->_pic, newWidth, newHeight);
}

void ray::Picture::ResizeCanvas(int newWidth, int newHeight, int offsetX, int offsetY, Color fill)
{
    ImageResizeCanvas(&this->_pic, newWidth, newHeight, offsetX, offsetY, fill);
}

void ray::Picture::Mipmaps()
{
    ImageMipmaps(&this->_pic);
}

void ray::Picture::Dither(int rBpp, int gBpp, int bBpp, int aBpp)
{
    ImageDither(&this->_pic, rBpp, gBpp, bBpp, aBpp);
}

void ray::Picture::FlipVertical()
{
    ImageFlipVertical(&this->_pic);
}

void ray::Picture::FlipHorizontal()
{
    ImageFlipHorizontal(&this->_pic);
}

void ray::Picture::RotateCW()
{
    ImageRotateCW(&this->_pic);
}

void ray::Picture::RotateCCW()
{
    ImageRotateCCW(&this->_pic);
}

void ray::Picture::ColorTint(Color color)
{
    ImageColorTint(&this->_pic, color);
}

void ray::Picture::ColorInvert()
{
    ImageColorInvert(&this->_pic);
}

void ray::Picture::ColorGrayscale()
{
    ImageColorGrayscale(&this->_pic);
}

void ray::Picture::ColorContrast(float contrast)
{
    ImageColorContrast(&this->_pic, contrast);
}

void ray::Picture::ColorBrightness(int brightness)
{
    ImageColorBrightness(&this->_pic, brightness);
}

void ray::Picture::ColorReplace(Color color, Color replace)
{
    ImageColorReplace(&this->_pic, color, replace);
}

Rectangle ray::Picture::GetAlphaBorder(float threshold)
{
    return GetImageAlphaBorder(this->_pic, threshold);
}

ray::Color ray::Picture::GetColor(int x, int y)
{
    return Color(GetImageColor(this->_pic, x, y));
}

ray::Picture::Picture(int width, int height, Color color)
{
    this->_pic = GenImageColor(width, height, color);
}


ray::Picture::Picture(int width, int height, Color top, Color side, bool vertical)
{
    if (vertical)
        this->_pic = GenImageGradientV(width, height, top, side);
    else
        this->_pic = GenImageGradientH(width, height, top, side); 
}


ray::Picture::Picture(int width, int height, float density, Color inner, Color outer)
{
    this->_pic = GenImageGradientRadial(width, height, density, inner, outer);
}

ray::Picture::Picture(int width, int height, int checksX, int checksY, Color col1, Color col2)
{
    this->_pic = GenImageChecked(width, height, checksX, checksY, col1, col2);
}

ray::Picture::Picture(int width, int height, float factor)
{
    this->_pic = GenImageWhiteNoise(width, height, factor);
}

ray::Picture::Picture(int width, int height, int tileSize)
{
    this->_pic = GenImageCellular(width, height, tileSize);
}

ray::Picture::Picture(Image image)
{
    this->_pic = ImageCopy(image);
}

ray::Picture::Picture(Image image, Rectangle rec)
{
    this->_pic = ImageFromImage(image, rec);
}

ray::Picture::Picture(std::string const &text, int fontSize, Color color)
{
    this->_pic = ImageText(text.c_str(), fontSize, color);
}

ray::Picture::Picture(Font font, std::string const &text, float fontSize, float spacing, Color tint)
{
    this->_pic = ImageTextEx(font, text.c_str(), fontSize, spacing, tint);
}



bool ray::Picture::Export(std::string const &fileName)
{
    return ExportImage(this->_pic, fileName.c_str());
}

bool ray::Picture::ExportAsCode(std::string const &fileName)
{
    return ExportImageAsCode(this->_pic, fileName.c_str());
}
