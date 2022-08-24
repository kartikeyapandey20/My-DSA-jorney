#include<iostream>

using namespace std;

void printArray(int arr[], int n){
    for(int i = 0; i < n ; i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
}

void selectionSort(int arr[],int n){
    for(int i = 0; i< n; i++){
        int minIndex = i;
        for(int j = i+1;j<n;j++ ){
            if(arr[j]<arr[minIndex]){
                minIndex=j;
            }
        }
        swap(arr[minIndex],arr[i]);
    }
 
}
int main(){
    int arr[]={1,4,3,6,7,2};
    printArray(arr,6);
    selectionSort(arr,6);
    printArray(arr,6);
    return 0;
}