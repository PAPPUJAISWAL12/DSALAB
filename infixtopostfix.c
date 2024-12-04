#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

int precedence(char c){
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
    int opTop=-1,posTop=-1,length,i;
char infix[100],opStack[100],postStack[100];
    printf("Enter an infix Expresion:");
    fgets(infix, sizeof(infix), stdin);
    //remove newline 
    infix[strcspn(infix,"\n")]='\0';
    length=strlen(infix);
    for(i=0;i<length;i++){
        if(infix[i] =='('){
            opStack[++opTop]=infix[i];
        }else if(isalnum(infix[i])){
            postStack[++posTop]=infix[i];
        }else if(infix[i]==')'){
            while(opTop !=-1 && opStack[opTop]!='('){
                postStack[++posTop]=opStack[opTop];
                opTop--;
            }
            opTop--;
        }else{
            while(precedence(opStack[opTop])>=precedence(infix[i])){
                postStack[++posTop]=opStack[opTop--];//push and pop
            }
            opStack[++opTop]=infix[i];
        }
    }
    while(opTop!=-1){
        postStack[++posTop]=opStack[opTop--];//push and pop
    }

    for(i=0;i<length;i++){
        printf("%c",postStack[i]);
    }
    printf("\n");

}