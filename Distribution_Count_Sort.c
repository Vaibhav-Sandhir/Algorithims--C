#include <stdio.h>
#include <stdlib.h>

int lower_range(int n,int arr[n]){
    int i;
    int min = arr[0];
    for(i = 0;i < n;i++){
        if(min > arr[i])
            min = arr[i];
    }
    return min;
}

int upper_range(int n,int arr[n]){
    int i;
    int max = arr[0];
    for(i = 0;i < n;i++){
        if(max < arr[i])
            max = arr[i];
    }
    return max;
}

void distr(int n,int n2,int l,int u,int arr[n],int distribution[n2]){
    int i,j;
    for(i = l; i <= u;i++){
        for(j = 0;j < n;j++){
            if(i == arr[j])
                distribution[i - l]++;
        }
    }
    for(i = 1;i < n2;i++){
        distribution[i] += distribution[i - 1];
    }
    return;
}

void placement(int n,int n2,int l,int u,int arr[n],int distribution[n2],int sorted[n]){
    int i,j;
    for(i = n - 1;i >= 0;i--){
        sorted[distribution[arr[i] - l] - 1] = arr[i];
        distribution[arr[i] - l]--;
    }
}

void main(){
    int n;
    int i;
    printf("\nEnter number of elements in the array: ");
    scanf("%d",&n);
    int arr[n];
    int sorted[n];
    printf("\nEnter the continous elements in the array: ");
    for(i = 0;i < n;i++){
        scanf("%d",&arr[i]);
        sorted[i] = 0;
    }
    int l = lower_range(n,arr);
    int u = upper_range(n,arr);
    int n2 = u - l + 1;
    int distribution[n2];
    for(i = 0;i < n2;i++){
        distribution[i] = 0;
    }
    distr(n,n2,l,u,arr,distribution);
    placement(n,n2,l,u,arr,distribution,sorted);
    for(i = 0;i < n;i++){
        printf("%d ",sorted[i]);
    }
}