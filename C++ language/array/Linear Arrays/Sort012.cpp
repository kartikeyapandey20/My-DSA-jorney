#include<iostream>

using namespace std;

void sort(int * arr , int n){
    int left = 0 , right = n -1;
    while(left<right){
        while(arr[left]==0 && left<right){
            left++;
        }
        while((arr[right]==1 || arr[right]==2) && left<right){
            right--;
        }
        if(left<right){
            swap(arr[left],arr[right]);
        
            left++;
            right--;
            // swap(arr[left],arr[right]);
        }
    }
    int left2 = 0;
    int right2 = n-1;
    while(arr[left2]==0 && left2<right2){
            left2++;
        }
    while(left2<right2){
        while(arr[left2]== 1 && left2<right2){
            left2++;
        }
        while((arr[right2]==2) && left2<right2){
            right2--;
        }
        if(left2<right2){
            swap(arr[left2],arr[right2]);
            left2++;
            right2--;
        }
    }    
}

void printArray(int arr[], int n){
    for(int i = 0; i < n;i++){
        cout<<arr[i]<<" ";
    }
}
int main(){
    int arr[]={0,0,2,1,0,1,0,2,1,2,1,2,1,2,1,0,0,0,0};
    int n = sizeof(arr)/sizeof(arr[0]);
    sort(arr , n);
    printArray(arr , n);
    return 0;
}