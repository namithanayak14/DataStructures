#include<stdio.h>
#include "bst.h"
void tree_initialize(Tree *tree)
{
    tree->root = (Node*)malloc(sizeof(Node));
    tree->root->left = NULL;
    tree->root->right = NULL;
}

void tree_insert(Tree *tree, int data)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL)
        printf("Could not allocate memory\n");
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    if (tree->root == NULL)
        tree->root = newNode;
    else{
        Node* r = tree->root;
        Node* p = NULL;
        while (r != NULL){
            p = r;
            if (newNode->data > r->data)
                r = r->right;
            else
                r = r->left;
        }
        if (newNode->data > p->data)
            p->right = newNode;
        else
            p->left = newNode;
    }
}
void tree_delete(Tree *tree, int element)
{
    Node* delNode(Node* root, int element){
        Node* temp = NULL;
        Node* p = NULL;
        if (root == NULL)
            return root;
        if (element < root->data)
            root->left = delNode(root->left,element);
        else if (element > root->data)
            root->right = delNode(root->right,element);
        else{
            if (root->left == NULL){
                temp = root->right;
                free(root);
                return temp;
            }
            else if (root->right == NULL){
                temp = root->left;
                free(root);
                return temp;
            }
            else{
                p = root->right;
                while (p->left != NULL)
                    p = p->left;
                root->data = p->data;
                root->right = delNode(root->right, p->data);
            }
        }
        return root;
    }

tree->root = delNode(tree->root, element);
}

void tree_inorder(Node *r)
{
    if (r != NULL){
        tree_inorder(r->left);
        printf("%d ",r->data);
        tree_inorder(r->right);
    }
}

void tree_preorder(Node *r)
{
    if (r != NULL){
        printf("%d ", r->data);
        tree_preorder(r->left);
        tree_preorder(r->right);
    }
}

void tree_postorder(Node *r)
{
    if (r != NULL){
        tree_postorder(r->left);
        tree_postorder(r->right);
        printf("%d ",r->data);
    }
}

void postorder(Tree *t)
{
   tree_postorder(t->root);
   printf("\n");
}

void preorder(Tree *t)
{
    tree_preorder(t->root);
    printf("\n");
}

void inorder(Tree *t)
{
    tree_inorder(t->root);
    printf("\n");
}

void destroy(Node *r)
{
    destroy(r->left);
    destroy(r->right);
    free(r);
}

void tree_destroy(Tree *t)
{
    if (t->root == NULL)
        return;
    destroy(t->root);
    free(t);
}
