#include<stdio.h>
#include<stdlib.h>
#include "sll.h"

void insert_at_end(List *list, int data) {
	Node* newNode;
	newNode = (Node*)malloc(sizeof(Node));
	if (newNode == NULL){
        printf("Unable to allocate memory\n");
	}
	else{
        Node* temp = NULL;
        temp = list->head;
        newNode->data=data;
        newNode->link=NULL;
        if(temp == NULL){
            list->head = newNode;
        }
        else{
            while(temp!=NULL && temp->link!=NULL)
                temp = temp->link;
            temp->link = newNode;
        }
        list->number_of_nodes += 1;
	}
}

void list_delete_front(List* list) {
	Node* temp = NULL;
	temp = list->head;
	list->head = temp->link;
	free(temp);
}

void list_insert_at (List *list, int data, int position){
    Node* temp = NULL;
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL){
        printf("Unable to allocate memory\n");
    }
    if (position == 1){
        newNode->data = data;
        newNode->link = list->head;
        list->head = newNode;
    }
    int count = 1;
    for(temp = list->head; temp != NULL; temp= temp->link){
        count++;
        if (count == position){
            newNode->data = data;
            newNode->link = temp->link;
            temp->link = newNode;
        }
    }
    list->number_of_nodes += 1;
}

void list_reverse(List* list)
{
   Node* prev = NULL;
   Node* next = NULL;
   Node* h = list->head;
   while(h != NULL){
    next = h->link;
    h->link = prev;
    prev = h;
    h = next;
   }
   list->head = prev;
}


