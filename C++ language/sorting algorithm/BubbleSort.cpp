#include<iostream>

using namespace std;

void printArray(int arr[],int n){
    for(int i = 0; i < n ; i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
}

void bubbleSort(int arr[], int n){
    for(int i = 1; i < n ; i++){
        for(int j = 0; j < n-i; j++){
            printArray(arr,n);
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
}

int main(){
    int arr[]={1,4,3,6,7,2};
    printArray(arr,6);
    bubbleSort(arr,6);
    printArray(arr,6);
    return 0;
}