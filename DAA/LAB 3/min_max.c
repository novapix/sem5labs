#include <stdio.h>

void MaxMin(int arr[], int i, int j, int *max, int *min)
{
    if (i == j)
    {
        printf("Subarray: [%d]\n", arr[i]);
        printf("Min: %d, Max: %d\n", arr[i], arr[i]);
        *max = arr[i];
        *min = arr[i];
    }
    else if (i == j - 1)
    {
        printf("Subarray: [%d, %d]\n", arr[i], arr[j]);
        if (arr[i] < arr[j])
        {
            printf("Min: %d, Max: %d\n", arr[i], arr[j]);
            *max = arr[j];
            *min = arr[i];
        }
        else
        {
            printf("Min: %d, Max: %d\n", arr[j], arr[i]);
            *max = arr[i];
            *min = arr[j];
        }
    }
    else
    {
        int mid = (i + j) / 2;

        printf("\nSplitting subarray: ");
        for (int k = i; k <= j; k++)
        {
            printf("%d ", arr[k]);
        }
        printf("\nLeft subarray: ");
        for (int k = i; k <= mid; k++)
        {
            printf("%d ", arr[k]);
        }
        printf("\nRight subarray: ");
        for (int k = mid + 1; k <= j; k++)
        {
            printf("%d ", arr[k]);
        }
        printf("\n\n");

        int max1, min1;
        MaxMin(arr, i, mid, max, min);
        MaxMin(arr, mid + 1, j, &max1, &min1); // Create new pointers for the second half

        if (*max < max1)
        {
            *max = max1;
        }
        if (*min > min1)
        {
            *min = min1;
        }
    }
}
int main()
{
    int arr[] = {10, 2, 3, 4, 5, 6, 7, 8};
    int n = 8;
    int max, min;

    MaxMin(arr, 0, n - 1, &max, &min);

    printf("\nMaximum element is: %d\n", max);
    printf("Minimum element is: %d\n", min);

    return 0;
}
