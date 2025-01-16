#include "Texture.h"

Texture::Texture(const char* image_path, int numberOfRows, int numberOfColumns) {
    image = SDL_LoadBMP(image_path);
    if (!image) {
        std::cerr << "Error loading image: " << SDL_GetError() << std::endl;
        exit(0);
    }
    SDL_PixelFormat* format = image->format;

    // Print the pixel format
    printf("Pixel Format Information:\n");
    printf("Bits per pixel: %d\n", format->BitsPerPixel);
    printf("Bytes per pixel: %d\n", format->BytesPerPixel);
    printf("R mask: 0x%X\n", format->Rmask);
    printf("G mask: 0x%X\n", format->Gmask);
    printf("B mask: 0x%X\n", format->Bmask);
    printf("A mask: 0x%X\n", format->Amask);
    printf("R shift: %d\n", format->Rshift);
    printf("G shift: %d\n", format->Gshift);
    printf("B shift: %d\n", format->Bshift);
    printf("A shift: %d\n", format->Ashift);
    printf("Pixel format: %s\n", SDL_GetPixelFormatName(image->format->format));
    printf("%d %d %d\n", sizeof((Uint8*)image->pixels), image->h, image->w);
    SDL_Surface* rgbaImage = SDL_CreateRGBSurfaceWithFormat(0, image->w, image->h, 32, SDL_PIXELFORMAT_RGBA32);
    int offset1 = 0;
    int offset2 = 0;
    Uint8 *imagePixels = (Uint8*)image->pixels;
    Uint8 *OutputPixels = (Uint8*)rgbaImage->pixels;
     for (int y = 0; y < image->h; ++y) {
        for (int x = 0; x < image->w; ++x) {

            // Extract RGB components
            Uint8 b = imagePixels[offset1++];
            Uint8 g = imagePixels[offset1++];
            Uint8 r = imagePixels[offset1++];

            OutputPixels[offset2++] = r;
            OutputPixels[offset2++] = g;
            OutputPixels[offset2++] = b;
            if( distance(r, g, b, 0xFF, 0x00, 0xFF) < 50)
                OutputPixels[offset2++] = 0;
            else
                OutputPixels[offset2++] = 255;
        }
    }
    SDL_FreeSurface(image);
    image = rgbaImage;
    rgbaImage->w = image->w;
    rgbaImage->h = image->h;
    glGenTextures(1, &textures);
    spriteWidth = image->w / numberOfColumns;
    spriteHeight = image->h / numberOfRows;
    this->numberOfColumns = numberOfColumns;
    this->numberOfRows = numberOfRows;
    spriteRow = 0;
    spriteColumn = 0;
}


int Texture::distance(Uint8 x, Uint8 y, Uint8 z, Uint8 x2, Uint8 y2, Uint8 z2){
    int dx = x2 - x;
    int dy = y - y2;
    int dz = z2 - z;
    int dist = dx + dy + dz;
    return dist;
}

void Texture::Apply() {
    glBindTexture(GL_TEXTURE_2D, textures);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image->w, image->h, 0, GL_RGBA, GL_UNSIGNED_BYTE, image->pixels);
}

void Texture::cycleLeft(){
    spriteColumn = spriteColumn == 0 ? numberOfColumns : spriteColumn -1;
}

void Texture::cycleRigth(){
    spriteColumn = (spriteColumn + 1) % numberOfColumns;
}

void Texture::fulllCycle(){
    spriteColumn += 1;
    spriteRow += spriteColumn/numberOfColumns;
    spriteColumn %= numberOfColumns;
    spriteRow %= numberOfColumns;
}

void Texture::moveSprite(int row, int column){
    spriteRow = row;
    spriteColumn = column;
}