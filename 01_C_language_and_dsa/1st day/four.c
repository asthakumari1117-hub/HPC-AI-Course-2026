#include<stdio.h>
 
  struct student{
    int rollno;
    char grade;
  };
  int main()
  {
    struct student s1;
    s1.rollno =101;
    s1.grade = 'A';
printf("Rollno : %d\n", s1.rollno);
printf("grade :%c\n", s1.grade);
return 0;
  }
 
