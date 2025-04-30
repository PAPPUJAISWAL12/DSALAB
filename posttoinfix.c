#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#define Max 100
char *stack[Max];
int top=-1;
void push(char *val){
 if(top==Max-1){
    printf("Stack Overflow\n");    
 }
 top++;
 stack[top]=val; 
}
char *pop(){
if(top==-1){
    printf("Stack is Empty\n");
   
    }
    return stack[top--];
}
void convert(char postfix[Max]){
int len,i;
char *op1,*op2;
len=strlen(postfix);
for(i=0;i<len;i++){
    if(isalnum(postfix[i])){
        char *opsize=(char *)malloc(sizeof(char));
        opsize[0]=postfix[i];
        opsize[1]='\0';
        push(opsize);
    }else if(postfix[i]=='+'
    || postfix[i]=='-'
    ||postfix[i]=='*'
    || postfix[i]=='/'
    || postfix[i]=='$'
    ||postfix[i]=='^'){
        op1=pop();
        op2=pop();
        char *infix=(char *)malloc(strlen(op1)+strlen(op2));
        sprintf(infix,"(%s%c%s)",op2,postfix[i],op1);
        push(infix);
        free(op1);
        free(op2);
    }
}
char *result=pop();
    printf("infix Expression is: %s",result);
    free(result);
}
int main(){
    char postfix[Max];
    printf("Enter postfixExpression: ");
    scanf("%s",postfix);
    convert(postfix);
    return 0;
}
