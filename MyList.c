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
        list *cont = malloc(sizeof(list));
        cont = first;
        while(cont->next)
        {
            cont=cont->next;
        }
        cont->next = data;
        cont = NULL;
        free(cont);
    }

    data = NULL;
    free(data);
    printf("***NUMBER ADDED SUCCESFULLY***\n\n");
}

void printList()
{
    list *print = malloc(sizeof(list));
    print = first;
    
    for(int i = 1; print; i++)
    {
        printf("Number #%d = %d\n",i,print->num);
        print = print->next;
    }
    print = NULL;
    free(print);
    printf("\n");
}

int nElements()
{
    list *cont = malloc(sizeof(list));
    cont = first;
    int index = 0;

    /*for(int i = 1; cont; i++)
    {
        index = i;
        cont = cont->next;
    }*/
    while(cont)
    {
        index++;
        cont = cont->next;
    }
    cont = NULL;
    free(cont);
    return index;
    
}

void display(int position)
{
    list *cont = malloc(sizeof(list));
    cont = first;
    
    if(position > nElements())
    {
        printf("***YOUR LIST ONLY HAVE %d ELEMENTS****\n\n",nElements()); 
    }
    else 
    {
        for(int i = 1; i<position; i++)
        {
            cont = cont->next;
        }
        printf("Number #%d = %d\n\n",position,cont->num);
    }
    cont = NULL;
    free(cont);
}

void delete(int position)
{
    list *cont = malloc(sizeof(list));
    list *temp = malloc(sizeof(list)); 
    cont = first;
    temp = first->next;

    int num = 0;
    if(position > nElements())
    {
        printf("***YOUR LIST ONLY HAVE %d ELEMENTS****\n\n",nElements()); 
    }
    else 
    {
        for(int i = 1; i<position-1; i++)
        {
            cont = cont->next;
            temp = temp->next;
        }
        
        if(temp->next != NULL)
        {
            num = cont->num;
            cont->next = NULL;
            free(cont->next);
            temp = temp->next;
            cont->next = temp;
        }
        else
        {   
            num = cont->num;
            cont->next = NULL;
            free(cont->next);
        }
        printf("***NUMBER %d DELETED***\n\n",num);
    }
    cont = NULL;
    temp = NULL;
    free(cont);
    free(temp);
}

void CleanUp(list *node)
{
    list *next;
    printf("\n");
    while(node)
    {
        next = node->next;
        free(node);
        node = next;
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
        printf("2.- Add a number to the end of the list.\n");
        printf("3.- Print a member of the list.\n");
        printf("4.- Display List.\n");
        printf("5.- Delete a member of the list.\n");
        printf("6.- Create default list.\n");
        printf("7.- Exit.\n");
        printf("Select an option: ");
        scanf("%d",&option);
        system("cls");
    }while(option < 1 || option > 7);
    
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
                if(position > 0 && position <= nElements()){delete(position);}
                else{printf("***ERROR***\n\n");}
            }
            main();
            break;
            
        case 6:
            system("cls");
            add(1,true);
            add(2,true);
            add(3,true);
            system("cls");
            printf("***DEFAULT LIST CREATED***\n\n");
            main();
            break;
        case 7:
            system("cls");
            CleanUp(first);
            first = NULL;
            printf("\n***PROGRAM FINISHED***\n");
            break;
    }
    return 0;
}
