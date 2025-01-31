#include <stdio.h>

int linear_search(int arr[], int len, int key)
{
    for (int i = 0; i < len; i++)
    {
        printf("Checking if %d = %d\n", arr[i], key);
        if (key == arr[i])
            return i;
    }
    return -1;
}

int main()
{
    int arr[] = {1, 4, 7, 8, 3, 9, 20, 33, 44, 62};
    int len = sizeof(arr) / sizeof(arr[0]);
    int key = 20;
    int result = linear_search(arr, len, key);
    if (result == -1)
        printf("Element not found\n");
    else
        printf("Element %d found at index %d.", key, result);
    return 0;
}