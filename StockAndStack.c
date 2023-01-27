/* 
* Desarrollador: Aaron Moreno Villeda
* Fecha: 26/01/23
* Desarrolla la logica de administracion de los productos ofrecidos
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<stdbool.h>
#include<time.h>

#define _BUFFER 25/* max lenght  */

/* NODES */
typedef struct STACK{
    int serialNumber;
    struct STACK *next;
}STACK;

typedef struct STOCK{
    char article[_BUFFER];
    struct STOCK *next;
    struct STACK *managementArticle;
}STOCK;

STOCK *head = NULL;

/* PROTOTYPES */
void callMenu(char* select);
int nElementsSTOCK();
bool isEmpty();
void showTitle(char* select);
void addElementSTOCK();
void addElementSTACK();
void removeElementSTOCK();
void removeElementSTACK();
void showSTOCK();
void showSTACK();
void cleanUp();

int main()
{
    callMenu("STOCK");
    return 0;
}

/* DEFINITIONS */
void callMenu(char* select)//display STOCK or STACK menu
{
    if(select == "STOCK")
    {
        system("cls");
        int option = 0;
        do
        {
            showTitle("STOCK");
            printf("1.- Show products\n");
            printf("2.- Add product\n");
            printf("3.- Remove product\n");
            printf("4.- Display STACK menu\n");
            printf("5.- Exit\n");
            printf("Select an option: ");
            scanf("%d", &option);
            system("cls");
        } while (option < 1 || option > 5);
        
        switch(option)
        {
            case 1: 
                system("cls");
                showTitle("STOCK");
                showSTOCK();
                callMenu("STOCK");
                break;
            case 2: 
                addElementSTOCK();
                callMenu("STOCK");
                break;
            case 3: 
                
                break;
            case 4: 
                callMenu("STACK");
                break;
            case 5: 
                cleanUp();
                break;
        }
    }
    else if(select == "STACK")
    {
        system("cls");
        int option = 0;
        do
        {
            showTitle("STACK");
            printf("1.- Show barcodes\n");
            printf("2.- Add barcodes\n");
            printf("3.- Remove barcodes\n");
            printf("4.- Return to main menu\n");
            printf("Select an option: ");
            scanf("%d", &option);
            system("cls");
        } while (option < 1 || option > 5);
        
        switch(option)
        {
            case 1: 
                
                break;
            case 2: 
                
                break;
            case 3: 
                
                break;
            case 4: 
                callMenu("STOCK");
                break;
        }
    }
    else{printf("\n***ERROR***\n");}
}

int nElementsSTOCK()//returns how many elements are in the list
{
    if(isEmpty()){return 0;}
    else
    {
        STOCK *temp = head;
        int cont = 0;
        while(temp)
        {
            cont++;
            temp = temp->next;
        }
        temp = NULL;
        free(temp);
        return cont;
    } 
}

bool isEmpty()//check if the STOCK is empty
{
    if(head == NULL){return true;}
    else{return false;}
}

void showTitle(char* select)//display a diferent title depending of the menu
{
    if(select == "STOCK")
    {
        printf("****MANAGER OF STOCK****\n\n");
    }
    else if(select == "STACK")
    {
        printf("****MANAGER OF STACK****\n\n");
    }
    else{printf("\n***ERROR***\n\n");}
}

void addElementSTOCK()//add a new item to the STOCK
{
    system("cls");
    fflush(stdin);
    showTitle("STOCK");

    STOCK *add = malloc(sizeof(STOCK));//create new node
    if(add != NULL)//check for correct memory alocation
    {
        char item[_BUFFER];//enter article name
        printf("Enter new article: ");
        scanf("%[^\n]",item);
        add->next = NULL;
        add->managementArticle = NULL;
        strcpy(add->article,item);

        if(isEmpty()){head = add;}//add the new item to the beginning of the list if it is empty
        else//add the new item at the end of the list
        {
            STOCK *temp = head;
            while(temp->next){temp = temp->next;}
            temp->next = add;
            temp = NULL;
            free(temp);
        }
        add = NULL;
        free(add);
        printf("\n***NEW ARTICLE ADDED SUCCESFULLY***\n\n");
    }
    else{printf("\n***ALOCATION FAILURE***\n\n");}
    getch();
}

void addElementSTACK()//add a new barcode to the STACK
{

}

void removeElementSTOCK()//remove an item from STOCK
{

}

void removeElementSTACK()//remove barcode(s) from STACK
{

}

void showSTOCK()//display the list of articles
{
    if(isEmpty()){printf("***STOCK EMPTY***\n");}//check if the list is empty
    else
    {
        STOCK *print = head;//pointer to traverse the list
        for(int i = 1; print; i++)
        {
            printf("%d.-%s\n",i,print->article);
            print = print->next;
        }
        print = NULL;
    }
    getch();
}

void showSTACK()//display the barcodes 
{

}

void cleanUp()//clean memory before finish the program
{
    system("cls");
    STOCK *maid;
    while(head)
    {
        maid = head->next;
        free(head);
        head = maid;   
    }
    printf("\n***PROGRAM FINISHED***\n");
}