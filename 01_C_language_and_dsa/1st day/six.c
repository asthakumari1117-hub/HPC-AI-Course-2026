#include<stdio.h>
 
  struct student{
    int rollno;
    char grade;
  };
  int main()
  {
    int age =20;
    int marks[3]={85,90,95};
    struct student s1;
    s1.rollno =101;
    s1.grade = 'A';
    printf("student age : %d\n\n",age);
    printf("marks : ");

    for(int i=0; i<3;i++)
    {
        printf("%d", marks[i]);
    }
    printf("\n\n");

    printf("student details \n");


printf("Rollno : %d\n", s1.rollno);
printf("grade :%c\n", s1.grade);
return 0;
  }
 
