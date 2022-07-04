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

void selectionSort(int *arr, int size)
{
    int temp, indexOfMin;
    for (int i = 0; i < size - 1; i++)
    {
        indexOfMin = i;
        for (int j = i + 1; j < size; j++)
        {
            // HERE WE HAVE GIVEN THE VALUE OF THE I TO THIS VARIALBLE SO THAT WE CAN CHANGE THE VAULE
            // OF THE VARIABLE WITHOUT CHANGING THE VALUE OF THE

            if (arr[j] < arr[indexOfMin])
            {
                indexOfMin = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[indexOfMin];
        arr[indexOfMin] = temp;
    }
}

int main()
{
    int arr[] = {8, 0, 7, 1, 3};
    int size = sizeof(arr) / sizeof(arr[0]);
    printArray(arr, size);
    selectionSort(arr, size);
    printArray(arr, size);
}