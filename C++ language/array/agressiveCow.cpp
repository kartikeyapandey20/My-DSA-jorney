#include<iostream>
#include<vector>
#include<bits\stdc++.h>

using namespace std;

bool isPossible(vector<int> arr, int k , int mid){
    int cowCount =1;
    int lastPostition = arr[0];
    for(int i = 0; i <arr.size();i++){
        if((arr[i]-lastPostition)>=mid){
            cowCount++;
            if(cowCount==k){
                return true;
            }
            lastPostition = arr[i];
        }   
    }
    return false;
}

int agressiveCow(vector<int> &stalls , int k){
    sort(stalls.begin(),stalls.end());
    int s = 0 ;
    int  max = -1;
    for(int i = 0 ; i < stalls.size();i++){
        if(stalls[i]>max){
            max = stalls[i];
        }
    }
    int ans;
    int e = max;
    int mid = s + (e-s)/2;
    while(s<=e){
        if(isPossible(stalls,2,mid)){
            ans = mid;
            s = mid +1;
        } 
        else{
            e= mid -1;
        }
        mid = s + (e-s)/2;
    }
    return ans;
}

int main(){
    vector<int> arr ={4,2,1,3,6};
    cout<<"distance between agressive cow is : "<<agressiveCow(arr,2);
    return 0;
}