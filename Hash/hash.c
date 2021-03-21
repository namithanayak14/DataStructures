#include "hash.h"
HashTable *create_table(int size)
{
    HashTable* hash = (HashTable*)malloc(sizeof(HashTable));
    hash->size = size;
    hash->table[size];
    for (int i = 0; i < size; i++)
        hash->table[i] = -1;
    return hash;
}

void insert(HashTable *htable, int element)
{
    int key = element % htable->size;
    if (htable->table[key] == -1)
        htable->table[key] = element;
    else
        printf("Collision, element already exists\n");
}

int search(HashTable *htable, int element)
{
    int key = element % htable->size;
    if (htable->table[key] == element)
        return 1;
    else
        return 0;
}

void delete (HashTable *htable, int element)
{
    int key = element % htable->size;
    if (htable->table[key] == element)
        htable->table[key] = -1;
}


void destroy_table(HashTable *htable)
{
    free(htable);
}
