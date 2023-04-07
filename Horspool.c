#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int characters(int start,char string[]){
    int i = start;
    int count = 0;
    while(string[i] != '\0'){
        count++;
        i++;
    }
    return count;
}

int present(char c){
    int x = c;
    if(c < 97 || c > 122)
        return 0;
    else
        return 1;    
}

void constructShiftTable(int shift_table[2][26],int m,char pattern[]){
    int i,j;
    int dist,ind;
    for(i = 0;i < 26;i++){
        shift_table[0][i] = i;
        shift_table[1][i] = m;
    }
    for(i = 0;i < m - 1;i++){
        ind = pattern[i] - 97;
        dist = characters(i,pattern) - 1;;
        if(dist < shift_table[1][ind])
            shift_table[1][ind] = dist;
    }
}

int check(int n,int m,char text[],char pattern[],int shift_table[2][26]){
    int i = m - 1;
    int j;
    while(i <= n -1){
        j = 0;
        while(text[i - j] == pattern[m - 1 - j] && j <= m -1){
            j = j + 1;
        }
        if(j == m){
            return i - m + 1;
        }
        else{       
            if(text[i] == ' ' || !present(text[i]))
                i = i + m;
            else{
                int k = text[i];
                k = k - 97;
                i = i + shift_table[1][k];
            }
        }         
   }
   return -1;
}

void main(){
    char text[50];
    char pattern[50];
    int shift_table[2][26];
    int n = 0;
    int m = 0;
    int i = 0;
    int j = 0;
    printf("\nEnter the text: ");
    scanf("%[^\n]s", text);
    getchar();
    printf("\nEnter the pattern: ");
    scanf("%[^\n]s", pattern);
    n = characters(0,text);
    m = characters(0,pattern);
    for(i = 0;i < 26;i++){
        shift_table[0][i] = 0;
        shift_table[1][i] = 0;
    } 
    constructShiftTable(shift_table,m,pattern);
    printf("\nThe shift table is:\n");
    for(i = 0;i < 2;i++){
        for(j = 0;j < 26;j++){
            if(!i)
                printf("%c ",shift_table[i][j] + 97);
            else
                printf("%d ",shift_table[i][j]);        
        }
        printf("\n");
    }
    int ind = check(n,m,text,pattern,shift_table);
    if(ind == -1)
        printf("\nPattern is not present in the text");
    else
        printf("\nPattern found in the text starting from index %d",ind);    
 }
