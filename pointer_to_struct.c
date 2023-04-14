/******************************************************************************
POINTER TO STRUCT EXAMPLES DOT AND DASH NOTATION 
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef struct
    {
        int x;
        int y;
    }point;
    
int main()
{
    point p1;//struct
    
    p1.x=5;
    p1.y=3;
    printf("P1(%d,%d)\n",p1.x,p1.y);
    
    point *p2=&p1;//pointer to struct
    p2->x=3;//dash notation
    p2->y=6;
    printf("P2(%d,%d)\n",p2->x,p2->y);
    
    point *p3;
    p3=malloc(sizeof(point));//dynamic memory alocation 
    (*p3).x=2;//dot notation
    (*p3).y=9;
    printf("P3(%d,%d)\n",(*p3).x,(*p3).y);
    
    return 0;
}
