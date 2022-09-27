#include<iostream>

using namespace std;

void print(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int partition(int arr[], int start , int end){
    int pivot = arr[start];
    int pivotLocation=0;

    for(int i  = start+1 ; i <= end ; i++){
        if(arr[i]<arr[start]){
            pivotLocation++;
        }
    }
    int pivotIndex = start + pivotLocation;
    swap(arr[pivotIndex],arr[start]);

    int i = start , j = end;
    while(i < pivotIndex && j > pivotIndex){
        while(arr[i] < pivot){
            i++;
        }
        while(arr[j] >  pivot){
            j--;
        }   
        if(i < pivotIndex && j > pivotIndex){
            swap(arr[i++],arr[j--]);
        }
        
    }
    return pivotIndex;
}

void quickSort(int arr[], int start , int end){
    //base case
    if(start >= end){
        return;
    }

    //partition
    int p = partition(arr , start, end);

    //recursive call

    //left side sort kerege
    quickSort(arr , start , p -1);

    //right side sort kerege
    quickSort(arr , p+1 , end );
}
int main(){
    int arr[]={3,6,4,3,5,3,5,3,9,6,4};
    int size = sizeof(arr)/sizeof(arr[0]);

    quickSort(arr, 0,size-1);

    print(arr , size);
    return 0;
}