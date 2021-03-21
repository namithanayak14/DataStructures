#include"dll.h"
int count_nodes(List* dll)
{
	int counter = 0;
	Node* temp = (Node*)malloc(sizeof(Node));
	temp = dll->head;
	if(temp == NULL)
        printf("List is empty\n");
    while(temp != NULL){
            counter++;
            temp = temp->next;
    }
    return counter;
}

void insert_front(List* dll, int data)
{
    Node* first = NULL;
    first = dll->head;
    Node* newNode = create_node(data);
    if (newNode == NULL)
        printf("Unable to allocate memory\n");
    if (first == NULL){
        dll->head = newNode;
    }
    else{
        newNode->next = first;
        first->prev = newNode;
        dll->head = newNode;
    }
    dll->number_of_nodes += 1;

    Node* temp = NULL;
    temp = dll->head;
    while (temp != NULL && temp->next != NULL)
        temp = temp->next;
    dll->tail = temp;
}


void dllist_delete_beginning(List* dll)
{
    if (dll->head == NULL)
        printf("Cannot delete from an empty list\n");
    else if (dll->number_of_nodes == 1){
        Node* temp = dll->tail;
        free(temp);
        dll->number_of_nodes--;
    }
    else{
        Node* temp = NULL;
        temp = dll->head;
        dll->head = temp->next;
        dll->head->prev = NULL;
        free(temp);
        dll->number_of_nodes--;
    }
}


void position_delete(List* dll, int pos)
{
    int counter = 0;
    if (pos == 0){
        dllist_delete_beginning(dll);
        dll->number_of_nodes--;
    }
    else if (pos == -1){
        Node* ptr = NULL;
        ptr = dll->tail;
        dll->tail = ptr->prev;
        dll->tail->next = NULL;
        free(ptr);
        dll->number_of_nodes--;
    }
    else if (dll->number_of_nodes == 1){
        Node* temp = dll->tail;
        free(temp);
        dll->number_of_nodes--;
    }
    else if (pos > dll->number_of_nodes)
        return;
    else{
        Node* temp = NULL;
        for (temp = dll->head; temp->next != NULL; temp = temp->next){
            if (counter == pos){
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                free(temp);
                dll->number_of_nodes--;
                break;
            }
            counter++;
        }
    }
}

int search_list(List* dll,int key)
{
    Node* temp = NULL;
    temp = dll->head;
    int count = 0;
    if (temp == NULL)
        printf("List is empty\n");
    while(temp != NULL){
        if (temp->data == key){
                return count;
        }
        count++;
        temp = temp->next;
    }
    return -1;
}


void reverse_list(List* dll)
{
    Node* ptr = dll->head;
    if (ptr == NULL)
        return;
    Node* temp;

    while(ptr != NULL){
        temp = ptr->next;
        ptr->next = ptr->prev;
        ptr->prev = temp;
        ptr = temp;
    }
    temp = dll->head;
    dll->head = dll->tail;
    dll->tail = temp;
}


