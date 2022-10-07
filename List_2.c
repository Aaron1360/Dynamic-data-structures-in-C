#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct person
{
    int age;
    struct person *next;
};

struct person *getNew(const int age)
{
    struct person *newperson = NULL;
    newperson = malloc(sizeof(struct person));
    if(newperson != NULL)
    {
        newperson->next = NULL;
        newperson->age=age;
        printf("Create new person at %p\n\n",newperson);
    }
    else
    {
        printf("¡¡¡¡ALOCATION FAILURE!!!\n");
    }
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
        printf("%s: Age: %d Address: %p Next in line:%p\n\n",comment,someone->age,someone,someone->next);
    }
}

void printList(const struct person *List)
{
    printf("Printing List:\n");
	const struct person *t;
	t = List;
    if(t == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        while(t)
        {
            printData(t, "t");
            t = t->next;
        }
    }
}

void CleanUp(struct person *list)
{
    struct person *next;
    while(list)
    {
        next = list->next;
        printf("Cleaning %d\n", list->age);
        free(list);
        list = next;
    }
}

int main() 
{
	printf("\n\n** START **\n\n");

    struct person *first = NULL;
    struct person *added = NULL;

    char command[64];
	int age;

    while(1)
    {
        printf( "Enter a command or value : ");
		fgets(command, 64, stdin);
		if (strcmp("q\n", command) == 0) 
		{
			printf("Quitting..\n");
			break;
		}
		else if (strcmp("print\n", command) == 0) 
        {
            printf("Printing..\n");
            printList(first);
        }
        else if(sscanf(command, "%d", &age) != 0)
        {
            printf("Adding %d\n", age);
            if (first == NULL)
            {
                first = getNew(age);
                if(first != NULL)
                {
                    added = first;
                }
            }
            else
            {
                added->next = getNew(age);
                if(added->next != NULL)
                {
                    added = added->next;
                }
            }
            
        }
    }

    CleanUp(first);
    first = NULL;
    added = NULL;

	return 0;
}





