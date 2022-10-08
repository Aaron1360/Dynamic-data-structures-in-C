//DYNAMIC LIST EXAMPLE JAVIER VILLENA
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
        printf("%s Article: %s x %d in %p pointing to %p\n\n",comment,
        product->product,product->account,product,product->next);
    }
}

void printList(const struct LIST *list)
{
    const struct LIST *temp;
    temp=list;
    
    if(temp==NULL)
    {
        printf("\nLIST IS EMPTY\n");
    }
    else
    {
        while(temp)
        {
            printData(temp,"t");
            temp=temp->next;
        }
    }
}

void clean(struct LIST *list)
{
    struct LIST *next;
    while(list)
    {
        next=list->next;
        printf("Cleaning %s\n", list->product);
        free(list);
        list = next;
    }
}
int main()
{
    printf("\n** START **\n\n");
    
    char command[64];
    char product[20];
    int account;

    struct LIST *first = NULL;
    struct LIST *added = NULL;
    
    while(1)
    {
        printf( "Enter a command or value : ");
		fgets(command, 64, stdin);
		
		if (strcmp("q\n", command) == 0) 
		{
			printf("Quitting..\n");
			break;
		}
		
		else if (strcmp("print\n", command) == 0) 
        {
            printf("Printing..\n");
            printList(first);
        }
        
        else if(sscanf(command, "%s %d", product,&account) != 0)
        {
            printf("Adding %s\n", product);
            
            if (first == NULL)
            {
                first = getNewItem(product,account);
                if(first != NULL)
                {
                    added = first;
                }
            }
            
            else
            {
                added->next = getNewItem(product,account);
                if(added->next != NULL)
                {
                    added = added->next;
                }
            }
        }
    }
    
    clean(first);
    first = NULL;
    added = NULL;
    
    return 0;
}
