#include <stdio.h>

void quickSort(int arr[], int low, int high, int pass);
int partition(int arr[], int low, int high);
void displayArray(int arr[], int size);
int best_case[] = {1, 2, 3, 4, 5, 6};
int avg_case[] = {3, 6, 2, 1, 5, 4};
int worst_case[] = {6, 5, 4, 3, 2, 1};
int n = 6;

int main()
{

    printf("\nBest Case:\n");
    quickSort(best_case, 0, n - 1, 1);
    displayArray(best_case, n);

    printf("\nAverage Case:\n");
    quickSort(avg_case, 0, n - 1, 1);
    displayArray(avg_case, n);

    printf("\nWorst Case:\n");
    quickSort(worst_case, 0, n - 1, 1);
    displayArray(worst_case, n);

    return 0;
}

void displayArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low + 1;
    int j = high;

    printf("Partitioning: ");
    displayArray(arr, n);
    printf("Pivot: %d\n", pivot);

    while (i <= j)
    {
        while (i <= high && arr[i] <= pivot)
        {
            i++;
        }
        while (j >= low && arr[j] > pivot)
        {
            j--;
        }

        if (i < j)
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    // Swap arr[low] and arr[j]
    int temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;

    return j;
}

void quickSort(int arr[], int low, int high, int pass)
{
    if (low < high)
    {
        printf("\nPass %d:\n", pass);
        int partitionIndex = partition(arr, low, high);

        printf("Subarrays after partition:\n");
        printf("Left: ");
        for (int i = low; i < partitionIndex; i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");
        printf("Right: ");
        for (int i = partitionIndex + 1; i <= high; i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");

        quickSort(arr, low, partitionIndex - 1, pass + 1);
        quickSort(arr, partitionIndex + 1, high, pass + 1);
    }
}