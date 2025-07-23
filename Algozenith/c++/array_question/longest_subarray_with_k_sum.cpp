#include<bits/stdc++.h>

using namespace std;

// Optimal solution
void longestSubarrayWithSumK(vector<int> nums , long long k)
{
    int left  = 0 , right = 0;
    long long sum = nums[0];
    int maxLen = 0;
    int n = nums.size();

    while(right < n){
        while(left <= right && sum > k){
            sum -= nums[left];
            left++;
        }
        if(sum == k){
            maxLen = max(maxLen , right - left + 1);
        }
        right++;
        if(right < n){
            sum += nums[right];
        }
    }

    cout  << "length of longest subarray with k sum is : " << maxLen;
}
int main(){
    vector<int> nums = {1,2,3,1,1,1,1,3,3};

    longestSubarrayWithSumK(nums,6);
}