#include <stdlib.h>
#include <stdio.h>

int column_search(int vertices, int matrix[vertices][vertices], int j)
{
    int i;
    for (i = 0; i < vertices; i++)
    {
        if (matrix[i][j] == 1)
        {
            return 1;
        }
    }
    return 0;
}

void delete_outgoing(int vertices, int matrix[vertices][vertices], int i)
{
    int j;
    for (j = 0; j < vertices; j++)
    {
        matrix[i][j] = 0;
    }
}

void back_track_search(int vertices, int matrix[vertices][vertices], char unvis[vertices], char top_order[vertices], int *p)
{
    int t;
    for (t = 0; t < vertices; t++)
    {
        if (unvis[t] != 'z')
        {

            int back = unvis[t] - 65;
            if (column_search(vertices, matrix, back) == 0)
            {
                top_order[(*p)++] = unvis[t];
                delete_outgoing(vertices, matrix, back);
                unvis[t] = 'z';
            }
        }
    }
}

void main()
{
    int vertices;
    int i;
    int j;
    int t;
    int ans;
    char temp;
    int *p;
    int ind = 0;
    p = &ind;
    printf("\nHow many vertices does the graph have:\n");
    scanf("%d", &vertices);
    char top_order[vertices];
    int matrix[vertices][vertices];
    char unvis[vertices];
    int ch = 65;
    for (i = 0; i < vertices; i++)
    {
        for (j = 0; j < vertices; j++)
        {
            printf("Does %c have a connection with %c [1/0]:", i + 65, j + 65);
            scanf("%d", &ans);
            if (ans == 1)
                matrix[i][j] = 1;
            else
                matrix[i][j] = 0;
        }
    }
    for (i = 0; i < vertices; i++)
    {
        for (j = 0; j < vertices; j++)
        {
            printf("  %d", matrix[i][j]);
        }
        printf("\n");
    }
    int k = 0;
    for (k = 0; k < vertices; k++)
    {
        unvis[k] = 'z';
    }
    k = 0;
    for (i = 0; i < vertices; i++)
    {
        char x = 65 + i;
        if (column_search(vertices, matrix, i) == 0)
        {
            top_order[ind++] = x;
            delete_outgoing(vertices, matrix, i);
        }
        else
        {
            unvis[k++] = x;
        }
        back_track_search(vertices, matrix, unvis, top_order, p);
    }
    back_track_search(vertices, matrix, unvis, top_order, p);
    for (i = 0; i < vertices; i++)
    {
        printf("%c  ", top_order[i]);
    }
}