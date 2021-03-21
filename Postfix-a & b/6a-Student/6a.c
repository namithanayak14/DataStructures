#include "6a.h"
#include<ctype.h>

static Node* create_Node(int data, Node* link) {
	Node* temp =  (Node*)malloc(sizeof(Node));
	temp -> data = data;
	temp -> link = link;
	return temp;
}

void List_initialize(List* ptr_List)
{
    ptr_List = (List*)malloc(sizeof(List));
    ptr_List->head = NULL;
    ptr_List->number_of_Nodes = 0;
}

void List_insert_front(List* ptr_List, int data)
{
    Node* node = create_Node(data,NULL);
    if (node == NULL)
        printf("Cannot allocate memory\n");
    if (ptr_List->head == NULL)
        ptr_List->head = node;
    else{
        node->link = ptr_List->head;
        ptr_List->head = node;
    }
    ptr_List->number_of_Nodes++;
}

const int Node_get_data(Node *Node_ptr)
{
    return Node_ptr->data;
}

void List_delete_front(List* ptr_List)
{
    if(ptr_List->number_of_Nodes == 0)
        printf("Cannot delete from an empty list\n");
    Node* temp = ptr_List->head;
    ptr_List->head = temp->link;
    free(temp);
    ptr_List->number_of_Nodes--;
}

void List_destroy(List* ptr_List)
{
    Node* temp = ptr_List->head;
    Node* cursor = NULL;
    while (temp != NULL){
        cursor = temp;
        temp = temp->link;
        free(cursor);
    }
    free(ptr_List);
}


void stack_initialize(Stack *ptr_stack)
{
    ptr_stack->ptr_List = (List*)malloc(sizeof(List));
    List_initialize(ptr_stack->ptr_List);
}

void stack_push(Stack *ptr_stack, int key)
{
    List_insert_front(ptr_stack->ptr_List,key);
}

void stack_pop(Stack *ptr_stack)
{
    List_delete_front(ptr_stack->ptr_List);
}

int stack_is_empty(Stack *ptr_stack)
{
    if(ptr_stack->ptr_List->number_of_Nodes == 0)
        return 1;
    else
        return 0;
}

const int stack_peek(Stack *ptr_stack)
{
    return Node_get_data(ptr_stack->ptr_List->head);
}

void stack_destroy(Stack *ptr_stack)
{
    List_destroy(ptr_stack->ptr_List);
    free(ptr_stack);
}

int postfix_eval(const char* expression)
{
    Stack stack;
    stack_initialize(&stack);
    if (stack == NULL)
        printf("Unable to initialize stack\n");
    for (int i = 0; expression[i]; ++i){
        if(isdigit(expression[i]))
            stack_push(&stack, expression[i] - '0');
        else{
            int num1 = stack_pop(&stack);
            int num2 = stack_pop(&stack);
            switch(expression[i]){
                case '+': stack_push(&stack, num1+num2);
                    break;
                case '-': stack_push(&stack, num2-num1);
                    break;
                case '*': stack_push(&stack, num2*num1);
                    break;
                case '/': stack_push(&stack, num2/num1);
                    break;
            }
        }
    }
    return stack_pop(&stack);
}
