#include <iostream>

void printArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void bubblesort(int *arr, int n)
{
    int temp = 0;
    int issorted = 0;
    for (int i = 0; i < n - 1; i++)
    {
        issorted = 1;
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                issorted = 0;
            }
        }
        if (issorted)
        {
            return;
        }
    }
}
int main()
{
    int arr[] = {5, 7, 9, 3, 7};
    int n = 5;
    printArray(arr, n);
    bubblesort(arr, n);
    printArray(arr, n);
    return 0;
}
