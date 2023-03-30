#include <stdio.h>

int DFS(int v, int parent,int n,int visited[n],int adj[n][n]) {
    visited[v] = 1;

    for (int i = 0; i < n; i++) {
        if (adj[v][i] == 1) {
            if (!visited[i]) {
                if (DFS(i,v,n,visited,adj))
                    return 1;
            } 
            else if (i != parent)
                return 1;
        }
    }
    return 0;
}

int isCyclic(int n,int visited[n],int adj[n][n]) {
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (DFS(i, -1,n,visited,adj))
                return 1;
        }
    }
    return 0;
}

int main() {
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
    if (isCyclic(n,visited,adj))
        printf("The graph is cyclic.\n");
    else
        printf("The graph is acyclic.\n");

    return 0;
}