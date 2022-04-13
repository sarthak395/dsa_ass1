#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "my_dll.h"
#include "node.h"

int main()
{
    printf("to exit at any time , press q\n");

    my_dll list;
    list.root=NULL; //any arbitrary value for root

    while(1)
    {
        char ins[14]; //max length is 14
        scanf("%s",ins);

        if(strcmp(ins,"insert")==0)
        {
            int x;
            scanf("%d",&x);
            insert(&list,x);
        }

        else if(strcmp(ins,"insert_at")==0)
        {
            int x,pos;
            scanf("%d %d",&x,&pos);
            insert_at(&list,x,pos);
        }

        else if(strcmp(ins,"delete")==0)
        {
            int pos;
            scanf("%d",&pos);
            delete(&list,pos);
        }

        else if(strcmp(ins,"find")==0)
        {
            int x;
            scanf("%d",&x);
            printf("%d\n",find(list,x));
        }

        else if(strcmp(ins,"prune")==0)
        {
            prune(list);
        }

        else if(strcmp(ins,"print")==0)
        {
            print(list);
        }

        else if(strcmp(ins,"print_reverse")==0)
        {
            print_reverse(list);
        }

        else if(strcmp(ins,"get_size")==0)
        {
            printf("%d\n",get_size(list));
        }

        else if(strcmp(ins,"q")==0)
        {
            break;
        }

        else
        {
            printf("invalid command\n");
        }
    }

    return 0;
}