// rolling dice generator

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int n, result;
    int counts[6] = {0};
    srand(time(NULL));

    printf("Enter the number of dice rolls: ");
    scanf("%d", &n);

    printf("Rolling a six-sided die %d times:\n", n);
    for (int i = 0; i < n; i++)
    {
        result = (rand() % 6) + 1;
        counts[result - 1]++;
        printf("Roll %d: %d\n", i + 1, result);
    }

    // Calculate and display probabilities
    printf("\nFace\tCount\tProbability\n");
    for (int i = 0; i < 6; i++)
    {
        double probability = (double)counts[i] / n;
        printf("%d\t%d\t%.2f\n", i + 1, counts[i], probability);
    }

    return 0;
}
