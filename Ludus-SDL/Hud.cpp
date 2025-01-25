#include "Hud.h"

Hud::Hud(float x, float y, float w, float h, Texture* texture, const char* text)
    : x(x), y(y), w(w), h(h), texture(texture), textDisplay(text), isString(true), isNumber(false) {}

Hud::Hud(float x, float y, float w, float h, Texture* texture, int number, int numberOfDigits)
    : x(x), y(y), w(w), h(h), texture(texture), numberDisplay(number), isString(false), isNumber(true), numberOfDigits(numberOfDigits) {}

Hud::~Hud() {
    delete texture;
}

void Hud::render() {
    glPushMatrix();
    glTranslatef(x, y, 0.0f);
    texture->Apply();
    if(isNumber) renderNumber();
    else if(isString) renderText();
    else renderSquare(0.0f, 0.0f);
    glPopMatrix(); // Restore the original matrix state
}

int Hud::getNumber(){
    return numberDisplay;
}

void Hud::setNumber(int number) {
    isNumber = true;
    isString = false;
    numberDisplay = number;
}

void Hud::setString(char *text) {
    isString = true;
    isNumber = false;
    textDisplay = text;
}

void Hud::renderSquare(float offset_x, float offset_y) {
    float x1 = (texture->spriteColumn * texture->spriteWidth) / (float)texture->image->w;  // Left coordinate (normalized)
    float y1 = (texture->spriteRow * texture->spriteHeight) / (float)texture->image->h;  // Bottom coordinate (normalized)
    float x2 = ((texture->spriteColumn + 1) * texture->spriteWidth) / (float)texture->image->w;  // Right coordinate (normalized)
    float y2 = ((texture->spriteRow + 1) * texture->spriteHeight) / (float)texture->image->h;  // Top coordinate (normalized)
    glTexCoord2f(offset_x, offset_y);
	glTexCoord2f(x1, y1);
    glVertex2f(-w / 2.f - offset_x, -h / 2.f - offset_y);
    glTexCoord2f(1.0f, 0.0f);
	glTexCoord2f(x2, y1);
    glVertex2f(w / 2.f - offset_x, -h / 2.f - offset_y);
    glTexCoord2f(1.0f, 1.0f);
    glTexCoord2f(x2, y2);
    glVertex2f(w / 2.f - offset_x, h / 2.f - offset_y);
    glTexCoord2f(0.0f, 1.0f);
    glTexCoord2f(x1, y2);
    glVertex2f(-w / 2.f - offset_x, h / 2.f - offset_y);
}

void Hud::renderNumber() {
    int tempNumber = numberDisplay;
    glBegin(GL_QUADS);
    float offset_x = 0.0f;
    int i = 0;
    while(tempNumber != 0 || numberOfDigits > i ){
        int numberToDisplay = tempNumber%10;
        setTextureNumber(numberToDisplay);
        renderSquare(offset_x, 0.0f);
        offset_x += w;
        tempNumber /= 10;
        i++;
    }
    glEnd();
}

void Hud::setTextureNumber(int number){
    if(number > 9) printf("WRONG NUMBER TO DISPLAY\n");
    texture->spriteColumn = number;
    texture->spriteRow = 2 + (texture->spriteColumn/texture->numberOfColumns);
    texture->spriteColumn %= texture->numberOfColumns;
}

void Hud::setTextureText(const char letter){
    int textureStartIndex = letter - ' ';
    texture->spriteColumn = textureStartIndex % texture->numberOfColumns;
    texture->spriteRow = textureStartIndex / texture->numberOfColumns;
}

void Hud::renderText() {
    const char *charIndex = textDisplay;
    glBegin(GL_QUADS);
    float offset_x = 0.0f;
    int i = 0;
    while( *charIndex ){
        setTextureText(*charIndex);
        renderSquare(offset_x, 0.0f);
        offset_x -= w;
        charIndex++;
    }
    glEnd();}