#include "heap.h"
#include <math.h>
heap* heap_construct(int n){
    heap* ptr_Heap = (heap*)malloc(sizeof(heap));
    ptr_Heap->capacity = n;
    ptr_Heap->size = -1;
    ptr_Heap->elements[ptr_Heap->capacity];
    return ptr_Heap;
}
void heap_destruct(heap* tmp){
    free(tmp);
}
int heap_get_capacity(heap* tmp){
    return tmp->capacity;
}
int heap_get_size(heap* tmp){
    return tmp->size;
}
int heap_insert(heap* tmp,int data){
    int s = heap_get_size(tmp);
    int cp = heap_get_capacity(tmp);
    if (s >= cp)
        return 0;
    else{
        tmp->size++;
        tmp->elements[tmp->size] = data;
        int elt, c, p;

        if (tmp->size > 1){
            for (int i = 0; i < tmp->size; i++){
                elt = tmp->elements[i];
                c = i;
                p = (c-1)/2;
                while (c > 0 && tmp->elements[i] < elt){
                    tmp->elements[i] = tmp->elements[p];
                    c = p;
                    p = (c-1)/2;
                }
                tmp->elements[i] = elt;
            }
        }
        return 1;
    }
}

int heap_get_min(heap* tmp){
    int min(int num1, int num2){
        if (num1 > num2)
            return num2;
        else
            return num1;
    }
    int minimum = tmp->elements[0];
    for (int i = 1; i < tmp->size; ++i)
        minimum = min(minimum, tmp->elements[i]);
    return minimum;
}

void heap_remove(heap* tmp){
    int m = heap_get_min(tmp);
    int pos;
    for (int i = 0; i < tmp->size; i++){
        if (m == tmp->elements[i]){
            pos = i;
            break;
        }
    }
    for (int i = pos; i < tmp->size; i++){
        tmp->elements[i] = tmp->elements[i+1];
    }
    tmp->size--;
}

