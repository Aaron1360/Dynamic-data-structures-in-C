#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct LIST
{
    char product[20];
    int account;
    struct LIST *next;
};

struct LIST *getNewItem(const char product[20],int account)
{
    struct LIST *newItem = NULL;
    newItem = malloc(sizeof(struct LIST));

    if(newItem != NULL)
    {
        newItem->next = NULL;
        strcpy(newItem->product,product);
        newItem->account=account;
        printf("Create new item at %p\n\n",newItem);
    }

    else
    {
        printf("¡¡¡¡ALOCATION FAILURE!!!\n");
    }

    return newItem;
}

void printData(const struct LIST *product,const char *comment)
{
    if(product == NULL)
    {
        printf("%s is NULL\n\n",comment);
    }
    else
    {
        printf("%s Article: %s x %d\n\n",comment,product->product,product->account);
    }
}

int main()
{
    char product[20];
    int account;

    struct LIST *first = malloc(sizeof(struct LIST));
    struct LIST *added = NULL;

    printf(">>>LINKED LIST 1<<<<<\n\n");
    printf("Enter a new product: ");
    scanf("%s",&product);
    printf("Enter # of items: ");
    scanf("%d",&account);
    
    first = getNewItem(product,account);
    
    printf("\n<<<FIRST<<<<\n");
    printData(first,"first");

    return 0;
}

