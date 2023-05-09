#include <stdio.h>
#include <stdlib.h>

int max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}

void traceback(int n, int W, int solution[n], int table[n + 1][W + 1], int weights[n + 1])
{
    int i = n;
    int j = W;
    int ind = n - 1;
    while (i != 0)
    {
        if (table[i][j] != table[i - 1][j])
        {
            solution[ind] = i;
            ind--;
            j = j - weights[i];
            i = i - 1;
        }
        else
        {
            i = i - 1;
        }
    }
}


int memoryFunction(int n,int W,int table[n+1][W+1],int weights[n+1],int values[n+1],int i,int j){
    int value;
    if(table[i][j] < 0){
        if(j < weights[i]){
            value = memoryFunction(n,W,table,weights,values,i -1,j);
        }
        else{
            value = max(memoryFunction(n,W,table,weights,values,i -1,j),values[i] + memoryFunction(n,W,table,weights,values,i -1,j - weights[i]));
        }
        table[i][j] = value;
    }
    return table[i][j];
}

void main(){
    int W, n, i, j;
    printf("\nEnter capacity of knapsack: ");
    scanf("%d", &W);
    printf("\nEnter number of items: ");
    scanf("%d", &n);
    int solution[n];
    int weights[n + 1];
    int values[n + 1];
    weights[0] = -1;
    values[0] = -1;
    for (i = 0; i < n; i++)
    {
        solution[i] = -1;
    }
    for (i = 1; i <= n; i++)
    {
        printf("\nEnter weight of item %d: ", i);
        scanf("%d", &weights[i]);
        printf("\nEnter value of item %d: ", i);
        scanf("%d", &values[i]);
    }
    int table[n + 1][W + 1];
    for (i = 0; i <= n; i++)
    {
        table[i][0] = 0;
    }
    for(i = 0;i <=W;i++){
        table[0][i] = 0;
    }
    for(i = 1;i <=n;i++){
        for(j = 1;j <=W;j++){
            table[i][j] = -1;
        }
    }
    memoryFunction(n,W,table,weights,values,n,W);
    for (i = 0; i <= n; i++)
    {
        for (j = 0; j <= W; j++)
        {
            printf("%d\t", table[i][j]);
        }
        printf("\n");
    }
    traceback(n, W, solution, table, weights);
    printf("\nThe items for the optimal solution are: ");
    for (i = 0; i < n; i++)
    {
        if (solution[i] != -1)
        {
            printf("%d ", solution[i]);
        }
    }
}