#include "et.h"
#include <ctype.h>

void Stack_initialize(Stack* ptr_Stack){
    ptr_Stack = (Stack*)malloc(sizeof(Stack));
    ptr_Stack->top = -1;
}

void Stack_push(Stack* ptr_Stack, Node* n){
    ptr_Stack->top++;
    ptr_Stack->s[ptr_Stack->top] = n;
}

Node* Stack_pop(Stack* ptr_Stack){
    Node* temp = ptr_Stack->s[ptr_Stack->top];
    ptr_Stack->top--;
    return temp;
}

Node * createExpressionTree(char* a,int len)
{
    Stack st;
    Stack_initialize(&st);
    Node *t1 = NULL;
    Node* t2 = NULL;
    Node* t = (Node*)malloc(sizeof(Node));
    t->left = NULL;
    t->right = NULL;
    for (int i = 0; i < len; i++){
        if (a[i] == '+' || a[i] == '-' || a[i] == '*' || a[i] == '/' || a[i] == '^'){
            t->data = a[i];
            t1 = Stack_pop(&st);
            t2 = Stack_pop(&st);
            t->right = t1;
            t->left = t2;
            Stack_push(&st, t);
        }
        else{
            t->data = a[i];
            Stack_push(&st, t);
        }
    }
    t = Stack_pop(&st);
    return t;
}

void inorder(Node *root)
{
 //TODO
 // Note : Do not change the printf
  inorder(root->left);
  printf("%c",root->data);
  inorder(root->right);
}

void preorder(Node *root)
{
 //TODO
 // Note : Do not change the printf
  printf("%c",root->data);
  preorder(root->left);
  preorder(root->right);
}

void postorder(Node *root)
{
 //TODO
 // Note : Do not change the printf
  postorder(root->left);
  postorder(root->right);
  printf("%c",root->data);
}

void freeTree(Node *root)
{
    freeTree(root->right);
    freeTree(root->left);
    free(root);
}

