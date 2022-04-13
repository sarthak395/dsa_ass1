#ifndef SONG_H
#define SONG_H

typedef struct Song
{
    char *name;
    char *artist;
    float duration;

    struct Song * next ; //as we are using queue ADT
}song;

song* makeSong(char* name_,char * artist_,float duration_);

#endif