#include<bits/stdc++.h>

using namespace std;

void singleNumber(vector<int>& nums) {
    int ans = 0;
    for(int i = 0; i < nums.size(); i++)
    {
        ans = ans ^ nums[i];
    }

    cout << "single Number is : " <<ans;
}

int main(){
    vector<int> nums = {2,2,1};
    singleNumber(nums);   
    return 0;
}