#include <stdio.h>
#include <stdbool.h>

void DFS(int v,int n,int adj[n][n],int visited[n]) {
    visited[v] = 1;
    printf("%d ", v);

    for (int i = 0; i < n; i++) {
        if (adj[v][i] == 1 && !visited[i])
            DFS(i,n,adj,visited);
    }
}

void main() {
    int n;
    int i,j,ans;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    int adj[n][n];
    int visited[n];
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("Does %d have a connection with %d [1/0]:", i, j);
            scanf("%d", &ans);
            if (ans == 1)
                adj[i][j] = 1;
            else
                adj[i][j] = 0;
        }
    }

    printf("DFS traversal starting from vertex 0: ");
    DFS(0,n,adj,visited);
    printf("\n");
}