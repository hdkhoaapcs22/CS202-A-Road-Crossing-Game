#include "GUITexture.h"

GUITexture::GUITexture(Rectangle bounds) {
    mRect = bounds;
}

GUITexture::~GUITexture() {
}

void GUITexture::update(float dt) {
}
void GUITexture::draw() {
    Rectangle destRect;
    if (mRect.width == 0 && mRect.height == 0) {
        destRect = {mRect.x, mRect.y, (float)mTexture.width, (float)mTexture.height};
    } else {
        destRect = mRect;
    }
    Rectangle srcRect = {0, 0, (float)mTexture.width, (float)mTexture.height};

    DrawTexturePro(mTexture, srcRect, destRect, {0, 0}, 0, WHITE);
}

void GUITexture::setTexture(Texture2D texture) {
    mTexture = texture;
}
