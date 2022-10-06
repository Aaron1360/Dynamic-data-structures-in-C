#include <stdio.h>
#include <stdlib.h>
struct person
{
    int age;
    struct person *next;
};

struct person *getNew(const int age);
void printData(const struct person *someone,const char *comment);

int main()
{
    printf("***START***\n");
    struct person *first = NULL;
    struct person *second = NULL;
    
    printData(first,"first");
    printData(second,"second");
    
    first = getNew(25);
    second = getNew(50);
    
    printData(first,"first");
    printData(second,"second");
    
    first->next=second;
    
    printData(first,"first");
    printData(first->next,"first->next");
    printData(second,"second");
    
    free(first);
    free(second);
    
    first = NULL;
    second = NULL;
    
    return 0;
}

struct person *getNew(const int age)
{
    struct person *newperson = NULL;
    newperson = malloc(sizeof(struct person));
    newperson->next = NULL;
    newperson->age=age;
    printf("create new person at %p\n\n",newperson);
    return newperson;
}

void printData(const struct person *someone,const char *comment)
{
    if(someone == NULL)
    {
        printf("%s is NULL\n\n",comment);
    }
    else
    {
        printf("%s: age: %d address: %p next in line:%p\n\n",comment,someone->age,someone,someone->next);
    }
}
