#include <stdio.h>

int main()
{
    // char typically occupies 1 byte
    // of memory.
    //
    // It stores the ASCII value
    // corresponding to the character.

    char letter = 'H';
    char digit = '5';
    char special = '@';

    printf("Letter  : %c\n", letter);
    printf("Digit   : %c\n", digit);
    printf("Special : %c\n", special);

    return 0;
}