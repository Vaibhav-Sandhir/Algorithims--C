#include <stdio.h>
#include <stdlib.h>
#define max 20

int big(int heap[], int lchild, int rchild)
{
    if (heap[lchild] > heap[rchild])
        return lchild;
    else
        return rchild;
}

void check(int *p, int heap[], int ind)
{
    if (ind == 0)
    {
        return;
    }
    int last_p = ((*p) - 1) / 2;
    int parent = ind;
    int lchild = 2 * ind;
    int rchild = (2 * ind) + 1;
    int bigger = big(heap, lchild, rchild);
    if (heap[parent] < heap[bigger])
    {
        int temp = heap[parent];
        heap[parent] = heap[bigger];
        heap[bigger] = temp;
        check(p, heap, bigger);
    }
    else
    {
        ind--;
        check(p, heap, ind);
    }
}

void rootDeletion(int *p,int heap[],int sorted[]){
    int ind = (*p) - 1;
    sorted[ind] = heap[1];
    heap[1] = heap[ind];
    heap[ind] = 0;
}

void heapSort(int *p,int heap[],int sorted[]){
    if((*p) == 1)
        return;    
    rootDeletion(p,heap,sorted);
    (*p)--;
    int last_p = ((*p) - 1) / 2;
    check(p, heap, last_p);
    heapSort(p,heap,sorted);
}

void main()
{
    int count = 1;
    int i;
    int ele;
    int *p = &count;
    int heap[max];
    heap[0] = -1;
    for (i = 0; i < 20; i++)
    {
        heap[i] = 0;
    }
    while (1)
    {
        printf("\nEnter element: ");
        scanf("%d", &ele);
        if (ele == -1)
            break;
        heap[(*p)] = ele;
        (*p)++;
    }
    int last_p = ((*p) - 1) / 2;
    check(p, heap, last_p);
    int sorted[count];
    printf("\nThe heap is\n");
    for (i = 1; i < count; i++)
    {
         printf("%d ", heap[i]);
         sorted[i] = 0;
    }
    int cnt = count;
    heapSort(p,heap,sorted);
    printf("\nThe sorted array is:\n");
    for(i = 1;i < cnt;i++){
        printf("%d ",sorted[i]);
    }
}