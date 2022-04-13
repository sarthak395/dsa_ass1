#ifndef my_dll_h
#define my_dll_h

typedef struct node_ node;

typedef struct my_dll_
{
    node *root; 
} my_dll;

node *createnode(int x);

void insert(my_dll* list, int x); // insert at end of list

void insert_at(my_dll* list, int x, int i); // insert at position 'i' (zero - indexed)

void delete (my_dll *listptr, int i); // delete element at pos 'i' (zero - indexed)

int find(const my_dll list, int x); // return position for 1st occurence of 'x' in list , if not found return -1

void prune(const my_dll list); // delete elements at odd-indices

void print(const my_dll list); // print elements of list

void print_reverse(const my_dll list); // print elements in reverse order (no use of arrays)

int get_size(const my_dll list); // returns the size of list

#endif