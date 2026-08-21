#include <stdio.h>
#include "ASTHA.h"

int main()
{
    ASTHA_banner();

    ASTHA_version();

    ASTHA_line();

    printf("10 + 20 = %d\n", ASTHA_add(10,20));

    ASTHA_success("Library Loaded Successfully");

    return 0;
}