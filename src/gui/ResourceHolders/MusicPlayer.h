#ifndef SRC_GUI_RESOURCEHOLDERS_MUSICPLAYER_H
#define SRC_GUI_RESOURCEHOLDERS_MUSICPLAYER_H

#include "ResourceIdentifiers.h"

#include "raylib.h"

#include <map>
#include <string>

class MusicPlayer {
public:
    MusicPlayer();

    void play(MusicID theme);
    void update();
    void stop();

    void setVolume(int volume);
    int getVolume() const;

    void setMuted(bool muted);
    bool getMuted() const;
private:
    std::map<MusicID, std::string> mFilenames;
    Music mMusic;
    int mVolume;

    bool isMuted;
};

#endif // SRC_GUI_RESOURCEHOLDERS_MUSICPLAYER_H
