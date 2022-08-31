#include<iostream>
#include<vector>
using namespace std;

vector<int> firstAndLastPosition(vector<int> arr,int n,int k){
    int i = 0;
    int j = n-1;
    int first = -1;
    int last = -1;
    vector<int> a(2);
    while(i < n){
        if(arr[i] == k){
            first = i;
            break;
        }
        i++;
    }
    while(j > 0){
        if(arr[j] == k){
            last = j;
            break;
        }
        j--;;
    }
    a[0] = first;
    a[1] = last;

    return a;
}
int main(){
    vector<int> arr{2,3,0,0,0,0,1};
    
    vector<int>  a ;
    a=firstAndLastPosition(arr,7,0);
    cout<<"first position is : "<<a[0]<<endl;
    cout<<"last position is : "<<a[1]<<endl;

    return 0;
}