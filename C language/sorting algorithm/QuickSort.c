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

int partition(int arr[], int low, int high)
{
    // HERE PIVOT VARIABLE IS USED FOR THE REFRENCE FOR SORTING THE ARRAY WHICH IS GENRALLY THE
    // LOWEST INDEX OF THE ARRAY IS THERE BUT U CAN TAKE THE HIGHER INDEX AND CAN SORT WITH RESPECT
    // HIGHER INDEX
    int pivot = arr[low];
    int i = low + 1;
    int j = high;
    int temp;
    do
    {
        //HERE WE ARE MOVING THE i TILL WE HAVE FOUND THE ELEMENT GREATER THAN PIVOT VALUE
        while (arr[i] <= pivot)
        {
            i++;
        }

        //HERE WE ARE MOVING j TILL WE HAVE  FOUND THE ELEMENT LESS THAN PIVOT VALUE
        while (arr[j] > pivot)
        {
            j--;
        }
        //AFTER FINDING THE ELEMENT HERE WE ARE SWAPING THE ELEMENTS
        if (i < j)
        {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    } while (i < j);
    //HERE WE ARE SWAING THE ELEMENT J WITH LOW SO THAT WE CAN SORT THE ARRAY THROUGH RECURSIVE CALL
    temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;
    //RETURN THE INDEX OF THE RECURSIVE CALL
    return j;
}
void quickSort(int arr[], int low, int high)
{
    // INDEX OF PIOVET AFTTER PARTITION
    int partitionIndex;
    //HERE WE HAVE GIVEN THE BASE CONDITION TO STOP THE RECUSIVE CALL
    if(low<high)
    {
    partitionIndex = partition(arr, low,high);
    // SORT THE LEFT SUBARRAY
    quickSort(arr, low, partitionIndex - 1);
    // SORT THE RIGHT SUBARRAY
    quickSort(arr, partitionIndex + 1, high);
    }
}
int main()
{
    int arr[] = {3,5,2,13,12,3,5,13,45};

    //HOW THIS ALOG IS WORKING
    //3,5i,2,13,12,3,5,13,j45
    //3,5,2,13i,12,3j,5,13,45
    //3,5,2,3j,12i,3,2,13,45 --> FIRST RECURSIVE CALL RETURNS 3  (HERE 3 IS INDEX NOT VALUE)
    int size = sizeof(arr) / sizeof(arr[0]);
    printArray(arr, size);
    quickSort(arr, 0, size - 1);
    printArray(arr, size);
    return 0;
}