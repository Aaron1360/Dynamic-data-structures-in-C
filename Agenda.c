/*
*Fecha de creación: 23/10/2022
*
*2.-Desarrolla un menu igual que el que hemos creado en el ejemplo de la lista de la compra, 
*que permite AÑADIR, LISTAR y ELIMINAR tareas para cierto día especifico que tendra que ser 
*introducido tras pedir el día y el mes. El mes indicara el primer indice de nuestra matriz 
*y el día el segundo indice, algo así calendar[month][day]
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct SCHEDULE{
    char task[50];
    struct SCHEDULE* next;
};

struct SCHEDULE *add(struct SCHEDULE ***agenda,int month,int day)
{
    char task[50];
    struct SCHEDULE *new = malloc(sizeof(struct SCHEDULE));
    if(new != NULL)//CHECK CORRECT MEMORY ALOCATION
    {
        printf("Type your new task: \n");
        scanf("%s",task);
        strcpy(new->task,task);
        new->next = NULL;
        
        if(agenda[month][day] == NULL){agenda[month][day] = new;}//CREATE NEW LIST IF THE DAY IS EMPTY
        
        else //ADD AT THE TOP OF THE LIST
        {
            new->next = agenda[month][day];
            agenda[month][day] = new;
        }
        printf("\n***NEW TASK ADDED ON %d/%d***\n", month,day);
    }
    else
    {
        printf("\n¡¡¡¡ALOCATION FAILURE!!!\n");
    }
    
    return new;
}

void printDayList(struct SCHEDULE ***agenda,int month,int day)
{
    if(agenda[month][day] == NULL){printf("\nYou are free on that day\n");}//CHECK FOR ANY TASK
    else
    {
        int i = 1;
        while(agenda[month][day])
        {
            printf("Task #%d = %s\n",i,agenda[month][day]->task);
            agenda[month][day] = agenda[month][day]->next;
            i++;
        }
        printf("\n");
    }
}

void deleteTask(struct SCHEDULE ***agenda,int month,int day,int position)
{
    struct SCHEDULE *cont = NULL, *temp = NULL;
    cont = agenda[month][day];
    temp = agenda[month][day]->next;
    
    for(int i = 1; i<position-1; i++)
        {
            cont = cont->next;
            temp = temp->next;
        }
        
        if(temp->next != NULL)
        {
            cont->next = NULL;
            free(cont->next);
            temp = temp->next;
            cont->next = temp;
        }
        else
        {
            cont->next = NULL;
            free(cont->next);
        }
        printf("\n***TASK DELETED***\n");
}

void menu(struct SCHEDULE ***agenda)
{
    int option = 0;
    int month = 0;
    int day = 0;
    
    do{
        printf("\n***AGENDA***\n\n");
        printf("1.- Add new task.\n");
        printf("2.- Delete a task.\n");
        printf("3.- Print task list.\n");
        printf("4.- Exit.\n");
        printf("Select an option: ");
        scanf("%d",&option);
        system("clear");
    }while(option < 1 || option > 4);
    
    switch(option)
    {
        case 1:
            printf("\nEnter date of the new task(MM DD)");
            scanf("%d %d", &month, &day);
            agenda[month][day] = add(agenda,month,day);
            menu(agenda);//TODO: FIX MEMORY PROBLEM CAUSED BY CALLING MENU(AGENDA) SEVERAL TIMES
            break;
            
        case 2:
            
            menu(agenda);
            break;
            
        case 3:
            printf("\nEnter date (MM DD)");
            scanf("%d %d", &month, &day);
            printDayList(agenda,month,day);
            menu(agenda);
            break;
            
        case 4:
            system("clear");
            printf("\n***PROGRAM FINISHED***\n");
            break;
    }
}


int main()
{
    //STATIC POINTER ARRAY WITH 12 ELEMENTS (MONTHS)
    struct SCHEDULE ***agenda=malloc(sizeof(struct SCHEDULE**)*12);
    int days;
    
    //DYNAMIC ALOCATION BASED ON THE # OF DAYS
    for(int i = 0;i<12;i++)
    {
        switch (i+1) {
            case 1: case 3:  case 5: case 7: case 8: case 10: case 12 : days = 31; break;
            case 4: case 6: case 9:  case 11: days = 30; break;
            default: days = 28;
        }
        
        agenda[i]=malloc(sizeof(struct SCHEDULE*)*days);
        
        for (int j=0;j<days;j++) agenda[i][j]=NULL;
    }
    
    menu(agenda);
    
  return 0;
}
