#include<stdlib.h>
#include<stdio.h>
#include<string.h>

typedef struct Node
{
 struct Node *right,*left,*prev;
 char data;
} Node;

typedef struct node{
    char data;
    struct node* link;
}node;

typedef struct List {
	Node *head;
	int number_of_Nodes;
};

typedef struct Stack {
	List *ptr_list;
} Stack;
//Create Binary Expression tree from a string in postfix form  of length len
Node * createExpressionTree(char* a,int len);

void list_initialize(List* List);

void list_insert_front(List* List, char data);

void list_delete_front(List* List);

const int Node_get_data(Node* Node_ptr);

void Stack_push(Stack* ptr_Stack, Node* data);
void Stack_pop(Stack* ptr_Stack);
const int Stack_peek(Stack* ptr_Stack);
void Stack_destroy(Stack* ptr_Stack);
//print the preorder traversal of the Binary Expression Tree
void preorder(Node *);


//print the postorder traversal of the Binary Expression Tree
void postorder(Node *);


//print the inorder traversal of the Binary Expression Tree
void inorder(Node *);


//Frees the space used by the Binary Expression Tree
void freeTree(Node * root);


