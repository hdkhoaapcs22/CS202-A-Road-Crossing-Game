#include "Animation.h"

Animation::Animation()
: mSpriteSheet(Texture2D())
, mFrameSize(Vector2())
, mNumFrames(0)
, mCurrentFrame(0)
, mDuration(0)
, mElapsedTime(0)
, mRepeated(false) {
}

void Animation::update(float dt) {
    float timePerFrame = mDuration / mNumFrames;
    mElapsedTime += dt;

    while (mElapsedTime >= timePerFrame
           && (mCurrentFrame <= mNumFrames || mRepeated)) {
        mElapsedTime -= timePerFrame;

        if (mFrameGridPosition.x + 1 < mSpriteSheetGridSize.x) {
            mFrameGridPosition.x++;
        } else {
            mFrameGridPosition.x = 0;
            mFrameGridPosition.y =
                (int)(mFrameGridPosition.y + 1) % (int)mSpriteSheetGridSize.y;
        }

        if (mRepeated) {
            mCurrentFrame = (mCurrentFrame + 1) % mNumFrames;
        } else {
            mCurrentFrame++;
        }
    }
}

void Animation::draw(Vector2 position, Vector2 size) {
    if (size.x == 0 && size.y == 0) {
        size = mFrameSize;
    }

    Rectangle sourceRect = {mFrameGridPosition.x * mFrameSize.x,
                            mFrameGridPosition.y * mFrameSize.y, mFrameSize.x,
                            mFrameSize.y};

    Rectangle destRect = {position.x, position.y, size.x, size.y};

    DrawTextureNPatch(mSpriteSheet,
                      NPatchInfo({sourceRect, 0, 0, 0, 0, NPATCH_NINE_PATCH}),
                      destRect, {0, 0}, 0, WHITE);
}

void Animation::setSpriteSheet(const Texture2D& spriteSheet) {
    mSpriteSheet = spriteSheet;
}

Texture2D Animation::getSpriteSheet() const {
    return mSpriteSheet;
}

void Animation::setSpriteSheetGridSize(const Vector2& spriteSheetGridSize) {
    mSpriteSheetGridSize = spriteSheetGridSize;
}

Vector2 Animation::getSpriteSheetGridSize() const {
    return mSpriteSheetGridSize;
}

void Animation::setFrameSize(const Vector2& frameSize) {
    mFrameSize = frameSize;
}

Vector2 Animation::getFrameSize() const {
    return mFrameSize;
}

void Animation::setNumFrames(int numFrames) {
    mNumFrames = numFrames;
}

int Animation::getNumFrames() const {
    return mNumFrames;
}

void Animation::setDuration(float duration) {
    mDuration = duration;
}

float Animation::getDuration() const {
    return mDuration;
}

void Animation::setRepeating(bool flag) {
    mRepeated = flag;
}

bool Animation::isRepeating() const {
    return mRepeated;
}

void Animation::restart() {
    mCurrentFrame = 0;
}

bool Animation::isFinished() const {
    return mCurrentFrame >= mNumFrames;
}
