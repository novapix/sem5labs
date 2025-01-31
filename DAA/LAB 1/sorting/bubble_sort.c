#include <stdio.h>

void bubbleSort(int[], int n);
void displayArray(int[], int n);

int main()
{
    int best_case[] = {1, 2, 3, 4, 5, 6};
    int avg_case[] = {3, 6, 2, 1, 5, 4};
    int worst_case[] = {6, 5, 4, 3, 2, 1};
    int n = 6;

    // Best Case:
    printf("Best Case :\n");
    printf("Tracing Sorting Process:\n");
    bubbleSort(best_case, n);
    printf("Array after sorting:\n");
    displayArray(best_case, n);

    // Worst Case:
    printf("\nWorst Case :\n");
    printf("Tracing Sorting Process:\n");
    bubbleSort(worst_case, n);
    printf("Array after sorting:\n");
    displayArray(worst_case, n);

    // Average Case:
    printf("\nAverage Case :\n");
    printf("Tracing Sorting Process:\n");
    bubbleSort(avg_case, n);
    printf("Array after sorting:\n");
    displayArray(avg_case, n);

    return 0;
}

// Function to display the array
void displayArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to sort the array using bubble sort
void bubbleSort(int arr[], int n)
{
    int swapped, i;

    for (i = 0; i < n - 1; i++)
    {
        swapped = 0;

        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }
        }
        printf("After pass %d : ", i + 1);
        displayArray(arr, n);
        if (swapped == 0)
        {
            printf("No swap is made. Array is sorted\n");
            break;
        }
    }
}