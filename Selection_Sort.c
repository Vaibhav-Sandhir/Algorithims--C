//Best case Time Complexity = O(n^2) --> Array is already sorted 
//Worst case TIme Complexity = O(n^2) --> Array is sorted in reverse 
//Total = O(n^2)

#include <stdio.h>

void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}


void selection_sort(int array[], int n){
    int i;
    int j;
    int index_min;
    for(i = 0; i < n; i++){
        index_min = i;
        for(j = i; j < n; j++){
            if(array[j] < array[index_min])
                index_min = j;    
        }
        swap(&array[index_min],&array[i]);
        }
    }

    void main(){
    int n;
    int i;
    int item;
    printf("\nEnter number of elements in the array: ");
    scanf("%d",&n);
    int array[n];
    printf("\nEnter array elements: ");
    for(i = 0; i< n; i++){
        scanf("%d",&item);
        array[i] = item;
    }
    selection_sort(array,n);
    for(i = 0;i < n; i++){
        printf("  %d",array[i]);
    }
}