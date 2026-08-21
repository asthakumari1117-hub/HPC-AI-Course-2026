#include <stdio.h>

int main()
{
    // Multiple character variables
    // can be declared just like
    // integer variables.

    char firstInitial = 'H';
    char middleInitial = 'R';
    char lastInitial = 'J';

    printf("Initials : %c.%c.%c\n",
           firstInitial,
           middleInitial,
           lastInitial);

    return 0;
}