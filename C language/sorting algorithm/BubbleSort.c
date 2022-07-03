#include<stdio.h>
//FUNCTION FOR PRINTING ARRAY
void printArray(int *arr,int size)
{
    
    printf("the size of the array is %d\n",size);
    for(int i =0 ;i <size; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}
//FUNCTION FOR THE BUBBLE SORT SO WE CAN SORT THE ARRAY
void bubbleSort(int * A , int size)
{
    //TEMPERORY VARIALBLE FOR SWAPING VALUES
    int temp;
    //FOR THE NUMBER OF PASSES
    for( int i=0;i<size-1;i++)
    {
        printf("pass number is %d\n",i+1);
        //FOR THE COMPARIONS FOR EACH PASS
        for(int j=0;j<size-1-i;j++)
        {
            if(A[j]>A[j+1])
            {
                temp =A[j];
                A[j]=A[j+1];
                A[j+1]=temp;
            }
        }
        
    }
}
//FUNCTION FOR THE ADAPTIVE BUBBLE SORT SO WE CAN SORT THE ARRAY WITH LESS PASSES
void bubbleSortAdaptive(int * A , int size)
{
    //TEMPERORY VARIALBLE FOR SWAPING VALUES
    int temp;
    //FOR MAKING BUBBLE SORT ADAPTIVE FOLLOWING VARIABLE IS DECLARED
    int isSorted=0;
    //FOR THE NUMBER OF PASSES
    for( int i=0;i<size-1;i++)
    {
        printf("pass number is %d\n",i+1);
        isSorted=1;
        //FOR THE COMPARIONS FOR EACH PASS
        for(int j=0;j<size-1-i;j++)
        {
            if(A[j]>A[j+1])
            {
                temp =A[j];
                A[j]=A[j+1];
                A[j+1]=temp;
                isSorted=0;
            }
        }
        //IF ARRAY IS ALREADY SORTED HENCE IT WILL BE COMPLETED IN 1 PASS IT WILL ADAPTIVE
        if(isSorted)
        {
            return ;
        }
    }
}

int main()
{
    int arr[6]={1,2,3,4,5,6};
    // int arr[6] = {12,54,65,7,23,9};
    int size = sizeof(arr)/sizeof(arr[0]);
    printArray(arr,size);
    bubbleSort(arr,size);
    printArray(arr,size);
    bubbleSortAdaptive(arr,size);
    printArray(arr,size);
    return 0;
}