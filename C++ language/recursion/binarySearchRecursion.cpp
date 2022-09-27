#include<iostream>

using namespace std;

bool binarySearchWithRecursion(int arr[] ,int s , int e, int k){
    if(s>e){
        return false;
    }
    int m = s + (e-s)/2;

    if(arr[m]==k){
        return true;
    }
    if(arr[m]<k){
        return binarySearchWithRecursion(arr,m+1,e,k);;
    }
    else{
        return binarySearchWithRecursion(arr,s,m -1,k);;
    }
}

int main(){
    int arr[]={1,2,3,4,5};
    int n = 5;
    int s = 0;
    int e = n;
    bool ans = binarySearchWithRecursion(arr,s,e,1);
    if(ans){
        cout << "Present" << endl;
    }
    else{
        cout << "Absent" << endl;
    }
    return 0;
}