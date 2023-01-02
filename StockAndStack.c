/*
*DESARROLLADOR: AARON MORENO VILLEDA
*FECHA: 01/01/23
*
*SUPERMARKET PRODUCT MANAGER
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <conio.h>

#define MAX_LIM 25

typedef struct STACK
{
  int serialNumber;
  struct STACK *next;
}STACK;

typedef struct STOCK
{
  char article[MAX_LIM];
  struct STOCK *next;
  struct STACK *managementArticle;
}STOCK;

STOCK *head = NULL;

int nArticles();
void addArticleToStock();
void deleteArticleFromStock(int index);
void printStockList();

int main()
{
    system("cls");
    int option = 0;

    do
    {
        printf("****PRODUCT MANAGER****\n\n");
        printf("1.-Add an article to stock.\n");
        printf("2.-Delete an article from stock.\n");
        printf("3.-Print list of articles in stock.\n");
        printf("4.-Exit\n");
        printf("Select an option: ");
        scanf("%d", &option);
        system("cls");
    } while (option < 1 || option > 4);
    
    switch(option)
    {
        case 1:
            addArticleToStock();
            main();
            break;
        case 2:
            deleteArticleFromStock(nArticles());
            main();
            break;
        case 3:
            printStockList();
            getch();
            main();
            break;
        case 4: 
            system("cls");
            printf("\nPROGRAM FINISHED\n");
            break;
    }
    return 0;
}

int nArticles()
{
    STOCK *cont = head;
    int index = 0;
    while(cont){index++; cont = cont->next;}
    cont = NULL;
    free(cont);
    return index;
}

void addArticleToStock()
{
    printf("****PRODUCT MANAGER****\n\n");
    char prod[MAX_LIM];
    printf("Enter article: ");
    scanf("%s",prod);

    STOCK *add = malloc(sizeof(STOCK));
    strcpy(add->article,prod);
    add->next = NULL;
    add->managementArticle = NULL;

    if(add != NULL)
    {
        if(head == NULL){head = add;}
        else
        {
            STOCK *temp = head;
            while(temp->next){temp = temp->next;}
            temp->next = add;
            temp = NULL;
            free(temp);
        }
        add = NULL;
        free(add);
        printf("\nNew article added\n");
    }
    else{printf("\n***ALOCATION FAILURE***\n");}
    getch();
}

void deleteArticleFromStock(int index)
{
    if(head == NULL)//STOCK EMPTY
    {
        printf("****PRODUCT MANAGER****\n\n"); 
        printf("\n***STOCK EMPTY***\n"); 
        getch();
    }

    else//ARTICLES IN STOCK 
    {
        printStockList();

        int prodNum = 0;
        printf("\nENTER ARTICLE NUMBER: \n");
        scanf("%d",&prodNum);

        if(prodNum > 0 && prodNum <= index)//INDEX BETWEEN RANGE
        {   
            if(index == 1){head = NULL; free(head);}//ONE ARTICLE ON THE LIST

            else//MULTIPLE ARTICLES ON THE LIST
            {
                STOCK *prev = head;
                STOCK *current = head->next;

                if(prodNum == 1){free(head); head = current;}//DELETE THE FIRST ARTICLE

                else
                {
                    for(int i = 0; i < prodNum-2; i++)
                    {
                        prev = prev->next;
                        current = current->next;
                    }
                    
                    prev->next = current->next;

                }
                prev = NULL;
                current = NULL;
                free(prev);
                free(current);
            }
            printf("\n***Article deleted***\n");
        }

        else{ printf("\n***ERROR***\n");}//INDEX OUT OF RANGE
        getch();
    }
}

void printStockList()
{
    printf("****PRODUCT MANAGER****\n\n");
    STOCK *print = head;
    if(print == NULL){printf("\n***STOCK EMPTY***\n");}
    else
    {
        printf("Products: \n");
        for (int  i = 1; print; i++)
        {
            printf("%d.-%s\n",i,print->article);
            print = print->next;
        }
        print = NULL;
        free(print); 
    }
}