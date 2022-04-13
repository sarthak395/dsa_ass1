#include "user.h"
#include <stdlib.h>
#include <string.h>
#include <assert.h>

user* createUser(char* username)
{
    //allocating space to store user info
    user* newuser=(user*) malloc(sizeof(user));

    //allocating space to store name
    newuser->name=(char*) malloc(strlen(username)+1);
    strcpy(newuser->name,username);

    //allocating space to store musicPlayer linked list
    newuser->MusicPlayer=(musicPlayer*) malloc(sizeof(musicPlayer));
    newuser->MusicPlayer->current_song=NULL;
    newuser->MusicPlayer->Queue=NULL;

    //allocating space to store liked songs list
    newuser->liked_songs=(list*) malloc(sizeof(list));
    newuser->liked_songs->root=NULL;

    return newuser;
}

int addSongToQueueUser(user* User,song* Song)
{
    return addsongtoQueue(User->MusicPlayer,Song);
}

int removeSongFromQueueUser(user* User,int pos)
{
    return removeSongFromQueue(User->MusicPlayer,pos);
}

int playSongUser(user* User)
{
    return playsong(User->MusicPlayer);
}

song* getCurrentSongUser(user* User)
{
    return getCurrentSong(User->MusicPlayer);
}

int addLikedSong(user* User,song* Song) //adds song at begining
{
    if((User==NULL)||(Song==NULL))
        return 1;

    //creating a node
    node* newnode=(node*) malloc(sizeof(node));
    assert(newnode!=NULL);

    newnode->Song=Song;
    newnode->next=NULL;

    //if list is empty
    if(User->liked_songs->root==NULL)
    {
        User->liked_songs->root=newnode;
    }
    //otherwise
    else
    {
        newnode->next=User->liked_songs->root;
        User->liked_songs->root=newnode;
    }
    return 0;
}

int removeLikedSong(user* User,song* Song)
{
    if((User==NULL)||(Song==NULL))
        return 1;
    
    node* currnode=User->liked_songs->root; 
    
    //removing first node
    if(currnode->Song==Song)
    {
        User->liked_songs->root=currnode->next;
        free(currnode);
        return 0;
    }

    node* prevnode=currnode;
    currnode=currnode->next;
    while(currnode!=NULL)
    {
        if(currnode->Song==Song)
        {
            prevnode->next=currnode->next;
            free(currnode);
            return 0;
        }
        prevnode=currnode;
        currnode=currnode->next;
    }

    return 1;
}

int userCompatibility(user* user1,user* user2)
{
    //yet to code
    node* user1_curr=user1->liked_songs->root;
    int count=0;

    while(user1_curr!=NULL)
    {
        for(node* user2_curr=user2->liked_songs->root;user2_curr!=NULL;user2_curr=user2_curr->next)
        {
            if(strcmp(user1_curr->Song->name,user2_curr->Song->name)==0)
            {
                count++;
            }
        }
        user1_curr=user1_curr->next;
    }
    return count;
}
