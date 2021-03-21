#include "queue.h"
static node *create_node(int id, int time, node *link)
{
    node* newNode = (node*)malloc(sizeof(node));
    newNode->id = id;
    newNode->time = time;
    newNode->link = NULL;
    return newNode;
}
void list_initialize(List *ptr_list)
{
    ptr_list->head = NULL;
    ptr_list->tail = NULL;
    ptr_list->number_of_nodes = 0;
}
const int node_get_id(node *node_ptr)
{
    return (node_ptr->id);
}

const int node_get_time(node *node_ptr)
{
    return (node_ptr->time);
}

void list_insert_rear(List *ptr_list, int id, int time)
{
    node* newNode = create_node(id, time, NULL);
    if (newNode == NULL)
        printf("Unable to allocate memory\n");
    if (ptr_list->number_of_nodes == 0){
        ptr_list->head = newNode;
        ptr_list->tail = newNode;
    }
    else{
        ptr_list->tail->link = newNode;
        ptr_list->tail = newNode;
    }
    ptr_list->number_of_nodes++;
}

void list_delete_front(List *ptr_list)
{
    if (ptr_list->number_of_nodes == 0)
        printf("List is empty\n");
    else{
        node* temp = ptr_list->head;
        ptr_list->head = temp->link;
        free(temp);
        ptr_list->number_of_nodes--;
    }
}

void list_destroy(List *ptr_list)
{
    node* temp = ptr_list->head;
    node* cursor = NULL;
    while(temp != NULL){
        cursor = temp;
        temp = temp->link;
        free(cursor);
    }
    free(temp);
    free(ptr_list);
}

void queue_initialize(Queue *queue_list)
{
    queue_list->ptr_list = (List*)malloc(sizeof(List));
    list_initialize(queue_list->ptr_list);
}

void queue_enqueue(Queue *ptr, int id, int time)
{
    list_insert_rear(ptr->ptr_list, id, time);
}

void queue_dequeue(Queue *ptr)
{
    list_delete_front(ptr->ptr_list);
}

int queue_is_empty(Queue *ptr)
{
    if (ptr->ptr_list->number_of_nodes == 0)
        return 1;
    else
        return 0;
}

void queue_peek(Queue *ptr)
{
    printf("id: %d", node_get_id(ptr->ptr_list->head));
    printf(" time: %d\n", node_get_time(ptr->ptr_list->head));
}

void queue_destroy(Queue *ptr)
{
    list_destroy(ptr->ptr_list);
    free(ptr);
}

const int queue_find_person(Queue *ptr_queue, int t)
{
    int time;
    int id;
    while (t != 0 && ptr_queue->ptr_list->head != NULL){
        id = node_get_id(ptr_queue->ptr_list->head);
        time = node_get_id(ptr_queue->ptr_list->head);
        queue_dequeue(ptr_queue);
        t = t - time;
    }
    printf("%d\n", id);
    return id;
}
