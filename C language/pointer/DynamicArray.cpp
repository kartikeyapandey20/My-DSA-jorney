#include<iostream>

using namespace std;

int main(){

    //CREATION OF 2-D ARRAY
    int n;
    cin>>n;
    int **arr = new int*[n];
    for(int i = 0 ; i < n ; i++ ){
        arr[i]=new int[n];
    }

    //taking input
    for(int i = 0 ;  i < n ; i++){
        for(int j = 0 ; j < n  ; j++){
            cin>>arr[i][j];
        }
    }

    //printing dynamic 2-d array
    for(int i = 0 ;  i < n ; i++){
        for(int j = 0 ; j < n  ; j++){
            cout<<arr[i][j];
            cout<<" ";
        }cout<<endl;
    }

    //releasing the memory
    for(int i = 0 ; i < n ; i++){
        delete [] arr[i];
    }
        delete []arr;
    return 0;
}