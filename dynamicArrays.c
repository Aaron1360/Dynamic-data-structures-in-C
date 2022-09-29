/*dynamic memory alocation*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void unod();
void dosd();
void dynamic();

int main()
{
  //unod();
  //dosd();
  dynamic();
  
  return 0;
}

void unod()
{
  int *p=malloc(sizeof(int)*5);//1D memory alocation
  
  for(int i=0;i<5;i++)
  {
    p[i]=i+1;
    printf("%d  ",p[i]);
  } 
  free(p);//DON´T FORGET TO FREE MEMORY
}

void dosd()
{
  int **p=malloc(sizeof(int*)*5);//2D memory alocation
  
  for(int i=0;i<5;i++)
  {
    p[i]=malloc(sizeof(int)*3);
  } 
  
  for(int i=0;i<5;i++)
  {
      for(int j=0;j<3;j++)
      {
          p[i][j]=pow(i+1,j+1);
          printf("%3d  ",p[i][j]);
      }
      printf("\n");
  }
  free(p);//DON´T FORGET TO FREE MEMORY
}
void dynamic()
{
    int size;
    printf("enter size: ");
    scanf("%d",&size);
    int **p=malloc(sizeof(int*)*size);//2D dynamic array
    int *cols=malloc(sizeof(int)*size);//save # of cols 
    
    for(int i=0;i<size;i++)
    {
        printf("\nenter # of cols in [%d]: ",i+1);
        scanf("%d",&cols[i]);
        p[i]=malloc(sizeof(int)*cols[i]);
    }
    
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<cols[i];j++)
        {
            p[i][j]=pow(i+1,j+1);
            printf("%3d ",p[i][j]);
        }
        printf("\n\n");
    }
    free(p);//DON´T FORGET TO FREE MEMORY
    free(cols);
}
