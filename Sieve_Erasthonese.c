#include <stdio.h>
#include <math.h>

void sieve(int all_array[],int n){
    int i;
    int j;
    for(i = 2;i <=sqrt(n);i++){
        if(all_array[i] != 0){
            j = i * i;
            while(j <= n){
                all_array[j] = 0;
                j = j + i;
            }
        }
    }
}

void main(){
    int n;
    int i;
    int j = 0;
    printf("\nEnter number greater than 2 till which you want prime numbers: ");
    scanf("%d",&n);
    int prime_array[n];
    int all_array[n];
    all_array[0] = 0;
    all_array[1] = 0;
    for(i = 2;i <= n;i++){
        all_array[i] = i;
    }
    sieve(all_array,n);
    for(i = 0;i<=n;i++){
        if(all_array[i] != 0)
            prime_array[j++] = all_array[i];
    }
    printf("%d\nThe prime numbers are\n");
    for(i = 0;i < j;i++){
        printf("%d  ",prime_array[i]);
    }
}