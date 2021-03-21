#include "stack.h"

static Node* create_Node(int data, Node* link)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->link = link;
    return newNode;
}


void list_initialize(List* ptr_list)
{
    ptr_list = (List*)malloc(sizeof(List));
    ptr_list->head = NULL;
    ptr_list->number_of_Nodes = 0;
}


void list_insert_front(List* ptr_list, int data)
{
    Node* node = create_Node(data,NULL);
    if (node == NULL)
        printf("Cannot allocate memory\n");
    if (ptr_list->head == NULL)
        ptr_list->head = node;
    else{
        node->link = ptr_list->head;
        ptr_list->head = node;
    }
    ptr_list->number_of_Nodes++;
}


const int Node_get_data(Node* Node_ptr)
{
    return Node_ptr->data;
}


void list_delete_front(List* ptr_list)
{
    if(ptr_list->number_of_Nodes == 0)
        printf("Cannot delete from an empty list\n");
    Node* temp = ptr_list->head;
    ptr_list->head = temp->link;
    free(temp);
    ptr_list->number_of_Nodes--;
}


void list_destroy(List* ptr_list)
{
    Node* temp = ptr_list->head;
    Node* cursor = NULL;
    while (temp != NULL){
        cursor = temp;
        temp = temp->link;
        free(cursor);
    }
    free(ptr_list);
}


void Stack_initialize(Stack* ptr_Stack)
{
    ptr_Stack->ptr_list = (List*)malloc(sizeof(List));
    list_initialize(ptr_Stack->ptr_list);
}

void Stack_push(Stack* ptr_Stack,int key)
{
    list_insert_front(ptr_Stack->ptr_list,key);
}

void Stack_pop(Stack* ptr_Stack)
{
    list_delete_front(ptr_Stack->ptr_list);
}

int Stack_is_empty(Stack* ptr_Stack)
{
    if(ptr_Stack->ptr_list->number_of_Nodes == 0)
        return 1;
    else
        return 0;
}

const int Stack_peek(Stack *ptr_Stack)
{
    return Node_get_data(ptr_Stack->ptr_list->head);
}

void Stack_destroy(Stack *ptr_Stack)
{
    list_destroy(ptr_Stack->ptr_list);
    free(ptr_Stack);
}

int match_parenthesis(const char* string)
{
    Stack ptr_Stack;
    Stack_initialize(&ptr_Stack);

    while(*string != '\0'){
        if (*string == '(' || *string == '{' || *string == '[')
                Stack_push(&ptr_Stack,*string);
        else if (*string == ')'){
            if (Stack_peek(&ptr_Stack) == '(')
                    Stack_pop(&ptr_Stack);
            else
                return 0;
        }
        else if (*string == ']'){
            if (Stack_peek(&ptr_Stack) == '[')
                    Stack_pop(&ptr_Stack);
            else
                return 0;
        }
        else if (*string == '}'){
            if (Stack_peek(&ptr_Stack) == '{')
                    Stack_pop(&ptr_Stack);
            else
                return 0;
        }
        string++;
    }
    if(Stack_is_empty(&ptr_Stack))
        return 1;
    else
        return 0;
}






