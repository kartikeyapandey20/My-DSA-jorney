#include<iostream>

using namespace std;

void print(int *arr,int n){
    for(int i = 0 ; i < n ; i++){
        cout << arr[i] << " " ;
    }cout<<endl;
}
void bubbleSort(int * arr , int n){
    if(n == 1 || n == 0){
        return ;
    }
    for(int i = 0 ; i < n ; i++){
        if(arr[i] > arr[i+1]){
            swap(arr[i],arr[i+1]);
        }
    }
    bubbleSort(arr,n-1);
}
int main(){
    int arr[] = {34,3,2,5,3};
    int size = 5;
    print(arr,size);
    bubbleSort(arr,size-1);
    print(arr,size);
    return 0;
}