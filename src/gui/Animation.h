#ifndef SRC_GUI_ANIMATION_H
#define SRC_GUI_ANIMATION_H

#include "raylib.h"

#include <string>
#include <vector>

class Animation {
public:
    Animation();
    
    void update(float dt);
    void draw(Vector2 position, Vector2 size = {0, 0});

    void setSpriteSheet(const Texture2D& spriteSheet);
    Texture2D getSpriteSheet() const;

    void setSpriteSheetGridSize(const Vector2& spriteSheetGridSize);
    Vector2 getSpriteSheetGridSize() const;

    void setNumFrames(int numFrames);
    int getNumFrames() const;

    void setDuration(float duration);
    float getDuration() const;

    void setRepeating(bool flag);
    bool isRepeating() const;

    void restart();
    bool isFinished() const;

    void setHorizontalFlipped(bool flag);
    void setVerticalFlipped(bool flag);

private:
    Texture2D mSpriteSheet;
    Vector2 mSpriteSheetGridSize;
    Vector2 mFrameGridPosition;
    int mNumFrames;
    int mCurrentFrame;
    float mDuration;
    float mElapsedTime;
    bool mRepeated;

    bool isHorizontalFlipped{false};
    bool isVerticalFlipped{false};
};

#endif // SRC_GUI_ANIMATION_H
