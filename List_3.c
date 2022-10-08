/******************************************************************************
dynamic list third attempt
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void showList()
{
    
}

void addElementList()
{
    
}
void removeElementList()
{
    
}

void createList()
{
    
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
            showList();
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
            break;
    }
}

int main()
{
    callMenuList();

    return 0;
}
