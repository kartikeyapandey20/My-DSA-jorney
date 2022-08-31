#include<iostream>

using namespace std;

int getPivot(int arr[], int n){

    int start = 0;
    int end = n-1;
    int mid = start + (end-start)/2;

    while(start<end){
        
        if(arr[mid]>=arr[0]){
            start = mid +1 ;
        }

        else{
            end = mid;
        }
        mid = start + (end-start)/2;
    }
    return start;
}
int main(){
    int arr[5]= {7,9,1,2,3};
    cout<<getPivot(arr,5)<<endl;
    return 0;
}