
#include "et.h"

int isoper(char chr);
void push(Node **, int *, Node *);
Node* pop(Node **,int *);


Node * createExpressionTree(char* a,int len)
{
struct Node *stack[100];
    int top = -1;
    
    struct Node *temp;
    
    for(int i=0;a[i]!='\0';i++)
    {
      temp = (struct Node *)(malloc(sizeof(struct Node)));	  
      temp->left = NULL;
      temp->right = NULL;
      temp->data = a[i];
      if(a[i]=='+' || a[i]=='-' || a[i]=='*' || a[i]=='/')	
      {
        temp->right = pop(stack,&top);
        temp->left = pop(stack,&top);
        push(stack,&top,temp);
      }	
      else 	
      {
        push(stack,&top,temp); 	 
      }
    }
    return(pop(stack,&top));
}


void inorder(Node *root)
{
 //TODO 
 // Note : Do not change the printf
if(root!=NULL)
  {
   inorder(root->left);
    printf("%c",root->data);
   inorder(root->right);
  }
  
}

void preorder(Node *root)
{
 //TODO 
 // Note : Do not change the printf
  if(root!=NULL)
  {
  	printf("%c",root->data);
   	preorder(root->left);
   	preorder(root->right);
  }  
}

void postorder(Node *root)
{
 //TODO 
 // Note : Do not change the printf
  if(root!=NULL)
  {
   	postorder(root->left);
   	postorder(root->right);
   	printf("%c",root->data);
  }
}

void freeTree(Node *root)
{
	
}



int isoper(char chr)
{
	switch(chr)
	{
		case '+':
		case '-':
		case '*':
		case '/': return 1;
		default : return 0;
	}
}



void push(Node **p,int *t, Node *temp)
{
	++(*t);
    p[*t]=temp;
}

Node* pop(Node **q,int *t)
{
	Node *temp;
	temp=q[*t];
	(*t)--;
	return temp;
}
