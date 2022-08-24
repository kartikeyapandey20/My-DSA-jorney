#include<iostream>

using namespace std;

void printArray(int arr[],int n){
    for(int i = 0; i < n ; i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
}

void insertionSort(int arr[], int n){
    for(int i = 1; i < n ; i++){
        int temp = arr[i];
        int j = i-1;
        for(; j >= 0 ; j--){
            if(arr[j]>temp){
                arr[j+1] = arr[j];
            }
            else{
                break;
            }
        }
        arr[j+1]=temp;
    }
}
int main(){
    int arr[]={4,2,1,3,5};
    printArray(arr,5);
    insertionSort(arr,5);
    printArray(arr, 5);
    return 0;
}