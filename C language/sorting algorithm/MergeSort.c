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
//FUNCTION FOR MERGING ARRAY AFTER SPLITTING IT
void merge(int arr[], int mid, int low, int high)
{
    int i, j, k;
    int b[100];
    i = low;
    j = mid + 1;
    k = low;
    while (i <= mid && j <= high)
    {
        if (arr[i] < arr[j])
        {
            b[k] = arr[i];
            i++;
            k++;
        }
        else
        {
            b[k] = arr[j];
            j++;
            k++;
        }
    }
    //HERE WE ARE COPYING ALL ELEMENT WHICH ARE ALREADY SORTED IN LEFT ARRAY IF ANY ELEMENT IS THERE
    while (i <= mid)
    {
        b[k] = arr[i];
        k++;
        i++;
    }

    //HERE WE ARE COPYING ALL ELEMENT WHICH ARE ALREADY SORTED IN RIGHT ARRAY IF ANY ELEMENT IS THERE
    while (j <= high)
    {
        b[k] = arr[j];
        k++;
        j++;
    }
    //AFTER SORTING THE ELEMENT IN ONE ARRAY HERE WE ARE COPYING ALL THE ELEMENTS IN THE ORIGINAL ARRAY
    for (int i = low; i <=high; i++)
    {
        arr[i] = b[i];
    }
}

//FUNCTION FOR SORTING ELEMENT USING MERGE SORT
void mergeSort(int arr[], int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        //HERE WE USING RECURSION FOR RECURSIVE CALL SO THAT WE CAN SORT THE ARRAY
        mergeSort(arr, low, mid);
        //PRINT FUNCITON OVER HERE WILL CLEAR MERGE SORT LITTLE BIT BUT NOT WHOLE
        //FOR MERGE SORT TO CLEAR YOU HAVE TO USE BOOK PEN AND DRAW A RECURSIVE TREE
        printArray(arr,mid);
        mergeSort(arr, mid + 1, high);
        //PRINT FUNCITON OVER HERE WILL CLEAR MERGE SORT LITTLE BIT BUT NOT WHOLE
        //FOR MERGE SORT TO CLEAR YOU HAVE TO USE BOOK PEN AND DRAW A RECURSIVE TREE
        printArray(arr,high);
        merge(arr, mid, low, high);
        //PRINT FUNCITON OVER HERE WILL CLEAR MERGE SORT LITTLE BIT BUT NOT WHOLE
        //FOR MERGE SORT TO CLEAR YOU HAVE TO USE BOOK PEN AND DRAW A RECURSIVE TREE
        printArray(arr,high);
    }
}
int main()
{
    int arr[] = {3, 5, 2, 13, 12, 3, 5, 13, 45};
    int size = sizeof(arr) / sizeof(arr[0]);
    printArray(arr, size);
    mergeSort(arr, 0, size - 1);
    printArray(arr, size);
    return 0;
}