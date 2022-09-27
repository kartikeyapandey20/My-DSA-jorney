#include<iostream>

using namespace std;

bool isPresent(int arr[][4] , int target , int row ,int col){
    for(int row = 0 ; row < 3 ; row++){
        for(int col = 0 ; col < 4 ; col++){
            if(arr[row][col]==target){
                return 1;
            }
        }
    }
    return 0;
}


int main(){

    //creating 2-d array
    int arr[3][4];

    //taking input in 2-d array

    for(int i = 0 ; i < 3 ; i++ )
    {
        for(int j = 0 ; j < 4 ; j++){
            cout<<"Enter the element at ["<<i<<"]["<<j<<"]";
            cin>>arr[i][j];
        }cout<<endl;
    }
    for(int i = 0 ; i < 3 ; i++ )
    {
        for(int j = 0 ; j < 4 ; j++){
            cout<<"Element at ["<<i<<"]["<<j<<"]"<<arr[i][j]<<endl;
        }cout<<endl;
    }

    cout<<"Enter the element you want to find"<<endl;
    int target;
    cin>>target;
    //searching element in 2-d array
    if(isPresent(arr ,target , 3 ,4 )){
        cout<<"Found"<<endl;
    }
    else{
        cout<<"Not Found"<<endl;
    }
    return 0;
}