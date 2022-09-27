#include<iostream>

using namespace std;

int sqrt(int n , int s , int e){
    if(n==0){
        return 0;
    }
    int mid = s + (e - s)/2;
    if(mid * mid == n){
        return mid;
    }
    if(mid * mid < n){
        s = mid +1;
        return sqrt(n , s , e);
    }
    else{
        e = mid - 1 ;
        return sqrt(n , s , e);
    }
}
int main(){
    int a = 16;
    int ans = sqrt(a,0,a);
    cout<< ans << endl;
    return 0;
}
