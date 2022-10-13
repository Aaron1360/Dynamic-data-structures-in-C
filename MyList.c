/*
2nd round
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct list{
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
    else if(select == true)//ADD AT THE TOP OF THE LIST
    {
        data->next = first;
        first = data;
    }
    else//ADD AT THE END OF THE LIST
    {
        list *cont = NULL;
        cont = first;
        while(cont->next)
        {
            cont=cont->next;
        }
        cont->next = data;
    }
    printf("***NUMBER ADDED SUCCESFULLY***\n\n");
}

void printList()
{
    list *print = NULL;
    print = first;
    
    for(int i = 1; print; i++)
    {
        printf("Number #%d = %d\n",i,print->num);
        print = print->next;
    }
    printf("\n");
}

void display(int position)
{
    list *cont = NULL;
    cont = first;
    int index = 0;
    
    for(int i = 1; cont; i++)//CHECK # OF ELEMENTS
    {
        index = i;
        cont = cont->next;
    }
    cont = first;//RETURN TO THE FIRST ELEMENT
    
    if(position > index)
    {
        printf("***YOUR LIST ONLY HAVE %d ELEMENTS****\n\n",index); 
    }
    else 
    {
        for(int i = 1; i<position; i++)
        {
            cont = cont->next;
        }
        printf("Number #%d = %d\n\n",position,cont->num);
    }
}

int main()
{
    int option = 0;
    int number = 0;
    int position = 0;
    
    do{
        printf("***NUMBER LIST***\n\n");
        printf("1.- Add a number to the beggining of the list.\n");
        printf("2.- Add a number to the end of the list..\n");
        printf("3.- Print a member of the list:\n");
        printf("4.- Display List:\n");
        printf("5.- Delete a member of the list:\n");
        printf("6.- Exit.\n");
        printf("Select an option: ");
        scanf("%d",&option);
        system("clear");
    }while(option < 1 || option > 6);
    
    switch(option)
    {
        case 1:
            printf("Enter a number: ");
            scanf("%d",&number);
            add(number,true);
            main();
            break;
            
        case 2:
            printf("Enter a number: ");
            scanf("%d",&number);
            add(number,false);
            main();
            break;
            
        case 3:
            if(first == NULL){printf("\n***LIST EMPTY***\n\n");}
            else{
                printf("Enter the positon of the number you want to see: ");
                scanf("%d",&position);
                if(position > 0){display(position);}
                else{printf("***ERROR***\n\n");}
            }
            main();
            break;
            
        case 4:
            if(first == NULL){printf("\n***LIST EMPTY***\n\n");}
            else{
                printf("Current list: \n");
                printList();
            }
            main();
            break;
        case 5:
            if(first == NULL){printf("\n***LIST EMPTY***\n\n");}
            else{
                printf("Current list: \n");
                printList();
                printf("Enter the positon of the number you want to delete: ");
                scanf("%d",&position);
                if(position > 0){/*TODO: DELETE FUNCTION*/}
                else{printf("***ERROR***\n\n");}
            }
            main();
            break;
            
        case 6:
            system("clear");
            printf("\n***PROGRAM FINISHED***\n");
            break;
    }
    return 0;
}
