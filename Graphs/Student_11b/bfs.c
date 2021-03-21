#include<stdio.h>
#include "bfs.h"

Queue* createQueue(Queue* q, int n){
    q = (Queue*)malloc(sizeof(Queue));
    q->capacity = n;
    q->f = q->size = 0;
    q->r = n - 1;
    q->arr = malloc(sizeof(int) * n);
    return q;
}

void Queue_enqueue(Queue* q, int data){
    if (q->size == q->capacity)
        return;
    q->r = (q->r+1)%(q->capacity);
    q->arr[q->r] = data;
    q->size ++;
}

int Queue_is_empty(Queue *q){
    if (q->size == 0)
        return 1;
    else
        return 0;
}

int Queue_dequeue(Queue* q){
    if (Queue_is_empty(q))
        printf("Queue is empty");
    int i = q->arr[q->f];
    q->f = (q->f + 1) % (q->capacity);
    q->size --;
    return i;
}

int check_path(int **graph, int n, int v, int u)
{
    if (v == u)
        return 1;

    int *visited = malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
        visited[i] = 0;
    Queue queue;
    visited[v] = 1;
    Queue_enqueue(&queue, v);
    while (!Queue_is_empty)
        v = Queue_dequeue(&queue);
    for (int i = graph[v][0]; i != graph[v][n]; ++i){
        if (i == u)
            return 1;
        if (!visited[i]){
            visited[i] = 1;
            Queue_enqueue(&queue, i);
        }
    }
    return 0;
}
