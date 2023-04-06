#include <stdio.h>
#include <stdlib.h>
#define max 20

void check(int *p, int heap[], int ele, int ind)
{
    int ind_p;
    int parent;
    if (ind == 1)
        return;
    else
    {
        if (ind % 2 == 0)
        {
            ind_p = ind / 2;
            parent = heap[ind_p];
        }
        else
        {
            ind_p = (ind - 1) / 2;
            parent = heap[ind_p];
        }
    }
    if (parent < ele)
    {
        int temp = heap[ind_p];
        heap[ind_p] = heap[ind];
        heap[ind] = temp;
        check(p, heap, ele, ind_p);
    }
}

void heapInsertion(int *p, int heap[], int ele)
{
    heap[(*p)] = ele;
    (*p)++;
    int ind = (*p) - 1;
    check(p, heap, ele, ind);
}

void main()
{
    int count = 1;
    int i = 0;
    int *p = &count;
    int heap[max];
    heap[0] = -1;
    int ele;
    while (1)
    {
        printf("\nEnter element to be inserted: ");
        scanf("%d", &ele);
        if (ele == -1)
            break;
        else
            heapInsertion(p, heap, ele);
    }
    printf("\nThe heap is\n");
    for (i = 1; i < count; i++)
    {
        printf("%d ", heap[i]);
    }
}