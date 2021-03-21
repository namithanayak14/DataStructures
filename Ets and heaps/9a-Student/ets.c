#include "et.h"

static Node* create_Node(char data)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->prev = NULL;
    return newNode;
}

void list_initialize(List* ptr_list)
{
    ptr_list = (List*)malloc(sizeof(List));
    ptr_list->head = NULL;
    ptr_list->number_of_Nodes = 0;
}

void list_insert_front(List* ptr_list, char data)
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

void list_delete_front(List* ptr_list)
{
    if(ptr_list->number_of_Nodes == 0)
        printf("Cannot delete from an empty list\n");
    Node* temp = ptr_list->head;
    ptr_list->head = temp->link;
    free(temp);
    ptr_list->number_of_Nodes--;
}

const int Node_get_data(Node* Node_ptr)
{
    return Node_ptr->data;
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

void Stack_push(Stack* ptr_Stack, Node* key)
{
    list_insert_front(ptr_Stack->ptr_list,key);
}

void Stack_pop(Stack* ptr_Stack)
{
    list_delete_front(ptr_Stack->ptr_list);
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

Node * createExpressionTree(char* a,int len)
{
    Stack ptr_Stack;
    ptr_Stack->ptr_list = (List*)malloc(sizeof(List));
    list_initialize(ptr_Stack->ptr_List);

    Node* t;
    Node* t1 = NULL;
    Node* t2 = NULL;
    int c;
    for (int i = 0; i < strlen(postfix); i++){
        c = postfix[i];
        if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^'){
            t = create_Node(c);
            t1 = Stack_peek(&ptr_Stack);
            Stack_pop(&ptr_Stack);
            t2 = Stack_peek(&ptr_Stack);
            Stack_pop(&ptr_Stack);

            t->right = t1;
            t->left = t2;
            Stack_push(&ptr_Stack, t);
        }
        else{
            t = create_Node(c);
            Stack_push(&ptr_Stack,t);
        }
    }
    t = Stack_peek(&ptr_Stack);
    Stack_pop(&ptr_Stack);
    return t;
}


void inorder(Node *root)
{
  inorder(root->left);
  printf("%c",root->data);
  inorder(root->right);
}

void preorder(Node *root)
{
  printf("%c",root->data);
  preorder(root->left);
  preorder(root->right);
}

void postorder(Node *root)
{
  postorder(root->left);
  postorder(root->right);
  printf("%c",root->data);
}

void freeTree(Node *root)
{
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

