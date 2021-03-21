#include "cll.h"
void position_insert(List* cll, int data, int pos)
{
    Node* newNode = create_node(data);
    if (newNode == NULL)
        printf("Could not allocate memory\n");
    if (cll->head == NULL && cll->tail == NULL){
        cll->head = newNode;
        cll->tail = newNode;
        cll->tail->next = cll->head;
    }
    else if (pos == 0){
        newNode->next = cll->head;
        cll->head = newNode;
        cll->tail->next = cll->head;
    }
    else if (pos == cll->length){
        cll->tail->next = newNode;
        cll->tail = newNode;
        newNode->next = cll->head;
    }
    else if (pos > cll->length)
        return;
    else{
        Node* temp = cll->head;
        for (int i = 0;  i < pos - 1; i++)
            temp = temp->next;
        newNode->next = temp->next;
        temp->next = newNode;
    }
    cll->length ++;
}

void position_delete(List* cll, int pos)
{
    Node* temp = NULL;
    if (cll->head == NULL)
        printf("Cannot delete from an empty list\n");
    else if (pos == 0){
        temp = cll->head;
        cll->head = temp->next;
        cll->tail = cll->head;
        free(temp);
   }
   else if (pos == -1){
        free(cll->tail);
        temp = cll->head;
        for (int i = 0; i < cll->length - 2; i++)
            temp = temp->next;
        cll->tail = temp;
        cll->tail->next = cll->head;
   }
   else if (pos > cll->length)
        return;
   else{
        Node* prev = cll->head;
        for (int i = 0; i < pos - 1; i++)
            prev = prev->next;
        temp = prev->next;
        prev->next = temp->next;
        free(temp);
   }
   cll->length--;
}

int josephus(List* cll, int k)
{
    if (cll->head == NULL)
        printf("List is empty\n");
    Node* temp = cll->head;
    Node* cursor = NULL;
    for (int i = 0; i != k; i++)
        temp = temp->next;
    while (cll->length != 1){
        cursor = temp->next;
        temp->next = cursor->next;
        free(cursor);
        cll->length --;
        temp = temp->next;
    }
    cll->head = temp;
    cll->tail = temp;
    return temp->data;
}


