#include<stdio.h>
#define SIZE 5
int main(){
    int stack[SIZE];
    int top = 4;
    printf("Top:%d\n",top);

    if (top == SIZE -1){
        printf("\nStack is Full");
    }
    else{
        printf("\nStack is not Full");
    }

    return 0;

}