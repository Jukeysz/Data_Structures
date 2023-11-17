#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *list = malloc(3 * sizeof(int));

    if (list == NULL)
    {
        return 1;
    }

    list[0] = 1;
    list[1] = 2;
    list[2] = 3;
    //I'm catching this chunk of memory that had been allocated, and then indexing, not related to the first or the second byte, but indeed slicing this chunk 
    //and doing the pointer arithmetic automatically.
    //This only happens because malloc also gives me a chunk of contiguous memory.

    //time passes and, somewhen, I must update the amount of memory in order to add more elements........

    int *tmp = realloc(list, 4 * sizeof(int)); //It handles all the copy for me, even the loops. First argument is the variable I want to resize, and second is what memory amount I want
    if (tmp == NULL)                           //And it automatically frees the previous memory for me.
    {
        free(list);
        return 1;
    }

    list = tmp; //the old list now points to temp who points to this new chunk that was reallocated;

    list[3] = 4;

    for (int i = 0; i < 4; i++)
    {
        printf("%i\n", list[i]);
    }

    free(list);  

    return 0;
}
