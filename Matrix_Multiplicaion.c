#include <stdio.h>
#include <stdlib.h>

void display(int n, int m,int matrix[n][m]){
    int i = 0;
    int j = 0;
    for (i=0;i<n;i++){
        for(j=0;j<m;j++){
            printf("   %d",matrix[i][j]);
        }
        printf("\n");
    }
}

void input(int n,int m,int m1[n][m]){
    int i,j;
    for(i = 0;i < n;i++){
        for(j = 0;j < m;j++){
            scanf("%d",&m1[i][j]);
        }
    }
}

void main(){
    int n,m,i,j,k;
    printf("\nEnter number of rows: ");
    scanf("%d",&n);
    printf("\nEnter number of columns: ");
    scanf("%d",&m);
    int p,q;
    printf("\nEnter number of rows: ");
    scanf("%d",&p);
    printf("\nEnter number of columns: ");
    scanf("%d",&q);
    int m1[n][m];
    int m2[p][q];
    int res[n][m];
    printf("\nEnter the first matrix: ");
    input(n,m,m1);
    printf("\nEnter the second matrix: ");
    input(p,q,m2);
    if(m != p)
        exit(0);
    for(i = 0;i < n;i++){
        for(j = 0;j < q;j++){
            res[i][j] = 0;
            for(k = 0;k < m;k++){
                res[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }
    display(n,m,res);
}