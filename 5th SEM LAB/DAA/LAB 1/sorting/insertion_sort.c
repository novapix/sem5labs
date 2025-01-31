#include <stdio.h>

void insertionSort(int[], int);
void displayArray(int[], int);

int main()
{
    int best_case[] = {1, 2, 3, 4, 5, 6};
    int worst_case[] = {6, 5, 4, 3, 2, 1};
    int avg_case[] = {3, 5, 2, 1, 6, 4};
    int n = 6;

    // Best Case (Already Sorted):
    printf("Best Case:\n");
    // printf("Array before sorting:\n");
    // displayArray(best_case, n);
    printf("Tracing Sorting Process:\n");
    insertionSort(best_case, n);
    printf("Array after sorting:\n");
    displayArray(best_case, n);
    printf("\n");

    // Worst Case (Reverse Order):
    printf("Worst Case:\n");
    // printf("Array before sorting:\n");
    // displayArray(worst_case, n);
    printf("Tracing Sorting Process:\n");
    insertionSort(worst_case, n);
    printf("Array after sorting:\n");
    displayArray(worst_case, n);

    // Average Case (Random Order):
    printf("\nAverage Case:\n");
    // printf("Array before sorting:\n");
    // displayArray(avg_case, n);
    printf("Tracing Sorting Process:\n");
    insertionSort(avg_case, n);
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

// Function to sort the array using insertion sort
void insertionSort(int arr[], int size)
{
    for (int i = 1; i < size; i++)
    {
        int element = arr[i];
        int j = i - 1;
        printf("Pass %d:\n", i);
        while (j >= 0 && arr[j] > element)
        {
            arr[j + 1] = arr[j];
            --j;
        }

        arr[j + 1] = element;
        printf("  After inserting %d at position %d: ", element, j + 1);
        displayArray(arr, size);
    }
}
