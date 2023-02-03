//Best case Time Complexity = O(n) --> Array is already sorted 
//Worst case TIme Complexity = O(n^2) --> Array is sorted in reverse 
//Total = O(n^2)

#include <stdio.h>

void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

void bubble_sort(int array[], int n){
    int i;
    int j;
    for(i = 0; i < n - 1; i++ ){
        for(j = 0; j < n - 1 - i; j++){
            if(array[j] > array[j + 1]){
                swap(&array[j],&array[j+1]);
            }
        }
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
    bubble_sort(array,n);
    for(i = 0;i < n; i++){
        printf("  %d",array[i]);
    }
}