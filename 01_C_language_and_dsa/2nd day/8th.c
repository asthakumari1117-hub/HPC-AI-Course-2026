#include<stdio.h>
#include<limits.h>
int main(){
    int number =INT_MIN;
    printf("before overflow : %d\n",number);
    number--;
    printf("after overflow :%d\n",number);
    return 0;

}