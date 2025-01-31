#include <stdio.h>
#include <stdlib.h>
int main()
{
    int random_number;
    for (int i = 0; i <= 10; i++)
    {
        random_number = rand();

        printf("Random Number: %d\n", random_number);
    }
    return 0;
}