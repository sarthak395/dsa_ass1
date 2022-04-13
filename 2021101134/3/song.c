#include "song.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

song *makeSong(char *name_, char *artist_, float duration_)
{
    song *newsong = (song *)malloc(sizeof(song));
    assert(newsong != NULL);

    newsong->name = name_;
    newsong->artist = artist_;
    newsong->duration = duration_;
    newsong->next = NULL;

    return newsong;
}