#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node *next;
    struct Node *prev;

};
typedef struct Node NodeType;
NodeType *first=NULL;
NodeType *last=NULL;
void insert_atFirst(){
    NodeType *Newnode;
    int el;
    Newnode=(NodeType*)malloc(sizeof(NodeType));
    printf("Enter data to be insert:");
    scanf("%d",&el);
    Newnode->data=el;
    if(first==NULL){
        Newnode->next=NULL;
        Newnode->prev=NULL;
        first=last=Newnode;
    }
    else{
        Newnode->next=first;
        Newnode->prev=NULL;
        first->prev=Newnode;
        first=Newnode;
    }
}
void insert_atLast(){
    int el;
    NodeType *Newnode,*temp;
    Newnode=(NodeType*)malloc(sizeof(NodeType));
    printf("Enter data to be insert:");
    scanf("%d",&el);
    Newnode->data=el;
    Newnode->next=NULL;
    if(first==NULL){
        Newnode->prev=NULL;
        first=last=Newnode;
    }else{
        
    Newnode->prev=last;
    last->next=Newnode;
    last=Newnode;

    }

}
void Delete_atFirst(){
    NodeType *temp;
    if(first==NULL){
        printf("List is empty");
    }else{
        temp=first;
        first=first->next;
        
        free(temp);
    }
}
void delete_atLast(){
    NodeType *temp,*hold;
  if(first==NULL){
    printf("list is empty");
  }else{
    temp=first;
    while(temp->next!=last){
        temp=temp->next;
    }    
    hold=temp->next;
    temp->next=NULL;
    last=temp;
    free(hold);
  }
}

void display(){
    NodeType *temp;
    temp=first;
    if(first==NULL){
        printf("List is empty");
        return;
    }
    printf("List is :");
    while(temp!=NULL){
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("NULL");
}
int main(){
    int choice;
    printf("Menu for Doubly list:");
    while(1){
        printf("\n1.Insert at First\n2.Insert at Last\n3.Delete at first.\n4.Delete at Last.\n5.Display.\n6.Exit\n");
        scanf("%d",&choice);
        switch (choice)
        {
            case 1: insert_atFirst();break;
            case 2: insert_atLast();break;
            case 3: Delete_atFirst();break;
            case 4: delete_atLast();break;
            case 5: display();break;
            case 6: exit(0);
            default: printf("Invalid choice");break;
        }
    }
}