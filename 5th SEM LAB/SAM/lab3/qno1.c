// WAP to compute PI using a monte carlo method.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SEEDtime(NULL)
int main()
{
    int i, count = 0, n;
    double x, y, z, pi;
    srand(time(NULL));
    printf("Enter the total number of random number to be generated: ");
    scanf(" %d", &n);
    count = 0;
    for (i = 0; i < n; ++i)
    {
        x = (double)rand() / RAND_MAX;
        y = (double)rand() / RAND_MAX;
        z = x * x + y * y;
        if (z <= 1)
            count++;
    }
    pi = (double)count / n * 4;
    printf(" Approximate pi=%f\n", pi);
    return 0;
}