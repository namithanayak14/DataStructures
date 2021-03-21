#include "poly.h"
void insert_at_end(List *list, int data)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL)
        printf("Unable to allocate memory\n");
    Node* temp = NULL;
    temp = list->head;
    newNode->data = data;
    newNode->link = NULL;
    if (temp == NULL)
        list->head = newNode;
    else{
        while(temp != NULL && temp->link != NULL)
            temp = temp->link;
        temp->link = newNode;
    }
    list->number_of_nodes += 1;
}

long long int evaluate(List *list, int x)
{
    Node* temp = NULL;
    temp = list->head;
    int count = 0;
    long long int value;
    long long int result;
    long long int total = 0;
    int n;
    while(temp != NULL){
        n = temp->data;
        value = 1;
        for(int i = 0; i < count; i++)
            value *= x;
        result = n * value;
        total += result;
        count++;
        temp = temp->link;
    }
    return total;
}
