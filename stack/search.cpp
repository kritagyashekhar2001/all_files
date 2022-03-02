#include <iostream>

int binarysearch(int arr[], int n, int element)
{
    int high, low, mid;
    low = 0;
    high = n - 1;
    while (low <= high)
    {
        mid = (high + low) / 2;
        if (arr[mid] == element)
        {
            return mid;
        }
        else if (arr[mid] < element)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}

int main()
{
    int arr[] = {1, 3, 5, 56, 64, 73, 123, 225, 444};
    int size = sizeof(arr) / sizeof(int);
    int element = 444;
    int searchIndex = binarysearch(arr, size, element);
    printf("The element %d is at index %d \n", element, searchIndex);
    return 0;
}