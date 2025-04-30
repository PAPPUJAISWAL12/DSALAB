#include <stdio.h>
#include <stdlib.h>
#define Max 100
struct Queue{
    int rear,front;
    int item[Max];
};
typedef struct Queue qu;
void Enqueue(qu *q){
    int val;
    printf("\nEnter Data to be insert:");
    scanf("%d",&val);
    if(q->rear==Max-1){
        printf("Queue is full");
    }else{
        q->rear++;
        q->item[q->rear]=val;
    }
};
void Dequeue(qu *q){
    if(q->rear < q->front){
        printf("queue is empty");
    }else{
        int val=q->item[q->front];
        q->front++;
        printf("Dequeue value is %d",val);
    }
};
void Display(qu *q){
    if(q->rear < q->front){
        printf("queue is empty");
    }else{
        for(int i=q->front;i<=q->rear;i++){
            printf("%d",q->item[i]);
        }
    }
};
int main(){
    qu * q;
    int ch;
    q->rear=-1;
    q->front=0;
    printf("\nMenu for queue operation:");
    while(1){
        printf("\n1:Enqueue\n2:Dequeue\n3:Display\n4:Exit\n");
        printf("\nEnter your choice:");
        scanf("%d",&ch);
        switch(ch){
            case 1:
             Enqueue(q);
             break;
            case 2:
                Dequeue(q);
                break;
            case 3:
             Display(q);
             break;
             case 4:exit(1); break;
             default:
             printf("Invalid your choice");
        }
    }
}