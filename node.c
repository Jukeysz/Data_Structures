#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    //node definition
    typedef struct node
    {
        int number;
        struct node *next; //it's a pointer to a node
    } node;

    //actual linked list, it's visually easier to understand with the slides
    node *list = NULL; //list will point to a node(reason behind the node type), but for now, let's define NULL and change it in the near future
    
    node *n = malloc(sizeof(node));
    n->number = 1; //the -> is the same as dereferencing a pointer and acessing it's structs
    n->next = NULL;
    list = n; //list now points to the same chunk of memory n points at

    node *n = malloc(sizeof(node)); //n now points to a new chunk in memory, and the list is intentionally disordered.
    n->number = 2; //defining the number of the new chunk.
    n->next = list; //the struct of the new chunk now points to the same place list points at, which is the ORIGINAL element(number 1) and now follows the right order.
    list = n; //and now, list is completely free to follow the correct order and point at the new chunk of memory(which in 
              //thesis is now the first element from left to right).

    node *n = malloc(sizeof(node)); //the same repeats......
    n->next = list;
    n->number = 3;
    list = n;

    return 0;
}