#include<stdio.h>
#include<stdlib.h>
#include "tbt.h"

void tree_initialize(Tree *tree)
{
    tree->root = NULL;
    /*tree->root->left = NULL;
    tree->root->right = NULL;
    tree->root->leftThread = 1;
    tree->root->rightThread = 1;*/
}

void tree_insert(Tree *tree, int data)
{
    Node* ptr = tree->root;
    Node* parent = NULL;
    while (ptr != NULL){
        parent = ptr;
        if (data < ptr->data){
            if (ptr->leftThread == 0)
                ptr = ptr->left;
            else
                break;
        }
        else{
            if (ptr->rightThread == 0)
                ptr = ptr->right;
            else
                break;
        }
    }
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = data;
    temp->leftThread = 1;
    temp->rightThread = 1;

    if (parent == NULL){
        tree->root = temp;
        temp->left = NULL;
        temp->right = NULL;
    }
    else if (data < parent->data){
        temp->left = parent->left;
        temp->right = parent;
        parent->leftThread = 0;
        parent->left = temp;
    }
    else{
        temp->left = parent;
        temp->right = parent->right;
        parent->rightThread = 0;
        parent->right = temp;
    }
}

Node *inorder_predecessor(Node *ptr)
{
    if (ptr->leftThread == 1)
        return ptr->left;
    ptr = ptr->left;
    while(ptr->rightThread == 0)
        ptr = ptr->right;
    return ptr;
}

Node *inorder_successor(Node *ptr)
{
    if (ptr->rightThread == 1)
        return ptr->right;
    ptr = ptr->right;
    while (ptr->leftThread == 0)
        ptr = ptr->left;
    return ptr;
}

void print_ascending(Tree *tree)
{
    if (tree->root == NULL)
    {
        printf("Empty\n");
        return;
    }
    Node* ptr = tree->root;
    while (ptr->leftThread == 0)
        ptr = ptr->left;
    while (ptr != NULL){
        printfun(ptr->data);
        ptr = inorder_successor(ptr);
    }
    nextline();

    // TODO : Use printf() specified in tbtmain.c. Dont use printf statement
}

void print_descending(Tree *tree)
{
    if (tree->root == NULL)
    {
        printf("Empty\n");
        return;
    }
    Node* ptr = tree->root;
    while (ptr->rightThread == 0)
        ptr = ptr->right;
    while (ptr != NULL){
        printfun(ptr->data);
        ptr = inorder_predecessor(ptr);
    }
    nextline();
// TODO : Use printf() specified in tbtmain.c. Dont use printf statement
}

void destroy(Node *r)
{
    destroy(r->left);
    destroy(r->right);
    free(r);
}

void tree_destroy(Tree *t)
{
    destroy(t->root);
    free(t);
}
