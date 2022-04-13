#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "my_dll.h"
#include "node.h"

node *createnode(int x)
{
    node *newnode = (node *)malloc(sizeof(node));
    assert(newnode!=NULL);

    newnode->data = x;
    newnode->next = NULL;
    newnode->prev = NULL;

    return newnode;
}

void insert(my_dll* list, int x) // insert at end of list
{
    node *newnode = createnode(x); //created the node to be inserted

    // list has root which points to first node

    node *currnode = list->root;

    // what if list is empty??????
    if (currnode == NULL)
    {
        list->root=newnode;
        return;
    }

    // if list is not empty
    while (currnode->next != NULL)
        currnode = currnode->next;

    // now currnode points to last node
    
    currnode->next = newnode;
    newnode->prev = currnode;
}

void insert_at(my_dll* list, int x, int i) // insert at position 'i' (zero - indexed)
{
    assert(i>=0);
    node *newnode = createnode(x); //created node to be inserted

    node *currnode = list->root;
    int pos = 0;

    //what if i==0
    if(i==0)
    {
        list->root->prev=newnode;
        newnode->next=list->root;
        list->root=newnode;
        return;
    }

    while (pos < i - 1)
    {
        currnode = currnode->next;
        pos++;
    }

    // now currnode points at pos (i-1) so that newnode will be placed at pos i
    newnode->next = currnode->next;
    currnode->next = newnode;
    newnode->prev = currnode;
    newnode->next->prev = newnode;
}

void delete (my_dll *listptr, int i) // delete element at pos 'i' (zero - indexed)
{
    assert(i<get_size(*listptr));
    assert(i>=0);
    assert(listptr->root!=NULL);
    node *currnode = listptr->root;
    int pos = 0;

    // to delete the first element
    if (i == 0)
    {
        node *tempptr = listptr->root->next;
        free(listptr->root);
        listptr->root = tempptr;
        listptr->root->prev = NULL;

        return;
    }

    while (pos < i)
    {
        currnode = currnode->next;
        pos++;
    }
    // now currnode points at pos i

    // to delete the last element
    if (currnode->next == NULL)
    {
        currnode->prev->next = NULL;
        free(currnode);
        return;
    }

    //to delete an intermediate element
    currnode->prev->next = currnode->next;
    currnode->next->prev = currnode->prev;
    free(currnode);
}

int find(const my_dll list, int x) // return position for 1st occurence of 'x' in list , if not found return -1
{
    node *currnode = list.root; 
    int pos = 0;
    while (currnode != NULL)
    {
        if (currnode->data == x)
        {
            return pos;
        }
        currnode = currnode->next;
        pos++;
    }

    return -1;
}

void prune(const my_dll list) // delete elements at odd-indices
{
    assert(list.root!=NULL);
    
    node *currnod = list.root;
    while (currnod->next != NULL)
    {
        // an exception here when currnod->next->next=NULL i.e in case of 2nd last element
        if (currnod->next->next == NULL)
        {
            //we are deleting last element here
            free(currnod->next);
            currnod->next=NULL;
            break;
        }

        // in normal cases
        node *tempnode = currnod->next;
        currnod->next->next->prev = currnod;
        currnod->next = currnod->next->next;
        free(tempnode);

        currnod = currnod->next;
    }
    return;
}

void print(const my_dll list) // print elements of list
{
    for (node *currnode = list.root; currnode != NULL; currnode = currnode->next)
        printf("%d\t", currnode->data);
}

void print_reverse(const my_dll list) // print elements in reverse order (no use of arrays)
{
    node *currnode = list.root;
    while (currnode->next != NULL)
        currnode = currnode->next;

    // now currnode points to last node
    while (currnode!= NULL)
    {
        printf("%d\n", currnode->data);
        currnode=currnode->prev;
    }
}

int get_size(const my_dll list) // returns the size of list
{
    node *currnode = list.root;
    int pos = 0;
    while (currnode != NULL)
    {
        currnode = currnode->next;
        pos++;
    }

    return pos;
}
