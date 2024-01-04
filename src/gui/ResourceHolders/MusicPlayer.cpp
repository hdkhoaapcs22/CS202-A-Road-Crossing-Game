#include "MusicPlayer.h"

MusicPlayer::MusicPlayer()
: mVolume(100) {
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
    UpdateMusicStream(mMusic);
}

void MusicPlayer::stop() {
    StopMusicStream(mMusic);
}

void MusicPlayer::setVolume(int volume) {
    mVolume = volume;
    SetMusicVolume(mMusic, mVolume / 100.f);
}

int MusicPlayer::getVolume() const {
    return mVolume;
}
