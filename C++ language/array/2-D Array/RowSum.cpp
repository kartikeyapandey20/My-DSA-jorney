#include<iostream>

using namespace std;

void RowSum(int arr[][3],int i, int j){
    int sum = 0 ;
    for(int i = 0 ; i < 3 ; i++){
        sum = 0;
        for(int j = 0 ; j < 3 ; j++){
            sum += arr[i][j];
        }
    }
        cout<<"the sum of row wise element is "<<sum<<endl;
}


int largestRowSum(int arr[][3]){
    int max = 0;
    int sum = 0;
    int num = -1;
    for(int i = 0 ; i < 3 ; i++){
        sum = 0;
        for(int j = 0 ; j < 3 ; j++){
            sum += arr[i][j];
        }
        cout<<"the sum of row wise element is "<<sum<<endl;
        if(max <= sum ){
            max = sum;
            num = i ;
        }
    }
    cout<<"The largest row wise sum element is "<<max<<endl;

    return num;
}
int main(){

    int arr[3][3];
    for(int i = 0 ; i < 3 ; i++ )
    {
        for(int j = 0 ; j < 3 ; j++){
            cout<<"Enter the element at ["<<i<<"]["<<j<<"]";
            cin>>arr[i][j];
        }cout<<endl;
    }

    RowSum(arr,3,3);

    int num = largestRowSum(arr);
    cout<<"The largest sum is available at "<<num<<endl;
    return 0;
}