/*
*DEVELOPER: AARON MORENO VILLEDA
*DATE: 01/01/23
*
*Create a dynamic array with as many elements as boxes the user indicates.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#define MAX_LIMIT 20

//QUEUE STRUCT FOR EACH CHECKOUT BOX 
typedef struct QUEUE
{
  char name[MAX_LIMIT];
  struct QUEUE *prev;
}QUEUE;

QUEUE **CheckOutCounter = NULL;

void callMenu();
void addCustomer();
void createDefaultCustomersList();
void serveCustomer();
void printQueue();

int main()
{
    int boxNum;    
    printf("****SUPERMARKET BOX MANAGER****\n\n");
    printf("Enter # of boxes: ");
    scanf("%d", &boxNum);
    
    // ARRAY OF POINTERS TO QUEUE STRUCT 
    CheckOutCounter = malloc(sizeof(QUEUE*[boxNum]));
    //INITIALIZE POINTER ARRAY TO NULL
    for(int i = 0; i < boxNum; i++) {CheckOutCounter[i] = NULL;}
    system("cls");
    callMenu();
    return 0;
}

void callMenu()
{
    int option = 0;
    do
    {
        printf("****SUPERMARKET BOX MANAGER****\n\n");
        printf("1.- Print queue\n");
        printf("2.- Add customer to queue\n");
        printf("3.- Serve customer\n");
        printf("4.- Create Default List\n");
        printf("5.- Exit\n");
        printf("Select an option: ");
        scanf("%d", &option);
        system("cls");
    } while (option < 1 || option > 5);
    
    switch(option)
    {
        case 1: 
            printQueue();
            callMenu();
            break;
        case 2: 
            addCustomer();
            callMenu();
            break;
        case 3: 
            serveCustomer();
            callMenu();
            break;
        case 4: 
            createDefaultCustomersList();
            callMenu();
            break;
        case 5: 
            printf("\nPROGRAM FINISHED\n");
            break;
    }
}

void addCustomer()
{
    int bNum = 0;
    char temp[MAX_LIMIT];
    QUEUE *client = malloc(sizeof(QUEUE));

    printf("****SUPERMARKET BOX MANAGER****\n\n");
    printf("Enter the box #: ");
    scanf("%d",&bNum);

    if(client != NULL)//CHECK FOR CORRECT MEMORY ALOCATION
    {
        printf("Type the name of your new client: ");
        fflush(stdin);
        scanf("%[^\n]",temp);
        strcpy(client->name,temp);
        client->prev = NULL;

        if(CheckOutCounter[bNum] == NULL){CheckOutCounter[bNum] = client;}//ADD NEW CLIENT TO THE EMPTY QUEUE
        else
        {
            QUEUE *aux = CheckOutCounter[bNum];
            while(aux->prev != NULL){ aux = aux->prev;}
            aux->prev = client;
            aux = NULL;
            free(aux);
        } 
        printf("\nNew client added.\n");
        getch();
        system("cls");
    }
    else
    {
        printf("\n***ALOCATION FAILURE***\n\n");
    }
    client = NULL;
    free(client);
}

void createDefaultCustomersList()
{
    for(int i = 0; i < 3; i++)
    {
        QUEUE *client = malloc(sizeof(QUEUE));
        strcpy(client->name,"Client");
        client->prev = CheckOutCounter[0];
        CheckOutCounter[0] = client;
    }
    printf("****SUPERMARKET BOX MANAGER****\n\n");
    printf("Default list added on box #0");
    getch();
    system("cls");
}

void serveCustomer()
{
    int bNum = 0;

    printf("****SUPERMARKET BOX MANAGER****\n\n");
    printf("Enter the box #: ");
    scanf("%d",&bNum);

    if(CheckOutCounter[bNum])
    {
        printf("\n%s was served\n",CheckOutCounter[bNum]->name);
        QUEUE *aux = malloc(sizeof(QUEUE));
        aux = CheckOutCounter[bNum];
        CheckOutCounter[bNum] = CheckOutCounter[bNum]->prev;
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

void printQueue()
{
    int bNum = 0;
    printf("****SUPERMARKET BOX MANAGER****\n\n");
    printf("Enter the box #: ");
    scanf("%d",&bNum);
    
    if(CheckOutCounter[bNum] == NULL){printf("\nThe queue is empty");}
    else
    {
        printf("\nCustomers on checkOutCounter #%d: \n",bNum);
        QUEUE *temp = CheckOutCounter[bNum];
        for(int i = 1; temp; i++)
        {
            printf("Position %d: %s\n",i,temp->name);
            temp = temp->prev;
        }
        temp = NULL;
        free(temp);
    }
    getch();
    system("cls");
}
