// write a c program to create a menu driven calculator using the switch stataement 
//the program should display a menu with the following options until the
//user chhose exit (adition, substraction, multiplication, division and modulus)

#include <stdio.h>

int main()
{
    int choice;
    int a, b;
    

    printf("Menu\n");
    printf("0. Exit\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Modulus\n");


    printf("Enter your choice: ");
    scanf("%d", &choice);

    if(choice == 0)
    {
    printf("\n"); 
    }
    else{
        printf("Enter two numbers: ");
        scanf("%d %d", &a, &b);
    }

    switch(choice)
    {
        case 0:
            printf("EXIT");
            break;
        case 1:
            printf("Result = %d", a + b);
            break;

        case 2:
            printf("Result = %d", a - b);
            break;

        case 3:
            printf("Result = %d", a * b);
            break;

        case 4:
            if (b != 0)
                printf("Result = %d", a / b);
            else
                printf("Division by zero is not possible.\n");
            break;

        case 5:
            printf("Result = %d", a % b );
            break;

        default:
            printf("\n Invalid number");
    }

     

    return 0;
}
 