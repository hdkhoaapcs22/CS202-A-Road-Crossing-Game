#ifndef SRC_GUI_GUICOMPONENTS_GUITEXTURE_H
#define SRC_GUI_GUICOMPONENTS_GUITEXTURE_H

#include "GUIComponent.h"

#include "raylib.h"

class GUITexture : public GUIComponent {
public:
    typedef std::shared_ptr<GUITexture> Ptr;

public:
    explicit GUITexture(Rectangle bounds = {0, 0, 0, 0});
    ~GUITexture();

    void update(float dt);
    void draw();

    void setTexture(Texture2D texture);
    Texture2D getTexture() const;

    void setHorizontalFlipped(bool flipped);
    void setVerticalFlipped(bool flipped);
    void setHidden(bool hidden);

private:
    Texture2D mTexture;

    bool isHorizontalFlipped{false};
    bool isVerticalFlipped{false};

    bool isHidden{false};
};

#endif // SRC_GUI_GUICOMPONENTS_GUITEXTURE_H
