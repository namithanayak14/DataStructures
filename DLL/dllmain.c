#include <stdio.h>
#include <stdlib.h>
#include "dll.h"
int main()
{
    List* dll = initialize_list();
    int ele,choice,pos,x;
    do
    {
        printf("enter option: ");
        scanf("%d",&choice);

        switch(choice)
        {
            // Insert at beginning
            case 1:
                printf("enter element: ");
                scanf("%d",&ele);
                insert_front(dll,ele);
                break;

	   // Delete element at the beginning of the list
            case 2:
                dllist_delete_beginning(dll);
                break;

	   // Count number of nodes
            case 3:
                x = count_nodes(dll);
                printf("%d\n",x);
            	break;

            // Delete at position
            case 4:
                printf("enter position: ");
                scanf("%d",&pos);
                position_delete(dll, pos);
                break;

            // Search for element
            case 5:
                printf("enter element to be searched: ");
                scanf("%d",&ele);
                pos = search_list(dll,ele);
                printf("%d\n",pos);
                break;

	    // reverse for element
            case 6:
                reverse_list(dll);
                break;

            // Print entire list
            case 7:
                display(dll);
                break;
        }
    }
    while (choice != 0);

    destroy_list(dll);
    return 0;
}

List* initialize_list()
{
    List* dll = (List*)malloc(sizeof(List));
    dll->head = NULL;
    dll->tail = NULL;
    dll->number_of_nodes = 0;

    return dll;
}

Node* create_node(int data)
{
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    node->prev = NULL;

    return node;
}

void display(List* dll)
{
    if(dll->number_of_nodes == 0)
        printf("EMPTY");
    else
    {
        Node* temp = dll->head;

        while(temp != NULL)
        {
            printf("%d ",temp->data);
            temp = temp->next;
        }
    }

    printf("\n");
}

void destroy_list(List* dll)
{
    Node *p = dll->head;
	Node *q = NULL;

    while (p != NULL)
    {
		q = p;
		p = p->next;
		free(q);
	}

    free(dll);
}

