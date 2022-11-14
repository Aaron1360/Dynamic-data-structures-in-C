/*
DEVELOPER: AARON MORENO VILLEDA
DATE: 13/11/22
Create multiple arrays of linked lists with different lenghts to simulate the concept of an agenda with 
different tasks for each day.
*/

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
    int days[]={1,2};
    int tasks[]={2,1,3};
    int number = 0;
    int taskNum = 0;

    //STATIC POINTER ARRAY (YEAR)
    test ***head = malloc(sizeof(test**)*monthNum);//ALOCATE MEMORY FOR AS MANY POINTERS TO POINTER AS # OF MONTHS

    //INITIALIZE POINTERS TO POINTER ARRAY (MONTHS)
    for(int i = 0; i < monthNum; i++)
    {
        head[i] = malloc(sizeof(test*[days[i]]));//ALOCATE MEMORY FOR THE # OF DAYS ON EACH MONTH
        
        //SET EVERY DAY TO NULL
        for(int j = 0; j < days[i]; j++){head[i][j] = NULL;}
    }

    /*FIND # OF TASKS
    while(taskNum < sizeof(tasks)/sizeof(tasks[0])){taskNum++;}
    */

    //TRAVERSE THE ARRAY
    for(int i = 0; i < monthNum; i++)
    {
        for(int j = 0; j < days[i]; j++)
        {
            //printf("MONTH [%d] DAY [%d]\n",i,j);
            for(int k = 0; k < tasks[taskNum]; k++)
            {
                test *new = malloc(sizeof(test));
                if(new != NULL)//CHECK CORRECT MEMORY ALOCATION
                {
                    printf("enter a number: ");
                    scanf("%d",&number);
                    new->number = number;
                    new->next = NULL;

                    if(head[i][j] == NULL){head[i][j] = new;}//CREATE NEW LIST IF THE DAY IS EMPTY
                    else 
                    {
                        /*//ADD AT THE TOP OF THE LIST
                        new->next = head[i][j];
                        head[i][j] = new;*/

                        //ADD AT THE END OF THE LIST
                        test *cont = malloc(sizeof(test));
                        cont = head[i][j];
                        while(cont->next)
                        {
                            cont=cont->next;
                        }
                        cont->next = new;
                        cont = NULL;
                        free(cont);
                    }
                    //printf("NUMBER ALOCATED\n");
                }
                else
                {
                    printf("\n****ALOCATION FAILURE****\n");
                    return 1;
                }
                new = NULL;
                free(new);
            }
            taskNum++;
            //printf("\n");
        }
    }

    printf("\n");
    
    //PRINT ALL DAYS
    for(int i = 0; i < monthNum; i++)
    {
        for(int j = 0; j < days[i]; j++)
        {
            printf("MONTH [%d] DAY [%d]\n",i,j);           
            test *temp = head[i][j];
            while(temp != NULL)
            {
                printf("%d\t",temp->number);
                temp = temp->next;
            }
            temp = NULL;
            free(temp);
            printf("\n");
        }
    }

    //CLEAN UP MEMORY
    for(int i = 0; i < monthNum; i++)
    {
        for(int j = 0; j < days[i]; j++)
        {
            int cont = 1;
            test *temp = head[i][j];
            test *next;
            printf("\nCLEANING [%d][%d]\n",i,j);// JUST TO VISUALIZE 

            while(temp)
            {
                next = temp->next;
                free(temp);
                temp = next;
                printf("task: %d\n",cont);
                cont++;
            }
        }
    }

    printf("\n***PROGRAM FINISHED***\n");
    return 0;
}

