#include "MusicPlayer.h"

MusicPlayer::MusicPlayer()
: mVolume(100), isMuted(false) {
    std::string BASE_PATH = "asset/audio/";
    mFilenames[MusicID::MenuTheme] = BASE_PATH + "ThemeMenu.mp3";
    mFilenames[MusicID::GameTheme] = BASE_PATH + "ThemeGame.mp3";
}

void MusicPlayer::play(MusicID theme) {
    std::string filename = mFilenames[theme];

    mMusic = LoadMusicStream(filename.c_str());
    mMusic.looping = true;

    SetMusicVolume(mMusic, mVolume / 100.f);
    PlayMusicStream(mMusic);
}

void MusicPlayer::update() {
    if (IsMusicReady(mMusic)) {
        if (isMuted) {
            SetMusicVolume(mMusic, 0);
        } else {
            SetMusicVolume(mMusic, mVolume / 100.f);
        }
        UpdateMusicStream(mMusic);
    }
}

void MusicPlayer::stop() {
    StopMusicStream(mMusic);
}

void MusicPlayer::setVolume(int volume) {
    mVolume = volume;
}

int MusicPlayer::getVolume() const {
    return mVolume;
}

void MusicPlayer::setMuted(bool muted) {
    isMuted = muted;
}

bool MusicPlayer::getMuted() const {
    return isMuted;
}
