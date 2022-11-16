/*
*Fecha de creación: 23/10/2022
*
*2.-Desarrolla un menu igual que el que hemos creado en el ejemplo de la SCHEDULEa de la compra, 
*que permite AÑADIR, IMPRIMIR y ELIMINAR tareas para cierto día especifico que tendra que ser 
*introducido tras pedir el día y el mes. El mes indicara el primer indice de nuestra matriz 
*y el día el segundo indice, algo así calendar[month][day]
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#define MONTHS 12
#define MAX_LIMIT 50

typedef struct SCHEDULE{
    char task[MAX_LIMIT];
    struct SCHEDULE* next;
}SCHEDULE;

SCHEDULE ***agenda = NULL;

void callMenu();
void addTasks(int month,int day);
void deleteTasks(int month,int day);
void printTasks(int month,int day);

int main()
{
    //STATIC POINTER ARRAY WITH 12 ELEMENTS (MONTHS)
    agenda = malloc(sizeof(SCHEDULE**[MONTHS]));
    int dayspos = 0;
    
    //DYNAMIC ALOCATION BASED ON THE # OF DAYS
    for(int i = 0; i < MONTHS; i++)
    {
        switch (i+1) {
            case 1: case 3:  case 5: case 7: case 8: case 10: case 12 : dayspos = 31; break;
            case 4: case 6: case 9:  case 11: dayspos = 30; break;
            default: dayspos = 28;
        }
        agenda[i] = malloc(sizeof(SCHEDULE*[dayspos]));//ALOCATE MEMORY FOR EACH DAY

        for (int j = 0;j < dayspos; j++) agenda[i][j]=NULL;//SET EVERYDAY TO NULL
    }
    
    callMenu();
  return 0;
}

void callMenu()
{
    int option = 0,month = 0,day = 0;

     do{
        printf("\n***AGENDA***\n\n");
        printf("1.- Add new task.\n");
        printf("2.- Delete a task.\n");
        printf("3.- Print task SCHEDULE.\n");
        printf("4.- Exit.\n");
        printf("Select an option: ");
        scanf("%d",&option);
        system("cls");
    }while(option < 1 || option > 4);
    
    switch(option)
    {
        case 1://ADD
            system("cls");
            printf("\n***AGENDA***\n\n");
            printf("Enter a date (MM/DD): ");
            scanf("%d %d",&month,&day);
            
            addTasks(month-1,day);//ARRAY INDEX STARTS AT MONTH 0
            getch();
            system("cls");
            callMenu();
            break;
            
        case 2://DELETE
            system("cls");
            printf("\n***AGENDA***\n\n");
            printf("Enter a date (MM/DD): ");
            scanf("%d %d",&month,&day);

            printTasks(month-1,day);
            deleteTasks(month-1,day);
            getch();
            system("cls");
            callMenu();
            break;
            
        case 3://PRINT
            system("cls");
            printf("\n***AGENDA***\n\n");
            printf("Enter a date (MM/DD): ");
            scanf("%d %d",&month,&day);
            
            printTasks(month-1,day);
            getch();
            system("cls");
            callMenu();
            break;
            
        case 4://EXIT
            system("cls");
            printf("\n***PROGRAM FINISHED***\n");
            break;
    }
}

void addTasks(int month,int day)
{
    char temp[MAX_LIMIT];
    SCHEDULE *new = malloc(sizeof(SCHEDULE));
    
    if(new != NULL)//CHECK FOR CORRECT MEMORY ALOCATION
    {
        printf("type your task: ");
        fflush(stdin);
        scanf("%[^\n]",temp);
        strcpy(new->task,temp);
        new->next = NULL;
        
        if(agenda[month][day] == NULL){agenda[month][day] = new;}//CREATE NEW SCHEDULE IF THE DAY IS EMPTY
        
        else //ADD AT THE END OF THE SCHEDULE
        {
            SCHEDULE *cont = malloc(sizeof(SCHEDULE));
            cont = agenda[month][day];
            while(cont->next)
            {
                cont=cont->next;
            }
            cont->next = new;
            cont = NULL;
            free(cont);
        }
        printf("\n***NEW TASK ADDED ON [%d]/[%d]***\n", day,month);
        new = NULL;
        free(new);
    }
    else
    {
        printf("\n¡¡¡¡ALOCATION FAILURE!!!\n");
    }
}

void deleteTasks(int month,int day)
{
    int pos = 0;

    printf("\nType the # of the task you want to delete: ");
    scanf("%d",&pos);
    SCHEDULE *cont = agenda[month][day];

    if(pos == 1 && cont != NULL)//DELETE FIRST TASK
    {
        agenda[month][day] = agenda[month][day]->next;
        cont = NULL;
        free(cont);
    }

    else//DELETE ANY OTHER TASK
    {
        SCHEDULE *temp = cont->next;
        for(int i = 1; i<pos-1; i++)
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
        temp = NULL;
        free(temp);
    }

    cont = NULL;
    free(cont);
    printf("\nTASK DELETED");
}

void printTasks(int month,int day)
{
    if(agenda[month][day] == NULL){printf("\nYou dont have tasks on the schedule\n");}
    else
    {
        int i = 1;
        SCHEDULE *temp = agenda[month][day];
        while(temp)
        {
            printf("Task #%d = %s\n",i,temp->task);
            temp = temp->next;
            i++;
        }
        temp = NULL;
        free(temp);
        printf("\n");
    }
}
