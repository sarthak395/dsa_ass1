#ifndef MUSIC_H
#define MUSIC_H
#include "song.h"

typedef struct que_
{
    song *rear; // pointer to the last song in que
} que;

typedef struct MusicPlayer
{
    song *playing_song;
    song *current_song; // first song of queue
    que *Queue;
} musicPlayer;

musicPlayer *createMusicPlayer();
int addsongtoQueue(musicPlayer *mp, song *s);
int removeSongFromQueue(musicPlayer *mp, int pos);
int playsong(musicPlayer *mp);
song *getCurrentSong(musicPlayer *mp);

#endif