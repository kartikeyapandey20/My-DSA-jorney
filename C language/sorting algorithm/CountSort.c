#include <stdio.h>
#include <stdlib.h>
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
//THIS FUCNTION IS USED TO FIND THE MAXIMUM NUMBER IN OUR ARRAY SO THAT WE CAN ALLOCATE MEMORY 
//FOR OUR ANOTHER ARRAY FOR THE SORTTING
int arrayMax(int arr[], int size)
{
    int max = arr[0];
    for (int i = 0; i < size; i++)
    {
        if (max < arr[i])
        {
            max = arr[i];
        }
    }
    return max;
}
//FUNCTION FOR SORTING THE ARRAY USING COUNT SORT
void countSort(int *arr, int size)
{
    int i = 0;
    int max = arrayMax(arr, size);
    // HERE WE HAVE ALLOCATED MEMORY FOR OUR EXTRA ARRAY
    int *arr2 = (int *)malloc((max + 1) * sizeof(int));
    //HERE WE HAVE INITILALIZED ALL THE VALUE OF THE ARRAY TO 0 OR YOU CAN USE CALLOC FUNCTION
    //TO ALLOCATE THE MEMORY SO THAT WE CAN INCREMENT THE VALUE LATER IN THE ARRAY
    for (int i = 0; i < max + 1; i++)
    {
        arr2[i] = 0;
    }
    //HERE WE HAVE INCREMENTED THE VALUE AT THE PARTICULAR INDEX IN THE ARRAY WITH RESPECT TO
    //THE VALUE IN OUR MAIN ARRAY

    //E.G

    //BEFORE

    //ARR2
    //INDEX 0 1 2 3 4 5 6 7 8 9
    //VALUE 0 0 0 0 0 0 0 0 0 0

    // ARR[0]=9;

    //AFTER
    
    //ARR2
    //INDEX 0 1 2 3 4 5 6 7 8 9
    //VALUE 0 0 0 0 0 0 0 0 0 1

    for (int i = 0; i < size; i++)
    {
        arr2[arr[i]] = arr2[arr[i]] + 1;
    }

    //HERE WE HAVE MADE ANOTHER VARIABLE SO THAT WE CAN ADD VALUES IN OUR ORIGINAL ARRAY
    //THIS IS THE COUNTER FOR EXTRA ARRAY
    i = 0;
    //THIS THE COUNTER FOR THE ORIGINAL ARRAY
    int temp = 0;
    while (i <= max)
    {
        if (arr2[i] > 0)
        {
            arr[temp] = i;
            arr2[i] -= 1;
            temp++;
        }
        else
        {
            i++;
        }
    }
}
int main()
{
    int arr[] = {56,785,4,2,5,10,4,5,2,4,85,74};
    // int arr[] = {5, 4, 3, 2, 1};
    int size = sizeof(arr) / sizeof(arr[0]);
    printArray(arr, size);
    countSort(arr, size);
    printArray(arr, size);
    return 0;
}