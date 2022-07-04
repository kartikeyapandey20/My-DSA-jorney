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
//FUNCTION FOR SORTING THE ARRAY FOR THE SELECTION SORT 
void selectionSort(int *arr, int size)
{
    int temp, indexOfMin;
    for (int i = 0; i < size - 1; i++)
    {
        // HERE WE HAVE GIVEN THE VALUE OF THE i TO THIS VARIALBLE SO THAT WE CAN CHANGE THE VAULE
        // OF THE VARIABLE WITHOUT CHANGING THE VALUE OF THE i
        indexOfMin = i;
        for (int j = i + 1; j < size; j++)
        {

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
    return 0;
}