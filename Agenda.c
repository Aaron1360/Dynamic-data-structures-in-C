/*
*Desarrollador: Aaron Moreno Villeda
*Fecha de creación: 29/09/2022
*
*1.-Debes crear un array con 12 elementos, uno por cada mes del año, cada elemento debe tener a su vez un array con tantos elementos como días tenga dicho mes. 
*Es decir, la posicion 0 del array, que correspondería a enero, debería tener 31 elementos para los 31 días correspondientes. 
*Finalmente cada uno de esos elementos debe contener un puntero a un struct. Ese struct constituiría el inicio de la lista de tareas que habría en cada día 
*de la agenda.
*/

#include <stdio.h>
#include <stdlib.h>


int main()
{
    //data type alocated on each position of the array 
    struct SCHEDULE{
        char task[50];
        struct SCHEDULE* next;
    };
    
    //static pointer array with 12 elements
    struct SCHEDULE***agenda=malloc(sizeof(struct SCHEDULE**)*12);
    int days;
    
    //dynamic alocation with as many elements as days have the corresponding month 
    for(int i=0;i<12;i++)
    {
        switch (i) {//# of days
            case 1: case 3:  case 5: case 7: case 8: case 10: case 12 : days = 31; break;
            case 4: case 6: case 9:  case 11: days = 30; break;
            default: days = 28;
        }
        
        agenda[i]=malloc(sizeof(struct SCHEDULE*)*days);
        
        for (int j=0;j<days;j++) agenda[i][j]=NULL;
    }
    
  return 0;
}
