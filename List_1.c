#include <stdio.h>
#include <string.h>

struct LIST
{
    char product[20];
    int account;
    struct LIST *next;
};

struct LIST *shoppingList = NULL;

void createList()
{
    struct LIST article1;
    strcpy(article1.product,"gel");
    article1.account = 2;
    article1.next = NULL;
    
    shoppingList = &article1;
    
    struct LIST article2;
    strcpy(article2.product,"cookies");
    article2.account = 42;
    article2.next = NULL;
    
    article1.next=&article2;
    
    struct LIST article3;
    strcpy(article3.product,"milk");
    article3.account = 12;
    article3.next = NULL;
    
    article2.next=&article3;
    
    printf("NEW LIST CREATED!\n\n");
}
void showList()
{
    struct LIST *item = shoppingList;
    int i=1;
    while(i<4)
    {
        printf("article %d: %s x %d\n\n",i,item->product,item->account);
        i++;
        item=item->next;
    }
}
int main()
{
    createList();
    showList();

    return 0;
}

