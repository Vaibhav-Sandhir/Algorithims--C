#include <stdio.h>
#include <stdlib.h>

int minDistance(int n,int dist[n],int visited[n]){
    int i = 0;
    int min;
    for(i = 0; i < n;i++){
        if(visited[i] != 1){
            min = i;
        }
    }
    for(i = 0;i < n;i++){
        if(dist[min] > dist[i] && visited[i] != 1)
            min = i;
    }
    return min;
}

void display(int n,int adj[n][n]){
    int i,j;
    for(i = 0;i < n;i++){
        for(j = 0;j < n;j++){
            printf("%d  ",adj[i][j]);
        }
        printf("\n");
    }
}

void dijkstra(int n,int s,int adj[n][n],int visited[n],int dist[n],int previous[n]){
    int i = 0;
    int j = 0;
    int min;
    while(i < n){
        min = minDistance(n,dist,visited);
        printf("\n%d\n",min);
        for(j = 0;j < n;j++){
            if(adj[min][j] != 0 && adj[min][j] < 99){
                if(adj[min][j] + dist[min] < dist[j]){
                    dist[j] = adj[min][j] + dist[min];
                    previous[j] = i;
                }
            }
        }
        visited[min] = 1;
        i++;
    }
}  

void main(){
    int i,j,n;
    char source;
    int s;
    printf("\nEnter number of vertices in the graph: ");
    scanf("%d",&n);
    int adj[n][n];
    int visited[n];
    int dist[n];
    int dist_aft[n];
    int previous[n];
    for(i =0; i < n;i++){
        for(j = 0;j < n;j++){
            printf("Dist between %c and %c (99 if not existing): ",i + 65,j + 65);
            scanf("%d",&adj[i][j]);
        }
    }
    display(n,adj);
    printf("\nEnter source vertex: ");
    getchar();
    scanf("%c",&source);
    s = source - 65;
    for(i = 0; i < n;i++){
        if(i == s)
            dist[i] = 0;
        else
            dist[i] = 99;    
    }
    for(i = 0; i < n;i++){
        previous[i] = 0;
        visited[i] = 0;
    }
    dijkstra(n,s,adj,visited,dist,previous);  
    for(i = 0; i < n;i++){
        printf("  %c", i + 65);
    }
    printf("\n");
    for(i = 0;i < n;i++){
        printf("  %d",dist[i]);
    }
    printf("\n");
}