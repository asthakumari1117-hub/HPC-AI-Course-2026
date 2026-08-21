#include <stdio.h>

int main()
{
    // Every character has an
    // ASCII (American Standard Code
    // for Information Interchange)
    // value.
    //
    // %c prints the character.
    // %d prints its ASCII value.

    char ch1 = 'A';
    char ch2 = 'a';
    char ch3 = '51';

    printf("Character : %c  ASCII : %d\n", ch1, ch1);
    printf("Character : %c  ASCII : %d\n", ch2, ch2);
    printf("Character : %c  ASCII : %d\n", ch3, ch3);

    return 0;
}