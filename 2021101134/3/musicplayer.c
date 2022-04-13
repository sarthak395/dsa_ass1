#include "musicplayer.h"
#include <stdlib.h>
#include <assert.h>

musicPlayer *createMusicPlayer()
{
    musicPlayer *newplayer = (musicPlayer *)malloc(sizeof(musicPlayer));
    assert(newplayer != NULL);

    newplayer->playing_song = NULL;
    newplayer->current_song = NULL;
    newplayer->Queue = NULL;

    return newplayer;
}

int addsongtoQueue(musicPlayer *mp, song *s)
{
    // if mp is empty
    if (s == NULL)
        return 1;

    if (mp->Queue == NULL) //when musicplayer is empty
    {
        mp->Queue = (que *)malloc(sizeof(que));

        if (mp->Queue == NULL)
            return 1;

        mp->current_song = s;
        mp->Queue->rear = s;

        return 0;
    }

    // else
    else
    {
        mp->Queue->rear->next = s;
        mp->Queue->rear = s;

        return 0;
    }
}

int removeSongFromQueue(musicPlayer *mp, int pos)
{
    if((mp->Queue==NULL)||(pos<0))
        return 1;

    song *currsongptr = mp->current_song;

    int i = 0;

    // removing the first element
    if (pos == 0)
    {
        mp->current_song = currsongptr->next;
        free(currsongptr);
        return 0;
    }

    song *prevsongptr = currsongptr;
    currsongptr = currsongptr->next;

    while (i < pos)
    {
        prevsongptr = currsongptr;
        currsongptr = currsongptr->next;
        i++;
        if(currsongptr==NULL)
            return 1;
    }

    // now currsongptr points to pos
    prevsongptr->next = currsongptr->next;
    free(currsongptr);
    return 0;
}

int playsong(musicPlayer *mp)
{
    if(mp->Queue==NULL) //if musicplayer is empty
        return 1;
        
    mp->playing_song = mp->current_song;
    song *tempsong = mp->current_song;
    mp->current_song = mp->current_song->next;
    free(tempsong);

    return 0;
}

song *getCurrentSong(musicPlayer *mp)
{
    return mp->playing_song;
}
