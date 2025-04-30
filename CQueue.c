#include <stdio.h>
#include <stdlib.h>
#define Max 5
struct CQueue{
    int front,rear;
    int item[Max];
};
typedef struct CQueue cq;
void Enqueue(cq * q){
    int val;
    printf("Enter data to be insert:");
    scanf("%d",&val);
    if(q->front==(q->rear+1)%Max){
        printf("queue is full");
    }else{
        //front=-1 and rear=-1
        if(q->rear==q->front){
            q->front=0;
        }
        q->rear=(q->rear+1)%Max;
        q->item[q->rear]=val;
    }
};
void Dequeue(cq * q){
    if(q->rear==q->front){
        q->rear=-1;
        q->front=-1;
    }else{
        int val=q->item[q->front];
        q->front=(q->front+1)%Max;
        printf("Dequeue element is:%d",val);
    }
};
void Display(cq *q){
    if(q->rear==q->front){

        printf("Queue is empty");
    }else{
        printf("CQueue Elements are:");
        for(int i=q->front;i!=q->rear;){
            printf("%d",q->item[i]);
            i=(i+1)%Max;
        }
        printf("%d\n", q->item[q->rear]);
    }
}
int main(){
    cq *q;
    int ch;
    q->rear=-1;
    q->front=-1;
    printf("Menu for program:\n");
    printf("1.Enqueue\n2.Dequeue\n3.Display\n4.Exit");
   
    while(1){
         printf("Enter your choice:");
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
            case 4:
                exit(1);
                break;
            default:
                printf("Invalid your choice!!");
        }
    }
    return 0;
}