/*
*Desarrollador: Aaron Moreno Villeda
*Fecha de creación: 26/09/2022
*
*1.-Debes crear un array con 12 elementos, uno por cada mes del año, cada elemento debe tener a su vez un array con tantos elementos como días tenga dicho mes. 
*Es decir, la posicion 0 del array, que correspondería a enero, debería tener 31 elementos para los 31 días correspondientes. 
*Finalmente cada uno de esos elementos debe contener un puntero a un struct. Ese struct constituiría el inicio de la lista de tareas que habría en cada día 
*de la agenda.
*/

#include <stdio.h>

typedef struct 
{
    char task[50];
    struct SCHEDULE *next;
}SCHEDULE;

int main()
{
  int *months[12];//static array of 12 elements
  int days[12]={31,28,31,30,31,30,31,31,30,31,30,31};//# of days
  
  for(int )
  
  return 0;
}
