#include<stdio.h>
int main()
{
     
int number =100;
short marks =95;
long distance = 25000;
printf("variable values\n");
printf("-----------\n");
printf("number =%d\n",number);
printf("marks :%hd\n",marks);
printf("distance :%ld\n",distance);
printf("memory addresses\n");
printf("number :%p\n",(void*)&number);
printf("marks :%p\n",(void*)&marks);
printf("distance :%p\n",(void*)&distance);

    printf("short : %zu bytes \n ", sizeof(short));
    printf("int : %zu bytes \n ", sizeof(int));
    printf("long : %zu bytes \n ", sizeof(long));
    printf("long long : %zu bytes \n ", sizeof(long long));
     
    return 0;
    
}