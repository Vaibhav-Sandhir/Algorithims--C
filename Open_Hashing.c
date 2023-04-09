#include <stdio.h>
#include <stdlib.h>

typedef struct Node* Nodeptr;

typedef struct Node{
    int data;
    Nodeptr chain;
} Node;

void insert(int n,int item,Node arr[]){
    int i = item % n;
    if(arr[i].data != 0){
        Nodeptr temp = (Node*)malloc(sizeof(Node));
        temp->data = item;
        Nodeptr p = &arr[i];
        if(arr[i].chain == NULL){
            arr[i].chain = temp;
            temp->chain = NULL;
            return;
        }
        while(p->chain != NULL){
            p = p->chain;
        }
        p->chain = temp;
        temp->chain = NULL;
    }
    else{
        arr[i].data = item;
    }
}

void display(int n,Node arr[]){
    int i;
    for(i = 0;i < n;i++){
        printf("%d",arr[i].data);
        if(arr[i].chain == NULL)
            printf("\n");
        else{
            Nodeptr p = arr[i].chain;
            while(p != NULL){
                printf(" -> %d",p->data);
                p = p->chain;
            }
            printf("\n");
        }    
    }
}

void find(int item,int n,Node arr[]){
    int i = item % n;
    if(arr[i].data == item){
        printf("\nElement found");
        return;
    }
    Nodeptr p = arr[i].chain;
    while(p != NULL){
        if(p->data == item){
            printf("\nElement found");
            return;
        }
        else{
            p = p->chain;
        }
    }
    printf("\nElement not found");
    return;
}

void main(){
    int num;
    int n,i;
    int item;
    printf("\nEnter mod function: ");
    scanf("%d",&n);
    Node arr[n];
    for(i = 0;i < n;i++){
        arr[i].data = 0;
        arr[i].chain = NULL;
    }
    while(1){
        printf("\nEnter element: ");
        scanf("%d",&item);
        if(item == -1)
            break;
        insert(n,item,arr);
    }
    display(n,arr);
    printf("\nEnter element to be found: ");
    scanf("%d",&item);
    find(item,n,arr);
}
