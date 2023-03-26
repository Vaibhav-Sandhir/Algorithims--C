#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void main(){
    int cap;
    int n;
    int i,j,k;
    int x =0;
    int num;
    int sum1 = 0;
    int sum2;
    int ind = 0;
    printf("\nEnter capacity of bag: ");
    scanf("%d",&cap);
    printf("\nEnter how many items: ");
    scanf("%d",&n);
    int max = pow(2,n);
    int tot = 4 * max;
    int values[n];
    int weights[n];
    int items[n];
    int binary[n];
    int tot_binary[tot];
    int p = 0;
    int sums_weight[max];
    int sums_value[max];
    int from[n];
    for(i = 1;i <= n;i++){
        items[i - 1] = i; 
    }
    for(i = 0;i < n;i++){
        printf("\nEnter value of %d: ",items[i]);
        scanf("%d",&values[i]);
    }
    for(i = 0;i < n;i++){
        printf("\nEnter weight of %d: ",items[i]);
        scanf("%d",&weights[i]);
    }
    for(i = 0; i <n;i++){
        binary[i] = 0;
    }
    for(i = 1;i < max;i++){
        num = i;
        for(j = 0;num > 0;j++){
            binary[j] = num % 2;
            num = num / 2;
        }
        for(k = n - 1;k >= 0;k--){
            tot_binary[p++] = binary[k];
            if(binary[k] == 1){
                sum1 += values[k];
                sum2 += weights[k];
            } 
    }
    sums_value[ind] = sum1;
    sums_weight[ind++] = sum2;
    sum1 = 0;
    sum2 = 0; 
  }
  for(i = 0; i < max - 1;i++){
    printf("\n%d%d%d%d %d %d",tot_binary[x],tot_binary[x + 1],tot_binary[x + 2],tot_binary[x + 3],sums_value[i],sums_weight[i]);
    x = x + 4;
  }
  int max_profit = sums_value[0];
  int ind_max_profit = 0;
  for(i = 0;i < max - 1;i++){
    if(max_profit < sums_value[i] && sums_weight[i] <= cap){
        max_profit = sums_value[i];
        ind_max_profit = i;
    }
  }

  printf("\nUsing the items: ");
  int fin = n * (ind_max_profit);
  for(i = 0;i < n;i++){
    printf("%d",tot_binary[fin + i]);
  }
  printf("\nMax Profit is : %d",max_profit);
}