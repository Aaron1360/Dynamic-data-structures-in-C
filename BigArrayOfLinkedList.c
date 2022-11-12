#include <stdio.h>
#include <stdlib.h>

typedef struct test{
    int number;
    struct test *next;
}test;

int main()
{
    //DIMENSIONS
    int monthNum = 2;
    int days[]={2,5};

    //STATIC POINTER ARRAY 
    test ***head = malloc(sizeof(test**)*monthNum);

    //INITIALIZE MONTHS ARRAY
    for(int i = 0; i < 2; i++)
    {
        head[i] = malloc(sizeof(test**[days[i]]));
        
        //SET YOUR MONTHS TO NULL
        for(int j = 0; j < days[i]; j++)
        {
            head[i][j] = NULL;
        }
    }

    //TRAVERSE THE POINTER ARRAY 
    for(int i = 0; i < monthNum; i++)
    {
        for(int j = 0; j < days[i]; j++)
        {
            //CREATE A NEW NODE
            test *new = calloc(1,sizeof(test));

            if(new != NULL)//CHECK CORRECT MEMORY ALOCATION
            {
                 //INPUT DATA
                new->number = 13;
                new->next = NULL;

                if(head[i][j] == NULL) {head[i][j] = new;}//CREATE NEW LIST IF THE DAY IS EMPTY
                else
                {
                    new->next = head[i][j];
                    head[i][j] = new;
                }//ADD AT THE TOP OF THE LIST
            }
            else
            {
                printf("***ERROR***");
                return 1;
            }
            
        }
    }

    printf("***PROGRAM FINISHED***");
    return 0;
}

