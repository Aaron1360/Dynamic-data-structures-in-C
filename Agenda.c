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

//data type alocated on each position of the array 
struct SCHEDULE{
    char task[50];
    struct SCHEDULE* next;
};

void menu()
{
    int option = 0;
    do{
        printf("\n***NUMBER LIST***\n\n");
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
            printf("\nTASK ADDED CORRECTLY\n");
            menu();
            break;
            
        case 2:
            printf("\nTASK DELETED CORRECTLY\n");
            menu();
            break;
            
        case 3:
            printf("\nYOUR LIST GOES HERE\n");
            menu();
            break;
            
        case 4:
            system("clear");
            printf("\n***PROGRAM FINISHED***\n");
            break;
    }
}

int main()
{
    /*
    //data type alocated on each position of the array 
    struct SCHEDULE{
        char task[50];
        struct SCHEDULE* next;
    };*/
    
    //static pointer array with 12 elements
    struct SCHEDULE ***agenda=malloc(sizeof(struct SCHEDULE**)*12);
    int days;
    
    //dynamic alocation with as many elements as days have the corresponding month 
    for(int i=0;i<12;i++)
    {
        switch (i+1) {//# of days
            case 1: case 3:  case 5: case 7: case 8: case 10: case 12 : days = 31; break;
            case 4: case 6: case 9:  case 11: days = 30; break;
            default: days = 28;
        }
        
        agenda[i]=malloc(sizeof(struct SCHEDULE*)*days);
        
        for (int j=0;j<days;j++) agenda[i][j]=NULL;
    }
    
    menu();
    
  return 0;
}
