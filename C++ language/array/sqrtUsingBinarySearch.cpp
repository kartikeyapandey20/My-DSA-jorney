#include<iostream>
using namespace std;

int sqrt(int n){
    int start = 0 ,end =n;
    int mid = start + (end -start)/2;
    int ans ;
    while(start <= end){
        int temp = mid * mid;
        if(temp==n){
            return mid;
        }
        if(temp>n){
            end = mid-1;
        }
        else{
            ans = mid;
            start = mid +1;
        }
        mid = start + (end -start)/2;
    }
    return ans;
}

int main(){
    cout<<sqrt(7);
    return 0;
}