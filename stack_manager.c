/*
*DESARROLLADOR: AARON MORENO VILLEDA
*FECHA: 01/01/23
*
*STACK EXAMPLE JAVIER VILLENA 
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <conio.h>

typedef struct STACK
{
  int serialNumber;
  struct STACK *next;
}STACK;

STACK *cheese = NULL;

void showProducts();
void addProducts();
void removeProducts();
void CleanUp();

int main()
{
    system("cls");
    int option = 0;
    do
    {
        printf("****STACK MANAGER****\n\n");
        printf("1.- Show products\n");
        printf("2.- Add product\n");
        printf("3.- Remove product\n");
        printf("4.- Exit\n");
        printf("Select an option: ");
        scanf("%d", &option);
        system("cls");
    } while (option < 1 || option > 4);
    
    switch(option)
    {
        case 1: 
            system("cls");
            showProducts();
            getch();
            main();
            break;
        case 2: 
            system("cls");
            addProducts();
            main();
            break;
        case 3: 
            system("cls");
            removeProducts();
            main();
            break;
        case 4: 
            system("cls");
            CleanUp();
            printf("\nPROGRAM FINISHED\n");
            break;
    }
    return 0;
}

void showProducts()
{
    STACK *print = malloc(sizeof(STACK));
    print = cheese;
    if(print != NULL)
    {
        for(int i = 1; print; i++)
    {
        printf("%d.- %d\n",i,print->serialNumber);
        print = print->next;
    }
    }
    else
    {
        printf("\n***STACK EMPTY***\n");
    }
    print = NULL;
    free(print);
}

void addProducts()
{
    int prodNum;
    printf("Enter # of products to add: ");
    scanf("%d",&prodNum);
    srand(time(NULL));
    for(int i = 0; i < prodNum; i++)
    {
        STACK *temp = malloc(sizeof(STACK));
        temp->serialNumber = (rand()%10000)+1000;
        temp->next = NULL;
        if(cheese == NULL){cheese = temp;}
        else
        {
            temp->next = cheese;
            cheese = temp;
        }
        temp = NULL;
        free(temp);
    }
}

void removeProducts()
{
    if(cheese == NULL){printf("\n***STACK EMPTY***\n");}
    else
    {
        int prodNum;
        printf("Enter # of products to remove: ");
        scanf("%d",&prodNum);

        for(int i = 0; i < prodNum; i++)
        {
            if(cheese == NULL){printf("\n***STACK EMPTY***\n");}
            else
            {
                STACK *aux = cheese;
                cheese = cheese->next;
                aux = NULL;
                free(aux);
            }
        }
    }
}

void CleanUp()
{
    STACK *aux = cheese;
    while(cheese)
    {
        aux = cheese->next;
        cheese = NULL;
        free(cheese);
        cheese = aux;
    }
}
