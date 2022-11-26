/*
*DESARROLLADOR: AARON MORENO VILLEDA
*FECHA: 25/12/22
*
*QUEUE EXAMPLE JAVIER VILLENA 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

typedef struct QUEUE
{
  char name[15];
  struct QUEUE *prev;
}QUEUE;

QUEUE *CheckOutCounter = NULL;

void showQueue();
void addElementQueue();
void removeElementQueue();
void CleanUp();

int main()
{
    int option = 0;
    do
    {
        printf("****MANAGER OF QUEUE****\n\n");
        printf("1.- Show queue\n");
        printf("2.- Add customer to queue\n");
        printf("3.- Serve customer\n");
        printf("4.- Exit\n");
        printf("Select an option: ");
        scanf("%d", &option);
        system("cls");
    } while (option < 1 || option > 4);
    
    switch(option)
    {
        case 1: 
            showQueue();
            main();
            break;
        case 2: 
            addElementQueue();
            main();
            break;
        case 3: 
            removeElementQueue();
            main();
            break;
        case 4: 
            CleanUp();
            printf("\nPROGRAM FINISHED\n");
            break;
    }
    return 0;
}

void showQueue()
{
    printf("\nCustomers on checkOutCounter:\n");
    QUEUE *aux = CheckOutCounter;
    if(aux == NULL){printf("QUEUE EMPTY!\n");}
    else
    {
        for(int i = 1; aux; i++)
        {
            printf("Position %d: %s\n",i,aux->name);
            aux = aux->prev;
        }
    }
    getch();
    system("cls");
}

void addElementQueue()

{
    char temp[15];
    QUEUE *client = malloc(sizeof(QUEUE));
    printf("Type the name of the new client: ");
    fflush(stdin);
    scanf("%s",temp);
    strcpy(client->name,temp);
    client->prev = NULL;

    if(CheckOutCounter == NULL){ CheckOutCounter = client;}
    else
    {
        QUEUE *aux = CheckOutCounter;
        while(aux->prev != NULL){ aux = aux->prev;}
        aux->prev = client;
    }
    printf("\nNew client added.\n");
    getch();
    system("cls");
}

void removeElementQueue()
{
    if(CheckOutCounter)
    {
        printf("\n%s was served\n",CheckOutCounter->name);
        QUEUE *aux = malloc(sizeof(QUEUE));
        aux = CheckOutCounter;
        CheckOutCounter = CheckOutCounter->prev;
        aux->prev = NULL;
        aux = NULL;
        free(aux);
    }
    else
    {
        printf("\nQUEUE EMPTY!\n");
    }
    getch();
    system("cls");
}

void CleanUp()
{
    QUEUE *aux;
    while (CheckOutCounter)
    {
        aux = CheckOutCounter;
        aux = NULL;
        free(aux);
        CheckOutCounter = CheckOutCounter->prev;
    }
}