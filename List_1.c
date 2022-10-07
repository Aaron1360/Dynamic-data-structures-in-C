#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct List
{
    char product[20];
    int account;
    struct List *nextProduct; 
};

struct List *newProduct(const char product[20],const int account);
void printList(const struct List *pList,const char *comment);

int main()
{
    
    return 0;
}