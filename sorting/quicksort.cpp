#include <iostream>
using namespace std;

void printArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low + 1;
    int j = high;
    int temp;

    do
    {
        while (arr[i] <= pivot)
        {
            i++;
        }

        while (arr[j] > pivot)
        {
            j--;
        }
        if (i < j)
        {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    } while (i < j);

    temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;
    return j;
}

void qiucksort(int arr[], int low, int high)
{
    int partitionindex;
    if (low < high)
    {
        partitionindex = partition(arr, low, high);
        qiucksort(arr, low, partitionindex - 1);
        qiucksort(arr, partitionindex + 1, high);
    }
}
int main()
{
    int A[] = {9, 4, 4, 8, 7, 5, 6};
    int n = 9;
    n = 7;
    printArray(A, n);
    qiucksort(A, 0, n - 1);
    printArray(A, n);
    return 0;
}