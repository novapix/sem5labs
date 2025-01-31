//  WAP in C to generate fibonacci sequence up to a user input value. Use Tail recursion for optimization.

#include <stdio.h>

int fibonacci(int n, int a, int b)
{
    if (n == 0)
        return a;

    else
        return fibonacci(n - 1, b, a + b);
}

int main()
{
    int n;
    printf("Enter the number of terms: ");
    scanf("%d", &n);

    if (n <= 0)
        printf("Invalid input. Please enter a positive integer.\n");

    printf("Fibonacci sequence up to %d terms:\n", n);
    for (int i = 0; i < n; ++i)
    {
        printf("%d ", fibonacci(i, 0, 1));
    }
    printf("\n");

    return 0;
}