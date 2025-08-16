#include<bits/stdc++.h>

using namespace std;




int majorityElementBrute(vector<int> nums, int n)
{
    
    for(int i = 0; i < n ; i++)
    {
        int cnt = 0;
        for(int j = 0 ; j < n; j++)
        {
            if(nums[i] == nums[j])
            {
                cnt++;
            }
        }
        if(cnt > n/2)
        {
            return nums[i];
        }
    }
    return -1;
}

int main(){
    vector<int> nums =  {2,2,1,1,1,2,2};
    int n = nums.size();

    int ans = majorityElementBrute(nums,n);
    cout  << "Answer : " << ans;
    return 0;
}