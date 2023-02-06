//Best case Time Complexity = O(n) --> Array is already sorted 
//Worst case TIme Complexity = O(n^2) --> Array is sorted in reverse 
//Total = O(n^2)

#include <stdio.h>
#include <stdlib.h>

void insertion_sort(int array[],int n){
    int i;
    int j;
    int current;
    for( i = 1; i < n; i++){
        current = array[i];
        for( j = i -1; j>= 0 && array[j] > current; j--){
            array[j + 1] = array[j];
        }       
        array[j + 1] = current;
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
insertion_sort(array,n);
for(i = 0;i < n; i++){
   printf("  %d",array[i]);
    }
}