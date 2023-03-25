#include <stdio.h>
#include <stdlib.h>

int count(char str[50]){
    int i = 0;
    while(str[i] != '\0'){
        i++;
    }
    return i;
}

void main(){
    int i,j;
    char string[50];
    char sub_string[50];
    printf("\nEnter String: ");
    scanf("%s",string);
    int n = count(string);
    printf("\nEnter Sub String: ");
    scanf("%s",sub_string);
    int m = count(sub_string);
    for(i = 0;i <= n -m;i++){
        j = 0;
        while(j < m && string[i + j] == sub_string[j]){
            j++;
        }
        if(j == m){
            printf("Matched from %d",i);
            exit(0);
        }    
    }
    printf("No match");
}