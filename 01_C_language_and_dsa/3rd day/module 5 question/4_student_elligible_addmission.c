//Create a calculator using arithmetic operators.
#include<stdio.h>
int main()
{
    int age;
    int marks;
     
    printf("\nEnter the age \n");
    scanf("\n%d",&age);
    printf("\nEnter the graduation marks\n");
    scanf("\n%d",&marks);

     if (marks >= 75 && age >= 20)
    {
        printf("Student is eligible for admission.");
    }
    else
    {
        printf("Student is not eligible for admission.");
    }
    return 0;
}