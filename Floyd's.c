#include <stdio.h>
#include <stdlib.h>

int min(int a,int b){
    if(a >= b)
        return b;
    else
        return a;     
}

void display(int n,int dist[n][n]){
    int i,j;
    for(i = 0;i < n;i++){
        for(j = 0;j < n;j++){
            printf("%d  ",dist[i][j]);
        }
        printf("\n");
    }
}

void floyd(int n,int dist[n][n]){
    int k,i,j;
    for(k = 0;k < n;k++){
        for(i = 0;i < n;i++){
            for(j = 0;j < n;j++){
                dist[i][j] = min(dist[i][j],dist[i][k] + dist[k][j]);
            }
        }
    }
}

void main(){
    int n;
    int i,j,ans;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    int dist[n][n];
    int visited[n];
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("Distance between %d and %d (1000 for unknown):", i, j);
            scanf("%d", &ans);
            dist[i][j] = ans;
        }
    }
    display(n,dist);
    floyd(n,dist);
    printf("\n");
    display(n,dist);
}