#include <stdio.h>
#include "hash.h"
int main()
{
    int size, choice, loop = 1;
    int element, find;
    printf("enter size: ");
    scanf("%d", &size);
    HashTable *htable = create_table(size);
    while (loop)
    {
        printf("enter choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            // Insert element
            printf("enter element: ");
            scanf("%d", &element);
            insert(htable, element);
            break;

        case 2:
            // Delete element
            printf("enter element: ");
            scanf("%d", &element);
            delete (htable, element);
            break;

        case 3:
            // Search element
            printf("enter element: ");
            scanf("%d", &element);
            find = search(htable, element);
            if (find)
                printf("YES\n");
            else
                printf("NO\n");
            break;

        case 4:
            // Print all elements in the hash table
            display_table(htable);
            break;

        default:
            // Destroy tree and exit the loop
            destroy_table(htable);
            loop = 0;
            break;
        }
    }
}

void display_table(HashTable *htable)
{
    for (int i = 0; i < htable->size; i++)
        printf("%d ", htable->table[i]);
    printf("\n");
}
