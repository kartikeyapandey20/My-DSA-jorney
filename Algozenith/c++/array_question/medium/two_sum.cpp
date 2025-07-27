#include<bits/stdc++.h>

using namespace std;

// Brute Force
void twoSumBrute(vector<int> nums , int target){
    int firstIndex = 0, secondIndex = 0;
    for(int i = 0; i < nums.size(); i++)
    {
        for(int j =  i + 1; j < nums.size(); j++)
        {
            if(nums[i] + nums[j] == target)
            {
                firstIndex = i;
                secondIndex = j;
                break;
            }
        }
    }

    cout << "First value " << nums[firstIndex] << " At Index " << firstIndex <<endl;
    cout << "Second value " << nums[secondIndex] << " At Index " << secondIndex <<endl;
}

// Better Solution
void twoSumBetter(vector<int> nums , int target){
    map<int,int> mpp;
    int n = nums.size();
    vector<int> ans = {0,0};
    for(int i = 0; i < n; i++)
    {
        int num = nums[i];
        int moreNeeded = target - num;
        if(mpp.find(moreNeeded) !=mpp.end())
        {
            ans = {mpp[moreNeeded] , i};
        } 
        mpp[num] = i;
    }

    cout << "First value " << nums[ans[0]] << " At Index " << ans[0] <<endl;
    cout << "Second value " << nums[ans[1]] << " At Index " << ans[1] <<endl;

}


int main(){
    vector<int> nums = {2,4,6,2,7};
    // Brute Force Solution
    twoSumBrute(nums,8);
    twoSumBetter(nums,8);
    return 0;
}