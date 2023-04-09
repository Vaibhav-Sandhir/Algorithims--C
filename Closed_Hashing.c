#include <stdio.h>
#include <stdlib.h>

void insert(int item,int n,int arr[]){
    int i = item % n;
    if(arr[i] == -1){
        arr[i] = item;
        return;
    }
    else{
        int x = i;
        i = (i + 1) % n;
        while(1){
            if(i == x){
                printf("\nArray is Full");
                return;
            }
            if(arr[i] == -1){
                arr[i] = item;
                return;
            }
            else{
                i = (i + 1) % n;
            }
        }
    }
}

void find(int item,int n,int arr[]){
    int i = item % n;
    if(arr[i] == item){
        printf("\nElement Found");
        return;
    }
    else{
        int x = i;
        i = (i + 1) % n;
        while(1){
            if(i == x){
                printf("\nElement Not Found");
                return;
            }
            if(arr[i] == item){
                printf("\nElement Found");
                return;
            }
            i = (i + 1) % n;
        }
    }
}

void main(){
    int n;
    int item;
    int i;
    printf("\nEnter mod function: ");
    scanf("%d",&n);
    int arr[n];
    for(i = 0;i < n;i++){
        arr[i] = -1;
    }
    while(1){
        printf("\nEnter element: ");
        scanf("%d",&item);
        if(item == -1)
            break;
        insert(item,n,arr);
    }
    printf("\nThe Hash table is: ");
    for(i = 0;i < n;i++){
        printf("%d ",arr[i]);
    }
    printf("\nEnter element to be found: ");
    scanf("%d",&item);
    find(item,n,arr);
}