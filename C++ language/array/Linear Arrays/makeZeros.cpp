#include<iostream>
#include<bits\stdc++.h>

using namespace std;

void makeZeros(int arr[],int n){
    int i =0;
    for(int j = 0; j < n ; j++ ){
        if(arr[j] != 0){
            swap(arr[i],arr[j]);
            i++;
        }
    }
}

void printArray(int arr[] , int n ){
    for(int i = 0 ; i < n; i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
}
int main(){
    int arr[]={0,1,0,3,2};
    printArray(arr,5);
    makeZeros(arr,5);
    printArray(arr,5);

    return 0;
}