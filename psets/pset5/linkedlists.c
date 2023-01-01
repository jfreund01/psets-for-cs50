#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int number;
    struct node *next;
}
node;

int main(void){

    node *list = NULL;
    //Add a number to list

    node *n = malloc(sizeof(node));
    if (n == NULL){
        printf("Invalid Memory Location");
        return 1;
    }

    n->number = 1;
    n->next = NULL;

    //Update list to point to new node
    list = n;

    //add a second number to the list;

    n = malloc(sizeof(node));
    if (n == NULL){
        free(list);
        return 1;
    }

    n->number = 2;
    n->next = NULL;
    list->next = n;

    n = malloc(sizeof(node));
    if (n == NULL){

        free(list->next); //free nodes in reverse order
        free(list);
        return 1;
    }

    n->number = 3;
    n->next = NULL;
    list->next->next = n;

    for (node *tmp = list; tmp != NULL; tmp = tmp->next){

        printf("Value %i at location %p\n", tmp->number, tmp);
    }

    while (list != NULL)
    {
        node *tmp = list->next;
        free(list);
        list = tmp;
    }

    return 0;
}//this is hard to understand