#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// #include<conio.h>
int main()
{
    int random_number;
    srand(time(NULL));
    random_number = rand() % 6 + 1;
    printf("The random number is: %d\n", random_number);
    // getch();
    return 0;
}