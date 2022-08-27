#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void printArray(int arr[],int n)
{
    for(int i = 0;i < n ; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void merge(int arri[],int n , int arrj[], int m , int arr3[]){
    int i = 0;
    int j = 0;
    int k = 0;
    while(i < n && j < m)
    {
        if(arri[i]<arrj[j]){
            arr3[k++]=arri[i++];
        }
        else {
            arr3[k++]=arrj[j++];
        }
    }
    while(i < n)
    {
        arr3[k++]=arri[i++];
    }
    while (j < m)
    {
        arr3[k++]=arrj[j++];
    }
}


int main()
{
    int arr1[]={1,3,5,7,9};
    int arr2[]={2,4,6};
    int arr3[8]={0};

    int n = 5;
    int m = 3;
    merge(arr1,n,arr2,m,arr3);
    // mergeArrays(arr1,arr2,n,m,arr3);
    printArray(arr3,8);
    return 0;

}