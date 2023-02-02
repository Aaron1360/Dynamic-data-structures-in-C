#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <stdbool.h>

typedef struct Btree
{
    int number;
    struct Btree *left;
    struct Btree *right;
}Btree;

Btree *root = NULL; 

void defaultTree();
void enterNode(int number);
void removeNodeTree(Btree *aux, Btree *prev);
void searchNodeTree(int number,bool del);
void searchNode();
void deleteNode();
void preorder(Btree *aux);
void inorder(Btree *aux);
void postorder(Btree *aux);
void showTree();

int main()
{
    defaultTree();
    showTree();
    return 0;
}
void defaultTree()
{
    enterNode(9);
    enterNode(3);
    enterNode(2);
    enterNode(7);
    enterNode(1);
    enterNode(12);
    enterNode(5);
}
void enterNode(int number)
{
    Btree *node = malloc(sizeof(Btree));
    node->number = number;
    node->left = NULL;
    node->right = NULL;
    if(root == NULL){root = node;}
    else
    {
        Btree *aux = root;
        Btree *prev;
        prev = aux;
        while(aux)
        {
            prev = aux;
            if(number < aux->number){aux = aux->left;}
            else{aux = aux->right;}
        }
        if(number < prev->number){prev->left = node;}
        else{prev->right = node;}
    }
}
void removeNodeTree(Btree *aux, Btree *prev)
{
    if(aux)
    {
         printf("\nDELETED NODE: %d\n",aux->number);
        if(prev)
        {
            if(aux->number < prev->number){prev->left = NULL;}
            else{prev->right = NULL;}
        }
        if(aux == root){root = NULL;}
        free(aux);
    }
   
}
void searchNodeTree(int number,bool del)
{
    int rounds;
    Btree *search = root;
    Btree *prev = NULL;
    
    for(rounds = 0; search; rounds++)
    {
        if(number == search->number){break;}
        else{prev = search;}
        
        if(number < search->number){search = search->left;}
        else{search = search->right;}
    }
    
    if(search == NULL){printf("NODE NOT FOUND\n");}
    else
    {
        if(!del){printf("NODE FOUND AFTER %d ROUNDS\n",rounds);}
        else
        {
            removeNodeTree(search,prev);
        }
    }
}
void searchNode()
{
    int number;
    printf("TYPE A NUMBER: ");
    scanf("%d",&number);
    searchNodeTree(number,false);
}
void deleteNode()
{
    int number;
    printf("TYPE A NUMBER: ");
    scanf("%d",&number);
    searchNodeTree(number,true);
}
void preorder(Btree *aux)
{
    if(aux)
    {
        printf("> %d\t",aux->number);
        preorder(aux->left);
        preorder(aux->right);
    }
}
void inorder(Btree *aux)
{
    if(aux)
    {
        inorder(aux->left);
        printf("> %d\t",aux->number);
        inorder(aux->right);
    }
}
void postorder(Btree *aux)
{
    if(aux)
    {
        postorder(aux->left);
        postorder(aux->right);
        printf("> %d\t",aux->number);
    }
}
void showTree()
{
    int option;
    do
    {
        printf("\n---<BINARY TREE>---\n\n");
        printf("1.-PREORDER\n");
        printf("2.-INORDER\n");
        printf("3.-POSTORDER\n");
        printf("4.-SEARCH\n");
        printf("5.-DELETE\n");
        printf("6.-EXIT\n");
        printf("Type a number: ");
        scanf("%d",&option);
    }while(option <= 0 || option > 6);
    
    switch(option)
    {
        case 1:
            preorder(root);
            showTree();
        break;
        case 2:
            inorder(root);
            showTree();
        break;
        case 3:
            postorder(root);
            showTree();
        break;
        case 4:
            searchNode();
            showTree();
        break;
        case 5:
            deleteNode();
            showTree();
        break;
    }
}
