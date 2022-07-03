#include <stdio.h>

// FUNCTION FOR PRINTING ARRAY
void printArray(int *arr, int size)
{

    printf("the size of the array is %d\n", size);
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// FUNCTION FOR SORTING ARRAY USING INSERTION SORT
int insertionSort(int *a, int size)
{
    int key, j;
    for (int i = 1; i <=size-1; i++)
    {
        key = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

int main()
{
    int a[] = {12, 54, 65, 7, 23, 9};
    int size = sizeof(a) / sizeof(a[0]);
    printArray(a, size);
    insertionSort(a, size);
    printArray(a, size);
    return 0;
}