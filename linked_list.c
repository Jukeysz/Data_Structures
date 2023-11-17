#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("You must send the elements\n");
    }
    int node_number = argc;

    //node definition
    typedef struct node
    {
        int number;
        struct node *next; //it's a pointer to a node
    } node; //defining shorthand name

    //actual linked list, it's visually easier to understand with the slides
    node *list = NULL; //list will point to a node(reason behind the node type), but for now, let's define NULL and change it in the near future
    
    for (int i = 1; i < argc; i++)
    {
        if (i > 1)
        {
            node *n = malloc(sizeof(node));
            if (n == NULL)
            {
                return 1;
            }
            n->number = atoi(argv[i]);
            n->next = list;
            list = n;
            if (i == node_number)
            {
                n->next = NULL;
            }
        }
        else 
        {
            node *n = malloc(sizeof(node));
            if (n == NULL)
            {
                return 1;
            }
            n->number = atoi(argv[i]);
            n->next = NULL;
            list = n;
        }
    }

    //indexing a linked list
    node *ptr = list;
    while(ptr != NULL)
    {
        printf("%i\n", ptr->number);
        ptr = ptr->next;
    }

    //freeing memory
    ptr = list;
    while (ptr != NULL)
    {
        node *next = ptr->next;
        free(ptr);
        ptr = next;
    }
    return 0;
}