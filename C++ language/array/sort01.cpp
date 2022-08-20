#include<iostream>

using namespace std;
int *sortOne(int *arr, int n){
    int left = 0 , right = n-1;
    while(left<right){
        while(arr[left]==0 && left<right){
            left++;
        }
        while(arr[right]==1 && left<right){
            right--;
        }
        if(left<right){
            int temp;
            temp = arr[left];
            arr[left]=arr[right];
            arr[right]=temp;
            left++;
            right--;
            // swap(arr[left],arr[right]);
        }
    }
    return arr;
}

void printArray(int arr[], int n){
    for(int i = 0; i < n;i++){
        cout<<arr[i]<<" ";
    }
}
int main(){
    int arr[6]={0,0,1,1,0,1};
    sortOne(arr,6);
    printArray(arr,6);
    return 0;
}