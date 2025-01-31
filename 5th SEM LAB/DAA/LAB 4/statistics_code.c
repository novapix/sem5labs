// 1. Implement the algorithm for finding order statistics as: mean, median and mode of a list of n unordered items.
// [you can use any sorting algorithm]

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to swap two elements
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Bubble sort implementation
void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

// Calculate the mean of the list
double mean(int arr[], int n)
{
    double sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    return sum / n;
}

// Calculate the median using bubble sort
double median(int arr[], int n)
{

    bubbleSort(arr, n);

    if (n % 2 == 1)
    {
        return arr[n / 2];
    }
    else
    {
        return (arr[n / 2 - 1] + arr[n / 2]) / 2.0;
    }
}

// Calculate the mode of the list
int mode(int arr[], int n)
{
    int max_count = 0, mode_value = arr[0];
    for (int i = 0; i < n; i++)
    {
        int count = 0;
        for (int j = 0; j < n; j++)
        {
            if (arr[j] == arr[i])
            {
                count++;
            }
        }
        if (count > max_count)
        {
            max_count = count;
            mode_value = arr[i];
        }
    }
    return mode_value;
}

int main()
{
    int data[] = {3, 1, 2, 5, 3, 2, 4, 1, 3};
    int n = 9;

    printf("Original List: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", data[i]);
    }
    printf("\n");

    printf("Sorted List: ");

    bubbleSort(data, n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", data[i]);
    }
    printf("\n");

    printf("Mean: %.2f\n", mean(data, n));
    printf("Median: %.2f\n", median(data, n));
    printf("Mode: %d\n", mode(data, n));

    return 0;
}
