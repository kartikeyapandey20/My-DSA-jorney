#include <stdio.h>

int linearSearch(int arr[], int size, int element);
int binarySearch(int arr[], int size, int element);
int main()
{
    int arr[] = {1, 4, 6, 3, 2, 4, 6, 4, 3};
    int arr2[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int size = sizeof(arr) / sizeof(int);
    int size2 = sizeof(arr2) / sizeof(int);
    int element = 4;
    int search = linearSearch(arr, size, 4);
    int seach2 = binarySearch(arr2, size2, 4);
    if (search != (-1))
    {
        printf("the element %d found at index %d with the help of linear search\n", element, search);
    }
    else
    {
        printf("the given element was not found\n");
    }
    printf("both are different arrays");
    if (seach2!=(-1))
    {
        printf("the element %d found at index %d with help of binary search\n", element, seach2);
    }
    else
    {
        printf("the given element was not found\n");
    }
    return 0;
}

int linearSearch(int arr[], int size, int element)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == element)
        {
            return i;
        }
    }
    return -1;
}

int binarySearch(int arr[], int size, int element)
{
    int high, mid, low;
    low = 0;
    high = size - 1;
    while (low <= high)
    {
        mid = (low + high ) / 2;
        
        if (arr[mid] == element)
        {
            return mid;
        }
        if (arr[mid] < element)
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
