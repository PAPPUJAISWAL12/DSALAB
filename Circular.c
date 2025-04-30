#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node *next;
};
typedef struct Node NodeType;
NodeType *first=NULL;
NodeType *last=NULL;
void Insert_atFirst(){
    int el;
    NodeType *Newnode;
    Newnode=(NodeType*)malloc(sizeof(NodeType));
    printf("Enter data to be insert");
    scanf("%d",&el);
    Newnode->data=el;
    if(first==NULL){
        Newnode->next=Newnode;
        first=last=Newnode;
    }else{
        Newnode->next=first;
        first=Newnode;
        last->next=first;
    }
}
void Insert_atLast(){
   int el;
   printf("Enter data to be insert");
   scanf("%d",&el);
    NodeType *Newnode;
    Newnode=(NodeType*)malloc(sizeof(NodeType));
    Newnode->data=el;
    if(first==NULL){
        Newnode->next=Newnode;
        first=last=Newnode;
    }else{
        last->next=Newnode;
        last=Newnode;
        last->next=first;
    }
}
void Delete_atFirst(){
    NodeType *temp;
    if(first==NULL){
        printf("list is empty");
    }else{
        temp=first;
        first=first->next;
        free(temp);
    }
}
void Delete_atEnd(){
    NodeType *temp,*hold;
    if(first==NULL){
        printf("List is empty");
    }else{
        temp=first;
        while(temp->next!=last){
            temp=temp->next;
        }
        hold=temp->next;
        last=temp;
        last->next=first;
        free(hold);
    }
}

void display(){
    NodeType *temp;
    temp=first;
    if(first==NULL){
        printf("List is empty");
        return;
    }else{
    printf("List is :");   
    do{
        printf("%d->",temp->data);
        temp=temp->next;
    }while(temp!=first);
    printf("NULL");
    }
    
}
int main(){
    int choice;
    printf("Menu for list:");
    //Insert_atLast(20);
    //display();
    while(1){
        printf("\n1. Insert at first.\n2.Insert at End.\n3.Delete at first.\n4.Delete at last\n5.Display\n6.Exit");
        printf("\nChoose an item:");
        scanf("%d",&choice);
        switch(choice){
            case 1:Insert_atFirst(); break;
            case 2:Insert_atLast();break;
            case 3:Delete_atFirst();break;
            case 4:Delete_atEnd();break;
            case 5:display();
            case 6:exit(0);
            default:printf("Invalid choice");break;
        }

    }
}