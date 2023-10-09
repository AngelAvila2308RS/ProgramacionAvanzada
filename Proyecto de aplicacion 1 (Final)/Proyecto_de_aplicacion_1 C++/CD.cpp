#include "CD.h"

CD::CD() : songCount(0) {}

CD::~CD() {}

void CD::setName(string& cdName) {
    name = cdName;
}

const string& CD::getName() const{
    return name;
}

void CD::addSong(const Song& song) {
    if (songCount < MAXSONGCOUNT) {
        songs[songCount++] = song;
    }
}

int CD::getSongCount() const{
    return songCount;
}

const Song& CD::getSong(int index) const{
    return songs[index];
}

