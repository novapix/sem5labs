#include <stdio.h>

void selectionSort(int[], int);
void displayArray(int[], int);
void swap(int *a, int *b);

int main()
{
    int best_case[] = {1, 2, 3, 4, 5, 6};
    int worst_case[] = {6, 5, 4, 3, 2, 1};
    int avg_case[] = {4, 77, 5, 9, 1, 34};
    int n = 6;

    // Best Case
    printf("Best Case:");
    printf("\nTracing Sorting Process:\n");
    selectionSort(best_case, n);
    printf("Array after sorting:\n");
    displayArray(best_case, n);

    // Worst Case
    printf("\nWorst Case:");
    printf("\nTracing Sorting Process:\n");
    selectionSort(worst_case, n);
    printf("Array after sorting:\n");
    displayArray(worst_case, n);

    // Average Case
    printf("\nAverage Case:");
    printf("\nTracing Sorting Process:\n");
    selectionSort(avg_case, n);
    printf("Array after sorting:\n");
    displayArray(avg_case, n);

    return 0;
}

// Function to display the array
void displayArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to swap two elements
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to sort the array using selection sort
void selectionSort(int arr[], int n)
{
    int i, j, minIndex;
    for (i = 0; i < n - 1; i++)
    {
        minIndex = i;
        printf("Pass %d:\n", i + 1);

        // Find the minimum element in the unsorted portion
        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j; // Update minIndex if a smaller element is found
            }
        }
        // Swap the found minimum element with the first element
        if (minIndex != i)
        {
            printf("  Swapping %d with %d\n", arr[i], arr[minIndex]);
            swap(&arr[i], &arr[minIndex]);
        }
        displayArray(arr, n);
    }
}
