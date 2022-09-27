#include<iostream>

using namespace std;


int nStairsToReach(int nStairs){
    if(nStairs < 0){
        return 0;
    }
    if(nStairs == 0){
        return 1;
    }
    int ans = nStairsToReach(nStairs-1) + nStairsToReach(nStairs-2);
    return ans;
}
int main(){
    cout<<nStairsToReach(3)<<endl;
    return 0;
}