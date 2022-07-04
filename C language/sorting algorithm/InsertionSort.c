//#include<iostream>

#include<stdio.h>

//using namespace std;

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

//C++ code for the insertion sort
// void printArray(int *arr, int size)
// {

//     cout<<"the size of the array is"<<size <<endl;
//     for (int i = 0; i < size; i++)
//     {
//         cout<<arr[i]<<" ";
//         //printf("%d ", arr[i]); 
//     }
//     printf("\n");
// }

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
    //-1 0    1   2   3   4  5
    //   12,| 54, 65, 7, 23, 9 --> i =1,key=54, j=0
    //   12,| 54, 65, 7, 23, 9 --> 1st pass done  (i=1)!

    //   12, 54,| 65, 7, 23, 9 --> i =2,key=65, j=1
    //   12, 54,| 65, 7, 23, 9 --> 2nd pass done  (i=2)!

    //   12, 54, 65,| 7, 23, 9 --> i =3,key=7, j=2
    //   12, 54, 65,| 65, 23, 9 --> i =3,key=7, j=1
    //   12, 54, 54,| 65, 23, 9 --> i =3,key=7, j=0
    //   12, 12, 54,| 65, 23, 9 --> i =3,key=7, j=-1
    //   7, 12, 54,| 65, 23, 9 --> 3rd pass done  (i=3)!

    //Fast forwarding and 4th and 5th pass will give :

    //   7, 12, 54, 65,| 23, 9 --> i =4,key=23, j=3
    //   7, 12, 23, 54,| 65, 9 --> after 4th pass

    //   7, 12, 23, 54, 65, | 9 --> i =5,key=9, j=4
    //   7, 9, 12, 23, 54,  65| --> after 5th pass

    int a[] = {12, 54, 65, 7, 23, 9};
    int size = sizeof(a) / sizeof(a[0]);
    printArray(a, size);
    insertionSort(a, size);
    printArray(a, size);
    return 0;
}