#include <stdio.h>

void merge(int arr[], int l, int m, int r);
void mergeSort(int arr[], int l, int r, int pass);
void displayArray(int arr[], int size);

int main()
{
    int best_case[] = {1, 2, 3, 4, 5, 6};
    int avg_case[] = {3, 6, 2, 1, 5, 4};
    int worst_case[] = {6, 5, 4, 3, 2, 1};
    int n = 6;

    printf("\nBest Case:\n");
    mergeSort(best_case, 0, n - 1, 1);
    displayArray(best_case, n);

    printf("\nAverage Case:\n");
    mergeSort(avg_case, 0, n - 1, 1);
    displayArray(avg_case, n);

    printf("\nWorst Case:\n");
    mergeSort(worst_case, 0, n - 1, 1);
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

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    // Create temporary arrays
    int L[n1], R[n2];

    // Copy data to temporary arrays L[] and R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // Merge the temporary arrays back into arr[l..r]
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if any
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if any
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r, int pass)
{
    if (l < r)
    {
        printf("\nPass %d:\n", pass);
        // Same as (l+r)/2, but avoids overflow for large l and h
        int m = l + (r - l) / 2;

        // Sort first and second halves
        printf("Splitting subarray: ");
        for (int i = l; i <= r; i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");
        printf("Left subarray: ");
        for (int i = l; i <= m; i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");
        printf("Right subarray: ");
        for (int i = m + 1; i <= r; i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");
        mergeSort(arr, l, m, pass + 1);
        mergeSort(arr, m + 1, r, pass + 1);

        // Merge the sorted halves
        printf("Merging subarrays: ");
        for (int i = l; i <= r; i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");
        merge(arr, l, m, r);
    }
}