#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct list
{
    int num;
    struct list *next;
};

typedef struct list list;

list *first = NULL;

void add(int num,bool select)
{
    list *data = malloc(sizeof(list));
    data->num = num;
    data->next = NULL;
    
    if(first == NULL){first = data;}
    
    else if(select == true)
    {
        data->next = first;
        first = data;
    }
    
    else
    {
        list *cont = malloc(sizeof(list));
        cont = first;
        while(cont->next != NULL)
        {
            cont = cont->next;
        }
        cont->next = data;
    }
    
    printf("\nElement added correctly\n");
}

void printList()
{
    system("clear");
    list *temp = malloc(sizeof(list));
    temp = first;
    
    if(temp == NULL){printf("\nList empty\n");}
    
    for(int i = 1; temp; i++)
    {
        printf("Member %d = %d\n",i,temp->num);
        temp = temp->next;
    }
}

int main()
{
    int option = 0;
    int num = 0;
    
    do{
        printf("***DYNAMIC LIST***\n\n");
        printf("1. Add element to the beginning of the list.\n");
        printf("2. Add element to the end of the list.\n");
        printf("3. Print list.\n");
        printf("4. Exit.\n");
        printf("Option: ");
        scanf("%d",&option);
        system("clear");
    }while(option<1 || option >4);
    
    switch(option)
    {
        case 1:
            printf("Enter a number: ");
            scanf("%d",&num);
            add(num,true);
            main();
            break;
        case 2:
            printf("Enter a number: ");
            scanf("%d",&num);
            add(num,false);
            main();
            break;
        case 3:
            system("clear");
            printList();
            printf("\n");
            main();
            break;
        case 4:
            system("clear");
            printf("\nProgram finished\n");
            break;
    }
    return 0;
}
