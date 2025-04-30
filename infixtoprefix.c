#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

int precedency(char c){
    switch(c){
        case '^':
          return 3;
        case '*':
        case '/':
          return 2;
        case '+':
        case '-':
         return 1;
        default:
        return 0;
    }
}
void main(){
    char infix[100], preStack[100],opStack[100];
    int opTop=-1,preTop=-1,i;
    printf("Enter an infix expression:");
    fgets(infix, sizeof(infix),stdin);
    //remove newline
    infix[strcspn(infix, "\n")] = '\0';
    int length = strlen(infix);
    for(i=length;i>=0;i--){
        if(infix[i]==')'){
            opStack[++opTop]=infix[i];//push
        }
        else if(isalnum(infix[i]))
        {
            preStack[++preTop]=infix[i];
        }
        else if(infix[i]=='(')
        {
            while(opTop!=-1 && opStack[opTop]!=')'){
                preStack[++preTop]=opStack[opTop];
                opTop--;
            }
            opTop--;
        }else{
            while(precedency(opStack[opTop]>precedency(infix[i]))){
                preStack[++preTop]=opStack[opTop--];//push and pop
            }
            opStack[++opTop]=infix[i];//push
        }
    }
    while(opTop!=-1){
        preStack[++preTop]=opStack[opTop--];
    }
    printf("\nThe postfix expression is: ");
    for(i=length;i>=0;i--){
        printf("%c",preStack[i]);
    }
}