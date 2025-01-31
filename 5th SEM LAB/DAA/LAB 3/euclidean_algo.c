// 2.Implementation of Euclid's algorithm to find the GCD of 2 user input numbers using recursive functions.

#include <stdio.h>
int GCD(int a, int b)
{
    if (b == 0)
    {
        printf("Base case reached: GCD is %d\n", b);
        return a;
    }
    else
    {
        printf("Recursive case called: GCD (%d,%d)\n", b, a % b);
        return GCD(b, a % b);
    }
}
int main()
{
    int a, b;
    printf("Enter any two number to find GCD of:");
    scanf("%d%d", &a, &b);
    int res = GCD(a, b);
    printf("GCD of %d & %d is  %d ", a, b, res);
    return 0;
}