#include<stdio.h>
 
  struct student{
    int rollno;
  };
  void display()
  {
    printf("function is derived data type\n");
  }
  int main()
  {
    int number =10;
    int arr[3] ={1,2,3};

    struct student s1;
    s1.rollno =25;
    printf("primitive datatype\n");
    printf("Array=\n");
    for(int i=0;i<3;i++)
    {
        printf("%d\n",arr[i]);
    }
printf("\n\n");
 printf("user-defined datatype\n");
printf("Rollno : %d\n\n", s1.rollno);
display();
return 0;
  }
 
