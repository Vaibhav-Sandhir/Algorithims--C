#include <stdio.h>
#include <stdlib.h>

int partition(int arr[],int low,int high){
    int pivot = arr[low];
    int i = low + 1;
    int j = high;
    do{
        while(arr[i] <= pivot){
            i++;
        }
        while(arr[j] > pivot){
            j--;
        }
        if( i < j){
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp; 
        }
    } while(i < j);
    int temp1 = arr[low];
    arr[low] = arr[j];
    arr[j] = temp1;
    return j;
}

void quickSort(int arr[],int low,int high){
    int pivot_index;
    if(low < high){
        pivot_index = partition(arr,low,high);
        quickSort(arr,low,pivot_index - 1);
        quickSort(arr,pivot_index + 1,high);
    }
}

void main(){
    int n;
    int i;
    printf("\nEnter number of elements in array: ");
    scanf("%d",&n);
    int arr[n];
    printf("\nEnter elements of array: ");
    for(i = 0;i < n;i++){
        scanf("%d",&arr[i]);
    }
    quickSort(arr,0,n - 1);
    for(i = 0;i < n;i++){
        printf("%d  ",arr[i]);
    }
}