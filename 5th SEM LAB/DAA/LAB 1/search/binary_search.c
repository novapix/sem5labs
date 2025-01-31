#include <stdio.h>

int binary_search(int arr[], int len, int key)
{
    int result;
    int left = 0;
    int right = len - 1;
    while (left <= right)
    {
        int middle = (left) + (right - left) / 2;
        printf("Checking if %d = %d\n", arr[middle], key);
        if (arr[middle] == key)

            return middle;

        if (arr[middle] < key)
            (left) = middle + 1;

        else
            right = middle - 1;
    }

    return -1;
}

int main()
{
    int arr[] = {1, 3, 4, 7, 8, 9, 20, 33, 44, 62};
    int len = sizeof(arr) / sizeof(arr[0]);
    int key = 9;
    int result = binary_search(arr, len, key);
    if (result == -1)
    {
        printf("Element not found\n");
    }
    else
    {
        printf("Element %d found at index %d.", key, result);
    }
}