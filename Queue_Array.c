/*
*DEVELOPER: AARON MORENO VILLEDA
*DATE: 25/12/22
*
*Create a dynamic array with as many elements as boxes the user indicates.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

//STRUCTURE OF QUEUE 
typedef struct QUEUE
{
  char name[15];
  struct QUEUE *prev;
}QUEUE;

void userInput(int *boxes);
void showAllQueues(int *boxes,QUEUE **head);
void showQueue(int *boxNum,QUEUE **head);
void addElementQueue(int *boxNum,QUEUE **head);
void removeElementQueue(int *boxNum,QUEUE **head);
void showMenu(int *boxes,QUEUE **head);
void CleanUp(int *boxes,QUEUE **head);

int main()
{
    int boxes = 0;
    userInput(&boxes);
    QUEUE **head = malloc(sizeof(QUEUE*[boxes]));// ARRAY OF POINTERS TO QUEUE STRUCT 
    //printf("\nboxes: %d",boxes);
    for(int i = 0; i < boxes; i++) {head[i] = NULL;} //INITIALIZE POINTER ARRAY TO NULL
    showMenu(&boxes,head);

    return 0;
}

void userInput(int *boxes)
{
    printf("ENTER THE NUMBER OF BOXES IN THE SUPERMARKET: ");
    scanf("%d", boxes);
}

void showAllQueues(int *boxes,QUEUE **head)
{
    //TODO: CHECK IF HEAD IS NULL, FIX TAB AND SPACE ERROR
    for(int i = 0; i < *boxes; i++)
    {
        QUEUE *temp = head[i];
        printf("%d\t",i);
        while(temp != NULL)
        {
            printf("--%s",temp->name);
            temp = temp->prev;
        }
        printf("\n");
    }
    printf("\n");
}

void showQueue(int *boxNum,QUEUE **head)
{
    //TODO: CHECK IF HEAD IS NULL, FIX TAB AND SPACE ERROR
    QUEUE *temp = head[*boxNum];
        printf("%d",*boxNum);
        while(temp != NULL)
        {
            printf("--%s",temp->name);
            temp = temp->prev;
        }
    printf("\n");
}

void addElementQueue(int *boxNum,QUEUE **head)
{
    char temp[15];
    QUEUE *client = malloc(sizeof(QUEUE));
    printf("Enter the name of the new client: ");
    fflush(stdin);
    scanf("%s",temp);
    strcpy(client->name,temp);
    client->prev = NULL;

    if(head[*boxNum] == NULL){ head[*boxNum] = client;}
    else
    {
        QUEUE *aux = head[*boxNum];
        while(aux->prev != NULL){ aux = aux->prev;}
        aux->prev = client;
    }
    printf("\nNew client added.\n");
    getch();
    system("cls");
}

void removeElementQueue(int *boxNum,QUEUE **head)
{

}

void showMenu(int *boxes,QUEUE **head)
{
    //TODO: FIX OPTIONS 2,3,4 PROBLEM WITH DO WHILE LOOP
    fflush(stdin);
    int option = 0, boxNum = 0;
    do
    {
        printf("****MANAGER OF QUEUES ARRAY****\n\n");
        printf("1.- Show all queues.\n");
        printf("2.- Show an especific queue.\n");
        printf("3.- Add customer to queue.\n");
        printf("4.- Serve customer.\n");
        printf("5.- Exit.\n");
        printf("Select an option: ");
        scanf("%d", &option);
        system("cls");
    } while (option < 1 || option > 5);
    
    switch(option)
    {
        case 1: 
            showAllQueues(boxes,head);
            showMenu(boxes,head);
            break;
        case 2:
            do
            {
                printf("\nENTER THE BOX NUMBER: \n");
                scanf("%d",&boxNum);
                system("cls");
            } while (boxNum < 0 || boxNum > *boxes);
            showQueue(&boxNum,head);
            showMenu(boxes,head);
            break;
        case 3: 
            do
            {
                printf("\nENTER THE BOX NUMBER WHERE YOU WANT ADD A CUSTOMER: \n");
                scanf("%d",&boxNum);
                system("cls");
            } while (boxNum < 0 || boxNum > *boxes);
            addElementQueue(&boxNum,head);
            showMenu(boxes,head);
            break;
        case 4: 
            do
            {
                printf("\nENTER THE BOX NUMBER WHERE YOU WANT SERVE A CUSTOMER: \n");
                scanf("%d",&boxNum);
                system("cls");
            } while (boxNum < 0 || boxNum > *boxes);
            removeElementQueue(&boxNum,head);
            showMenu(boxes,head);
            break;
        case 5: 
            CleanUp(boxes,head);
            printf("\nPROGRAM FINISHED\n");
            break;
    }
}

void CleanUp(int *boxes,QUEUE **head)
{
    for(int i = 0; i < *boxes; i++)
    {
        QUEUE *temp = head[i];
        QUEUE *prev;

        while(temp)
        {
            prev = temp->prev;
            free(temp);
            temp = prev;
        }
    }
}