//  WAP TO GENERATE RANDOM NUMBER USING Congruential Method

#include <stdio.h>
int main()
{
    int x0, x1;
    int a, c, m;
    int i, n;
    int array[20]; // to store the random numbers generated
    printf("Enter the seed value x0: ");
    scanf("%d", &x0);
    printf("Enter multiplier(a): ");
    scanf("%d", &a);
    printf("Enter increment(c): ");
    scanf("%d", &c);
    printf("Enter modulo(c): ");
    scanf("%d", &m);
    printf("Enter how many random number you want to generate: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        x1 = (a * x0 + c) % m;
        array[i] = x1;
        x0 = x1;
    }

    printf("Random numbers: ");
    for (i = 0; i < n; i++)

    {
        printf("%d ", array[i]);
    }
    return 0;
}