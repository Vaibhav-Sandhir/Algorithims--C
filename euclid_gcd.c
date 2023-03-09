#include <stdio.h>
#include <stdlib.h>

int euclid_gcd(int m,int n){
    int t = m % n;
    if(t == 0)
        return n;
    else
        euclid_gcd(n,t);    
}

void main(){
    int m;
    int n;
    int temp;
    printf("\nEnter two numbers: ");
    scanf("%d %d",&m,&n);
    if(m < n){
        temp = m;
        m = n;
        n = temp;
    }
    int gcd = euclid_gcd(m,n);
    printf("\nGCD is %d",gcd);
}
