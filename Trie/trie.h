#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct stack
{
  struct trienode *m;
  int index;
};
struct trienode
{
   struct trienode* child[26]; //array of pointers to trienode type
   int endofword; //indicate if it is the end of the word
};
struct trienode *getnode();
void insert(struct trienode *, char *);
void display(struct trienode*);
void delete_trie(struct trienode*,char*);
int search(struct trienode *,char *);
int check(struct trienode *);
void push(struct trienode*,int);
void printnewline();
void printfun(char);
struct stack pop();

char word[100];
int length;
int top;
struct stack s[100];//stack
