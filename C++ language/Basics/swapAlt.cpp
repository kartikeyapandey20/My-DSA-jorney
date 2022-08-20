#include<iostream>
using namespace std;

void altSwap(int arr[],int n)
{
    int i = 0;
    int j =1;
    while(i<n && j <n)
    {
        swap(arr[i],arr[j]);
        i+=2;
        j+=2;
    }
}

void approach2(int arr[],int n)
{
    for(int i = 0; i<n;i+=2)
    {
        if(i+1<n)
        {
            swap(arr[i],arr[i+1]);
        }
    }
}
void printArray(int arr[], int n)
{
    for(int i =0 ;i < n ; i++)
    {
        cout<< arr[i]<<endl;
    }
}
int main()
{
    int arr[]={1,2,3,4,5,6};
    altSwap(arr,6);
    printArray(arr,6);
    approach2(arr,6);
    printArray(arr, 6);
    return 0;
}