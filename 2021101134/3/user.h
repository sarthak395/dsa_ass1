#ifndef USER_H
#define USER_H
#include "musicplayer.h"

typedef struct node_
{
    song* Song; //actual song
    struct node_* next;
}node;

typedef struct list_
{
    node* root;//pointing to current node
}list;

typedef struct User
{
    char * name;
    musicPlayer* MusicPlayer;
    list*  liked_songs; //storing liked songs in linked lists , kind of
}user;

user* createUser(char* username);
int addSongToQueueUser(user* User,song* Song);
int removeSongFromQueueUser(user* User,int pos);
int playSongUser(user* User);
song* getCurrentSongUser(user* User);
int addLikedSong(user* User,song* Song);
int removeLikedSong(user* User,song* Song);
int userCompatibility(user* user1,user* user2);

#endif