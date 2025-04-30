#include <stdio.h>

int stack[100],i,n,choice=0,top=-1;
void push();
// void pop();
void display();
void main(){
    printf("Ener the number of element in the stack");
    scanf("%d",&n);
    while(choice!=4){
        printf("\n1. push \n2. pop\n3. display\n4.Exit ");
        printf("\n Enter your choice\n");
        scanf("%d",&choice);
        switch(choice){
            case 1: push();
            break;
            case 2: printf("Pop");
            break;
            case 3: display();
            break;
            case 4: 
             printf("exiting ...");
             break;
            default:
             printf("Invalid Choice.");
        }
    

    }
}
void push(){
    int val;
    printf("%d",top);
    if(top==n){
        printf("\nStack Overflow");
    }else{
        printf("\n Enter the Value");
        scanf("%d",&val);
        top++;
        stack[top]=val;
    }
}
void display(){
    if(top==-1){
        printf("\n stack is empty");
    }else{
        printf("\n Stack Elements are:");
        for(i=top;i>=0;i--){
            printf("%d ",stack[i]);
        }
    }
}