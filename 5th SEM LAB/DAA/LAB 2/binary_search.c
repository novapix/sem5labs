// WAP in C/C++ to implement binary search algorithm. Also implement to check the precondition for the algorithm.

#include <stdio.h>

int is_sorted(int arr[], int len)
{
    for (int i = 0; i < len - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            return -1;
        }
    }
    return 1;
}

int binary_search(int arr[], int left, int right, int key)
{
    if (left > right)
    {
        return -1;
    }

    int middle = left + (right - left) / 2;
    printf("Checking %d = %d\n", key, arr[middle]);
    if (key == arr[middle])
        return middle;
    if (arr[middle] > key)
        return binary_search(arr, left, middle - 1, key);

    return binary_search(arr, middle + 1, right, key);
}

int main()
{
    int arr[] = {2, 3, 4, 5, 6, 7, 8, 10, 33};
    int key = 10;
    int len = sizeof(arr) / sizeof(arr[0]);
    if (is_sorted(arr, len))
    {
        int result = binary_search(arr, 0, len - 1, key);
        if (result == -1)
            printf("Element not found");
        else
            printf("Element %d found at %d index", key, result);
    }
    else
    {
        printf("Array is not sorted");
    }
    return 0;
}