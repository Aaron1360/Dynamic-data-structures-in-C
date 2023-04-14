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
STOCK *item = NULL;

/* PROTOTYPES */
void callMenu(char* select);
// int nItems();
bool isEmpty(STOCK *item);
STOCK *selectItem();
void showTitle(char* select);
void addItem(char* select,STOCK *item);
void removeItem(char* select,STOCK *item);
void showList(char* select,STOCK *item);
void cleanUp();

int main()
{
    callMenu("STOCK");
    return 0;
}

/* DEFINITIONS */
void callMenu(char* select)//display STOCK/STACK menu
{
    system("cls");
    if(select == "STOCK")
    {
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
                showList("STOCK",NULL);
                getch();
                callMenu("STOCK");
                break;
            case 2: 
                system("cls");
                showTitle("STOCK");
                addItem("STOCK",NULL);
                callMenu("STOCK");
                break;
            case 3: 
                system("cls");
                showTitle("STOCK");
                removeItem("STOCK",NULL);
                getch();
                callMenu("STOCK");
                break;
            case 4:
                item = selectItem();
                callMenu("STACK");
                break;
            case 5: 
                cleanUp();
                break;
        }
    }
    else if(select == "STACK")
    {
        if(isEmpty(NULL))
        {
            printf("***STOCK EMPTY***\n");
            getch();
            callMenu("STOCK");
        }
        else
        {   
            int option = 0;
            do
            {
                showTitle("STACK");
                printf("CURRENT ARTICLE: %s\n",item->article);
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
                    system("cls");
                    showTitle("STACK");
                    showList("STACK",item);
                    getch();
                    callMenu("STACK");
                    break;
                case 2: 
                    system("cls");
                    showTitle("STACK");
                    addItem("STACK",item);
                    callMenu("STACK");
                    break;
                case 3:
                    system("cls");
                    showTitle("STACK");
                    removeItem("STACK",item);
                    callMenu("STACK");
                    break;
                case 4: 
                    callMenu("STOCK");
                    break;
            }
        }
    }
    else{printf("\n***ERROR***\n");}
}

/* int nItems()//returns how many elements are in the list
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
} */

bool isEmpty(STOCK *item)//check if the STOCK is empty
{
    if(item == NULL)
    {
        if(head == NULL){return true;}
        else{return false;}
    }
    else
    {
        if(item->managementArticle == NULL){return true;}
        else{return false;}
    }
    
}

STOCK *selectItem()//returns an item to work in STACK menu
{
    system("cls");
    showTitle("STACK");
    showList("STOCK",NULL);
    if(!isEmpty(NULL))
    {
        STOCK *temp = head;
        int select = 0;
        printf("Enter item #: ");
        scanf("%d",&select);
        {
            if(select > 1)
            {
                for(int i = 1; i < select; i++)
                {
                    temp = temp->next;
                }
            }
            return temp;
        }
    }
    else{return NULL;}
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

void addItem(char* select,STOCK *item)//add a new item to the STOCK
{
    if(select == "STOCK")
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

            if(isEmpty(NULL)){head = add;}//add the new item to the beginning of the list if it is empty
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
            printf("\n***NEW ARTICLE ADDED***\n\n");
        }
        else{printf("\n***ALOCATION FAILURE***\n\n");}
        getch();
    }
    else if(select == "STACK")
    {
        system("cls");
        showTitle("STACK");

        int prodNum;
        printf("Enter # of products to add: ");
        scanf("%d",&prodNum);
        srand(time(NULL));

        for(int i = 0; i < prodNum; i++)
        {
            STACK *temp = malloc(sizeof(STACK));
            temp->serialNumber = (rand()%10000)+1000;
            temp->next = NULL;
            if(item->managementArticle == NULL){item->managementArticle = temp;}
            else
            {
                temp->next = item->managementArticle;
                item->managementArticle = temp;
            }
            temp = NULL;
            free(temp);
        }
        printf("\n***BARCODES ADDED***\n");
        getch();        
    }
    else{printf("\n***ERROR***\n");}
}

void removeItem(char* select,STOCK *item)//remove an item from STOCK
{
    if(select == "STOCK")
    {
        showList("STOCK",NULL);
        if(!isEmpty(NULL))
        {
            int temp = 0;
            printf("Enter item #: ");
            scanf("%d",&temp);
            STOCK *prev = head;
            STOCK *current = head->next;
            if(temp == 1){head == NULL; head = current;}
            else
            {
                for(int i = 0; i < temp-2; i++)
                {
                    prev = prev->next;
                    current = current->next;
                }
                prev->next = current->next;
            }
            prev = NULL;
            current = NULL;
            printf("***ARTICLE DELETED***\n");
        }
    }
    else if(select == "STACK")
    {
        system("cls");
        showTitle("STACK");

        int prodNum;
        printf("Enter # of products to remove: ");
        scanf("%d",&prodNum);

        for(int i = 0; i < prodNum; i++)
        {
            if(item->managementArticle == NULL){printf("\n***STACK EMPTY***\n");}
            else
            {
                STACK *temp = item->managementArticle;
                item->managementArticle = item->managementArticle->next;
                temp = NULL;
                free(temp);
            }
        }
        printf("\n***BARCODES REMOVED***\n");
        getch();
    }
    else{printf("\n***ERROR***\n");}
}

void showList(char* select, STOCK *item)//display the list of articles
{
    if(select == "STOCK")
    {
        if(isEmpty(NULL)){printf("***STOCK EMPTY***\n");}//check if the list is empty
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
    }
    else if(select == "STACK")
    {
        if(isEmpty(item)){printf("***STACK EMPTY***\n");}//check if the list is empty
        else
        {
            STACK *print = item->managementArticle;//pointer to traverse the list
            for(int i = 1; print; i++)
            {
                printf("%d.-%d\n",i,print->serialNumber);
                print = print->next;
            }
            print = NULL;
        }
    }
    else{printf("\n***ERROR***\n");}
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
