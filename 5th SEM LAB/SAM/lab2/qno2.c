#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// #include<conio.h> // This header is not generally used in modern C

void printRandoms(int min, int max, int count)
{
    srand(time(0));
    printf("Random number between %d and %d\n", min, max);
    for (int i = 0; i < count; ++i)
    {
        int randomNum = min + rand() % (max - min + 1);
        printf("%d ", randomNum);
    }
    printf("\n");
}

int main()
{
    int min, max, count;

    printf("Enter minimum value: ");
    scanf("%d", &min);

    printf("Enter maximum value: ");
    scanf("%d", &max);

    printf("Enter number of random numbers to generate: ");
    scanf("%d", &count);

    printRandoms(min, max, count);

    return 0;
}