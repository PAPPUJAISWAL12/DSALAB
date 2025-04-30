#include <stdio.h>
void LinearTimeComplexity(int arr[], int length){
    for(int i=0;i<length;i++){
        printf("Value of lenear time: %d",arr[i]);
    }
printf("\n");
}
int main(){
    int arr[]={1,3,45,6};
    int length=4;
    LinearTimeComplexity(arr,length);
}
