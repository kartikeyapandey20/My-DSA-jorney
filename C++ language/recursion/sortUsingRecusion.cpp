#include<iostream>

using namespace std;

bool isSorted(int *arr,int n){
    if(n==0 || n==1){
        return true;
    }

    if(arr[0] > arr[1]){
        return false;
    }
    else{
        bool ans = isSorted(arr + 1,n - 1);
        return ans;
    }
          
}
int main(){
    int arr[5] = {1,2,3,4,5};
    int size = 5;
    bool ans = isSorted(arr,size);
    if(ans){
        cout<<"Array is sorted"<<endl;
    }
    else{
        cout<<"Array is not sorted"<<endl;

    }
    return 0;
}