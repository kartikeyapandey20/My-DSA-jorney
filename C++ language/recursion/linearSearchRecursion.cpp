#include<iostream>

using namespace std;

bool linearSearch(int arr[],int n , int key){
    if(n==0){
        return 0;
    }

    if(arr[0]==key){
        return 1;
    }
    else{
    bool remainingPart=linearSearch(arr+1,n-1,key);  
    return remainingPart;
    }
}
int main(){
    int arr[]={1,2,3,4,5};
    int size = 5;
    int ans = linearSearch(arr,size,2);
    if(ans){
        cout<<"Number is present in the array"<<endl;
    }
    else{
        cout<<"Number is not present in the arry"<<endl;
    }
    return 0;
}