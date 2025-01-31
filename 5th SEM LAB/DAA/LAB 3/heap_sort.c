// 3. Implementation of Heap sort algorithm to sort the given list of elements using DAC strategy.
#include <stdio.h>

// Function to display an array
void displayArray(int arr[], int n, const char *message)
{
    printf("%s", message);
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Function to heapify a subtree rooted at index `i`
void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i)
    {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        heapify(arr, n, largest);
    }
}

// Function to perform heap sort
void heapSort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    displayArray(arr, n, "After building Max Heap: ");

    int index = 1;
    for (int i = n - 1; i > 0; i--)
    {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        char passMessage[50];
        sprintf(passMessage, "After Pass %d(move root to index %d): ", index++, i);
        displayArray(arr, n, passMessage);

        heapify(arr, i, 0);
    }
}

int main()
{
    // Best case: Array already sorted
    int bestCase[] = {1, 2, 3, 4, 5, 6};
    // Average case: Random unsorted array
    int avgCase[] = {4, 6, 1, 3, 5, 2};
    // Worst case: Array sorted in reverse order
    int worstCase[] = {6, 5, 4, 3, 2, 1};
    int n = 6;

    printf("Best Case :\n");
    displayArray(bestCase, n, "Original array: ");
    heapSort(bestCase, n);
    displayArray(bestCase, n, "Sorted array: ");
    printf("\n");

    printf("Worst Case :\n");
    displayArray(worstCase, n, "Original array: ");
    heapSort(worstCase, n);
    displayArray(worstCase, n, "Sorted array: ");
    printf("\n");

    printf("Average Case :\n");
    displayArray(avgCase, n, "Original array: ");
    heapSort(avgCase, n);
    displayArray(avgCase, n, "Sorted array: ");
    printf("\n");

    return 0;
}
