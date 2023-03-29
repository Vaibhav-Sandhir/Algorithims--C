#include <stdio.h>
#include <stdlib.h>

void merge(int B[],int p,int C[],int q,int A[])
{
    int i = 0;
    int j = 0;
    int k = 0;
    while(i < p && j < q)
    {
        if(B[i] <= C[j])
        {
            A[k]=B[i];
            k++;
            i++;
        }
        else
        {
            A[k]=C[j];
            k++;
            j++;
        }
    }
    while(i < p)
    {
        A[k]=B[i];
        k++;
        i++;
    }
    while(j < q)
    {
        A[k]=C[j];
        k++;
        j++;
    }
}

void mergeSort(int A[],int n)
{
    if(n>1)
    {
        int t=n/2;
        int B[t],C[n-t];
        for(int i=0;i<t;i++)
        {
            B[i]=A[i];
        }
        for(int i=t;i<n;i++)
        {
            C[i-t]=A[i];
        }
        mergeSort(B,t);
        mergeSort(C,n-t);
        merge(B,t,C,n-t,A);
    }
}

void main()
{
    int n;
    printf("Enter Array Length: ");
    scanf("%d",&n);
    int A[n];
    printf("\nEnter Array Elements: ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&A[i]);
    }
    mergeSort(A,n);
    printf("\nSorted Array is \n");
    for(int i=0;i<n;i++)
    {
        printf("%d ",A[i]);
    }
}