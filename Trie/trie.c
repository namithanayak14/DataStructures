#include<stdio.h>
#include "trie.h"





































/*struct trienode *getnode(){
    struct trienode* newNode = (struct trienode*)malloc(sizeof(struct trienode));
    if (newNode){
      newNode->endofword = 0;
      for (int i = 0; i < 26; i++)
        newNode->child[i] = NULL;
    }
    return newNode;
}

void insert(struct trienode *root, char *key){
    int i,index;
    struct trienode *curr;
    curr=root;

    for(i=0;key[i]!='\0';i++){
        index=key[i]-'a';
        if(curr->child[index]==NULL)
            curr->child[index]=getnode();
        curr=curr->child[index];
    }
    curr->endofword=1;
}

void display(struct trienode *curr){
      //TODO:
     //Note : DO NOT USE printf() statement, use printfun() and   newline function for printing output
    int i,j;
    for(i=0;i<26;i++){
        if(curr->child[i]!=NULL){
            word[length++]=i+97;
            if(curr->child[i]->endofword==1){
                printf("\n");//print the word
            for(j=0;j<length;j++)
                printfun(word[j]);
                printnewline();
            }
            display(curr->child[i]);
        }
    }
    length--;
    return;
}

int search(struct trienode * root,char *key){
    int i,index;
    struct trienode *curr;
    curr=root;

    for(i=0;key[i]!='\0';i++){
        index=key[i]-'a';
        if(curr->child[index]==NULL)
            return 0;
        curr=curr->child[index];
    }
    if(curr->endofword==1)
        return 1;
   return 0;
}


void delete_trie(struct trienode *root,char *key){
    int i,j,index;
    struct trienode* curr;
    curr=root;

    for(i=0;key[i]!='\0';i++){
        index=key[i]-'a';
        if(curr->child[index]==NULL){
            printf("Key not found\n");
            return;
        }
        curr=curr->child[index];
    }
    curr->endofword=0;
        return;
}

  int check(struct trienode *x)
  {
    //TODO
 }

  void push(struct trienode *x,int k)
  {
    //TODO
  }

  struct stack pop()
  {
    //TODO
  } */





























































