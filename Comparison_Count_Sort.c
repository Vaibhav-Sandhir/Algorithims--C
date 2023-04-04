#include <stdio.h>
#include <stdlib.h>

void comparison_count(int n,int arr[n],int count[n]){
    int i,j;
    for(i = 0;i < n - 1;i++){
        for(j = i + 1;j < n ;j++){
            if(arr[i] > arr[j])
                count[i]++;
            else
                count[j]++;    
        }
    }
}

void sort(int n,int arr[n],int count[n],int sorted[n]){
    int i;
    for(i = 0;i < n;i++){
        sorted[count[i]] = arr[i];
    }
}

void main(){
    int n;
    int i;
    printf("\nEnter number of elements in the array: ");
    scanf("%d",&n);
    int arr[n];
    int count[n];
    int sorted[n];
    printf("\nEnter the elements of the array: ");
    for(i = 0; i < n;i++){
        scanf("%d",&arr[i]);
        count[i] = 0;
        sorted[i] = 0;
    }
    comparison_count(n,arr,count);
    sort(n,arr,count,sorted);
    for(i = 0; i < n;i++){
        printf("%d ",sorted[i]);
    }
}