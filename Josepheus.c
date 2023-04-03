#include <stdio.h>
#include <stdlib.h>

typedef struct Node* Nodeptr;

typedef struct Node{
    int data;
    Nodeptr next;
}Node;

Nodeptr getNode(int item){
    Nodeptr node = (Node*)malloc(sizeof(Node));
    node->data = item;
    node->next = NULL;
    return node;
}

Nodeptr create(int data,int n)
{
    Nodeptr head = getNode(1);
    Nodeptr p = head;
    int i;
    for(i = 2;i <=n;i++){
        p->next = getNode(i);
        p = p->next;
    }
    p->next = head;
    return head;
}

void delete_index(Nodeptr *head, int index)
{
    Nodeptr p = (*head)->next;
    Nodeptr q = *head;
    if(index == 0){
        (*head) = (*head)->next;
        return;
    }
    while (index != 1)
    {
        p = p->next;
        q = q->next;
        index--;
    }
    q->next = p->next;
    free(p);
}

void display(Nodeptr head)
{
    Nodeptr p = head;
    do
    {
        printf("  %d", p->data);
        p = p->next;
    }while (p != head);
    printf("\n");
}

int josephus(Nodeptr *head,int n){
    int i;
    Nodeptr p = *head;
    while(n > 1){
        Nodeptr q = p->next;
        Nodeptr qb = p;
        for(i = 1;i < 1;i++){
            qb = qb->next;
            q = q->next;
        }
        qb->next = q->next;
        free(q);
        p = p->next;
        n--;
    }
    return p->data;
}

void main(){
    int n;
    int k;
    int i;
    printf("\nEnter number of soldiers: ");
    scanf("%d",&n);
    Nodeptr head = create(1,n);
    int survivor = josephus(&head,n);
    printf("\nThe person number %d will survive",survivor);
}
