#include <stdio.h>
#include <stdlib.h>
#define Max 100
struct  PQueue
{
    int front,rear;
    int item[Max];
};
typedef struct PQueue pq;
void Enqueue(pq * q){
    int val;
    if(q->rear==Max-1){
        printf("Queue is full");
    }else{
        printf("Enter data to be inserted:");
        scanf("%d",&val);
        q->rear++;
        q->item[q->rear]=val;
    }
}
void FindMinValue(pq * q){
   
}
void Dequeue(pq *q){

    if(q->rear<q->front){
        printf("Queue is empty");
    }else{
         int minIndex=q->front;
        for(int i=q->front+1;i<=q->rear;i++){
            if(q->item[i]< q->item[minIndex]){
                minIndex=i;
            }
        }
        for(int i=minIndex;i<=q->rear-1;i++){
            q->item[i]=q->item[i+1];
        }
        q->rear--;

    }
}
void Display(pq *q){
    if(q->rear<q->front){
        printf("Queue is empty");
    }else{
        printf("Queue elements are:");
        for(int i=q->front;i<=q->rear;i++){
            printf("%d",q->item[i]);
        }
    }
}
int main(){
    pq *q;
    q->rear=-1;
    q->front=0;
    int ch;
    
    printf("\n1.Enquue\n2.Dequeue\n3.Display\n4.Exit");
    while(1){
       printf("Enter your choice");
       scanf("%d",&ch);
       switch (ch)
       {
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
        printf("Invalid choice.");
        break;
       }
    }
    return 0;
}

