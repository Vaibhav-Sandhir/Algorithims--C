#include <stdio.h>

int search(int array[],int key,int n){
    int i;
    for(i = 0;i < n;i++){
        if(array[i] == key){
            return i;
        }
    }
    return -1;
}

void main(){
    int n;
    int i;
    int key;
    printf("\nEnter size of array: ");
    scanf("%d",&n);
    int array[n];
    printf("\nEnter array elements: ");
    for(i = 0;i < n;i++){
        scanf("%d",&array[i]);
    }
    printf("\nEnter element to be searched: ");
    scanf("%d",&key);
    if(search(array,key,n) == -1)
        printf("\nElement Found");
    else
        printf("\nElement found at %d position",search(array,key,n) + 1);    
}