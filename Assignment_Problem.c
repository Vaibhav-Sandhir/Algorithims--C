#include <stdio.h>
#include <stdlib.h>

int row_min(int n,int matrix[n][n],int i){
    int j;
    int min = matrix[i][0];
    for(j = 0;j < n;j++){
        if(min > matrix[i][j])
            min = matrix[i][j];
    }
    return min;
}

int column_min(int n,int matrix[n][n],int j){
    int i;
    int min = matrix[0][j];
    for(i = 0;i < n;i++){
        if(min > matrix[i][j])
            min = matrix[i][j];
    }
    return min;
}

int one_zero(int n,int matrix[n][n],int i){
    int count = 0;
    int j;
    for(j = 0;j < n;j++){
        if(matrix[i][j] == 0)
            count++;
    }
    if(count == 1)
        return 1;
    else
        return 0;    
}

int visited(int n,int matrix[n][n],int i){
    int j;
    for(j = 0;j < n;j++){
        if(matrix[i][j] == -1)
            return 1;
    }
    return 0;
}

void set(int n,int matrix[n][n],int j){
    int i;
    for(i = 0;i < n;i++){
        if(matrix[i][j] == 0)
            matrix[i][j] = -9;
    }
}

void main(){
    int n;
    int i,j,k;
    int min;
    int ind = 0;
    printf("\nEnter number of persons: ");
    scanf("%d",&n);
    int answer[n];
    int matrix[n][n];
    int reduced_matrix[n][n];
    for(i = 0; i < n;i++){
        for(j = 0; j < n;j++){
            printf("\nEnter cost of P%d doing J%d: ",i + 1,j + 1);
            scanf("%d",&matrix[i][j]);
            reduced_matrix[i][j] = matrix[i][j];
        }
    }
    for(i = 0;i < n;i++){
        min = row_min(n,reduced_matrix,i);
        for(k = 0;k < n;k++){
            reduced_matrix[i][k] = reduced_matrix[i][k] - min;
        }
    }
    for(j = 0;j < n;j++){
        min = column_min(n,reduced_matrix,j);
        for(k = 0;k < n;k++){
            reduced_matrix[k][j] = reduced_matrix[k][j] - min;
        }
    }
    for(i = 0;i <= n;i = (i + 1)% n){
        if(one_zero(n,reduced_matrix,i) && !(visited(n,reduced_matrix,i))){
            for(j = 0;j < n;j++){
                if(reduced_matrix[i][j] == 0){
                    answer[ind++] = i;
                    answer[ind++] = j;
                    reduced_matrix[i][j] = -1;
                    set(n,reduced_matrix,j);
                    break;
                }
            } 
        }
        if(ind == (2*n))
            break;   
    }
    int cost = 0;
    for(i = 0;i < 2*n;i = i + 2){
        printf("P%d -> J%d  ",answer[i] + 1,answer[i + 1] + 1);
        cost += matrix[answer[i]][answer[i+1]];
    }
    printf("\nThe cost is: %d",cost);
}