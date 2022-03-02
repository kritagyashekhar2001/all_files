#include <stdio.h>

void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d", arr[i]);
        }
    printf("\n");
}

int indInsert(int size, int arr[], int index, int capacity, int element)
{
    if (size >= capacity)
    {
        return -1;
    }
    for (int i = size - 1; i >= index; i--)
    {
        arr[i + 1] = arr[i];
    }
    arr[index] = element;
}
int main()
{
    int arr[100] = {1, 2, 3, 4, 5};
    display(arr, 5);
    int size = 6, element = 7, index = 4;
    indInsert(size, arr, index, 100, element);
    display(arr, size);
    return 0;
}