#include<stdio.h>
#define SIZE 5
int main(){
    int stack[SIZE];
    int top = -1;
    printf("Top:%d\n",top);

    if (top == -1){
        printf("\nStack is Empty");
    }
    else{
        printf("\nStack is not Empty");
    }

    return 0;

}