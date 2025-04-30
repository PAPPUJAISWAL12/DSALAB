#include <stdio.h>
 int GCD(int x,int y);
int main(){
    int x,y;
    printf("Enter value of X:");
    scanf("%d",&x);
    printf("Enter value of y:");
    scanf("%d",&y);
    printf("GCD of %d and %d is: %d\n",x,y,GCD(x,y));

}
 int GCD(int x,int y){
    if(y==0){
        return x;
    }else{
        return GCD(y,x%y);
    }
}