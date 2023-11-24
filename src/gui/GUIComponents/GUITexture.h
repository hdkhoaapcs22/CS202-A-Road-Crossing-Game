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

private:
    Texture2D mTexture;
};

#endif // SRC_GUI_GUICOMPONENTS_GUITEXTURE_H
