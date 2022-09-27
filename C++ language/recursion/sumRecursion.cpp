#include<iostream>

using namespace std;

int arraySum(int arr[], int n){
    if(n==0){
        return 0;
    }
    if(n==1){
        return arr[0];
    }
    int ans = arraySum(arr+1,n-1);
    int sum = arr[0] + ans;
    return sum;
}
int main(){
    int arr[]={1,2,3,4,4,5,3};
    int size = 7;
    cout<<arraySum(arr,size)<<endl;
    return 0;
}