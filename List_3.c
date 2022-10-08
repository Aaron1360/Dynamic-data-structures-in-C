/******************************************************************************
dynamic list third attempt
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct list{
    char product[20];
    int account;
    struct list *next;
};

struct list *shoppingList = NULL;

void callMenuList();

void showList(bool optionalMenu)
{
    struct list *item;
    item=shoppingList;
    
    for(int i=1;item;i++)
    {
        printf("article %d: %s x %d\n",i,item->product,item->account);
        item=item->next;    
    }
    printf("\n");
    if(optionalMenu){callMenuList();}
    
}

void insertElementList(char product[20],int account)
{
    struct list *article=malloc(sizeof(struct list));
    strcpy(article->product,product);
    article->account=account;
    article->next=NULL;
    
    struct list *item=malloc(sizeof(struct list));
    if(shoppingList == NULL){shoppingList = article;}
    else
    {
        item = shoppingList;
        bool added = false;
        while(added == false)
        {
            if(item->next == NULL)
            {
                item->next = article;
                added = true;
            }
            else item=item->next;
        }
    }
    
    article=NULL;
    item=NULL;
    free(article);
    free(item);
    
   
}

void addElementList()
{
    char product[20];
    int account;
    
    printf("Type the product you want to buy: ");
    scanf("%s",product);
    printf("Type the account: ");
    scanf("%d",&account);
    
    insertElementList(product,account);
    
    callMenuList();
    
}
void removeElementList()
{
   showList(false);
   
   int num;
   printf("Type the number of the article you want to remove: ");
   scanf("%d",&num);
   system("clear");
   if(num == 1 && shoppingList != NULL){shoppingList = shoppingList->next;}
   else
   {
       
       }
   }
   printf("\nARTICLE %d REMOVED\n",num);
   callMenuList();
   
}

void createList()
{
    char product[20];
    strcpy(product,"Milk");
    insertElementList(product,6);
    
    strcpy(product,"Eggs");
    insertElementList(product,12);
    
    strcpy(product,"Bread");
    insertElementList(product,1);
    
    
    printf("\nSHOPPING LIST CREATED \n\n");
    
    callMenuList();
}


void callMenuList()
{
    int option;
    do{
        printf("\tMANAGER OF SHOPPING LIST:\n\n");
        printf("1.- Show shopping list.\n");
        printf("2.- Add article.\n");
        printf("3.- Remove article.\n");
        printf("4.- Create default shopping list.\n");
        printf("5.- Exit.\n");
        printf("Type the option: ");
        scanf("%d",&option);
        system("clear");
    }while(option < 1 || option > 5);
    
    switch(option)
    {
        case 1:
            showList(true);
            break;
        case 2:
            addElementList();
            break;
        case 3:
            removeElementList();
            break;
        case 4:
            createList();
            break;
        case 5:
            system("clear");
            printf("\n\tPROGRAM FINISHED\n");
            break;
    }
}

int main()
{
    callMenuList();

    return 0;
}
