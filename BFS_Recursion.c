#include <stdio.h>

void BFS(int n,int queue[n], int front, int rear,int adj[n][n],int visited[n]) {
    if (front > rear)
        return;

    int v = queue[front];
    printf("%d ", v);
    front++;

    for (int i = 0; i < n; i++) {
        if (adj[v][i] == 1 && !visited[i]) {
            visited[i] = 1;
            queue[++rear] = i;
        }
    }

    BFS(n,queue, front, rear,adj,visited);
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

    int queue[n];
    int front = 0, rear = 0;
    visited[0] = 1;

    printf("BFS traversal starting from vertex 0: ");
    BFS(n, queue, front, rear, adj,visited);
    printf("\n");
}