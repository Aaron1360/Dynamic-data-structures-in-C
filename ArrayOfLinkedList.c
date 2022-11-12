#include <stdio.h>
#include <stdlib.h>
// STRUCTURE OF LINKED LIST
typedef struct info{
    int number;
    struct info *next;
}info;

int main()
{
    int size = 10;

    //POINTER TO POINTER ARRAY
    info **head;
    
    // ARRAY OF POINTERS TO INFO STRUCT 
    head = malloc(sizeof(info*[size])); 
    
    //INITIALIZE POINTER ARRAY TO NULL
    for(int i = 0; i < size; i++) {head[i] = NULL;}//{*(head + i) = NULL;}

    //TRAVERSE THE POINTER ARRAY 
    for(int i = 0; i < size; i++)
    {
        info *prev = NULL;

        int s = 4;

        while(s--){
            //CREATE A NEW NODE
            info *new = calloc(1,sizeof(info));
            //INPUT DATA
            new->number = i * s;
            new->next = NULL;
            //IF THE NODE IS FIRST
            if(head[i] == NULL) {head[i] = new;}//(*(head + i) == NULL) {*(head + i) = new;}
            else{prev->next = new;}
            prev = new;
        }
    }

    //PRINT THE ARRAY OF LINKED LIST
    for(int i = 0; i < size; i++)
    {
        info *temp = head[i];//*(head + i);
        //LINKED LIST #
        printf("%d\t",i);
        //PRINT THE LINKED LIST
        while(temp != NULL)
        {
            printf("%d  ",temp->number);
            temp = temp->next;
        }
        printf("\n");
    }

    //CLEAN UP MEMORY
    for(int i = 0; i < size; i++)
    {
        info *temp = head[i];//*(head + i);
        info *next;

        while(temp)
        {
            next = temp->next;
            free(temp);
            temp = next;
        }
    }
    printf("\n\nCLEANING DONE\n");
    return 0;
}