#include <stdio.h>

int min(int m,int n){
    if (m > n)
        return n;
    else
        return m;    
}

int consecutive_check(int m,int n){
    int t = min(m,n);
    while(t != 0){
    if(m % t == 0){
        if(n % t == 0)
            return t;
        else
            t--;
    }
    else
        t--;    
    }
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
    int gcd = consecutive_check(m,n);
    printf("\nGCD is : %d",gcd);
}