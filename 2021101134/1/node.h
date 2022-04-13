#ifndef node_H
#define node_H

typedef struct node_
{
    int data;
    struct node_* prev; 
    struct node_* next;
}node;

node *createnode(int x);
#endif